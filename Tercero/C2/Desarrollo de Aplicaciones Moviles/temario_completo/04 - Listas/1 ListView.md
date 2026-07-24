# 1. ListView

Status: Not started
🪴 Units: 4. Listas (../Unidades/4%20Listas%20ff4eeadeed7082ad941d016823ffc6d8.md)

# ListView

Como se ha dicho antes, los recyclerview son las listas que más se utilizan en android por su eficiencia a la hora de mostrar los datos. Pero también existen otro tipo de listas que también se pueden utilizar. En este caso estaríamos hablando de listas que no muestran una cantidad de datos grandes ya que su capacidad de carga no es muy buena. A diferencia de los recycler, este tipo de listas pueden mostrar datos sin necesidad de un adaptador complejo (como el que creamos en un archivo aparte). Para poder mostrar el uso de los ListView vamos a realizar el ejemplo realizado en el punto anterior. Lo primero que vamos hacer es crear una activity nueva llamado ListadoActivity, junto con un xml que tan solo tenga un objeto de tipo ListView con el id listview_lenguajes

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".ListadoActivity">

    <ListView
        android:layout_width="409dp"
        android:layout_height="729dp"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        android:id="@+id/listview_lenguajes"
        />
</androidx.constraintlayout.widget.ConstraintLayout>

```

Una vez hecho esto en el archivo xml referente a la parte gráfica, en el archivo de la parte lógica vamos a crear el mismo arraylist de lenguajes del ejercicio anterior.

```java
package com.develop.listasrecycler

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import com.develop.listasrecycler.databinding.ActivityListadoBinding
import com.develop.listasrecycler.model.Lenguaje

class ListadoActivity : AppCompatActivity() {

    private lateinit var listaLenguajes: ArrayList<Lenguaje>
    private lateinit var binding: ActivityListadoBinding;

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityListadoBinding.inflate(layoutInflater)
        val view: View = binding.root;
        setContentView(view)
        rellenarDatos()

    }

    private fun rellenarDatos() {
        listaLenguajes = ArrayList();
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("KotlinÚltimo", 1.7, "JetBrain", R.drawable.kotlin))
    }
}

```

Hasta este momento la diferencia no ha sido ninguna, ya que tan solo se ha creado el arraylist y se ha rellenado con una serie de datos. La diferencia viene a la hora de asociar los datos (parte lógica) con la lista (parte gráfica). Cuando trabajamos con un recyclerview teníamos que crear un adaptador con la creación de una clase que implementase la interfaz RecyclerView.Adapter, pero en el caso del listView existe un adaptador ya creado que puede servir como base, no teniendo la necesidad de crear una clase nueva. Este adaptador es de tipo ArrayAdapter y ya lo vimos cuando el tema anterior hablamos de los spinner. PAra crearlo es necesario indicar el contexto, un layout que nos da android y la lista de datos que se quieren representar

```java

    private lateinit var binding: ActivityListadoBinding;

    private fun configurarLista() {
        adaptadorLista = ArrayAdapter(this, android.R.layout.simple_list_item_1, listaLenguajes)
        binding.listviewLenguajes.adapter = adaptadorLista

    }

```

Si incluimos ese código en la actividad, obtendremos una lista de datos pero en cada uno de los item no aparecerá el nombre, sino que aparecerá el elemento - objeto completo por lo que no nos serviría. Para poder representarlo bien tendríamos que sobreescribir el método toString en la clase Lenguaje. Al tratarse de una clase de datos (ya que así lo representamos para poder ahorra código), el código en una clase normal debería ser el siguiente

```java
class Lenguaje (var nombre: String, var version: Double, var detalle: String, var imagen: Int) : Serializable {
    override fun toString(): String {
        return nombre
    }
}

```

Esto representará cada uno de los item distribuidos en filas. Sin embargo este tipo de adaptador no es muy personalizable, ya que tan solo se puede utilizar un item con un elemento. En código completo de la actividad es el siguiente:

```java
class ListadoActivity : AppCompatActivity() {

    private lateinit var listaLenguajes: ArrayList<Lenguaje>
    private lateinit var binding: ActivityListadoBinding;
    private lateinit var adaptadorLista: ArrayAdapter<Lenguaje>

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityListadoBinding.inflate(layoutInflater)
        val view: View = binding.root;
        setContentView(view)
        rellenarDatos()
        configurarLista()

    }

    private fun configurarLista() {
        //adaptadorLista = ArrayAdapter(this, android.R.layout.simple_list_item_1, listaLenguajes)
        adaptadorLista = ArrayAdapter(this,R.layout.fila_recycler, R.id.nombre_item,listaLenguajes)
        binding.listviewLenguajes.adapter = adaptadorLista

    }

    private fun rellenarDatos() {
        listaLenguajes = ArrayList();
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("KotlinÚltimo", 1.7, "JetBrain", R.drawable.kotlin))
    }
}

