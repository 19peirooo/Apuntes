# Comunicación entre fragments

Status: Not started
🪴 Units: 6. Fragments (../Unidades/6%20Fragments%20252eeadeed7082efa2df013ca1631e30.md)

## Fragment - Activity

Al igual que hacíamos en los cuadros de diálogo o en los recycler view, la comunicación de los fragments con la activity es mediante interfaces de callback o mediante funciones vacías. En este caso, y al no definir los fragments como objetos dentro de la activiy, se va a optar por la primera opción al mejorar mucho el rendimiento. Si recordamos de temas anteriores, el proceso requería de los siguientes pasos:

1. Declarar una interfaz en el origen de los datos (en este caso el fragment) desde el cual se quiere lanzar la comunicación. En esta interfaz es necesario crear tantos métodos como sean necesarios para hacer la comunicación. Para explicar esto vamos a seguir el ejemplo empezar en el punto anterior, donde en el fragment inicial teníamos que seleccionar un lenguaje en el spinner del fragment y teníamos un edit texto para poder un comentario. Estos dos datos serán los que se comunicarán a la activity

```java
interface OnLenguajeListener{
        fun onLenguajeSelected(lenguaje: String)
    }

```

Con la interfaz creada es necesario utilizar el método cuando se quiera realizar la comunicación, por lo que tendremos que crear un objeto del tipo de la interfaz y llamar el método cuando se pulse el botón del fragment

```java
    private lateinit var listener: OnLenguajeListener

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        binding.spinnerFragment.adapter = ArrayAdapter<String>(requireContext(), android.R.layout.simple_spinner_item, arrayLenguajes)
        (binding.spinnerFragment.adapter as ArrayAdapter<String>).setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        binding.botonFragment.setOnClickListener {
            if (!binding.editFragment.text.isEmpty()){
                val lenguaje = binding.spinnerFragment.selectedItem.toString()
                val comentario = binding.editFragment.text.toString()
                listener.onLenguajeSelected(lenguaje,comentario)
            }

        }
    }

```

1. Para que el objeto pueda ser llamado, es necesario que tenga valor ya que en el caso de ser nulo provocaría un fallo. Para darle valor es necesario igualar la variable al contexto (que será la clase desde donde se llama al fragment), casteándola al tipo de la interfaz. Para ello se utiliza el método onAttach ya que tiene el contexto como parámetro

```java
    private lateinit var listener: OnLenguajeListener

    override fun onAttach(context: Context) {
        super.onAttach(context)
        arrayLenguajes = arrayOf("Kotlin", "Java", "Python", "JS", "C#")
        try {
            listener = context as OnLenguajeListener
        } catch (e: java.lang.ClassCastException){
            Log.v("conversion", "error de conversion en el tipo")
        }

    }

```

Para que esta igualdad tenga sentido, es necesario implementar en el destino de la comunicación (en nuestro caso el activity) la interfaz, de forma que sea obligatorio la escritura de cada uno de los métodos

```java
class MainActivity : AppCompatActivity(), OnClickListener, FragmentInicial.OnLenguajeListener {

    private lateinit var binding: ActivityMainBinding
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.botonF1.setOnClickListener(this)
        binding.botonF2.setOnClickListener(this)
        binding.botonF3.setOnClickListener(this)

    }

    override fun onClick(p0: View?) {
        var fragmentTransaction = supportFragmentManager.beginTransaction()

        when(p0!!.id){
            binding.botonF1.id ->{
                fragmentTransaction.replace(binding.ubicacionFragments.id, FragmentInicial())
                fragmentTransaction.setCustomAnimations(android.R.anim.slide_in_left,
                    android.R.anim.slide_out_right);
                if(supportFragmentManager.findFragmentById(binding.ubicacionFragments.id) as? FragmentInicial == null){
                    fragmentTransaction.addToBackStack("f1_top")
                }

            }
            binding.botonF2.id ->{
                fragmentTransaction.replace(binding.ubicacionFragments.id, FragmentSecond())
                fragmentTransaction.setCustomAnimations(android.R.anim.slide_in_left,
                    android.R.anim.slide_out_right);
                fragmentTransaction.addToBackStack("f2_top")
            }
            binding.botonF3.id ->{

                fragmentTransaction.replace(binding.ubicacionFragments.id, FragmentThird())
                fragmentTransaction.setCustomAnimations(android.R.anim.slide_in_left,
                    android.R.anim.slide_out_right);
                fragmentTransaction.addToBackStack("f3_top")

            }
        }

        fragmentTransaction.commit();

    }

    override fun onLenguajeSelected(lenguaje: String, comentario: String) {
        TODO("Not yet implemented")
    }
}

```

Una vez hecho esto tan solo quedaría utilizar los método tal y como indique la lógica de la aplicación, ya que en la activity se tendrían todos los datos comunicados. En este ejemplo sacaremos un Snackbar con los datos seleccionados.

