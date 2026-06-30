__author__ = '???'
__students__ = 'Diego Jaime Vega Sanchez y Victor Manuel Peiro Martinez'


from geopy.geocoders import Nominatim
from geopy.exc import GeocoderTimedOut
import time
from typing import Generator, Any, Self
from geojson import Point
import pymongo
from bson.objectid import ObjectId
import yaml

def getLocationPoint(address: str) -> Point:
    """ 
    Obtiene las coordenadas de una dirección en formato geojson.Point
    Utilizar la API de geopy para obtener las coordenadas de la direccion
    Cuidado, la API es publica tiene limite de peticiones, utilizar sleeps.

    Parameters
    ----------
        address : str
            direccion completa de la que obtener las coordenadas
    Returns
    -------
        geojson.Point
            coordenadas del punto de la direccion
    """
    #Asignamos un numero maximo de intentos ya que a veces tarda
    max_attempts = 5
    attempts = 0

    location = None
    while location is None and attempts < max_attempts:
        try:
            time.sleep(1)
            # Es necesario proporcionar un user_agent para utilizar la API
            # Utilizar un nombre aleatorio para el user_agent
            location = Nominatim(user_agent="Diego-Peiro").geocode(address)
        except GeocoderTimedOut:
            # Puede lanzar una excepcion si se supera el tiempo de espera
            # Volver a intentarlo
            attempts += 1
            continue
        
        attempts += 1

    #Si alcanza el numero maximo de intentos sin geolocalizar, lanza error
    if location is None and attempts >= max_attempts:
        raise ValueError("No se pudieron obtener coordenadas")

    # Devolver un GeoJSON de tipo punto con la latitud y longitud almacenadas
    return Point((location.longitude,location.latitude)) #Devuelve un objeto Point que contiene la tupla de coordenadas


