# 📘 Proyecto P3 -- Cache, Sesiones y HelpDesk (Redis + MongoDB)

Este proyecto implementa la tercera fase del desarrollo de la red
social, incorporando:

-   **Cache con Redis (db=0)**
-   **Gestión de sesiones con Redis (db=1 y db=2)**
-   **Sistema de HelpDesk basado en prioridades**


# 1️⃣ Cache (Redis -- db=0)

El sistema implementa un mecanismo de cache para documentos MongoDB,
cumpliendo con los requisitos de la práctica.

### ✔ Características principales

-   Cachea cualquier documento recuperado mediante `find_by_id()`.
-   Las entradas de cache duran **24 horas (TTL 24h)**.
-   Cada acceso renueva automáticamente el TTL.
-   Se configura Redis para que tenga un límite máximo de **150MB**
    usando:
    -   `maxmemory 150mb`
    -   `maxmemory-policy allkeys-lru`

### ✔ Funciones relacionadas

-   `find_by_id()`
-   `save()`
-   `delete()`
-   `init_class()`

### Fichero de Pruebas
`ODM_main.py`

# 2️⃣ Sesiones (Redis -- db=1)

La gestión de sesiones y usuarios se hace en **LoginManager.py**,
almacenando:

-   Nombre completo
-   Nombre de usuario
-   Contraseña
-   Privilegios
-   Token de sesión

### ✔ Funciones implementadas

-   `register_user()`
-   `login_user()`
-   `login_token()`
-   `update_user()`
-   `delete_user()`
-   `get_user()`
-   `existe_usuario()`

### Fichero de Pruebas
`LoginManager_tests_sessions.py`

# 3️⃣ HelpDesk (Redis -- db=2)

Sistema de prioridad basado en Sorted Sets.

### ✔ Funciones

-   `priorityHelp(usrId, priorityValue)`
-   `handleUsr()`


### Fichero de Pruebas
`LoginManager_tests_helpdesk.py`


# 👥 Autores

**Diego Jaime Vega Sánchez**\
**Víctor Manuel Peiró Martínez**