```java
  override fun onLenguajeSelected(lenguaje: String, comentario: String) {
        Snackbar.make(
            binding.root,
            "El lenguaje seleccionado es ${lenguaje} con los siguientes comentarios: ${comentario}",
            Snackbar.LENGTH_SHORT
        ).show()
    }

```

El código completo del fragment sería el siguiente:

```java
class FragmentInicial : Fragment() {

    private lateinit var binding: InicialFragmentBinding
    private lateinit var arrayLenguajes: Array<String>
    private lateinit var listener: OnLenguajeListener

    override fun onAttach(context: Context) {
        super.onAttach(context)
        arrayLenguajes = arrayOf("Kotlin", "Java", "Python", "JS", "C#")
        try {
            listener = context as OnLenguajeListener
        } catch (e: java.lang.ClassCastException){
            Log.v("conversion", "error de conversion en el tipo")
        }

    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = InicialFragmentBinding.inflate(inflater, container, false)
        return binding.root

    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        binding.spinnerFragment.adapter = ArrayAdapter<String>(requireContext(), android.R.layout.simple_spinner_item, arrayLenguajes)
        (binding.spinnerFragment.adapter as ArrayAdapter<String>).setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        binding.botonFragment.setOnClickListener {
            if (!binding.editFragment.text.isEmpty()){
                val lenguaje = binding.spinnerFragment.selectedItem.toString()
                val comentario = binding.editFragment.text.toString()
                listener.onLenguajeSelected(lenguaje,comentario)
            }

        }
    }

    interface OnLenguajeListener{
        fun onLenguajeSelected(lenguaje: String, comentario: String)
    }
}

```

En el siguiente punto veremos como poder pasar los datos de la activity a un fragment.

## Activity - Fragment

El otro tipo de comunicación que existe dentro de los fragments es el de mandar datos desde la pantalla al fragment. En este caso se pueden dar dos tipos de comunicación: si queremos arrancar un fragment que no existe o si queremos pasar datos a un fragment que no existe en la pila de ejecución. Por norma general utilizaremos el primero de los casos, pero siempre es posible que nos encontremos en algún escenario donde nos sirva buscar y ejecutar cosas de un fragment existente:

### Comunicación desde 0

En este caso el fragment al que le queremos comunicar datos no está en la pila, por lo que lo debemos arrancar y pasar datos al mismo tiempo. Para poder hacer esto se utilizan los argumentos, que son partes que se e añaden al fragment en su creación. Como no es posible modificar el constructor de un fragment por extender de una clase ya creada, se utiliza un constructor estático, representado en kotlin por un objeto de tipo companion. Este objeto es declarado dentro de la clase fragment y dentro tiene declarados todos los elementos que son necesarios. De esta forma se podrán ejecutar como métodos estáticos. Para el ejemplo vamos a continuar la comunicación anterior, pasando el lenguaje seleccionado y comentario al segundo fragment. Si recordamos el aspecto gráfico del segundo fragment con las modificaciones ya hechas es el siguiente:

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:id="@+id/texto_fragment_2"
        android:text="FRAGMENT SENCUNDARIO"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

    <TextView
        android:layout_marginTop="20dp"
        android:id="@+id/texto_fragment_comunicado"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        app:layout_constraintEnd_toEndOf="@+id/texto_fragment_2"
        app:layout_constraintStart_toStartOf="@+id/texto_fragment_2"
        app:layout_constraintTop_toBottomOf="@+id/texto_fragment_2" />

    <Button
        android:layout_marginTop="20dp"
        android:id="@+id/boton_fragment"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Contestar"
        app:layout_constraintEnd_toEndOf="@+id/texto_fragment_comunicado"
        app:layout_constraintStart_toStartOf="@+id/texto_fragment_comunicado"
        app:layout_constraintTop_toBottomOf="@+id/texto_fragment_comunicado" />

</androidx.constraintlayout.widget.ConstraintLayout>

```

Para poder pasar datos al fragment secundario tendremos que seguir los siguientes pasos

1. Crear un objeto companion en el destino de la comunicación: dentro de este objeto declararemos la función y elementos que serán ejecutados de forma directa. Es lo que en java se llaman métodos estáticos

```java
class FragmentSecond : Fragment() {

    private lateinit var binding: SecondFragmentBinding

    companion object{
        fun newInstance(lenguaje: String, comentario: String):FragmentSecond {
            val args = Bundle()
            val fragment = FragmentSecond()
            args.putString("lenguaje", lenguaje)
            args.putString("comentario", comentario)
            fragment.arguments = args
            return fragment
        }
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = SecondFragmentBinding.inflate(inflater, container, false)
        return binding.root

    }

}

```

Dentro del objeto companion se crea una función que devuelve un objeto de tipo Fragment, el cual queremos crear. Sobre este objeto se ponen tantos argumentos (en un bundle) como se quieran y se retorna el fragment con el método setArgument ejecutado. Una vez se retorna el fragment el ciclo de vida normal del mismo se empezará a ejecutar

1. Una vez retornado el fragment mediante el método newInstance, en el ciclo de vida del fragment será necesario capturar los argumentos, recuperarlos y utilizarlos dentro de la parte que queramos.

```java
class FragmentSecond : Fragment() {

