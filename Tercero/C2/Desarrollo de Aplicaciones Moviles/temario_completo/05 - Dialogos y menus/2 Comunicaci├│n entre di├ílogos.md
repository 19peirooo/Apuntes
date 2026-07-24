# 2 Comunicación entre diálogos

Status: Not started
Type: Stations
🪴 Units: 5. Diálogos y menús (../Unidades/5%20Di%C3%A1logos%20y%20men%C3%BAs%201a0eeadeed708261a57d0160f016c827.md)

# Comunicación en los cuadros de diálogo

En todos los ejemplos que se han mostrado anteriormente, no ha sido necesario ejecutar tareas pesadas o complejas pero imaginemos que se quiere arrancar una tarea con la constestación de un cuadro de diálogo. Para ello es necesario hacer una comunicación bien sea desde el cuadro de diálogo hasta la pantalla o desde la pantalla hasta el cuadro de diálogo. Esto es lo que se conoce como interfaces de callback o también existe la posibilidad de crear funciones posible nulas. Vamos a ver ambas posibilidades.

## Comunicación diálogo - activity

Para poder ilustrar este ejemplo vamos a coger el cuadro de diálogo personalizado. Este será lanzado desde la pulsación de un botón que se ubica en una activity, por lo que es necesario programar su pulsación

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <Button
        android:id="@+id/boton_dialogo_perso"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="24dp"
        android:layout_marginStart="24dp"
        android:text="Diálogo login"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent"

        />

    <TextView
        android:id="@+id/texto_perso"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        app:layout_constraintBottom_toBottomOf="@+id/boton_dialogo_perso"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toEndOf="@+id/boton_dialogo_perso"
        app:layout_constraintTop_toTopOf="@+id/boton_dialogo_perso" />
</androidx.constraintlayout.widget.ConstraintLayout>

```

```java
class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        acciones();
    }

    private fun acciones() {
        binding.botonDialogoPerso.setOnClickListener {

            DialogoPerso().show(supportFragmentManager,"")
        }
    }
}

```

Con este código el cuadro de diálogo es mostrado. Ahora lo que se quiere es, una vez introducidos los datos dentro del cuadro de diálogo, que estos (nombre y pass) sean enviados de vuelta a la activity para allí gestionarlos. Esto se puede hacer de dos formas

- Comunicación mediante interfaces de callback

Por definición, una interfaz es una clase abstracta que tiene un conjunto de métodos que no están implementados. Si nos ceñimos a esta definición una interfaz sirve para que sea implementada en diferentes clases y así poder juntar tipos que inicialmente no tienen nada que ver. Además de esta funcionalidad, las interfaces también sirven para ser ejecutadas desde un sitio (donde se implementan) y llamadas desde otro donde se declaran. Precisamente esto es lo que permite comunicar un diálogo con una interfaz. Vayamos por pasos:

1. Crear una interfaz en el origen de los datos: en aquella clase donde tengamos los datos que queremos comunicar se declara una interfaz con los métodos que se necesiten. Es obvio que tendrá un método cuyos parámetros sean aquellos datos que se quieren comunicar. En este caso esta interfaz será creada en el diálogo, yaq ue es allí donde está el nombre y pass que se quieren comunicar a la activity

```java
class DialogoPerso : DialogFragment() {

    private lateinit var vista: View;
    private lateinit var botonLog: Button;
    private lateinit var editNombre: EditText;
    private lateinit var editPass: EditText;

    override fun onAttach(context: Context) {
        super.onAttach(context)
        vista = LayoutInflater.from(context).inflate(R.layout.dialog_perso, null);
    }

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        var builder = AlertDialog.Builder(requireContext())
        builder.setView(vista)
        return builder.create()
    }

    override fun onStart() {
        super.onStart()
        editNombre = vista.findViewById(R.id.edit_nombre);
        editPass = vista.findViewById(R.id.edit_password);
        botonLog = vista.findViewById(R.id.button_login);
    }

    override fun onResume() {
        super.onResume()
        botonLog.setOnClickListener {

        }
    }

    interface OnLoginListener{
        fun onLoginDataSelected(nombre: String, pass: String)
    }
}