class Model:
    """ 
    Clase de modelo abstracta
    Crear tantas clases que hereden de esta clase como  
    colecciones/modelos se deseen tener en la base de datos.

    Attributes
    ----------
        required_vars : set[str]
            conjunto de atributos requeridos por el modelo
        admissible_vars : set[str]
            conjunto de atributos admitidos por el modelo
        db : pymongo.collection.Collection
            conexion a la coleccion de la base de datos
    
    Methods
    -------
        __setattr__(name: str, value: str | dict) -> None
            Sobreescribe el metodo de asignacion de valores a los 
            atributos del objeto con el fin de controlar qué atributos 
            son modificados y cuando son modificados.
        __getattr__(name: str) -> Any
            Sobreescribe el metodo de acceso a atributos del objeto 
        save()  -> None
            Guarda el modelo en la base de datos
        delete() -> None
            Elimina el modelo de la base de datos
        find(filter: dict[str, str | dict]) -> ModelCursor
            Realiza una consulta de lectura en la BBDD.
            Devuelve un cursor de modelos ModelCursor
        aggregate(pipeline: list[dict]) -> pymongo.command_cursor.CommandCursor
            Devuelve el resultado de una consulta aggregate.
        find_by_id(id: str) -> dict | None
            Busca un documento por su id utilizando la cache y lo devuelve.
            Si no se encuentra el documento, devuelve None.
        init_class(db_collection: pymongo.collection.Collection, required_vars: set[str], admissible_vars: set[str]) -> None
            Inicializa las variables de clase en la inicializacion del sistema.

    """
    _required_vars: set[str]
    _admissible_vars: set[str]
    _location_var: None
    _db: pymongo.collection.Collection
    _unique_indexes: [str]

    def __init__(self, **kwargs: dict[str, str | dict]):
        """
        Inicializa el modelo con los valores proporcionados en kwargs
        Comprueba que los valores proporcionados en kwargs son admitidos
        por el modelo y que las atributos requeridos son proporcionadas.

        Parameters
        ----------
            kwargs : dict[str, str | dict]
                diccionario con los valores de las atributos del modelo
        """
        # ??
        super().__setattr__('_modified_vars', {})  
        super().__setattr__('_data', {}) 

        # Realizar las comprabociones y gestiones necesarias
        # antes de la asignacion.
        new_vars = set(kwargs.keys())

        #Comprobacion de que se tengan todos los required vars
        has_required_vars = self._required_vars.issubset(new_vars) #Comprueba si mis required vars son un subset de mis atributos
        if not has_required_vars:
            raise AttributeError("ERROR: No se cumplen los requisitos de la coleccion")
        
        location_GEOJSON = {f"{self._location_var}_loc"} if self._location_var else {}
        allowed_vars = self._admissible_vars | self._required_vars | {"_id"} | location_GEOJSON #Cojo todas las variables permitidas
        invalid_attributes = new_vars - allowed_vars #Comprueba si hay duplicados y los elimina
        if invalid_attributes: #Si la lista esta vacia es que no hay ningun atributo que sobre
            raise AttributeError(f"ERROR: Hay atributos que no estan admitidos: {invalid_attributes}")

        for name,value in kwargs.items(): #Hace set de todas las variables ya que sabemos que estan todas permitidas
            self.__setattr__(name,value)
            self._modified_vars[name] = False


    def __setattr__(self, name: str, value: str | dict) -> None:
        """ Sobreescribe el metodo de asignacion de valores a los 
        atributos del objeto con el fin de controlar que atributos 
        son modificados y cuando son modificados.
        """
        # Realizar las comprabociones y gestiones necesarias
        # antes de la asignacion.

        #Comprueba si queremos cambiar algun atributo del objeto. Ej: Quiero meter una variable admissible mas
        if name in {'_modified_vars', '_required_vars', '_admissible_vars', '_db', '_data', '_location_var'}:
            super().__setattr__(name,value)
            return

        #Vuelvo a comprobar si la variable es una variable permitida
        location_GEOJSON = {f"{self._location_var}_loc"} if self._location_var else {}
        allowed_vars = self._admissible_vars | self._required_vars | {"_id"} | location_GEOJSON
        if name not in allowed_vars:
            raise AttributeError(f"ERROR: {name} no es una variable admisible o requerida")

        #Si la variable es la variable location, hay que pasarlo a formato 2dsphere
        #Compruebo si hay una variable location asignada y despues si es la que tenemos
        if name in self._unique_indexes:
            query = {name: value}
            if '_id' in self._data:
                query['_id'] = {'$ne': self._data['_id']} #Para que no se encuentre a si mismo
            if self._db.find_one(query) is not None:
                raise ValueError("ERROR: Unique key duplicada. No se cargara el dato")
            if value == "":
                raise ValueError("ERROR: La cadena no puede estar vacia")

        if name in self._data: #Si hay un valor asignado para este atributo
            prev_val = self._data[name]
            if prev_val != value: #Compruebo si he modificado el valor
                self._modified_vars[name] = True
        else:
            self._modified_vars[name] = True

        if self._location_var and name == self._location_var:
            new_name= name + '_loc'
            self._data[new_name] = getLocationPoint(value)

        # Asigna el valor value a la variable name
        self._data[name] = value

    def __getattr__(self, name: str) -> Any:
        """ Sobreescribe el metodo de acceso a atributos del objeto
        __getattr__ solo es llamado cuando no encuentra el atributo
        en el objeto 
        """
        if name in {'_modified_vars', '_required_vars', '_admissible_vars', '_db', '_data', '_location_var'}:
            return super().__getattribute__(name)
        try:
            return self._data[name]
        except KeyError:
            raise AttributeError
        
    def save(self) -> None:
        """
        Guarda el modelo en la base de datos
        Si el modelo no existe en la base de datos, se crea un nuevo
        documento con los valores del modelo. En caso contrario, se
        actualiza el documento existente con los nuevos valores delj
        modelo.
        """
        if self._db is None:
            raise ValueError("ERROR: No hay un base de datos cargada")

        data = self._data.copy() # Creo una copia por si algo le pasase a los datos originales durante la transacción

        #Compruebo si el documento ya existe
        #Si no existe lo inserta
        if '_id' not in self._data:
            res = self._db.insert_one(data)
            self._data['_id'] = res.inserted_id #Al ser nuevo, le tenemos que asignar el id que le ha asignado mongo
        #Si ya existe, actualizo solo los atributos que he modificado
        else:
            #Busco el id del documento que quiero
            doc_id = data['_id']
            for name,updated in self._modified_vars.items():
                if updated:
                    new_val = data[name]
                    self._db.update_one({'_id':doc_id},{'$set':{name:new_val}})
                self._modified_vars[name] = False
        print(f"Informacion añadida en la Base de Datos")

    def delete(self) -> None:
        """
        Elimina el modelo de la base de datos
        """
        #Compruebo si hay una base de datos asignada
        if self._db is None:
            raise ValueError('ERROR: No hay una base de datos cargada')
        #Comprueba que el documento exista en la base de datos
        if '_id' not in self._data or self._data['_id'] is None:
            raise ValueError('ERROR: No puedes borrar algo que no esta cargado en la base de datos')
        
        #Lo elimina unicamente en la BD
        res = self._db.delete_one({'_id': self._data['_id']})
        
        if res.deleted_count == 1:
            # Limpiar el contenido del objeto en memoria
            self._data.clear()
            self._modified_vars.clear()
            del self
        
        print(f"Documento eliminado con éxito")
    
    def print_document(self):
        for name,value in self._data.items():
            print(f"{name}: {value}")

    @classmethod
    def find(cls, filter: dict[str, str | dict]) -> Any:
        """ 
        Utiliza el metodo find de pymongo para realizar una consulta
        de lectura en la BBDD
        find debe devolver un cursor de modelos ModelCursor

        Parameters
        ----------
            filter : dict[str, str | dict]
                diccionario con el criterio de busqueda de la consulta
        Returns
        -------
            ModelCursor
                cursor de modelos
        """ 
        # cls es el puntero a la clase
        if cls._db is None:
            raise ValueError('ERROR: No hay una base de datos cargada')

        cursor = cls._db.find(filter)
        return ModelCursor(cls,cursor)

    @classmethod
    def aggregate(cls, pipeline: list[dict]) -> pymongo.command_cursor.CommandCursor:
        """ 
        Devuelve el resultado de una consulta aggregate. 
        No hay nada que hacer en esta funcion.
        Se utilizara para las consultas solicitadas
        en el segundo proyecto de la practica.

        Parameters
        ----------
            pipeline : list[dict]
                lista de etapas de la consulta aggregate 
        Returns
        -------
            pymongo.command_cursor.CommandCursor
                cursor de pymongo con el resultado de la consulta
        """ 
        return cls.db.aggregate(pipeline)
    
    @classmethod
    def find_by_id(cls, id: str) -> Self | None:
        """ 
        NO IMPLEMENTAR HASTA EL TERCER PROYECTO
        Busca un documento por su id utilizando la cache y lo devuelve.
        Si no se encuentra el documento, devuelve None.

        Parameters
        ----------
            id : str
                id del documento a buscar
        Returns
        -------
            Self | None
                Modelo del documento encontrado o None si no se encuentra
        """ 
        #TODO
        pass

    @classmethod
    def init_class(cls, db_collection: pymongo.collection.Collection, indexes:dict[str,str], required_vars: set[str], admissible_vars: set[str]) -> None:
        """ 
        Inicializa los atributos de clase en la inicializacion del sistema.
        Aqui se deben inicializar o asegurar los indices. Tambien se puede
        alguna otra inicialización/comprobaciones o cambios adicionales
        que estime el alumno.

        Parameters
        ----------
            db_collection : pymongo.collection.Collection
                Conexion a la collecion de la base de datos.
            indexes: Dict[str,str]
                Set de indices y tipo de indices para la coleccion
            required_vars : set[str]
                Set de atributos requeridos por el modelo
            admissible_vars : set[str] 
                Set de atributos admitidos por el modelo
        """
        cls._db = db_collection
        cls._required_vars = required_vars
        cls._admissible_vars = admissible_vars
        cls._location_var = indexes.get('location_index')
        cls._unique_indexes = indexes.get('unique_indexes',[])

        if cls._location_var:
            loc_var = cls._location_var+"_loc"
            cls._db.create_index([(loc_var,pymongo.GEOSPHERE)])
        
        for idx_field in cls._unique_indexes:
            cls._db.create_index(idx_field,unique=True)
        
        for idx_field in indexes.get('regular_indexes',[]):
            cls._db.create_index(idx_field)


