# 4. Analisis JSON

Status: Not started
🪴 Units: 4. Listas (../Unidades/4%20Listas%20ff4eeadeed7082ad941d016823ffc6d8.md)

Una de las tareas más recurrentes cuando estamos trabajando con listas, es la de carga de datos que vienen de una base de datos externa. Esta base de datos, lo normal es que esté enlazada con un servidor web que actue como intermediario entre el cliente (en este caso el móvil) y la base de datos, utilizando un esquema conocido como arquitectura de 3 capas. 

Dentro de Android, el analisis de este tipo de accesos se puede realizar mediante librerías como Volley o Retrofil. Estas librerías, permiten el manezo de las peticiones HTTP hacia el servidor, manejando la respuesta y el orden de ejecución lo más eficientemente posible. 

Para poder utilizarlo, lo primero es implementar la dependencia de la libreriía seleccionada. En este ejemplo se utilizará volley como libreria de conexión. Para poder utilizarla, la implementación de esta se lleva a cabo en el fichero build.grade (module) en el nodo de las dependencias;

```java
dependencies {
    **implementation**("com.android.volley:volley:1.2.1")
}
```

Además de la implementación de la dependencia, es necesario indicar que la aplicación tenga acceso a internet, por lo cual dentro del fichero manifest.xml se configurará un nodo con los permisos solicitados:

```java
    <uses-permission android:name="android.permission.INTERNET"/>
```

Con todo esto, la app está preparada para realizar una petición JSON a través de HTTP. 

Cuando trabjamos con Volley, lo primero que hay que tener en cuenta es el tipo de contestación que se obtiene mediante la url, viendo esta en el archivo de respuesta. 

> En el caso de que la contestación comience con { estaríamos hablando de una respuesta de tipo JSONObject. En el caso de que la contestacion comience con [ estaríamos hablando de una respuesta de tipo JSONArray
> 

Dependiendo de cual sea la respuesta, crearemos un objeto de tipo JSONObjectRequest o JSONObjectArray. La constrccion de ámbos objetos es la misma, tenieendo como parámetros en la forma simple los siguientes:

- URL de consulta
- Response.Listener: con la contestación de la petición, siendo el tipo diferente para cada contestacion (JSONObject o JSONArray)
- Error.Listener: con el error en el caso de que la contestación sea erronea

Para pode crear un objeto de este tipo sería el siguiente código

```java
val peticion: JsonObjectRequest = JsonObjectRequest(urlConsulta,
            {
                val results = it.getJSONArray("results")
                for (i in 0..results.length() - 1) {
                    val question = results.getJSONObject(i)
                }
            },
            {
                Log.v("preguntas",it.toString())
            })
```

En este ejemplo tendríamos una repuesta de un json con una estructura donde encontramos un tag “results” la cual tiene un array asociado, diendo este recorrido para sacar todos los datos que están dentro. Una vez obtenido cada uno de los objetos del array, podríamos acceder a los elemento del objeto, preguntado por cada una de las keys

```java
                val results = it.getJSONArray("results")
                for (i in 0..results.length() - 1) {
                    val question = results.getJSONObject(i)
                    val pregunta: Pregunta = gson.fromJson(question.toString(),Pregunta::class.java)
                    adapterTrivial.agregarPregunta(pregunta)
                    val title= question.getString("question")
                    val correct= question.getString("correct_answer")
                    val incorrects= question.getJSONArray("incorrect_answers")
                    Log.v("preguntas",pregunta.question!!)
                }
```

Si además de esta opción, queremos contemplar un mapeo directo de cada una de las características del objeto, podríamos utilizar la librería GSON. Para ello utilizaríamos el siguiente código

```java
val urlConsulta = "https://opentdb.com/api.php?amount=20"
        val gson: Gson = Gson()
        val peticion: JsonObjectRequest = JsonObjectRequest(urlConsulta,
            {
                val results = it.getJSONArray("results")
                for (i in 0..results.length() - 1) {
                    val question = results.getJSONObject(i)
                    val pregunta: Pregunta = gson.fromJson(question.toString(),Pregunta::class.java)
                }
            },
            {
                Log.v("preguntas",it.toString())
            })
```

> Hay que tener en cuenta que para poder utlizar la librería GSON y que el mapeo se lleve a cabo de forma correcta, es necesario contar con una clase que tenga tantas características como se quieran obtener (con el mismo nombre que está configurado en el API) y un constructor vacío
> 

> Además de los requisitos anteriores, es necesario implementar la dependecia de la librería utilizando el siguiente código implementation("com.google.code.gson:gson:2.11.0")
>