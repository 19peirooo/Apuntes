import ODM
import redis

cache = redis.Redis(
    host="localhost",
    port=6379,
    db=0,
    decode_responses=True #Para que devuelve cadenas y no bytes
)

def main():

    ODM.dropDataBase()
    ODM.initApp()

    #Creacion de Personas para la practica
    print("\n-- Creacion de Personas de Prueba --")
    p1 = ODM.Persona(nombre="Diego Jaime Vega", dni="12345679A")
    p2 = ODM.Persona(nombre="Victor Manuel Peiro", dni="98765432Z")
    p3 = ODM.Persona(nombre="Pablo Gonzalez", dni="45612389K")
    p4 = ODM.Persona(nombre="Gonzalo Martinez", dni="30412795J")
    p5 = ODM.Persona(nombre="Matias Svriz", dni="30303030V")

    p1.save()
    p2.save()
    p3.save()
    p4.save()
    p5.save()

    #Obtengo los ids de todos
    print("\n-- Obteniendo IDs de Personas de Prueba --")
    cursor = ODM.Persona.find({})
    ids = []
    for doc in cursor:
        ids.append(doc._id)
        print(f"ID: {doc._id}")
    
    redis_ids = [f"Persona:{id}" for id in ids]

    print("\n-- Subimos Personas 1 y 3 a cache --")
    p1.find_by_id(ids[0])
    p3.find_by_id(ids[2])

    print("\n-- Verificacion de que se ha subido a cache --")
    p1_data = p1.find_by_id(ids[0])
    p3_data = p3.find_by_id(ids[2])

    print("Datos de Persona 1 de cache", p1_data)
    print("Datos de Persona 3 de cache", p3_data)

    print("\n-- Actualizando a Persona 1 (Se borra de cache) --")
    p1.nombre = "Diego Jaime Vega Sanchez"
    p1.save()

    p1_data = cache.get(redis_ids[0])
    print("Datos de Diego en cache: ", p1_data)

    print("\n-- Eliminado a Persona 3 (Se borran datos de cache) --")
    p3.delete()
    p3_data = p3.find_by_id(ids[2])
    print("Datos de Pablo en cache: ", p3_data)

    

if __name__ == '__main__':
    main()