class ModelCursor:
    """ 
    Cursor para iterar sobre los documentos del resultado de una
    consulta. Los documentos deben ser devueltos en forma de objetos
    modelo.

    Attributes
    ----------
        model_class : Model
            Clase para crear los modelos de los documentos que se iteran.
        cursor : pymongo.cursor.Cursor
            Cursor de pymongo a iterar

    Methods
    -------
        __iter__() -> Generator
            Devuelve un iterador que recorre los elementos del cursor
            y devuelve los documentos en forma de objetos modelo.
    """

    def __init__(self, model_class: Model, cursor: pymongo.cursor.Cursor):
        """
        Inicializa el cursor con la clase de modelo y el cursor de pymongo

        Parameters
        ----------
            model_class : Model
                Clase para crear los modelos de los documentos que se iteran.
            cursor: pymongo.cursor.Cursor
                Cursor de pymongo a iterar
        """
        self.model = model_class
        self.cursor = cursor
    
    def __iter__(self) -> Generator:
        """
        Devuelve un iterador que recorre los elementos del cursor
        y devuelve los documentos en forma de objetos modelo.
        Utilizar yield para generar el iterador
        Utilizar la funcion next para obtener el siguiente documento del cursor
        Utilizar alive para comprobar si existen mas documentos.
        """

        while self.cursor.alive: #Mientras haya documentos 
            try:
                doc = next(self.cursor) #Cogemos el siguiente documento del cursor
                model_instance = self.model(**doc) #Crea una instancia del modelo con el documento
                yield model_instance #Genera el iterador y lo devuelve
            except StopIteration: #Cuando no haya mas documentos, se lanza esta excepcion asi que sabremos que hemos recorrido todos los documentos
                break


