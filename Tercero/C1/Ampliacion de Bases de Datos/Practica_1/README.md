# ODM para MongoDB

**Autores:**  Diego Jaime Vega Sánchez y Víctor Manuel Peiró Martínez

## Descripción

Implementación de un Object Document Mapper (ODM) en Python.  
Permite definir modelos dinámicamente a partir de un archivo de configuración YAML.  
El ODM facilita la gestión y acceso a la información en la base de datos de manera sencilla.  

Para su funcionamiento, el ODM precisa de un fichero **YAML** en el que se indique la estructura de los modelos a almacenar, así como: variables requeridas, variables aceptadas, índices y otras propiedades.

---

## Funciones propias del ODM

Son aquellas funciones, ajenas a los modelos; que utilizará el ODM para el tratamiento u obtención de datos.

### getLocationPoint(address: str) -> Point

Dada una dirección, la transforma en coordenadas virtuales con el formato [latitud, longitud].  
Utiliza la API pública de **Geopy (Nominatim)**.

**Parámetros:**

- `address (str)`: Dirección completa a geolocalizar.

**Retorna:**

- `geojson.Point`: Coordenadas (latitud, longitud).

**Excepciones:**

- `GeocoderTimedOut`: Si la petición a la API de geolocalización supera el tiempo de espera.  
- `ValueError`: Si no se pueden obtener coordenadas tras varios intentos.

---

### initApp(definitions_path: str, mongodb_uri: str, db_name: str, scope: dict)

Carga las definiciones de modelos desde un archivo YAML y los inicializa dinámicamente.  
Se encargará de crear tanto la Base de Datos como las colecciones especificadas en el YAML, así como los tipos de variables, índices, etc.

**Parámetros:**

- `definitions_path`: Ruta al archivo YAML con las definiciones.  
- `mongodb_uri`: URI de conexión a MongoDB.  
- `db_name`: Nombre de la base de datos.  
- `scope`: Espacio de nombres donde registrar las clases generadas.

**Acciones:**

- Crea dinámicamente las clases ODM según el YAML.  
- Inicializa los índices y variables de clase.

**Excepciones:**

- `FileNotFoundError`: Si el fichero YAML no existe o no está en la ruta.  
- `yaml.YAMLError`: Si el contenido del YAML no tiene un formato válido.  
- `ValueError`: Si las claves del YAML no coinciden con las requeridas (`required_vars`, `admissible_vars`, etc.).

---

## Clase Model

Clase base abstracta para la definición de modelos ODM.  
Permite gestionar la persistencia y validación de documentos.  
Los objetos de esta clase representan los documentos que se almacenan en la base de datos.

**Atributos principales:**

- `_required_vars`: Conjunto de variables requeridas definidas en el YAML.  
- `_admissible_vars`: Conjunto de variables permitidas definidas en el YAML.  
- `_db`: Conexión a la base de datos de MongoDB.

---

### Métodos Model

#### **init**(**kwargs)

Inicializa una instancia verificando atributos requeridos y válidos.

**Excepciones:**

- `AttributeError`:  
  - Si no se cumplen las variables requeridas.  
  - Si se incluyen atributos no admitidos por el modelo.

---

#### **setattr**(name, value)

Controla la asignación y validación de atributos (incluye índices únicos y geolocalización).

**Excepciones:**

- `AttributeError`: Si se intenta asignar un atributo no permitido.  
- `ValueError`:  
  - Si se intenta insertar un valor duplicado en un índice único.  
  - Si se produce un error al obtener coordenadas de una variable de localización.

---

#### **getattr**(name)

Permite acceder a atributos definidos en `_data`.

**Excepciones:**

- `AttributeError`: Si el atributo solicitado no existe.

---

#### save()

Inserta o actualiza el documento en MongoDB según exista o no `_id`.

**Excepciones:**

- `ValueError`: Si no existe una conexión a la base de datos.  

---

#### delete()

Elimina el documento actual de la base de datos.

**Excepciones:**

- `ValueError`:  
  - Si no hay conexión a la base de datos.  
  - Si se intenta eliminar un documento no cargado (sin `_id`).  

---

#### print_document(self)

Imprime el nombre de todos los documentos en una colección

---

#### find(filter)

Realiza una consulta y devuelve un `ModelCursor`.

**Excepciones:**

- `ValueError`: Si la base de datos no está inicializada.  

---

#### aggregate(pipeline)

Ejecuta una agregación de MongoDB.

---

#### find_by_id(id)

(Pendiente de implementación)

---

#### init_class(db_collection, indexes, required_vars, admissible_vars)

Inicializa los parámetros de clase y define los índices. No necesita gestión de excepciones, porqué se realizan en `initApp`.

---

## Clase ModelCursor

Envuelve un cursor de MongoDB y permite iterar sobre los resultados como objetos `Model`.

### Métodos ModelCursor

#### **init**(model_class, cursor)

Asocia la clase de modelo y el cursor de MongoDB.

#### **iter**()

Itera sobre los resultados devolviendo instancias del modelo.

## Ejecucion
Para ejecutar el ODM, hemos preparado 2 posibles archivos que son los siguentes:
- `ODM_main_script.py`
- `ODM_main_app.py`

### Script
El archivo `ODM_main_script.py` es un archivo sencillo con un solo flujo de ejecucion donde se van enseñando como funciona el ODM lanzando algunas de las posibles excepciones que lanza el programa.

### App
El archivo `ODM_main_app.py` simula una aplicacion personalizada donde mediante un menu puedes probar las siguiente funcionalidades:

#### Añadir Documento
El programa de deja crear un documento de cualquier coleccion definida en el `models.yml`. Primero te pide la colección y luego te permite introducir las variables que quieras en formato **nombre:valor** hasta que recibe una cadena vacia. Se tiene en cuenta todos los posibles errores que pueden aparecer.

#### Modificar Elemento
Te permite seleccionar un documento de una coleccion y actualizarlo. Los cambios se introducen de la misma manera que como cuando se añaden nuevos documentos.

#### Buscar Documento
Te permite buscar documentos en la colección que decidas. Las busquedas se hacen mediante queries como si estuvieses en mongo.

#### Borrar Documento
Te permite borrar un documento de la base de datos

#### Generación de Dumps
Permite generar un dump de la coleccion que elijas con el nombre que tu quieras.
