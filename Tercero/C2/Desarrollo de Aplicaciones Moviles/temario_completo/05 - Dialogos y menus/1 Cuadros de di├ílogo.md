# 1. Cuadros de diálogo

Status: Not started
Type: Stations
🪴 Units: 5. Diálogos y menús (../Unidades/5%20Di%C3%A1logos%20y%20men%C3%BAs%201a0eeadeed708261a57d0160f016c827.md)

# Cuadros de diálogo

Como se ha dicho, los diálogos son una forma de interactuar con el usuario, bien para dar información a modo información o para pedir algún tipo de dato. Antiguamente se utilizaban diálogos normales, pero desde la aparición de Android 4.0 se utilizan por defecto DialogFragment. Por este motivo el ciclo de vida de un diálogo es idéntico al que se explicará en el siguiente tema de la gestión de los fragments.

Antes de empezar a explicar la creación de diálogos es importante recordar los siguiente elementos:

- getSupportFragmentManager(): elemento que permite manejar los diálogos, mostrarlos y asignarles etiquetas
- DialogFragment: tipo que representa el diálogo como tal. Esta clase tiene sus propios elementos (titulo, contenido, botones) o se le puede inflar una vista propia.
- AlertDialog.Builder: Tipo que permite la creación del diálogo con todos sus elementos

Para poder hacer un ejemplo de diálogos, vamos a crear una aplicación que permita lanzar diferentes tipos. Para ello vamos a crear la siguiente interfaz:

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <Button
        android:id="@+id/boton_dialogo_normal"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="24dp"
        android:layout_marginStart="24dp"
        android:text="Diálogo aviso"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent"/>

    <TextView
        android:id="@+id/texto_aviso"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        app:layout_constraintBottom_toBottomOf="@+id/boton_dialogo_normal"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toEndOf="@+id/boton_dialogo_normal"
        app:layout_constraintTop_toTopOf="@+id/boton_dialogo_normal" />
</androidx.constraintlayout.widget.ConstraintLayout>

```

Una vez creado la parte gráfica y gestionada de forma correcta, vamos crear y lanzar un cuadro de diálogo. Para ello vamos a gestionar la pulsación del botón.

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
        binding.botonDialogoNormal.setOnClickListener{

        }
    }
}

```

Una vez gestionada la pulsación vamos a lanzar el cuadro de diálogo. Para ello lo primero es crearlo utilizando la clase AlertDialog.Builder() el cual pide como parámetro el contexto de la aplicación, ya que un cuadro de diálogo es mostrado sobre algo:

```java
AlertDialog.Builder(applicationContext)

```

En cuanto a la forma de crearlo existen dos posibilidades:

- Crearlo en el propio código
- Crearlo en una clase independiente

Ambas posibilidades son útiles, dependiendo de cual es el uso se realizará de una forma u otra. Por ejemplo, si queremos reutilizar el diálogo lo crearemos en una clase independiente para que pueda ser llamado desde diferentes sitios sin tener que crear el mismo código n veces. No obstante el código de programación vamos a ver que es el mismo.

Dependiendo de cual sea el cuadro de diálogo que queramos crear las características que se le pondrán son diferentes. Antes de empezar a distinguir cuadros de diálogo, es necesario entender la morfología de los mismos, y en que parte pueden ir los datos. Para ello podemos ver la siguiente imagen

Para explicar esto, vamos a utilizar la creación de los cuadros de diálogo mediante clases independientes. Para ello lo primero es crear una clase kotlin la cual extienda de DialogFragment (de la clase androidx) y sobreescribimos el método onCreateDialgo. Este método del ciclo de vida del cuadro de diálogo permite crear y personalizar el cuadro de forma completa. Si nos fijamos, este método debe retornar un objeto de tiempo Dialog, el cual será construido a través del Builder

```java
class DialogoAviso: DialogFragment() {

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        var  builder = AlertDialog.Builder(requireContext())

        return builder.create()
    }
}

```

Una vez visto cuales son las ubicaciones donde se pueden poner las cosas en los cuadros de diálogo y su creación básica, vamos a ver los diferentes tipos

## Cuadros de diálogo de aviso

