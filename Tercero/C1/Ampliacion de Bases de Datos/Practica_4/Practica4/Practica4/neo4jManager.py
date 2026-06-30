import neo4j
import json
import os
from enum import Enum
from datetime import date

class NodeType(Enum):
    PERSONA = "Persona"
    MENSAJE = "Mensaje"
    PUBLICACION = "Publicacion"
    EMPRESA = "Empresa"
    CENTRO_EDUCATIVO = "CentroEducativo"

class RelationshipType(Enum):
    FAMILY = "FAMILY"
    FRIEND = "FRIEND"
    STUDIED_AT = "STUDIED_AT"
    WORKS_AT = "WORKS_AT"
    SENT = "SENT"
    RECEIVED = "RECEIVED"
    POSTED = "POSTED"
    MENTIONS = "MENTIONS"

class Neo4jManager:

    def __init__(self,uri, user, password):
        self.driver = neo4j.GraphDatabase.driver(uri, auth=(user,password))
    
    def close(self):
        self.driver.close()

    def create_node(self, node_type, node_data):
        query = f"MERGE (n:{node_type} {{id:$id}}) SET n += $props"
        
        with self.driver.session() as session:
            res = session.run(query,id=node_data["id"], props=node_data)
            summ = res.consume()

            if summ.counters.nodes_created == 1:
                print(f"Se creo nodo de tipo {node_type}")
            else:
                print("Nodo Actualizado") 

    def create_relationship(self, label1, key1, label2, key2, relationship_type, relationship_data=None):
        query= f"""
                MATCH (a:{label1} {{id: $id1}}),
                (b:{label2} {{id:$id2}})
                MERGE (a)-[r:{relationship_type}]->(b)
                SET r += $props
                """
        with self.driver.session() as session:
            res = session.run(query, id1=key1,id2=key2,props=relationship_data or {})
            summ = res.consume()

            if summ.counters.relationships_created == 1:
                print(f"Se creo la relacion {relationship_type} entre {label1} {key1} y {label2} {key2}")
            else:
                print("Relacion Actualizada")
    
    def send_msg(self, id_sender, id_received, msg_id, conv_id, seq_num, msg, fecha=None):

        if fecha is None:
            fecha = str(date.today())

        query = """
                MATCH (a:Persona {id:$sender}), (b:Persona {id:$receiver})
                CREATE (a)-[:SENT]->(m:Mensaje {id: $msg_id, conv: $conv_id, seq: $seq_number, texto: $text, fecha:$fecha})-[:RECEIVED]->(b)
                """
        
        with self.driver.session() as session:
            session.run(query, sender=id_sender, receiver=id_received, 
                        msg_id=msg_id, conv_id=conv_id, seq_number=seq_num, text=msg, fecha=fecha)
    
    def publish_post(self,post_id,title,body,fecha,autor, usuarios_mencionados=None):

        if fecha is None:
            fecha = str(date.today())

        if usuarios_mencionados is None:
            usuarios_mencionados=[]

        post_data = {
            "id": post_id,
            "titulo":title,
            "cuerpo": body,
            "fecha": fecha,
        }

        self.create_node(NodeType.PUBLICACION.value,post_data)
        self.create_relationship(NodeType.PERSONA.value,autor,NodeType.PUBLICACION.value,post_id,
                                 RelationshipType.POSTED.value)
        
        for usuario in usuarios_mencionados:
            self.create_relationship(NodeType.PUBLICACION.value,post_id,NodeType.PERSONA.value,usuario,
                                     RelationshipType.MENTIONS.value)
        

    
    def delete_all_data(self):
        with self.driver.session() as session:
            session.run("MATCH (n) DETACH DELETE n")
        print("Neo4j vaciado")

    def get_node_labels_by_id(self, node_id):
        with self.driver.session() as session:
            res = session.run(
                "MATCH (n {id:$id}) RETURN labels(n) as labels", 
                id=node_id
            )
            record = res.single()
            if record:
                return record["labels"][0]
            else:
                return []
    
    # CONSULTAS USUARIO
    def familyNfriends(self, usr_id):
        print("FAMILY N FRIENDS")
        usuario =  NodeType.PERSONA.value
        familiar = RelationshipType.FAMILY.value
        amistad = RelationshipType.FRIEND.value

        query = f"""
        MATCH (n:{usuario} {{id:$usr_id}})
        OPTIONAL MATCH (n)-[:{amistad}]->(u:{usuario})
        OPTIONAL MATCH (n)-[:{familiar}]->(f:{usuario})
        RETURN
            n.name AS nombre,
            collect(DISTINCT u.name) AS amigos,
            collect(DISTINCT f.name) AS familiares
        """

        with self.driver.session() as session:
            res = session.run(query, usr_id=usr_id)
            return res.single()
        
    def familyOFfamilies(self, usr_id):
        print("FAMILY OF FAMILIES")
        usuario =  NodeType.PERSONA.value
        familiar = RelationshipType.FAMILY.value

        query = f"""
        MATCH (n:{usuario} {{id:$usr_id}})
        OPTIONAL MATCH (n)-[:{familiar}]->(f:{usuario})
        OPTIONAL MATCH (f)-[:{familiar}]->(ff:{usuario})
        WHERE ff IS NULL OR ff.id <> n.id
        RETURN
            n.name AS nombre,
            collect(DISTINCT f.name) AS familiares,
            collect(DISTINCT ff.name) AS familiares_de_familiares
        """
        with self.driver.session() as session:
            res = session.run(query, usr_id=usr_id)
            return res.single()
    
    # CONSULTAS MENSAJES
    def chatSendedSinceDate(self, sender_id, receiver_id, date):
        print("CHAT SENDED SINCE DATE")
        usuario =  NodeType.PERSONA.value
        mensaje = NodeType.MENSAJE.value
        sent = RelationshipType.SENT.value
        received = RelationshipType.RECEIVED.value

        query = f"""
            MATCH (n:{usuario} {{id:$sender_id}})-[:{sent}]->(msg:{mensaje})-[:{received}]->(u:{usuario} {{id:$receiver_id}})
            WHERE msg.fecha >= $date
            RETURN n.name AS remitente, msg.texto AS mensaje
            ORDER BY msg.fecha ASC
            """
        with self.driver.session() as session:
            res = session.run(query, sender_id=sender_id, receiver_id=receiver_id, date=date)
            return res.data()
    
    def getChatHistory(self, sender_id, receiver_id):
        print("GET CHAT HISTORY")
        usuario =  NodeType.PERSONA.value
        mensaje = NodeType.MENSAJE.value
        sent = RelationshipType.SENT.value
        received = RelationshipType.RECEIVED.value
        
        query = f"""
                MATCH (n:{usuario})-[:{sent}]->(msg:{mensaje})-[:{received}]->(u:{usuario})
                WHERE (n.id = $sender_id AND u.id = $receiver_id)
                OR (n.id = $receiver_id AND u.id = $sender_id)
                RETURN CASE WHEN n.id = $sender_id THEN n.name ELSE u.name END AS remitente, msg.texto AS mensaje, msg.fecha AS fecha
                ORDER BY fecha ASC
                """
       
        with self.driver.session() as session:
            res = session.run(query, sender_id=sender_id, receiver_id=receiver_id)
            return res.data()
    
    # CONSULTAS PUBLICACIÓN
    def getUserMentioned(self, usr_id):
        print("GET USER MENTIONED")
        usuario =  NodeType.PERSONA.value
        publicacion = NodeType.PUBLICACION.value
        empresa = NodeType.EMPRESA.value
        mencionado = RelationshipType.MENTIONS.value
        publicado = RelationshipType.POSTED.value
        laboral = RelationshipType.WORKS_AT.value
        
        query = f"""
                MATCH (n:{usuario} {{id:$usr_id}})-[:{publicado}]->(post:{publicacion})-[:{mencionado}]->(u:{usuario})
                MATCH (n)-[:{laboral}]->(e:{empresa})<-[:{laboral}]-(u)
                RETURN n.name AS posted_by, post.titulo AS post, collect(u.name) AS mentioned
                """
        
        with self.driver.session() as session:
            res = session.run(query, usr_id=usr_id)
            return res.data()
    
    # CONSULTAS POR SALTOS
    def unRelatedUsers(self, usr_id, saltos):
        print("UNRELATED USERS")
        usuario = NodeType.PERSONA.value
        if saltos < 1:
            return "ERROR: the number of jumps has to be greater than 0"
        query = f"""
                MATCH (n:Persona {{id: $usr_id}})-->(j:Persona)
                MATCH path = (j)-[*1..{saltos}]->(u:Persona)
                WHERE u <> n
                AND NOT (n)-->(u)
                RETURN j.name AS segundo, u.name AS tercero, length(path) AS saltos
                ORDER BY saltos ASC
            """

        with self.driver.session() as session:
            res = session.run(query, usr_id=usr_id)
            return res.data()
    
    def getUnRelatedUsersMessages(self, usr_id, num_msg):
        print("GET UNRELATED USERS MESSAGES")
        usuario =  NodeType.PERSONA.value
        mensaje = NodeType.MENSAJE.value
        sent = RelationshipType.SENT.value
        received = RelationshipType.RECEIVED.value

        query = f"""
            MATCH (n:{usuario} {{id: $usr_id}})-->(j:{usuario})

            CALL (n, j) {{
                MATCH (n)-[:{sent}]->(m1:{mensaje})-[:{received}]->(j)
                RETURN count(m1) AS count1
            }}

            CALL (n, j) {{
                MATCH (j)-[:{sent}]->(m2:{mensaje})-[:{received}]->(n)
                RETURN count(m2) AS count2
            }}

            WITH n, j, count1 + count2 AS msg_nj
            WHERE msg_nj > $num_msg

            MATCH (j)-->(u:{usuario})
            WHERE u <> n AND NOT (n)-->(u)

            CALL (j, u) {{
                MATCH (j)-[:{sent}]->(m3:{mensaje})-[:{received}]->(u)
                RETURN count(m3) AS count3
            }}

            CALL (j, u) {{
                MATCH (u)-[:{sent}]->(m4:{mensaje})-[:{received}]->(j)
                RETURN count(m4) AS count4
            }}

            WITH j, u, msg_nj, count3 + count4 AS msg_ju
            WHERE msg_ju > $num_msg

            RETURN j.name AS secundarios, u.name AS terciarios, msg_nj AS mensajes_primario_secundario, msg_ju AS mensajes_secundario_terciario
            
            ORDER BY mensajes_primario_secundario ASC, mensajes_secundario_terciario ASC
            """
        
        with self.driver.session() as session:
            res = session.run(query, usr_id=usr_id, num_msg=num_msg)
            return res.data()

    def dump_nodes(self, node_type):

        os.makedirs("dumps", exist_ok=True)

        with self.driver.session() as session: 
            res = session.run(f"MATCH (n:{node_type}) RETURN count(n) as c")
            num_nodes = res.single()["c"]

            if num_nodes == 0:
                print(f"No hay nodos de tipo {node_type} para dumpear")
                return 
            
            query = f"MATCH (n:{node_type}) RETURN n.id as id, properties(n) as props"

            res = session.run(query)
            node_list = [node.data() for node in res]

            with open(f"dumps/node_{node_type}.json","w") as f:
                json.dump(node_list,f,indent=2)

        print(f"Nodo {node_type} dumpeado")        
    
    def dump_relationship(self, relationship_type):

        os.makedirs("dumps", exist_ok=True)

        with self.driver.session() as session: 
            res = session.run(f"MATCH ()-[r:{relationship_type}]->() RETURN count(r) as c")
            num_rels = res.single()["c"]

            if num_rels == 0:
                print(f"ERROR: No se pudo dumpear relaciones de tipo {relationship_type}. Relacion no existe")
                return 
            
            query = f"""MATCH (a)-[r:{relationship_type}]->(b) 
                        RETURN a.id as start, b.id as end,
                        labels(a) as start_labels,labels(b) as end_labels,
                        properties(r) as props
                    """
            
            res = session.run(query)
            rels_list = [rel.data() for rel in res]

            with open(f"dumps/relationship_{relationship_type}.json","w") as f:
                json.dump(rels_list,f,indent=2)

        print(f"Relacion {relationship_type} dumpeada")
    
    def load_nodes(self, node_type):
        
        file_path = f"dumps/node_{node_type}.json"

        if not os.path.exists(file_path):
            print(f"ERROR: No existe el archivo {file_path}")
            return

        with open(file_path, "r") as f:
            node_list = json.load(f)

        for node in node_list:
            props = node["props"]
            self.create_node(node_type, props)

        print(f"Nodos de tipo {node_type} cargados correctamente.")                


    def load_relationship(self, relationship_type):
        file_path = f"dumps/relationship_{relationship_type}.json"

        if not os.path.exists(file_path):
            print(f"ERROR: No existe el archivo {file_path}")
            return

        with open(file_path, "r") as f:
            rel_list = json.load(f)

        for rel in rel_list:
            start_id = rel["start"]
            start_labels = rel["start_labels"]
            end_id = rel["end"]
            end_labels = rel["end_labels"]
            props = rel["props"]

            # Usamos create_relationship con los labels y props
            self.create_relationship(
                label1=start_labels[0],
                key1=start_id,
                label2=end_labels[0],
                key2=end_id,
                relationship_type=relationship_type,
                relationship_data=props
            )

        print(f"Relaciones de tipo {relationship_type} cargadas correctamente.")