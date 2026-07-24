# 2. Operaciones con base de datos y Room

Status: Not started
🪴 Units: 7. Base datos (../Unidades/7%20Base%20datos%20343eeadeed7082648c4f817840eb78e6.md)

Con todos los pasos anteriores, el sistema está preparado para crear la base de datos y realizar acciones sobre ella. Es importante antes de continuar tener muy claro que la base de datos aún no se ha creado, y que lo hará en el primer momento en el que se llame al método build que se va a explicar ahora.

Para poder crear la base de datos, se utiliza un método companion de la librería Room llamado databaseBuilder. Este método tienen como parámetros el contexto, la clase que representa la base de datos y el nombre de la misma. En el caso de no existir la crea en la ruta local, y en el caso de encontrarla no la crea, simplemente la captura para poder utilizarla. Por último se ejecuta el método build para crear la base de datos.

```java
val database = Room.databaseBuilder(applicationContext, UsuariosBD::class.java,"usuarios.db").build()

```

Con todo esto, la variable database tiene el acceso a todos los métodos del dato a partir de las funciones que se han declarado.

```java
database.usuarioDAO().insert(Usuario(1,"Borja", "Martin", "developandsys@gmail.com"))

```

Esta forma de creación es válida, sin embargo no es la mejor. Al tratarse de un objeto complejo (abrir una base de datos requiere de mucho procesamiento), es recomendable utilizar un patrón singleton, el cual indica que en las sucesivas veces que la base de datos sea llamada, no es necesaria su carga sino que tan solo recupera una variable donde ha sido guardada

```java
@Database (entities = [Usuario::class], version = 1, exportSchema = false)
abstract class UsuariosBD: RoomDatabase(){
    abstract fun usuarioDAO(): UsuarioDAO
    companion object DatabaseBuilder{
        private var INSTANCE : UsuariosBD ? = null
        fun getInstance (context: Context): UsuariosBD {
            if (INSTANCE == null) synchronized(Usuario::class) {
                INSTANCE = buildRoomDB(context)
            }
            return INSTANCE!!
        }

        private fun buildRoomDB (contexto : Context) =
            Room.databaseBuilder (
                contexto.applicationContext, UsuariosBD::class.java, "usuarios.db"
            ).build ()
    }

}

```

Como se puede ver, este patrón crea una variable de tipo de la base de datos. La función getInstance, en el caso de ser esta variable null la creará mediante la ejecución del método buildRoomDB, el cual ejecuta el método que habíamos utilizado hasta este momento. En el caso de ser diferente de null (porque ya se haya llamado en algún momento), se devolverá la propia variable. Una vez creado este patrón, para poder obtener una instancia de la base de datos basta con llamar al método getInstance(), el cual devolverá una instancia nueva de la BD o una ya existente

```java
val database = UsuariosBD.getInstance(applicationContext)

```

Este código está bien escrito, pero sin embargo aún no funciona. En android, y en especial en kotlin hay ejecuciones que no deben hacerse en cualquier sitio ya que de hacerse sin control pueden saturar el hilo principal de ejecución. Las bases de datos y sus consultas son un ejemplo típico de esto. Para poder hacer todo de forma asíncrona y que no afecte al hilo principal existe lo que se conoce como corrutinas, las cuales permiten crear ejecuciones paralelas de forma que no afectan al resto de acciones de la aplicación. Para poder ejecutar estas corrutinas es necesario ejecutar el siguiente código

```java
val database = Room.databaseBuilder(applicationContext, UsuariosBD::class.java,"usuarios.db").build()
GlobalScope.launch(Dispatchers.IO){
                database.usuarioDAO().insert(Usuario(1,"Borja", "Martin", "developandsys@gmail.com"))
}

```

### Operaciones sobre la base de datos.