Se trata de unos cuadros de diálogo que no tienen mucha interacción con el usuario, simplemente muestran un mensaje. Para ello se utiliza el método setTitle y setMessage para indicar ambas posiciones. Para poder crear un cuadro de diálogo de este tipo, vamos a crear una clase tal y como hemos visto en el punto anterior

```java
class DialogoAviso: DialogFragment() {

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        return
    }
}

```

Para poder crear el cuadro de diálogo, tan solo es necesario que este método retorne un objeto de tipo diálogo. Para ello hay que instanciar el Builder a través del contexto (sitio donde se ejecuta la aplicación) y utilizar los métodos que se quieran. En este caso utilizaremos los que se comentaron anteriormente

```java
    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        var  builder = AlertDialog.Builder(requireContext())
        builder.setTitle("Cuadro de aviso")
            .setMessage("Mensaje de aviso para el usuario")
            .setIcon(android.R.drawable.ic_dialog_info)
        return builder.create()
    }

```

Adicionalmente a los métodos anteriores, se ha ejecutado el método setIcon el cual pone un icono al diálogo. Una vez está creado esto y retornado el builder.create(), este cuadro de diálogo puede ser mostrado. Para ello, en la clase donde queramos utilizarlo es necesario crear un objeto de la clase y llamar al método .show(). Este método admite dos parámetros:

- SupportFragmentManager: el elemento que permite gestionar que ventanas se muestran o se ocultan. Hay que recordad que los cuadros de diálogo son fragments
- Tag: Un texto que se le asigna al cuadro para que si se quiere recuperar pueda ser llamado por esta etiqueta. En fragments esta opción es muy útil

```java
private fun acciones() {
        binding.botonDialogoNormal.setOnClickListener {
            DialogoAviso().show(supportFragmentManager,"")
        }
    }

```

Una vez hecho esto el cuadro de diálogo es mostrado, y para poder ocultarlo es necesario pulsar fuera. En el caso de querer poner un botón de confirmación podríamos hacerlo incluyendo el método setPositiveButton dentro de la clase del diálogo

```java
    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        var  builder = AlertDialog.Builder(requireContext())
        builder.setTitle("Cuadro de aviso")
            .setMessage("Mensaje de aviso para el usuario")
            .setIcon(android.R.drawable.ic_dialog_info)
            .setPositiveButton("OK",null)
        return builder.create()
    }

```

Esta última parte la explicaremos en detalle en el siguiente tipo de cuadro de diálogo

**cuando se trabaja con cuadros de diálogo / fragments siempre hay que mantener una correlación con las clases que se utilizan. Siempre es necesario trabajar con android.x que ofrece clases de soporte (retrocompativilidad), por lo que se utilizará getSuppontFragmentManager en vez de FragmentManager a la hora de mostrarlos**

## Diálogos de confirmación

En el siguiente tipo de cuadro de diálogo, además de poder mostrar un mensaje, se le pide al usuario que pulse un botón para constestar a una pregunta simple. Las opciones serán: respuesta positiva, respuesta negativa o respuesta neutra.

Al igual que antes es necesario crear una clase adicional incluiyendo en el onCreateDialog los métodos de setPostiveButton setNegativeButton o setNeutralButton

```java
class DialogoConfirmacion : DialogFragment() {

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        var builder = AlertDialog.Builder(requireContext());
        builder.setTitle("Cuadro de confirmacion")
            .setMessage("Mensaje de confirmación para el usuario, ¿Confirmas la acción?")
            .setPositiveButton("OK") { dialogInterface, posicion ->
                Log.v(
                    "dialogos",
                    "Pulsado aceptar "+posicion.toString()
                )
            }.setNegativeButton("Cancelar"){ dialogInterface, posicion ->
                Log.v(
                    "dialogos",
                    "Pulsado cancelar "+posicion.toString()
                )
            }.setNeutralButton("Cancelar"){ dialogInterface, posicion ->
                Log.v(
                    "dialogos",
                    "Pulsado neutral "+posicion.toString()
                )
            }

        return builder.create()
    }
}

```

