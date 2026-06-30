import LoginManager as lm

def main():
    print("=== INICIO DE TESTS ===")

    # Limpiar DB de sesiones antes del test
    lm.sessions.flushdb()

    # -------------------------------
    # 1. Registrar usuario
    # -------------------------------
    user1 = {
        "full_name": "Diego Jaime Vega Sanchez",
        "username": "djaime3",
        "password": "djvs123"
    }

    print("\n-- Registrando usuario djaime3 --")
    lm.register_user(user1)

    # Intentar registrarlo otra vez → ERROR esperado
    print("\n-- Intentando registrar djaime3 de nuevo --")
    lm.register_user(user1)

    # -------------------------------
    # 2. Login usuario
    # -------------------------------
    print("\n-- Login djaime3 --")
    try:
        privileges,token = lm.login_user(user1)
        print(f"Privilegios: {privileges}, Token: {token}")
    except TypeError:
        print("ERROR: No se pudo iniciar sesion")
   

    # Login con usuario inexistente → ERROR
    print("\n-- Login usuario inexistente bob --")
    fake_user = {
        "full_name": "Bobby",
        "username": "bob",
        "password": "1233"
    }
    try:
        p1,t1 = lm.login_user(fake_user)
    except TypeError:
        print("ERROR: No se pudo iniciar sesion")

    # -------------------------------
    # 3. Login mediante token
    # -------------------------------
    print("\n-- Login mediante token correcto --")
    try:
        p2,t2 = lm.login_token(token)
        print(f"Privilegios: {p2}, Token: {t2}")
    except TypeError:
        print("ERROR: No se pudo iniciar sesion")
    

    # Login con token inválido
    print("\n-- Login mediante token inválido --")
    try:
        p2,t2 = lm.login_token("-1")
    except TypeError:
        print("ERROR: No se pudo iniciar sesion")

    # -------------------------------
    # 4. Actualizar usuario
    # -------------------------------
    print("\n-- Actualizando datos de djaime3 --")
    updated_user = lm.get_user("djaime3")
    updated_user['password'] = "diev653"

    update_result = lm.update_user("djaime3", updated_user)
    print(f"Resultado actualización: {update_result}")

    # Intentar cambiar el token → ERROR
    print("\n-- Intentar modificar token: ERROR esperado --")
    invalid_update = updated_user.copy()
    invalid_update["token"] = 123456
    lm.update_user("djaime3", invalid_update)

    # Intentar cambiar el username a uno ya existente
    print("\n-- Crear usuario vpeiro4 para test --")
    user2 = {
        "full_name": "Victor Manuel Peiro Martinez",
        "username": "vpeiro4",
        "password": "peirooooo15"
    }
    lm.register_user(user2)
    try:
        p3,t3 = lm.login_user(user2)
    except TypeError:
        print("ERROR: No se pudo iniciar sesion")

    print("\n-- Intentar renombrar djaime3 → vpeiro4 (ERROR esperado) --")
    conflicting_update = updated_user.copy()
    conflicting_update["username"] = "vpeiro4"
    lm.update_user("djaime3", conflicting_update)

    #Comprobaciones cambio de usuario
    print("\n-- Cambio el nombre de usuario de vpeiro4 a vpeiro1")
    changed_username_user = lm.get_user("vpeiro4")
    changed_username_user['username'] = "vpeiro1"
    lm.update_user("vpeiro4",changed_username_user)

    print("\n-- Hago login de vpeiro1 mediante su token (MISMO token que vpeiro4) --")
    try:
        p4,t4 = lm.login_token(changed_username_user['token'])
        print(f"Privilegios: {p4}, Token: {t4}")
    except TypeError:
        print("ERROR: No se pudo iniciar sesion")

    # -------------------------------
    # 5. Borrar usuario
    # -------------------------------
    print("\n-- Eliminando djaime3 --")
    delete_result = lm.delete_user("djaime3")
    print(f"Resultado borrado: {delete_result}")

    # Borrarlo otra vez → ERROR
    print("\n-- Eliminando djaime3 de nuevo (ERROR esperado) --")
    lm.delete_user("djaime3")

    #Comprobacion de Borrado de token
    print("\n-- Intentar login a usuario eliminado por token (ERROR esperado) --")
    try:
        p4,t4 = lm.login_token(token)
    except TypeError:
        print("ERROR: No se pudo iniciar sesion")

    print("\n=== FIN DE TESTS ===")

# EXECUTAR MAIN
if __name__ == "__main__":
    main()