Como se ha visto en el ejemplo anterior, realizar acciones sobre la base de datos es muy sencillo, ya que tan solo es necesario hacer una llamada al DAO correspondiente y al método que se quiera ejecutar (recordad que es ahí donde se han definido las querys). Dentro de las acciones quizá la más interesante es la de rellenar una lista o spinner sobre una consulta realizada.

### Rellenar lista

Antes de rellenar una lista, vamos a realizar la operación de consulta sobre la base de datos. Como se configuró en el DAO, el método getAll realiza la acción de SELECT *, obteniendo como resultado un conjunto de usuarios en nuestro caso

```java
    @Query("Select * from Usuario")
    fun selectAll(): List<Usuario>

```

Sabiendo esto, sería tan sencillo como llamar al método del DAO y recorrer la lista de resultados para poder mostrarlos (en este caso en un LOG)

```java
GlobalScope.launch(Dispatchers.IO){
            val database = UsuariosBD.getInstance(applicationContext)
            val lista = database.usuarioDAO().selectAll()
            lista.forEach {
                Log.v("usuario", "${it.id} ${it.nombre}")
            }
        }

```

Por lo tanto, si se quiere rellenar una lista con este resultado se podría hacer de la siguiente forma

```java
        GlobalScope.launch(Dispatchers.IO){
            val database = UsuariosBD.getInstance(applicationContext)
            val lista = database.usuarioDAO().selectAll()
            adapter = ArrayAdapter<Usuario>(applicationContext,android.R.layout.simple_list_item_1,lista)
            binding.listaUsaurios.adapter = adapter
        }

```

En el caso de querer hacerlos sobre un recycler sería necesario la creación de un adaptador y un xml que represente el aspecto de las filas

```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    android:orientation="horizontal"
    android:layout_width="match_parent"
    android:layout_height="wrap_content">

    <TextView
        android:layout_width="0dp"
        android:layout_weight="0.5"
        android:textSize="25dp"
        android:gravity="center"
        android:layout_height="wrap_content"
        android:id="@+id/id_item_fila"/>

    <TextView
        android:layout_width="0dp"
        android:layout_weight="0.5"
        android:gravity="center"
        android:textSize="25dp"
        android:layout_height="wrap_content"
        android:id="@+id/nombre_item_fila"/>

</LinearLayout>

```

El adaptador tendría el siguiente aspecto

```java
class AdaptadorRoom(var lista: List<Usuario>, val context: Context) :
    RecyclerView.Adapter<AdaptadorRoom.MyHolder>() {

    inner class MyHolder(itemView: View) : ViewHolder(itemView) {

        var texto: TextView
        var id: TextView

        init {
            texto = itemView.findViewById(R.id.nombre_item_fila)
            id = itemView.findViewById(R.id.id_item_fila)
        }

    }

    fun changeList(lista: List<Usuario>){
        this.lista = lista;
        notifyDataSetChanged()
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyHolder {

        val view =
            LayoutInflater.from(parent.context).inflate(R.layout.item_recycler, parent, false);
        return MyHolder(view);

    }

    override fun onBindViewHolder(holder: MyHolder, position: Int) {
        val item: Usuario = lista[position]
        holder.texto.text = item.nombre
        holder.id.text = item.id.toString()

    }

    override fun getItemCount(): Int {
        return lista.size
    }
}

```

en este caso no se ha introducido una interfaz de callback, pero sería tan sencillo como seguir los pasos de temas anteriores. Lo único algo diferente es la inclusión de un método adicional que cambia la lista existente por otra que se le pasa por parámetros. Este método se ejecutará cuando hay un filtrado por ejemplo, y se quiere representar un dato nuevo

Por último, a la hora de crear el adaptador desde la activity sería de la siguiente forma

```java
class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var adapter: ArrayAdapter<Usuario>
    private lateinit var adaoterRoom: AdaptadorRoom;
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        GlobalScope.launch(Dispatchers.IO) {
            val database = UsuariosBD.getInstance(applicationContext)
            val lista = database.usuarioDAO().selectAll()
            adaoterRoom = AdaptadorRoom(lista, applicationContext)
            binding.listaUsaurios.adapter = adaoterRoom
            binding.listaUsaurios.layoutManager =
                LinearLayoutManager(applicationContext, LinearLayoutManager.VERTICAL, false)

        }
    }
}

```