```

Otra de las posibilidades de creación del ArrayAdapter es la de indicar un layout creado y el id de la vista donde se colocará el elemento de la lista. Para ello lo primero será crear un layout (utilizaremos el creado anteriormente con el nombre fila_recycler)

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:padding="10dp">

    <ImageView
        android:id="@+id/imagen_item"
        android:layout_width="100dp"
        android:layout_height="100dp"
        android:layout_marginStart="16dp"
        android:layout_marginTop="16dp"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        tools:srcCompat="@tools:sample/avatars" />

    <TextView
        android:id="@+id/nombre_item"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Prueba"
        android:textSize="30sp"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toEndOf="@+id/imagen_item"
        app:layout_constraintTop_toTopOf="parent" />
</androidx.constraintlayout.widget.ConstraintLayout>

```

Con este archivo representando el elemento de la lista, el siguiente paso es crear un adaptador dentro de la actividad de tipo ArrayAdapter pero en este caso indicando contexto, layout a utilizar, id de la vista donde se pondrá el elemento y lista de datos

```java
  private fun configurarLista() {
        adaptadorLista = ArrayAdapter(this,R.layout.fila_recycler, R.id.nombre_item,listaLenguajes)
        binding.listviewLenguajes.adapter = adaptadorLista
    }

```

Sin embargo este tipo de adaptador también se queda muy corto ya que tan solo se puede poner uno de los datos. En el caso de querer hacer un adaptador personalizado, es necesario crear una clase adicional que extienda de la clase ArrayAdapter o BaseAdaper. Esta implementación obligará a escribir los siguientes métodos

- getCount: método que será el encargado de indicar el número de elementos que tendrá la lista
- getItem: método encargado de retornar el elemento de la posición indicada como parámetro
- getItemId: método encargado de retornar el id del elemento de la posición indicada como parámetro
- getView: método encargado de traer el layout que se quiera utilizar y rellenar las filas con cada uno de los datos.

Para el ejemplo de la lista de lenguajes la clase quedará de la siguiente forma

```java
class AdaptadorLenguajesLista(var lista: List<Lenguaje>, var context: Context): BaseAdapter() {

    override fun getCount(): Int {
        return lista.size
    }

    override fun getItem(p0: Int): Any {
        return lista.get(p0)
    }

    override fun getItemId(p0: Int): Long {
        return p0.toLong();
    }

    override fun getView(p0: Int, p1: View?, p2: ViewGroup?): View {
        val view: View = p1?:LayoutInflater.from(context).inflate(R.layout.fila_recycler, p2,false)
        val imagen = view.findViewById<ImageView>(R.id.imagen_item);
        val nombre = view.findViewById<TextView>(R.id.nombre_item);
        imagen.setImageResource(lista.get(p0).imagen)
        nombre.setText(lista.get(p0).nombre)
        return view
    }
}

```

Una vez creado el adaptador será necesario crearlo y setearlo dentro de la activity mediante el método setAdapter

```java
class ListadoActivity : AppCompatActivity() {

    private lateinit var adaptadorLenguajesLista: AdaptadorLenguajesLista;

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityListadoBinding.inflate(layoutInflater)
        val view: View = binding.root;
        setContentView(view)
        rellenarDatos()
        configurarLista()

    }

    private fun configurarLista() {
        adaptadorLenguajesLista = AdaptadorLenguajesLista(listaLenguajes,this)
        binding.listviewLenguajes.adapter = adaptadorLenguajesLista

    }

    private fun rellenarDatos() {
        listaLenguajes = ArrayList();
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("KotlinÚltimo", 1.7, "JetBrain", R.drawable.kotlin))
    }
}

```

## Manejo de eventos en las listas

Otra de las grandes diferencias entre las listas y los recycler es el manejo de eventos. Si recordáis cuando creamos los recycler, para que pudiésemos tratar el item pulsado era necesario declarar una función nula que más tarde era llamada desde la clase de la activity y declarada al mismo tiempo, donde obteníamos como parámetro el dato que queríamos tratar. Esto no pasa en las listas, ya que se puede hacer directamente gracias a su listener onItemCliclListener. Este recibe como parámetros la vista que ha generado el evento (en este caso la lista), la posición del item pulsado y el id del item pulsado (fijaros que son todos los datos que hemos sobreescrito cuando se ha creado el adaptador personalizado)

```java
class ListadoActivity : AppCompatActivity() {

    private lateinit var listaLenguajes: ArrayList<Lenguaje>
    private lateinit var binding: ActivityListadoBinding;
    private lateinit var adaptadorLista: ArrayAdapter<Lenguaje>
    private lateinit var adaptadorLenguajesLista: AdaptadorLenguajesLista;

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityListadoBinding.inflate(layoutInflater)
        val view: View = binding.root;
        setContentView(view)
        rellenarDatos()
        configurarLista()
        acciones()

    }

    private fun acciones() {
        binding.listviewLenguajes.setOnItemClickListener{ parent, view, position, id ->
            Toast.makeText(
                applicationContext,
                "pulsado elemento con nombre ${listaLenguajes.get(position).nombre}",
                Toast.LENGTH_SHORT
            ).show()
        }
    }

    private fun configurarLista() {
        adaptadorLenguajesLista = AdaptadorLenguajesLista(listaLenguajes, this)
        binding.listviewLenguajes.adapter = adaptadorLenguajesLista

    }

    private fun rellenarDatos() {
        listaLenguajes = ArrayList();
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("Kotlin", 1.7, "JetBrain", R.drawable.kotlin))
        listaLenguajes.add(Lenguaje("KotlinÚltimo", 1.7, "JetBrain", R.drawable.kotlin))
    }
}

```