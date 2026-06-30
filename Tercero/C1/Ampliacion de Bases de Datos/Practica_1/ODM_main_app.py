import ODM
import random
import pymongo
import json
import yaml
import sys

def parse_value(val):
    try:
        if '.' in val:
            return float(val)
        else:
            return int(val)
    except ValueError:
        return val

def dump_collection(coleccion,name):
    client = pymongo.MongoClient("mongodb://localhost:27017/")
    db = client["db_Practica1"]

    docs = list(db[coleccion].find({}))

    for doc in docs:
        doc["_id"] = str(doc["_id"])

    output_path = f"{name}.json"
    with open(output_path, "w", encoding="utf-8") as f:
        json.dump(docs, f, ensure_ascii=False, indent=2)
    
def print_models(models):
    for idx,model in enumerate(models):
        print(f"{idx+1}. {model}")

def print_docs(cursor):
    docs = []
    for idx,doc in enumerate(cursor):
        print(f"*** Documento {idx+1} ***")
        doc.print_document()
        print()
        docs.append(doc)

    return docs

def create_document(models,scope):
    validOption = False
    num_models = len(models)
    while not validOption:
        model_selected = -1
        print_models(models)
        model_selected = int(input("Elige coleccion: "))
        validOption = True if model_selected > 0 and model_selected <= num_models else False

        if not validOption:
            print("ERROR: Coleccion Invalida")
        else:
            ModelClass = scope[models[model_selected-1]]
            new_data={}
            val = "a"
            while val != "":
                val = input("Introduce en formato (variable:valor). Cadena Vacia para no introducir mas datos: ")
                if val != "":
                    try:
                        name = val.split(":")[0].strip()
                        value = val.split(":")[1].strip()
                        new_data[name] = parse_value(value)
                    except IndexError:
                        print("ERROR: Formato Incorrecto")
            
            doc = ModelClass(**new_data)
            doc.save()

    return doc

def modify_elements(models, scope):
    validOption = False
    num_models = len(models)
    while not validOption:
        model_selected = -1
        print_models(models)
        model_selected = int(input("Elige coleccion: "))
        validOption = True if model_selected > 0 and model_selected <= num_models else False

        if not validOption:
            print("ERROR: Coleccion Invalida")
        else:
            ModelClass = scope[models[model_selected-1]]
            cursor = ModelClass.find({})
            docs = print_docs(cursor)

            if len(docs) == 0:
                print("ERROR: No hay documentos que modificar")
                return

            valid_doc = False
            while not valid_doc:
                doc_selected = int(input("Selecciona un documento: "))

                valid_doc = True if doc_selected > 0 and model_selected <= len(docs) else False

                if not valid_doc:
                    print("ERROR: Documento invalido")
                else:
                    modified_doc = docs[doc_selected-1]
                    val = "a"
                    while val != "":
                        val = input("Introduce en formato (variable:valor). Cadena Vacia para no introducir mas datos: ")
                        if val != "":
                            try:
                                name = val.split(":")[0].strip()
                                value = val.split(":")[1].strip()
                                value = parse_value(value)
                                try:
                                    setattr(modified_doc,name,value)
                                except (AttributeError,ValueError) as e:
                                    print(e)
                            except IndexError:
                                print("ERROR: Formato Incorrecto")
                    modified_doc.print_document()
                    modified_doc.save()
                    
def find_document(models,scope):
    validOption = False
    num_models = len(models)
    while not validOption:
        model_selected = -1
        print_models(models)
        model_selected = int(input("Elige coleccion: "))
        validOption = True if model_selected > 0 and model_selected <= num_models else False

        if not validOption:
            print("ERROR: Coleccion Invalida")
        else:
            find_filter = input("Introduce el filtro de busqueda: ")
            ModelClass = scope[models[model_selected-1]]
                               
            try:
                docs = []
                query = json.loads(find_filter)
                cursor = ModelClass.find(query)
                for idx,doc in enumerate(cursor):
                    print(f"Documento {idx+1}")
                    doc.print_document()
                    print()
                    docs.append(doc)
                return docs

            except json.decoder.JSONDecodeError:
                print("ERROR: JSON Query Invalida")

def delete_document(models,scope):
    validOption = False
    num_models = len(models)
    while not validOption:
        model_selected = -1
        print_models(models)
        model_selected = int(input("Elige coleccion: "))
        validOption = True if model_selected > 0 and model_selected <= num_models else False

        if not validOption:
            print("ERROR: Coleccion Invalida")
        else:
            ModelClass = scope[models[model_selected-1]]
            cursor = ModelClass.find({})
            docs = print_docs(cursor)
            if len(docs) != 0:
                docIndex = int(input("Introduce el indice del documento a eliminar: "))
                docs[docIndex - 1].delete()
            else:
                print("La colección está vacía\n")

if __name__ in '__main__':

    scope = {}
    try:
        ODM.initApp(scope=scope)
    except (FileNotFoundError,yaml.YAMLError) as e:
        print(e)
        print("No se pudo iniciar app")
        sys.exit(1)

    num_models = len(scope)
    models = list(scope.keys())

    option=-1

    while option != 0:
        print("***ODM***")
        print("1. Añadir Documento")
        print("2. Añadir Varios Documentos")
        print("3. Modificar documento")
        print("4. Buscar Documentos")
        print("5. Borrar Documento")
        print("6. Dumpear Coleccion")
        print("0. Salir")

        option = int(input("Elige Opcion: "))
        match option:
            case 1:
                try:
                    create_document(models,scope)
                except (ValueError,AttributeError) as e:
                    print(e)
            case 2:
                num_docs = -1
                while num_docs <= 0:
                    num_docs = int(input("Cuantos documentos quieres crear: "))

                    if num_docs <= 0:
                        print("ERROR: Numero de documentos a crear ha de ser mayor que 0")
                
                for i in range(num_docs):
                    try:
                        create_document(models,scope)
                    except (ValueError,AttributeError) as e:
                        print(e)

            case 3:
                try:
                    modify_elements(models,scope)
                except Exception as e:
                    print(e)
            case 4:
                try:
                    find_document(models,scope)
                except Exception as e:
                    print(e)

            case 5:
                try:
                    delete_document(models,scope)
                except Exception as e:
                    print(e)
            case 6:
                nombre_archivo = input("Nombre del Archivo a Guardar (sin extension): ")
                validOption = False
                while not validOption:
                    model_selected = -1
                    print_models(models)
                    model_selected = int(input("Elige coleccion: "))
                    validOption = True if model_selected > 0 and model_selected <= num_models else False

                    if not validOption:
                        print("ERROR: Coleccion Invalida")
                    else:
                        model = models[model_selected-1]
                        dump_collection(model,nombre_archivo)
            case 0:
                print("Saliendo del programa")
                break
            case _:
                print("ERROR: Opcion invalida")