Por último imaginemos que tenemos una acción que agregar elementos dentro de la base de datos. Lo que se querrá es que al mismo tiempo que los agrega los muestre en la lista. Para ello utilizamos corrutinas para hacer la inserción, pero será necesario un cambio de contexto para utilizar elementos de la interfaz gráfica

```java
        binding.botonAgregar.setOnClickListener {

            GlobalScope.launch(Dispatchers.IO) {

                val database = UsuariosBD.getInstance(applicationContext)
                database.usuarioDAO()
                    .insert(Usuario("Borja", "Martin", "developandsys@gmail.com"))
                val lista = database.usuarioDAO().selectAll();
                withContext(Dispatchers.Main){
                    adaoterRoom.changeList(lista)
                }
            }

        }

```

El cambio de contexto se debe a que el Dispatcher Main es el encargado de realizar la actualización de la UI, por lo que no podría ser ejecutado desde el Dispatcher IO al hacer este otra tarea.

### Entendiendo las corrutinas

Como se ha dicho en el punto anterior, las corrutinas son elementos que permiten realizar operaciones simultaneas de forma que ninguna de las dos quede congelada o saturada por la ejecución de la otra. La utilización de corrutinas permite entre otras cosas:

- Reducir recursos del sistema al evitar la creación de grandes cantidades de hilos
- Facilitar el retorno de datos de una tarea asíncrona
- Facilitar el intercambio de datos entre tareas asíncronas

Para poder utiliza ejecutar las corrutinas y de forma genérica, kotlin nos ofrece tres posibilidades de ejecución "por defecto"

- Global Scope: utilizado para cualquier corrutina que debe continuar su ejecución mientras la aplicación esté activa. Esto quiere decir que no debe estar asociada a ningún elemento de la aplicación, como por ejemplo fragments. Para poder utilizarla es necesario lanzarla de la siguiente forma

```java
GlobalScope.launch(Dispatchers.IO){
                // acción a ejecutar en 2º plano
}

```

Como parámetros del método launch es necesario indicar un Dispatcher, el cual indica en que hilo debe ejecutarse. Por defecto cada scope tiene uno por defecto (que es el indicado en el método launch), aunque puede cambiarse con la ejecución del método whitcontext(). Los tres dispatcher que tiene kotlin configurado por defecto son los siguientes:

- Main: hilo principal de la ejecución. Es el encargado de todo el tema de interfaz gráfica y configuración de los escuchadores
- IO: hilo reservado para aquellas tareas que implican un flujo de datos de entrada / salida como puede ser manejo de base de datos, comunicaciones por red, manejo de ficheros, etc...
- Default: se trata del hilo predeterminado, reservado para tareas de cálculo potentes

```java
GlobalScope.launch(Dispatchers.Main)
GlobalScope.launch(Dispatchers.IO)
GlobalScope.launch(Dispatchers.Default)

```

En el caso de querer cambiar el hilo de ejecución es necesario llamar al método withContext

```java
val resultadoEjecucion = withContext(Dispatchers.Main){
                    // tarea a ejecutar
                }

```

- LifeCicleScope: En este caso, la ejecución de la tarea que se realiza en paralelo tendrá vida siempre y cuando el ciclo de vida del elemento donde se ha declarado exista. Por ejemplo si se declara dentro de un fragment, cuando el ciclo de vida del fragment haya terminado, la corrutina terminará al mismo tiempo.
- ViewModelSCcope: En este caso, la ejecución de la corrutina está asociada al ViewModel. En el momento en el que la asociación termina, la ejecución de la corrutina queda sin efecto

En este tema vamos a ver la ejecución por defecto de GlobalScope, dejando el resto para temas posteriores.