Si nos damos cuenta el código es muy similar al visto anteriormente, tan solo se ha añadido la funcionalidad de los botones. Para ello el método ha pedido dos paramentos: el texto que tendrá el boton y la función de flecha (o listener asociado) la cual admite dos parámetros: la interfaz que ha generado el evento y la posición del boton pulsado:

```java
        builder.setTitle("Cuadro de confirmacion")
            .setMessage("Mensaje de confirmación para el usuario, ¿Confirmas la acción?")
            .setPositiveButton("OK") { dialogInterface, posicion ->
                Log.v(
                    "dialogos",
                    "Pulsado aceptar "+posicion.toString()
                )
            }.setNegativeButton("Cancelar"){ dialogInterface, posicion ->
                Log.v(
                    "dialogos",
                    "Pulsado cancelar "+posicion.toString()
                )
            }.setNeutralButton("Cancelar"){ dialogInterface, posicion ->
                Log.v(
                    "dialogos",
                    "Pulsado neutral "+posicion.toString()
                )
            }

```

En el caso de querer tener más de una opción a seleccionar dentro del cuadro de diálogo, sería necesario utilizar un cuadro de diálogo de selección

## Diálogo de selección

Su construcción es muy similar a los casos anteriores, la única diferencia es que a la hora de trabajar con el builder es necesario incorporar un método nuevo que es el setItems, el cual admite un array de elementos (también objetos de los cuales cuales cogerá el método toString para representar el dato) y quitar el método setMessage ya que ambos elementos ocupan la misma posición. Esto es importante ya que luego a la hora de determinar cual ha sido el seleccionado se utilizará un parámetro que indique la posición, siendo 0 el primer elemento de la lista.

```java
class DialogoSeleccion : DialogFragment() {

    lateinit var elementos: Array<String>

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        elementos = arrayOf("Opción 1", "Opción 2", "Opción 3")

        var builder = AlertDialog.Builder(requireContext());
        builder.setTitle("Cuadro de selección")
            //.setMessage("Que opción quieres hacer")
            .setItems(elementos) { dialgoInterface, posicion ->
                 Toast.makeText(context, elementos.get(posicion), Toast.LENGTH_SHORT).show()
            }

        return builder.create()
    }
}

```

Es importante tener en cuenta que este tipo de cuadro de diálogo no necesita botón, ya que el diálogo se oculta en el momento que se realice una selección. Es posible que queramos agregarle un botón cancelar par que no tengamos necesidad de seleccionar nada, para lo cual tendríamos que agregar un boton negative sin acción en el listener

```java
setNegativeButton("Cerrar"){dialogo, posicion->null}

```

## Diálogos de selección simple y múltiple

### Selección simple

Estos dos tipos de cuadro de diálogo son muy similares. La diferencia entre ellos es el tipo de selección que se puede hacer, solo un elemento y o varios
En el caso de querer tener una selección simple utilizaremos el método setOnSingle tener una selección

```java
class DialogoSingle : DialogFragment() {

    lateinit var elementos: Array<String>

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        elementos = arrayOf("Opción 1", "Opción 2", "Opción 3")

        var builder = AlertDialog.Builder(requireContext());
        builder.setTitle("Cuadro de selección")
            //.setMessage("Que opción quieres hacer")
            .setSingleChoiceItems(elementos, -1) { dialogo, posicion ->
                run {
                    Log.v("seleccion","seleccion realizada "+ elementos[posicion])
                }
            }

        return builder.create()
    }
}

```

En este caso el método setSingleChoiceItems pide tres parámetros: el dialogo, la posición del seleccionado y la interfaz que hace de ejecución. Es importante tener en cuenta que en este tipo de cuadro de diálogo a diferencia de los anteriores, si es necesario tener un botón que permita cerrar el cuadro de diálogo (o un método dismiss() dentro de la pulsación)

```java
class DialogoSingle : DialogFragment() {

    lateinit var elementos: Array<String>
    lateinit var seleccion: String;
    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        elementos = arrayOf("Opción 1", "Opció 2", "Opción 3")
        var builder = AlertDialog.Builder(requireContext());
        builder.setTitle("Cuadro de selección")
            //.setMessage("Que opción quieres hacer")
            .setSingleChoiceItems(elementos, -1) { dialogo, posicion ->
                run {
                    Log.v("seleccion", "seleccion realizada " + elementos[posicion])
                    seleccion = elementos[posicion]
                    //dismiss()
                }
            }
            .setPositiveButton("Aceptar") { dialogo, posicion->
                Toast.makeText(
                    context,
                    "Selección: " + seleccion,
                    Toast.LENGTH_SHORT
                ).show()
            }

        return builder.create()
    }
}

```

