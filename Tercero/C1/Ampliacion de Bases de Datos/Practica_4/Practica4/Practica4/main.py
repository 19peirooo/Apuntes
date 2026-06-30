from neo4jManager import Neo4jManager as manager,NodeType,RelationshipType 
from generate_data import generate_data,dump_data,load_data

HOST = "bolt://localhost:7687"
USER = "neo4j"
PASSWORD = "12345678"

def main():

    try:
        api = manager(HOST,USER,PASSWORD)
    except Exception:
        print("ERROR: No se pudo acceder a Neo4j. Credenciales Incorrectas")
        return

    # api.delete_all_data() # Descomentar para vaciar neo4j
    # generate_data(api) # Descomentar para generar datos nuevos
    # load_data(api) # Descomentar para cargar los datos guardados en los JSONs
    
    print("===========================")
    print("       TEST QUERIES        ")
    print("===========================")

    print("------ QUERY 1 ------")
    q1 = api.familyNfriends(usr_id= 7)
    if q1 is not None:
        print(q1)
    else:
        print("Query No Devuelve Nada")

    print("------ QUERY 2 ------")
    q2 = api.familyOFfamilies(usr_id= 7)
    if q2 is not None:
        print(q2)
    else:
        print("Query No Devuelve Nada")

    print("------ QUERY 3 ------")
    q3 = api.chatSendedSinceDate(sender_id= 7, receiver_id= 4, date= "2025-12-12")
    if not q3 or q3 is None:
        print("Query No Devuelve Nada")
    else:
        print(q3)

    print("------ QUERY 4 ------")
    q4 = api.getChatHistory(sender_id= 4, receiver_id= 8)
    if not q4 or q4 is None:
        print("Query No Devuelve Nada")
    else:
        print(q4)

    print("------ QUERY 5 ------")
    q5 = api.getUserMentioned(usr_id= 0)
    if not q5 or q5 is None:
        print("Query No Devuelve Nada")
    else:
        print(q5)

    print("------ QUERY 6 ------") 
    q6 = api.unRelatedUsers(usr_id= 0, saltos= 2)
    if not q6 or q6 is None:
        print("Query No Devuelve Nada")
    else:
        for data in q6:
            print(data)

    print("------ QUERY 7 ------")
    q7 = api.getUnRelatedUsersMessages(usr_id= 0, num_msg= 1)
    if not q7 or q7 is None:
        print("Query No Devuelve Nada")
    else:
        for data in q7:
            print(data)

    print("===========================")
    print("     FIN TEST QUERIES      ")
    print("===========================")

    # dump_data(api) #Descomentar para actualizar los archivos JSON

    api.close()

if __name__ in "__main__":
    main()
