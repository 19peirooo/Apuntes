import redis
import json
import random

sessions = redis.Redis(
    host="localhost",
    port=6379,
    db=1,
    decode_responses=True #Para que devuelve cadenas y no bytes
)

helpDesk = redis.Redis(
    host="localhost",
    port=6379,
    db=2,
    decode_responses=True #Para que devuelve cadenas y no bytes
)

TTL = 30*24*60*60 #30 dias
TIMEOUT = 60 # 1 min

def get_user(username):
    return sessions.hgetall(username)

def existe_usuario(username):
    return sessions.exists(username) == 1


def register_user(user):

    if "full_name" not in user or "username" not in user or "password" not in user:
        print("ERROR: Faltan datos para poder registrar al usuario")
        return -1

    #Comprobar si existe
    username = user['username']

    #Si existe --> -1
    if existe_usuario(username):
        print("ERROR: No se puede registrar usuario ya registrado")
        return -1
    
    privileges= random.randint(0,777)
    user['privileges'] = str(privileges)
    user['token'] = ""

    #Si no existe
    sessions.hset(username,mapping=user)
    return 1

def login_user(user):
    #Comprobar si existe
    username = user['username']
    password = user['password']
    #Si no existe --> -1
    if not existe_usuario(username):
        print("ERROR: Usuario no encontrado")
        return -1
    
    stored_user = get_user(username)

    if password != stored_user['password']:
        print("ERROR: Contraseña incorrecta")
        return -1
    
    token = stored_user.get("token")

    if token:
        sessions_token = token
    else:
        sessions_token = str(random.randint(1,10**9))
        sessions.hset(username,"token", sessions_token)
        sessions.set(sessions_token,username)
    
    sessions.expire(sessions_token,TTL)
    privileges = stored_user['privileges']
    return privileges,sessions_token

def login_token(token):
    if not token:
        print("ERROR: Usuario no tiene token asignado")
        return -1

    username = sessions.get(token)
    if username is None:
        print("ERROR: Token no encontrado")
        return -1

    if not existe_usuario(username):
        print("ERROR: Usuario no encontrado")
        return -1
    
    user = get_user(username)
    sessions.expire(token,TTL)
    return user['privileges'],user['token']
    

def update_user(username,updated_user):
    #Comprueba si existe el usuario
    #Si existe
    if existe_usuario(username):
        #Consigo datos del usuario y verifico si hay datos
        old_user = get_user(username)

        if not old_user:
            print("ERROR: Usuario no encotrado")
            return -1
        
        old_username = old_user['username']
        new_username = updated_user['username']
        token = old_user['token']

        #Comprueba si el usuario puede modificar el token --> ERROR si lo intenta
        if token != updated_user['token']:
            print("ERROR: No se puede modificar el token")
            return -1

        #Si cambia el usuario --> Hay que asegurarse que su token se redirija al nuevo nombre
        if old_username != new_username:
            #Comprobar que el nuevo usuario no exista ya en BBDD
            if existe_usuario(new_username):
                print("ERROR: No se pudo actualizar usuario")
                return -1 
            
            if token:
                sessions.set(token,new_username) #Asigno el token al nuevo nombre
                sessions.expire(token,TTL)
                
            sessions.delete(old_username) #Elimino los datos anteriores
            sessions.hset(new_username, mapping=updated_user) #Los reemplazo por los nuevos

            return 1
        
        sessions.hset(old_username, mapping=updated_user) 
        return 1
    
    #Si no existe --> ERROR
    print("ERROR: Usuario no encontrado")
    return -1

def delete_user(username):
    if existe_usuario(username):
        user = get_user(username)
        token = user.get("token","")
        if token:
            sessions.delete(token)
        sessions.delete(username)
        return 1
    print("ERROR: Usuario no encontrado")
    return -1

def priorityHelp(usrId, priorityValue):

    #insertar en la BBDD nombre y prioridad asociadas.
    helpDesk.zadd("priority_set", {usrId:priorityValue})

def handleUsr():

    usr = helpDesk.bzpopmax(["priority_set"], timeout = TIMEOUT)
    return usr[1]