    private lateinit var binding: SecondFragmentBinding
    private lateinit var lenguaje: String
    private lateinit var comentario: String

    companion object{
        fun newInstance(lenguaje: String, comentario: String):FragmentSecond {
            val args = Bundle()
            val fragment = FragmentSecond()
            args.putString("lenguaje", lenguaje)
            args.putString("comentario", comentario)
            fragment.arguments = args
            return fragment
        }
    }

    override fun onAttach(context: Context) {
        super.onAttach(context)
        lenguaje = arguments?.getString("lenguaje") ?: ""
        comentario= arguments?.getString("comentario") ?: ""
    }

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        binding = SecondFragmentBinding.inflate(inflater, container, false)
        return binding.root

    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)
        binding.textoFragment2.text = lenguaje
        binding.textoFragmentComunicado.text = comentario
    }

}

```

En el método onAttach mediante el elemento arguments podemos recuperar cada uno de los elementos mediante su key. Hay que tener en cuenta que este elemento puede ser nulo, pero que las variables que utilicemos no deben serlo, por lo que es obligatorio el uso de null safety u operador elvis

1. Por último, para poder utilizar este paso de datos, es necesario llamar al método newInstance cuando queremos crear el fragment. Para ello, desde el método de la interfaz que se implementó en el punto anterior se llama al fragment con el método

```java
class MainActivity : AppCompatActivity(), OnClickListener, FragmentInicial.OnLenguajeListener {

    private lateinit var binding: ActivityMainBinding
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.botonF1.setOnClickListener(this)
        binding.botonF2.setOnClickListener(this)
        binding.botonF3.setOnClickListener(this)

    }

    override fun onClick(p0: View?) {
        var fragmentTransaction = supportFragmentManager.beginTransaction()

        when (p0!!.id) {
            binding.botonF1.id -> {
                fragmentTransaction.replace(binding.ubicacionFragments.id, FragmentInicial())
                fragmentTransaction.setCustomAnimations(
                    android.R.anim.slide_in_left,
                    android.R.anim.slide_out_right
                );
                if (supportFragmentManager.findFragmentById(binding.ubicacionFragments.id) as? FragmentInicial == null) {
                    fragmentTransaction.addToBackStack("f1_top")
                }

            }
            binding.botonF2.id -> {
                fragmentTransaction.replace(binding.ubicacionFragments.id, FragmentSecond())
                fragmentTransaction.setCustomAnimations(
                    android.R.anim.slide_in_left,
                    android.R.anim.slide_out_right
                );
                fragmentTransaction.addToBackStack("f2_top")
            }
            binding.botonF3.id -> {

                fragmentTransaction.replace(binding.ubicacionFragments.id, FragmentThird())
                fragmentTransaction.setCustomAnimations(
                    android.R.anim.slide_in_left,
                    android.R.anim.slide_out_right
                );
                fragmentTransaction.addToBackStack("f3_top")

            }
        }

        fragmentTransaction.commit();
        Log.v("numero_fragments", supportFragmentManager.fragments.size.toString())
        Log.v("estados", supportFragmentManager.backStackEntryCount.toString())

    }

    override fun onLenguajeSelected(lenguaje: String, comentario: String) {
        supportFragmentManager.beginTransaction().replace(
            binding.ubicacionFragments.id,
            Fragm.commit()entSecond.newInstance(lenguaje, comentario)
        ).commit()
        /*Snackbar.make(
                binding.root,
                "El lenguaje seleccionado es ${lenguaje} con los siguientes comentarios: ${comentario}",
                Snackbar.LENGTH_SHORT
            ).show()*/
    }
}

```

## Comunicación buscando el fragment

El caso anterior se basa en una comunicación donde el fragment con el que se quiere comunicar no existe y hay que crearlo con los datos ya puestos. Pero en el caso de que el fragment ya exista, es necesario buscarlo en la pila de ejecución y pasarle los datos que se quieran. Este tipo de comunicación combina todo lo anterior. Para este ejemplo vamos a realizar una pulsación en el botón del segundo fragment (el que acabamos de terminar) y le vamos a pasar un dato al fragment inicial, el cual ya estará en la pila. Para ello realizaremos los siguientes pasos:

1. Crear una interfaz de callback que permita comunicar la pulsación del boton del fragment 2 con la activity
2. En el método implementado de la interfaz en la activity, se buscará el fragment en la pila de ejecuciones. En el caso de encontrarlo se ejecutará un método que deberá estar escrito en el fragment, realizando la comunicación deseada

```java
    override fun onSecondSelected() {
        val fragmentUno = supportFragmentManager.findFragmentById(R.id.ubicacion_fragments) as? FragmentInicial
        fragmentUno?.comunicadDatos()
    }

```