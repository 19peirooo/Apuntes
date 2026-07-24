# 4. Firebase Realtime Database

Status: Not started
🪴 Units: 7. Base datos (../Unidades/7%20Base%20datos%20343eeadeed7082648c4f817840eb78e6.md)

Para poder explicar toda la funcionalidad vamos a utilizar un ejemplo sencillo donde utilizaremos botones para poder implementar cada una de las funcionalidades. La parte gráfica de la aplicación quedará de la siguiente manera:

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <LinearLayout
        android:id="@+id/linear_acciones"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent">

        <Button
            android:id="@+id/boton_agregar"
            android:layout_width="0dp"
            android:layout_height="wrap_content"
            android:layout_weight="0.33"
            android:text="Agregar " />

        <Button
            android:id="@+id/boton_modificar"
            android:layout_width="0dp"
            android:layout_height="wrap_content"
            android:layout_weight="0.33"
            android:text="Modificar " />

        <Button
            android:id="@+id/boton_buscar"
            android:layout_width="0dp"
            android:layout_height="wrap_content"
            android:layout_weight="0.33"
            android:text="Buscar " />

    </LinearLayout>

</androidx.constraintlayout.widget.ConstraintLayout>

```

### Utilizar una acceso a la base de datos

Antes de empezar con cualquier acción sobre la base de datos, lo que se necesita es tener acceso a la misma. Para ello se utiliza el siguiente código

```java
val database = Firebase.database("<https://fir-develop-2730d-default-rtdb.europe-west1.firebasedatabase.app/>")

```

De esta forma la base de datos queda accesible desde el nodo general. Todas las acciones que se realicen sobre ella se produciran en el nodo root. Recordad que cada uno de los nodos tiene un par clave - valor

### Escribir nodos en la base de datos

Para podre escribir dentro de la base de datos ya accesible, lo que se necesita es crear una referencia. Esto no es más que un puntero al nodo donde se quiere guardar el valor. Por ejemplo si queremos guardar en un nodo llamado nombre un valor determinado utilizaremos el siguiente código

```java
val database = Firebase.database("<https://fir-develop-2730d-default-rtdb.europe-west1.firebasedatabase.app/>")
val ref = database.getReference("nombre")
ref.setValue("Borja")

```

Una cosa muy importante es que en el caso de que el nodo no exista (como es este caso), lo crea y le asocia el valor indicado. En el caso de que el nodo exista el valor se modifica por el que se indica. En el caso de querer borrar el nodo se puede poner un valor null y esto eliminará el nodo

```java
val database = Firebase.database("<https://fir-develop-2730d-default-rtdb.europe-west1.firebasedatabase.app/>")
val ref = database.getReference("nombre")
ref.setValue(null)

```

Cuando se produce la acción de guardar, los datos como se han dicho antes pueden ser muchos: Int, Double, String, [], {}. En el caso de ser una estructura compleja como un [] o un {}, firebase interpretar los datos y los agrega de la misma forma que tiene en su construcción

```java
val database = Firebase.database("<https://fir-develop-2730d-default-rtdb.europe-west1.firebasedatabase.app/>")
val ref = database.getReference("opciones")
val arrayList = ArrayList<String>()
arrayList.add("Opcion1")
arrayList.add("Opcion2")
arrayList.add("Opcion3")
ref.setValue(arrayList)

```

En el caso de querer guardad un objeto sería de la siguiente forma

```java
class Usuario (var nombre: String, var apellido: String, var correo: String, var edad: Int ){

    override fun toString(): String {
        return super.toString()
    }

}

```

Esta clase representa el objeto que se quiere guardad en la base de datos. Para poder guardarlo utilizaríamos el siguiente código

```java
val database = Firebase.database("<https://fir-develop-2730d-default-rtdb.europe-west1.firebasedatabase.app/>")
val ref = database.getReference("usuario")
ref.setValue(Usuario("Borja", "Martin","develop@gmail.com",38))

```

En el caso de querer situar el elemento en otro nodo y este no exista, se crea. Para poder hacer esto utilizaríamos el método child

```java
val database = Firebase.database("<https://fir-develop-2730d-default-rtdb.europe-west1.firebasedatabase.app/>")
val ref = database.getReference("datos_app")
val usuario = Usuario("Borja", "Martin","develop@gmail.com",38)
val correo =usuario.correo.replace("@","_").replace(".","_")
ref.child(correo).setValue(Usuario("Borja", "Martin","develop@gmail.com",38))

```

### Modificar nodos en la base de datos

Si bien con el punto anterior podemos hacer tanto inserciones como borrados (poner el valor a null), hacer modificaciones tiene la misma metodología. En el caso de apuntar a un nodo que ya exista, el valor que se indique se sustituirá por el que esté guardado dentro de la base de datos, así en el ejemplo que teníamos del punto anterior, podríamos modificar el nodo edad simplemente apuntando a su key

```java
            ref = database.getReference("datos_app");
            ref.child("develop_gmail_com").child("edad").setValue(39);