Como se puede ver, y al igual que en los casos anteriores, la gestión de la pulsación se realiza mediante un listener que trae como parámetros dos elementos: el propio diálogo y la posición del elemento seleccionado.

### Selección multiple

Muy similar al anterior, con la diferencia que el usuario podrá seleccionar más de una opción al mismo tiempo. Para ello es necesario utilizar el método setMultiChoiceItems, pasando como parámetros el conjunto de acciones, un array de booleanos que indican cual de los elementos están marcados por defecto y el listener que en este caso es OnMultiChoiceListener, el cual tiene como parámetros el diálogo, la posición del seleccionado y un booleano que indica el estado del elemento pulsado

```java
setMultiChoiceItems(elementos, null) { dialogo, posicion, boolean ->}

```

```java
class DialogoMulti : DialogFragment() {

    lateinit var elementos: Array<String>
    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        elementos = arrayOf("Opción 1", "Opció 2", "Opción 3")
        var builder = AlertDialog.Builder(requireContext());
        builder.setTitle("Cuadro de selección")
            //.setMessage("Que opción quieres hacer")
            .setMultiChoiceItems(elementos, null) { dialogo, posicion, boolean ->
                run {
                    Log.v("multiple","Posición seleccionada: ${posicion.toString()}")
                    Log.v("multiple","Valor del seleccionado: ${boolean}")
                }
            }
            .setPositiveButton("Aceptar") { dialogo, posicion ->
               null
            }

        return builder.create()
    }
}

```

Al igual que pasa en el caso del diálogo de selección simple, es necesario (y en este caso con más sentido) que añadamos un botón aceptar y/o cancelar para cerrar el cuadro de diálogo con el resultado del mismo

```java
class DialogoMulti : DialogFragment() {

    lateinit var elementos: Array<String>
    lateinit var elementosSeleccionados: ArrayList<String>

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        elementosSeleccionados = ArrayList();
        elementos = arrayOf("Opción 1", "Opción 2", "Opción 3")
        var builder = AlertDialog.Builder(requireContext());
        builder.setTitle("Cuadro de selección")
            //.setMessage("Que opción quieres hacer")
            .setMultiChoiceItems(elementos, null) { dialogo, posicion, boolean ->
                run {
                    Log.v("multiple", "Posición seleccionada: ${posicion.toString()}")
                    Log.v("multiple", "Valor del seleccionado: ${boolean}")
                    if (boolean) {
                        elementosSeleccionados.add(elementos[posicion])
                    } else {
                        elementosSeleccionados.remove(elementos[posicion])
                    }
                }
            }
            .setPositiveButton("Aceptar") { dialogo, posicion ->
                run {
                    Log.v(
                        "multiple",
                        "Selección finalizada ${elementosSeleccionados.size.toString()}"
                    )
                    elementosSeleccionados.forEach {Log.v("multiple","$it") }
                }
            }

        return builder.create()
    }
}

```

En este ejemplo, cada vez que un elemento es pulsado y el valor que se captura es un true, el elemento se mete dentro de un ArrayList previamente instanciado. En el caso de capturar un false se elimina del array. Cuando se pulsa el botón de confirmar se muestra el tamaño del mismo y sus elementos

Hasta este punto se han visto todos los cuadros de diálogo que tienen una creación por defecto. Sin embargo hay ocasiones donde no basta con las posibilidades que me dá el sistema operativo, sino que se necesita construir un cuadro de diálogo personalizado, con una vista propia. Para ello y tal y como se verá en el siguiente punto, es necesario crear un archivo xml nuevo que represente la vista y asociarlo a la clase del diálogo.

## Diálogos personalizados