def initApp(definitions_path: str = "./models.yml", mongodb_uri="mongodb://localhost:27017/", db_name="db_Practica1", scope=globals()) -> None:
    """ 
    Declara las clases que heredan de Model para cada uno de los 
    modelos de las colecciones definidas en definitions_path.
    Inicializa las clases de los modelos proporcionando los indices y 
    atributos admitidos y requeridoscli para cada una de ellas y la conexión a la
    collecion de la base de datos.
    
    Parameters
    ----------
        definitions_path : str
            ruta al fichero de definiciones de modelos
        mongodb_uri : str
            uri de conexion a la base de datos
        db_name : str
            nombre de la base de datos
    """
    # Inicializar base de datos
    client = pymongo.MongoClient(mongodb_uri) #Se conecta con MongoDB
    db = client[db_name] #Selecciona la base de datos

    try: 
        with open(definitions_path,'r') as f:
            models_definitions = yaml.safe_load(f)
    except FileNotFoundError:
        raise FileNotFoundError(f"ERROR: Fichero no encontrado. Verifique la ruta")
    except yaml.YAMLError as e:
        raise ValueError(f"ERROR: El fichero YAML tiene un formato inválido: {e}")
    
    yaml_requierements = {'required_vars','admissible_vars','unique_indexes','regular_indexes','location_index'}

    # indices y los atributos admitidos y requeridos para cada una de ellas.
    for collection, defs in models_definitions.items():
        yaml_keys = set(defs.keys())

        if yaml_keys != yaml_requierements:
            raise ValueError("ERROR: Las claves del YAML no coinciden con las requeridas")

        required_vars = set(defs.get('required_vars',[]))
        admissible_vars = set(defs.get('admissible_vars',[]))
        indexes = {
            'unique_indexes': defs.get('unique_indexes',[]),
            'regular_indexes': defs.get('regular_indexes',[]),
            'location_index': defs.get('location_index')
        }
        """ 
        La funcion type:
            Parametros:
            -   Coleccion: Nombre de la coleccion extraida del yaml (yaml.safeload)
            -   (Model,): Es una tupla que contiene un diccionario con una referencia a la clase Model.
                Es una tupla que indica que una nueva clase hereda de Model
            -   {}: Esta indicando que no se necesitan ni métodos ni atributos adicionales.
            Funcionamiento:
                Sirve para definir en ModelClass la estructura que van a tener las colecciones de la Base de Datos.
                El resultado es una nueva clase del tipo Model.
        """
        ModelClass = type(collection, (Model,),{})
        scope[collection] = ModelClass

        ModelClass.init_class(
            db_collection=db[collection],
            indexes=indexes,
            required_vars= required_vars,
            admissible_vars= admissible_vars
        )

def dropDataBase(mongodb_uri="mongodb://localhost:27017/", db_name="db_Practica1", scope=globals()) -> None:
    client = pymongo.MongoClient(mongodb_uri) #Se conecta con MongoDB
    client.drop_database(db_name)