```

1. Una vez está creada la interfaz, es momento de utilizarla. En este caso se utilizará con la pulsación del botón, por lo que se necesita un objeto del tipo de la interfaz en la clase para llamar al método onLoginDataSelected con los parametros que se quieren comunicar. Es necesario declarar esta variable como lateinit porque no se puede inicializar tal cual

```java
class DialogoPerso : DialogFragment() {

    private lateinit var vista: View;
    private lateinit var botonLog: Button;
    private lateinit var editNombre: EditText;
    private lateinit var editPass: EditText;
    private lateinit var listener: OnLoginListener;

    override fun onAttach(context: Context) {
        super.onAttach(context)
        vista = LayoutInflater.from(context).inflate(R.layout.dialog_perso, null);
    }

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        var builder = AlertDialog.Builder(requireContext())
        builder.setView(vista)
        return builder.create()
    }

    override fun onStart() {
        super.onStart()
        editNombre = vista.findViewById(R.id.edit_nombre);
        editPass = vista.findViewById(R.id.edit_password);
        botonLog = vista.findViewById(R.id.button_login);
    }

    override fun onResume() {
        super.onResume()
        botonLog.setOnClickListener {
            listener.onLoginDataSelected(editNombre.text.toString(), editPass.text.toString())
            dismiss()
        }
    }

    interface OnLoginListener{
        fun onLoginDataSelected(nombre: String, pass: String)
    }
}

```

La variable listener es utilizada cuando se pulsa el botón, por lo que como última configuración antes de pasar al siguiente paso es la de instanciar la variable ya que ahora mismo tiene un valor de null. Para poder instanciarla hay que igualarla a algo que sea de tipo OnLoginListener y no sería nada útil hacerlo sobre ella misma

```java
listener = object : OnLoginListener {
            override fun onLoginDataSelected(nombre: String, pass: String) {

            }
        }

```

De esta forma no conseguimos nada ya que los datos no se mueven de la clase donde está declarada la interfaz. Lo que tenemos que hacer es igualarla al contexto dentro del método onAttach() haciendo un casting.

```java
    override fun onAttach(context: Context) {
        super.onAttach(context)
        vista = LayoutInflater.from(context).inflate(R.layout.dialog_perso, null);
        listener = context as OnLoginListener;
        }
    }

```

De esta forma dejamos a la variable preparada para el último paso. Si recordamos de casos anteriores, hemos dicho siempre que el contexto es el ámbito o sitio donde se ejecutan las cosas, por lo que en este caso el contexto es el MainActivity o desde donde se haya sacado el diálogo. Una vez visto esto, ¿como podemos hacer que MainActivity sea también de tipo OnLoginListener? Muy sencillo

1. La respuesta a la pregunta es muy fácil: implementando la interfaz. Con la implementación de la interfaz en el destino de los datos conseguimos que la igualdad que se ha hecho antes en el método onAttach siempre sea verdadera. No solo eso, sino que esta implementación obliga a escribir el método de la interfaz el cual tiene los dos parámetros que son los datos que queremos comunicar desde el diálogo hasta la pantalla

```java
class MainActivity : AppCompatActivity(), DialogoPerso.OnLoginListener {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        acciones();
    }

    private fun acciones() {
        binding.botonDialogoPerso.setOnClickListener {

            DialogoPerso().show(supportFragmentManager,"")
        }
    }

    override fun onLoginDataSelected(nombre: String, pass: String) {
        TODO("Not yet implemented")
    }
}

```

Por último tan solo quedaría por utilizar los datos que vienen como parámetros y tendremos la comunicación terminada

- Comunicación mediante funciones null

En el caso de no querer utilizar una interfaz de callback, existe la posibilidad de utilizar funciones nulas, ya que kotlin ofrece dicha funcionalidad. En realidad es un proceso muy parecido al que hemos descrito en el punto anterior, ya que el fondo es exactamente igual. Para poder hacer un ejemplo de esto vamos a realizarlo sobre el dialogo de selección multiple, donde al dar al botón de aceptar queremos llevar los datos al la pantalla de origen. Para ello es necesario seguir los siguientes pasos:

1. En el origen de los datos, declaramos una variable de tipo función, la cual admite como parámetros aquellos datos que queremos comunicar. En este caso seré el array de elementos que se vá llenando con la pulsación de cada opción tal y como vimos en los puntos anteriores

```java
    lateinit var funcionComunicar: ((ArrayList<String>)->Unit)? = null

