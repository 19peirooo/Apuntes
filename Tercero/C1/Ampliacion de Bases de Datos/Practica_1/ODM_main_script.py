import ODM_main_app as manager

def main():
    manager.ODM.dropDataBase()
    manager.ODM.initApp()
    print(f"Generando instancias de las colecciones... ")
    print()
    persona = manager.ODM.Persona(nombre = "Victor", dni = "1263789X")
    persona1 = manager.ODM.Persona(nombre = "Victor", dni = "126789X")
    persona2 = manager.ODM.Persona(nombre = "Victor", dni = "13789X")
    centroEducativo = manager.ODM.CentroEducativo(nombre = "Maristas", codigo = "14567878")
    empresa = manager.ODM.Empresa(nombre = "Adif", cif = "34567890")

    persona.nombre = "Diego"
    centroEducativo.nombre = "Zurbaran"
    empresa.nombre = "CruzCampo"
    try:
        persona.dni = ""
    except ValueError as e:
        print(e)
    persona.save()
    persona1.save()
    persona2.save()
    centroEducativo.save()
    empresa.save()

    print("Generando Persona sin DNI y guardo su altura:")
    try:
        persona_sin_dni = manager.ODM.Persona(nombre="Jorge")
        persona_sin_dni.altura = 1.5
    except (AttributeError,ValueError) as e:
        print(e)

    try:
        persona_alta = manager.ODM.Persona(nombre="x",dni="ads")
        persona_alta.altura = 1.5
    except (AttributeError,ValueError) as e:
        print(e)

    print("Generando Persona con DNI 126789X. Mismo DNI que Victor")
    try:
        dni_dupe = manager.ODM.Persona(nombre="Juan", dni="126789X")
    except ValueError as e:
        print(e)

    cursor = persona.find({})
    for idx,doc in enumerate(cursor):
        print(f"*** Documento {idx+1} ***")
        doc.print_document()
        print()

    print("Eliminando Persona Diego...")
    persona.delete()
    try:
        persona.find({"nombre": "Diego"})
    except ValueError as e:
        print(e)
    
    print("Intento Borrar Dato no Cargado en Mongo...")
    try:
        persona.delete()
    except ValueError as e:
        print(e)
    
    manager.dump_collection("Persona", "persona")

if __name__ in '__main__':
    main()
