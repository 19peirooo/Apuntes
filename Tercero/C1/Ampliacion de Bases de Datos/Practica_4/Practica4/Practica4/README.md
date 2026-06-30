# Proyecto Neo4j – Red Social Académica/Laboral

Este proyecto implementa una **red social** utilizando **Neo4j** como base de datos de grafos y **Python** como lenguaje de acceso mediante el driver oficial `neo4j`.

Se modelan usuarios, mensajes, publicaciones, empresas y centros educativos, junto con relaciones sociales, laborales, académicas y de comunicación. Además, se incluyen **consultas avanzadas sobre grafos**, generación de datos de prueba y mecanismos de persistencia (dump/load).

---

## 📌 Tecnologías utilizadas

- **Python 3.10+**
- **Neo4j 5.x**
- Driver oficial `neo4j` para Python
- Base de datos orientada a grafos

---

## 📂 Estructura del proyecto

```
.
├── neo4jManager.py      # API principal de acceso a Neo4j
├── generate_data.py     # Generación, dump y carga de datos
├── main.py              # Script principal de ejecución y pruebas
├── dumps/               # Directorio de volcado de datos (JSON)
└── README.md
```

---

## 🧠 Modelo de datos

### 🔹 Nodos

| Tipo | Descripción |
|----|----|
| `Persona` | Usuario del sistema |
| `Mensaje` | Mensaje privado entre usuarios |
| `Publicacion` | Publicación creada por un usuario |
| `Empresa` | Empresa |
| `CentroEducativo` | Centro educativo |

---

### 🔹 Relaciones

| Relación | Origen → Destino | Descripción |
|--------|------------------|------------|
| `FRIEND` | Persona → Persona | Amistad |
| `FAMILY` | Persona → Persona | Relación familiar |
| `WORKS_AT` | Persona → Empresa | Relación laboral |
| `STUDIED_AT` | Persona → CentroEducativo | Relación académica |
| `POSTED` | Persona → Publicacion | Publicación creada |
| `MENTIONS` | Publicacion → Persona | Usuario mencionado |
| `SENT` | Persona → Mensaje | Mensaje enviado |
| `RECEIVED` | Mensaje → Persona | Mensaje recibido |

---

## ⚙️ Instalación y configuración

1. Instalar dependencias:
```bash
pip install neo4j
```

2. Asegurarse de que **Neo4j esté ejecutándose** en:
```
bolt://localhost:7687
```

3. Configurar credenciales en `main.py`:
```python
HOST = "bolt://localhost:7687"
USER = "neo4j"
PASSWORD = "12345678"
```

Nota: La contraseña ha de ser tu contraseña en neo4j. Lo mismo con el usuario

---

## 🚀 Uso básico

### ▶️ Ejecutar el proyecto

```bash
python3 main.py
```

Nota: Recuerda activar el entorno de python
```bash
conda activate nombre_entorno
```

Desde `main.py` se pueden:
- Generar datos de prueba
- Ejecutar consultas
- Dumpear y cargar datos

Nota: Asegurate de que haya datos en Neo4j. Usar funcion load_data o generate_data para subir datos o generar datos nuevos

---

## 🧪 Generación de datos de prueba

En `generate_data.py`:

```python
generate_data(api)
```

Se generan automáticamente:
- 10 usuarios
- Empresas y centros educativos
- Relaciones sociales, laborales y académicas
- Mensajes con conversaciones
- Publicaciones con menciones

Las fechas se generan aleatoriamente en los últimos 10 años.

---

## 💾 Persistencia de datos

### Dump (exportar a JSON)
```python
dump_data(api)
```

Genera archivos JSON en el directorio `dumps/` para:
- Todos los tipos de nodos
- Todos los tipos de relaciones

---

### Load (importar desde JSON)
```python
load_data(api)
```

Reconstruye el grafo completo usando `MERGE` para evitar duplicados.

---

## 🔍 Consultas implementadas
Las consultas han sido implementadas como metodos de la clase Neo4jManager

### 1️⃣ Familiares y amigos de un usuario
```python
familyNfriends(usr_id)
```

---

### 2️⃣ Familiares de familiares
```python
familyOFfamilies(usr_id)
```

---

### 3️⃣ Mensajes enviados desde una fecha
```python
chatSendedSinceDate(sender_id, receiver_id, date)
```

---

### 4️⃣ Historial completo de chat
```python
getChatHistory(sender_id, receiver_id)
```

---

### 5️⃣ Usuarios mencionados que trabajan con el autor
```python
getUserMentioned(usr_id)
```

---

### 6️⃣ Usuarios no relacionados directamente (por saltos)
```python
unRelatedUsers(usr_id, saltos)
```

---

### 7️⃣ Usuarios no relacionados con intercambio de mensajes
```python
getUnRelatedUsersMessages(usr_id, num_msg)
```

---

## 🧩 Consideraciones técnicas

- Se utiliza `MERGE` en nodos y relaciones para evitar duplicados.
- Las fechas se almacenan como `string` para facilitar serialización JSON.
- Las relaciones sociales (`FRIEND`, `FAMILY`) son bidireccionales.
- El sistema es extensible a nuevos tipos de nodos y relaciones.

---

## 📌 Autor

Diego Jaime Vega Sánchez y Víctor Manuel Peiró Martínez