Como se acaba de comentar, hay ocasiones en los que el programador necesita realizar un cuadro de diálogo que se sale de lo estándar, por lo que se necesita una vista especial. Aquí es donde entran los cuadros de diálogo personalizados. Lo primero que es necesario para poder tener un cuadro de diálogo personalizado es la creación de la vista, por lo que se creará un archivo xml con la vista que se quiera utilizar:

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:padding="50dp"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <ImageView
        android:id="@+id/imageView"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        tools:srcCompat="@tools:sample/avatars" />

    <EditText
        android:hint="Introduce correo de usuario"
        android:layout_marginTop="20dp"
        android:id="@+id/edit_nombre"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:ems="10"
        android:inputType="textEmailAddress"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toBottomOf="@+id/imageView" />

    <EditText
        android:hint="Introduce pass de usuario"
        android:layout_marginTop="10dp"
        android:id="@+id/edit_password"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:ems="10"
        android:inputType="textPassword"
        app:layout_constraintEnd_toEndOf="@+id/edit_nombre"
        app:layout_constraintStart_toStartOf="@+id/edit_nombre"
        app:layout_constraintTop_toBottomOf="@+id/edit_nombre" />

    <CheckBox
        android:id="@+id/checkBox"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Recordar sesión"
        app:layout_constraintEnd_toEndOf="@+id/edit_password"
        app:layout_constraintTop_toBottomOf="@+id/edit_password" />

    <Button
        android:layout_marginTop="20dp"
        android:id="@+id/button_login"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="LogIn"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toBottomOf="@+id/checkBox" />

    <TextView
        android:id="@+id/textView"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="20dp"
        android:text="Recordar pass"
        app:layout_constraintEnd_toEndOf="@+id/edit_password"
        app:layout_constraintTop_toBottomOf="@+id/button_login" />

    <TextView
        android:layout_marginTop="20dp"
        android:id="@+id/textView2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Crear cuenta"
        app:layout_constraintStart_toStartOf="@+id/edit_password"
        app:layout_constraintTop_toBottomOf="@+id/button_login" />
</androidx.constraintlayout.widget.ConstraintLayout>

```

Esta vista representa el típico cuadro de diálogo de login. Una vez se tiene la parte gráfica, es necesario crear la parte lógica. En este caso la parte lógica es manejada desde el cuadro de diálogo, por lo que lo primero necesario será asociar ambas partes. Para ello, en una clase que haya extendido de DialogFragment traemos el xml que se ha creado mediante un objeto de tipo LayoutInflater. Este tipo de objetos permite manejar ficheros de tipo layout e incorporarlos dentro de las clases. Esta clase tiene un método estático from() el cual pide un contexto (ya que no se puede crear un cuadro de diálogo de la nada), para lo que es muy útil el método onAttach (primer método del ciclo de vida del diálogo)

```java
class DialogoPerso : DialogFragment() {

    lateinit var vista: View;

    override fun onAttach(context: Context) {
        super.onAttach(context)
        vista = LayoutInflater.from(context).inflate(R.layout.dialog_perso,null);
    }
}

```

Con el elemento layout traído al código, el siguiente paso es el de ponerlo dentro del diálogo. Para ello se utiliza el método setView dentro del builder que hemos usado en los casos anteriores

```java
class DialogoPerso : DialogFragment() {

    lateinit var vista: View;

    override fun onAttach(context: Context) {
        super.onAttach(context)
        vista = LayoutInflater.from(context).inflate(R.layout.dialog_perso,null);
    }

    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {

        var builder = AlertDialog.Builder(requireContext())
        builder.setView(vista)
        return builder.create()

    }
}

```

Con esto ya sería suficiente y la vista sería mostrada cuando el cuadro de diálogo sea llamado. El siguiente punto es el recuperar los datos que se metan en los campos o simplemente trabajar con la pulsación del botón. Para ello es necesario instanciar cada uno de los elementos (o utilizar viewBinding). Para ello es necesario utilizar el método findViewById pero no sobre this (que es el diálogo), sino sobre view que es el objeto donde se ha guardado el xml y por lo tanto tiene todos los elementos. Una vez instanciados se puede hacer con ellos lo que se quiera

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
            run {
                Log.v("perso", editNombre.text.toString())
                Log.v("perso",editPass.text.toString())
                dismiss()
            }
        }
    }
}

```