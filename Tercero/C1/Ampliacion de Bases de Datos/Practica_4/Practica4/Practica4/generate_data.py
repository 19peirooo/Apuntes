from datetime import date, timedelta
import random
from neo4jManager import NodeType,RelationshipType

def random_date_last_10_years():
    today = date.today()
    days_back = random.randint(0, 10 * 365)
    return today - timedelta(days=days_back)


def generate_data(manager):

    users = []
    empresas = []
    ces = []

    # ------ NODOS ------
    for i in range(10):
        # ------ PERSONAS ------
        user_data = {
            "id": i,
            "name": f"u{i}",
            "edad": random.randint(14,80)
        }
        users.append(user_data)
        manager.create_node(NodeType.PERSONA.value, user_data)

        # ------ EMPRESA ------
        empresa_data = {
            "id": i,
            "name": f"e{i}",
            "numEmpleados": random.randint(1,1000)
        }
        empresas.append(empresa_data)
        manager.create_node(NodeType.EMPRESA.value, empresa_data)

        # ------ CENTRO EDUCATIVO ------
        ce_data = {
            "id": i,
            "name": f"ce{i}",
            "numAlumnos": random.randint(100,500)
        }
        ces.append(ce_data)
        manager.create_node(NodeType.CENTRO_EDUCATIVO.value, ce_data)
    
    # ------ RELACIONES ENTRE PERSONAS ------
    for _ in range(15):
        u1, u2 = random.sample(users, 2)
        rel_type = random.choice([RelationshipType.FRIEND.value, RelationshipType.FAMILY.value])
        manager.create_relationship(
            NodeType.PERSONA.value, u1["id"],
            NodeType.PERSONA.value, u2["id"],
            rel_type
        )

        manager.create_relationship(
            NodeType.PERSONA.value, u2["id"],
            NodeType.PERSONA.value, u1["id"],
            rel_type
        )

    # ------ RELACIONES LABORALES ------
    for u in users:
        empresa = random.choice(empresas)
        manager.create_relationship(
            NodeType.PERSONA.value, u["id"],
            NodeType.EMPRESA.value, empresa["id"],
            RelationshipType.WORKS_AT.value,
            {"desde": random.randint(2015, 2025)}
        )
    
    # ------ RELACIONES ACADEMICAS ------
    for u in users:
        ce = random.choice(ces)
        manager.create_relationship(
            NodeType.PERSONA.value, u["id"],
            NodeType.CENTRO_EDUCATIVO.value, ce["id"],
            RelationshipType.STUDIED_AT.value
        )

    # ---------- MENSAJES ----------
    conv_id = 0
    msg_id = 0

    for _ in range(50):
        sender, receiver = random.sample(users, 2)

        manager.send_msg(
            id_sender=sender["id"],
            id_received=receiver["id"],
            msg_id=msg_id,
            conv_id=conv_id,
            seq_num=msg_id % 5,
            msg=f"Mensaje {msg_id}",
        )

        msg_id += 1
        if msg_id % 5 == 0:
            conv_id += 1

    # ---------- PUBLICACIONES ----------
    pub_id = 0

    for u in users:
        mencionados = random.sample(users, random.randint(0, 5))
        mencionados_ids = [m["id"] for m in mencionados if m["id"] != u["id"]]

        manager.publish_post(
            post_id=pub_id,
            title=f"Publicación {pub_id}",
            body="Texto de la publicación",
            fecha=str(random_date_last_10_years()),
            autor=u["id"],
            usuarios_mencionados=mencionados_ids
        )

        pub_id += 1

def dump_data(api):
    
    for node_type in NodeType:
        api.dump_nodes(node_type.value)

    for rel_type in RelationshipType:
        api.dump_relationship(rel_type.value)

def load_data(api):
    
    for node_type in NodeType:
        api.load_nodes(node_type.value)

    for rel_type in RelationshipType:
        api.load_relationship(rel_type.value)