```

Evidentemente esta función es nula, ya que no es aquí donde la queremos definir pero si es donde la queremos utilizar. Al ser un posible nulo (?), para poder utilizarla es necesario el uso de la función invoke donde como parámetros podremos lo que pide la función. En este caso se realizar con la pulsación del botón positivo

```java
class DialogoMulti : DialogFragment() {

    lateinit var elementos: Array<String>
    lateinit var elementosSeleccionados: ArrayList<String>
    var funcionComunicar: ((ArrayList<String>)->Unit)? = null

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        elementosSeleccionados = ArrayList();
        elementos = arrayOf("Opción 1", "Opción 2", "Opción 3")
        var builder = AlertDialog.Builder(requireContext());
        builder.setTitle("Cuadro de selección")
            //.setMessage("Que opción quieres hacer")
            .setMultiChoiceItems(elementos, null) { dialogo, posicion, boolean ->
                run {
                    if (boolean) {
                        elementosSeleccionados.add(elementos[posicion])
                    } else {
                        elementosSeleccionados.remove(elementos[posicion])
                    }
                }
            }
            .setPositiveButton("Aceptar") { dialogo, posicion ->
                    funcionComunicar?.invoke(elementosSeleccionados)
            }

        return builder.create()
    }
}

```

1. Una vez está la llamada hecha, es necesario irse al destino de los datos (en este ejemplo el MainActivity) y declarar un objeto del tipo Dialogo (la clase donde está definida la función) y dentro de instancias al mismo tiempo que se da valor al objeto, se define el comportamiento del la función nula.

```java
class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var dialogo: DialogoPerso

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        instancias();
        acciones();
    }

    private fun instancias() {

        dialogo = DialogoPerso();
        dialogo.funcionNula = {elementos -> binding.textoPerso.setText(elementos.size.toString())}
    }

    private fun acciones() {

        binding.botonDialogoPerso.setOnClickListener {

            dialogo.show(supportFragmentManager,"")
        }
    }
}

```

## Comunicación de activity a diálogo

Sería el caso contrario al anterior. Si se quiere pasar un dato desde la pantalla al cuadro de diálogo es necesario utilizar un constructor estático, lo que se conoce con el nombre de newInstance. Este método se guarda en un objeto compacion, de forma que sea acesible directamente, pasándole como parámetros tantos datos como se quiera.

```java
    companion object {
        fun newInstance(nombre: String, pass: String): DialogoComunicacion {
            val dialog: DialogoComunicacion = DialogoComunicacion();
            val bundle: Bundle = Bundle()
            bundle.putString("nombre", nombre)
            bundle.putString("pass", pass)
            dialog.arguments = bundle
            return dialog
        }
    }
```

Dentro de este método, es necesario, además de retornar un objeto del cuadro de diálogo, utilizar un objeto de tipo Bundle el cual se mapea (par clave - valor) con todos los datos que son pasados por parámetros. Una vez está creado, este objeto es puesto com oargumento en el diálogo antes de retornarlo. Una vez retornado, el diálogo ejecutará todo el ciclo de vida desde el onAttach hasta el onDetach

El siguiente paso para poder terminar con la comunicación, es utilizar los datos. Para ello, tal como se ha dicho antes, al retornar el cuadro de diálogo se empieza a ejecutar el ciclo de vida, siendo el primer método onAttach clave para poder recuperar los argumentos pasados, utilizando las keys indicadas. 

```java
    override fun onAttach(context: Context) {
        super.onAttach(context)
        // capturo los datos
        nombre = this.arguments?.getString("nombre") ?: "sin nombre"
        pass = this.arguments?.getString("pass") ?: "sin pass"
    }
```

Con la recuperacion mediante arguments.getTipo(”key”), podremos guardar en una variable de clase el dato que previamente ha sido pasado y así poder utilizarlo en cualquier parte del ciclo de vida.

Por último, cuando desde una activity queramos sacar un diálogo, en vez de hacerlo directamente con un objeto de la clase, utilizaremos el método newInstances para poder crearlo, pasándole así tantos datos como hayan sido indicados en el cuadro de diálogo.

```java
val dialog = DialogoComunicar.newInstance("nombre comunicar", "apellido comunicar")
dialog.show(supportFragmentManager, null)

```