```

### Selección de datos

Para poder hacer selecciones en firebase se utiliza una clase especial llamada Query. Aunque el nombre es común a una base de datos SQL, la sentencia no tiene nada que ver, ya que se escribe de forma totalmente diferente. Antes de hacer una query, hay que aplicar dos pasos:

- Ordenar los datos: esto permite indicar mediante que elemento los datos van a quedar ordenados. Se puede hacer por child, por key o por value
- Filtrar los datos: una vez los datos están ordenados el siguiente paso es filtrarlos, indicando alguna característica de los elementos ordenados que cumpla la condición que se desea. Los filtros que se pueden aplicar son: equal, limitToFirst, limitToLast, startAt, startAfter, endAt, endBefore

Para poder hacer ejemplos sobre búsquedas vamos a utilizar un json que guardaremos en la base de datos. Los datos que se utilizarán son los siguientes: [https://github.com/annexare/Countries/blob/master/data/countries.json](https://github.com/annexare/Countries/blob/master/data/countries.json)

![](https://www.notion.so./images/paises.png)

Como se puede ver en la imagen, la estructura de la base de datos tienen un nodo general que se llama países del cual penden todos. En el caso de querer buscar un país con una siglas concretas (imaginemos que las ha introducido el usuario en un edit) se utilizaría el siguiente código

```java
val database =
                Firebase.database("<https://fir-develop-2730d-default-rtdb.europe-west1.firebasedatabase.app/>")
                database.getReference("países").orderByChild("name").equalTo("Andorra").addListenerForSingleValueEvent(object:ValueEventListener {
                    override fun onDataChange(snapshot: DataSnapshot) {
                        if (snapshot.exists()) {
                            /*for (i in snapshot.children) {
                                Log.v("pais", i.value.toString())

                            }*/
                            snapshot.
                        }
                        else {
                            Log.v("pais", "sin resultados")
                        }
                    }

                    override fun onCancelled(error: DatabaseError) {
                    }
                })

// la salida sería la siguiente --> {continent=EU, capital=Andorra la Vella, languages=[ca], native=Andorra, phone=[376], name=Andorra, currency=[EUR]}

```

En este caso se ha utilizado el métpdp orderByChild, el cual obtiene un child cuyo nombre es el indicado (name) y sonre este busca aquel que tiene como valor Andorra. Una vez encontrado se evalúa el valor del nodo encontrado. Para ello mediante un objeto de tipo ValueEventListener se obtiene el DataSnapshot, que es el nodo encontrado. En el caso de querer recorrer cada uno de los nodos internos sería de la siguiente forma

```java
                database.getReference("países").orderByChild("name").equalTo("Andorra").addListenerForSingleValueEvent(object:ValueEventListener {
                    override fun onDataChange(snapshot: DataSnapshot) {
                        if (snapshot.exists()) {
                            /*for (i in snapshot.children) {
                                Log.v("pais", i.value.toString())
                            }*/
                            for (i in snapshot.children){
                                for (j in i.children){
                                    Log.v("pais", j.value.toString())
                                }
                            }
                        }
                        else {
                            Log.v("pais", "sin resultados")
                        }
                    }

```

En el caso de querer cambiar el valor de alguna parte del snapshot, es necesario obtener primero su referencia

```java
            val database =
                Firebase.database("<https://fir-develop-2730d-default-rtdb.europe-west1.firebasedatabase.app/>")
            database.getReference("países").orderByChild("name").equalTo("Andorra")
                .addListenerForSingleValueEvent(object : ValueEventListener {
                    override fun onDataChange(snapshot: DataSnapshot) {
                        if (snapshot.exists()) {
                           for (i in snapshot.children) {
                                for (j in i.children) {
                                    if (j.key.toString() == "capital") {
                                        Log.v("pais", j.value.toString())
                                        j.ref.setValue("LA VELLA")
                                    }
                                }
                            }
                        } else {
                            Log.v("pais", "sin resultados")
                        }
                    }

```

Como se ha visto, en el caso de querer hacer una selección de datos, para poder obtener el valor es necesario acceder al value del hijo/os del snaptshot. Se ha comentado en muchas ocasiones que estos datos pueden ser de muy diferentes tipos. En concreto, si el tipo de dato que tiene un hijo representa un objeto, en vez de recuperar característica a característica y luego crear el objeto, se puede igualar directamente. En el ejemplo de los países un pais consta de los siguientes datos:

- "name": "Andorra",
- "native": "Andorra"
- "phone": [376]
- "continent": "EU"
- "capital": "Andorra la Vella"
- "currency": ["EUR"]
- "languages": ["ca"]

Todas estas características son las que componen cada uno de los nodos, por lo que representar las propiedades del objeto que se quiere recuperar. Para poder hacerlo de golpe, primero es necesario tener una clase con las mismas características donde cada uno de los atributos está inicializado como null o como dato por defecto en caso de los Int, Double, Bool, etc...

```java
data class Pais(
    var name: String? = null,
    var native: String? = null,
    var phone: Array<String>? = null,
    var continent: String? = null,
    var currency: Array<String>? = null,
    var languages: Array<String>? = null,
)

```

Como se puede ver, la clase Pais es el punto de acceso para que Firebase pueda hacer la traducción entre el contenido del nodo y el elemento que se creará en código. Para poder obtener esta traducción, basta con ejecutar el método getValue() indicando como parámetro la clase que realizará la conversión

```java
val database =
                Firebase.database("<https://fir-develop-2730d-default-rtdb.europe-west1.firebasedatabase.app/>")
            database.getReference("países").orderByChild("name").equalTo("Andorra").addListenerForSingleValueEvent(object: ValueEventListener{
                override fun onDataChange(snapshot: DataSnapshot) {
                    if (snapshot.exists()){
                        for (i in snapshot.children){
                            val pais = i.getValue(Pais::class.java)
                            Log.v("pais",pais?.name!!)
                        }
                    }
                }

                override fun onCancelled(error: DatabaseError) {
                    TODO("Not yet implemented")
                }

            })

```

- * En el caso de haber quitado el equalTo hubiesen salido todos los países **

### Cargar datos en un recyclerview

Para poder cargar los datos dentro de un recycler utilizando firebase tan solo tendríamos que realizar la consulta que hemos hecho en el método anterior y además ir rellenando la lista con los datos que se van obteniendo. El siguiente ejemplo muestra un recycler de todos los paises con sus respectivas capitales.

1. Crear el xml que representará el item de las filas

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.cardview.widget.CardView xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:layout_margin="20dp"
    app:cardCornerRadius="10dp"
    app:cardElevation="20dp">

    <androidx.constraintlayout.widget.ConstraintLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:padding="10dp">

        <TextView
            android:id="@+id/textview1"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:layout_marginRight="20dp"
            android:text="Nombre"
            app:layout_constraintStart_toStartOf="parent"
            app:layout_constraintTop_toTopOf="parent" />

        <TextView
            android:id="@+id/text_pais"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:layout_marginLeft="50dp"
            android:text="TextView"
            app:layout_constraintStart_toEndOf="@+id/textview1"
            app:layout_constraintTop_toTopOf="@+id/textview1" />

        <TextView
            android:id="@+id/textview2"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:layout_marginTop="10dp"
            android:text="Capital"
            app:layout_constraintStart_toStartOf="@+id/textview1"
            app:layout_constraintTop_toBottomOf="@+id/textview1" />

        <TextView
            android:id="@+id/text_capital"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="TextView"
            app:layout_constraintStart_toStartOf="@+id/text_pais"
            app:layout_constraintTop_toTopOf="@+id/textview2" />

    </androidx.constraintlayout.widget.ConstraintLayout>

</androidx.cardview.widget.CardView>

```

1. Crear un adaptador para poder ponerlo dentro del recycler. En este caso tan solo pedirá como parámetro una lista. Además de los métodos implementados tendrá un método adicional que permitirá agregar un pais de forma individual

```java
class AdapterPais(var listado: List<Pais>) : RecyclerView.Adapter<AdapterPais.MyHolder>() {

    inner class MyHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        var textoPais: TextView
        var textoCapital: TextView

        init {
            textoPais = itemView.findViewById(R.id.text_pais)
            textoCapital = itemView.findViewById(R.id.text_capital)
        }
    }

    fun addaPais(pais: Pais){
        (listado as ArrayList<Pais>).add(pais)
        notifyItemInserted(listado.size -1)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyHolder {
        val view =
            LayoutInflater.from(parent.context).inflate(R.layout.item_recycler, parent, false)
        return MyHolder(view)
    }

    override fun onBindViewHolder(holder: MyHolder, position: Int) {
        val pais = listado[position]
        holder.textoPais.text = pais.name
        holder.textoCapital.text = pais.capital
    }

    override fun getItemCount(): Int {
        return listado.size
    }
}

```

1. Además de poner el adaptador dentro de un recycler, cuando se hacen las consultas a los nodos es necesario además de obtener el objeto de tipo país pasárselo al adaptador mediante el método que acabamos de mencionar en el paso anterior.

```java
class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var adapterPais: AdapterPais
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        adapterPais = AdapterPais(ArrayList<Pais>())
        binding.recyclerPaises.adapter = adapterPais
        binding.recyclerPaises.layoutManager = LinearLayoutManager(applicationContext, LinearLayoutManager.VERTICAL, false)

    override fun onResume() {
        super.onResume()

        val database =
            Firebase.database("<https://fir-develop-2730d-default-rtdb.europe-west1.firebasedatabase.app/>")
        database.getReference("países").orderByChild("name").addValueEventListener(object: ValueEventListener{
            override fun onDataChange(snapshot: DataSnapshot) {
                if (snapshot.exists()){
                    for (i in snapshot.children){
                        adapterPais.addaPais(i.getValue(Pais::class.java) as Pais)
                    }
                }
            }

            override fun onCancelled(error: DatabaseError) {
                TODO("Not yet implemented")
            }
        })
    }
}

```