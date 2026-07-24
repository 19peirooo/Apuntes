# 5. Intents

Status: Not started
Type: Stations
🪴 Units: 2. Android Studio: primeros pasos (../Unidades/2%20Android%20Studio%20primeros%20pasos%201c2eeadeed70829a8199011feab9aa2b.md)

Otro de los elementos básicos de una aplicación android son los intents. Este tipo de objeto permite desde código realizar tareas como navegar entre pantallas, lanzas aplicaciones del sistema como el navegador, mapas, cámara, etc... en resumen una acción que puede ser definida por el usuario o definida en la URI con la que se configura el intent. Antes de empezar a ver las opciones de este tipo de objetos, comentar que su creación y lanzamiento se puede realizar de forma explicita (creando el objeto y sus datos en la parte lógica con el constructor del intent) o implícitos (definiendo sus acciones en el fichero AndroidManifest.xml o desde la URI que define la acción). A continuación vamos a ver los principales usos que tiene este tipo de objetos

## Navegar a una segunda actividad

Uno de los principales usos de los intents es el de navegar a otra actividad, con o sin datos asociados. Para ello se va a crear un proyecto que conste de dos actividades, cada una de las cuales tendrá los siguientes elementos:

- MainActivity: constará de un botón en el centro de la pantalla con el texto Pasar pantalla.

```xml
<!--activity_mainxml-->

<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Pasar pantalla"
        android:id="@+id/boton_pasar"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintLeft_toLeftOf="parent"
        app:layout_constraintRight_toRightOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>

```

```java
// MainActivity.kt
private lateinit var bindind: ActivityMainBinding
class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutinglater)
        setContentView(binding.root)
    }
}

```

- SecondActivity: constará de una etiqueta en el centro de la pantalla con el texto Pantalla dos. Para poder crear una segunda pantalla es necesario crear tanto el fichero .java como el .xml que se ha visto y declarar la activity dentro del fichero AndroidManifest.xml. Además de este proceso, también es posible utilizar el asistente de creación pulsando botón derecho new -> activity -> empty activity indicando el nombre de la actividad. Este proceso creará automáticamente todos los ficheros relacionados y actualizará el fichero AndroidManifest con la nueva actividad.

```xml
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="<http://schemas.android.com/apk/res/android>"
    package="com.develop.intents">

    <application
        android:allowBackup="true"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:roundIcon="@mipmap/ic_launcher_round"
        android:supportsRtl="true"
        android:theme="@style/Theme.Intents">
        <activity
            android:name=".SecondActivity"
            android:exported="false" />
        <activity
            android:name=".MainActivity"
            android:exported="true">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>

</manifest>

```

Una vez hecho esto ya podemos empezar a crear el paso de pantallas. En el caso de querer hacer un cambio de pantalla explicito sería necesario crear una variable de tipo Intent y pasarle como parámetros el origen (la clase donde estamos - this - y el destino - la clase a la que queremos pasar-). Una vez creado este objeto para poder realizar el cambio de pantalla se utiliza el método `startActivity`

```java
// el this se podría poner como this@MainActivity, para poder definir que hacemos referencia al ámbito de la clase entera
val intent: Intent = Intent(this, SecondActivity::class.java)
startActivity(intent)

```

Ejecutando este código la segunda pantalla (en este caso SecondActivity) pasaría a primer plano y la activity actual (MainActivity) pasaría a segundo plano. Con el ejemplo que hemos empezado, podríamos configurar el botón para que al ser pulsado se realice el cambio de pantalla

```java
class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        val view: View = binding.root
        setContentView(view)
        acciones()
    }

    private fun acciones() {
        binding.botonPasar.setOnClickListener {
            val intent: Intent = Intent(this, SecondActivity::class.java)
            startActivity(intent)
        }
    }
}

```

En el caso de querer realizar un intent implícito, es el sistema el que se encarga de decidir que pantalla es la que se tiene que hacer. Generalmente, el sistema realiza esto dependiendo de la acción que se indique y de la URI (Universal Resource Identifier) configurada. Para ellos y al igual que se ha hecho antes es necesario crear una variable de tipo intent, indicando en el constructor la acción (Action_View es la más genérica). Además de esto es necesario indicar los datos que acompañarán a la petición (ya que al abrir una pantalla como por ejemplo el navegador, es necesario indicar la página que será mostrada)

```java
val intent: Intent = Intent(Intent.ACTION_VIEW);
intent.setData(Uri.parse("<https://www.developandsys.es>"))
startActivity(intent)

```

Al igual que antes si se quiere realizar con la pulsación del botón se realizará mediante el siguiente código

```java
class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        val view: View = binding.root
        setContentView(view)
        acciones()
    }

    private fun acciones() {
        binding.botonPasar.setOnClickListener {
            val intent: Intent = Intent(Intent.ACTION_VIEW);
            intent.setData(Uri.parse("<https://www.developandsys.es>"))
            startActivity(intent)
        }
    }
}

```

En este caso la acción indica que la pantalla que se tiene que abrir es un navegador (al utilizar el protocolo https). En el caso de no tener una aplicación que sea capaz de abrir este tipo de acción el código del intent daría error, por lo que sería necesario comprobar antes si existe alguna aplicación capaz de gestionar la petición:

```java
val intent: Intent = Intent(Intent.ACTION_VIEW);
intent.setData(Uri.parse("<https://www.developandsys.es>"))
if (intent.resolveActivity(packageManager)!=null){
    startActivity(intent)
}

```

En el caso de que el método resolveActivity responda con un objeto diferente de nulo, quiere decir que existe una aplicacion que permite manejar la petición, En caso contrario habría que avisar al usuario que la acción no se podría llevar a cabo.

Las principales acciones asociadas a los intents son:

Como se ha indicado antes, por defecto el sistema es capaz de detectar la aplicación con la que se abrirá el intent, pero en el caso de querer indicar al usuario un mensaje para que el usuario seleccione con que aplicación quiere abrirlo se podría hacer mediante un objeto de tipo IntentChooser, el cual recibe por paramentos el intent con la acción que se quiere realizar y el texto que aparecerá con el selector de aplicaciones

```java
val intent = Intent(Intent.ACTION_VIEW);
intent.setData(Uri.parse("<https://www.developandsys.es>"))
val intentChooser = Intent.createChooser(intent,"Selecciona la aplicación para abrir la acción")
if (intent.resolveActivity(packageManager)!=null){
    startActivity(intentChooser)
}

```

## Pasar de activity con parámetros

Otra de las funcionalidades que es muy utilizada en los intents es la de arrancar una nueva actividad pero además de realizar ese cambio de pantalla, también pasar una serie de datos. Esto es posible si al intent utilizar para pasar de pantalla se se agregan los datos utilizando el método putExtra(), identificando los datos con un par clave valor al igual que en un Map. A la hora de recuperarlo se utilizará el método getExtra(), indicando la clave con la que se ha asociado el dato.Para poder explicar esto nos vamos a basar en el ejemplo que se ha utilizado anteriormente del paso de dos pantallas. Si recordamos lo visto anteriormente, lo que has ha hecho ha sido crear un Intent donde en constructor se ha declarado origen y destino, y una vez se tiene construido se ha utilizado el método startActivity(). Si seguimos el mismo ejemplo, imaginemos que en en la primera pantalla (MainActivity) se quiere capturar uno o varios datos desde un editText y al pulsar un botón pasarlo a la segunda pantalla para que esta lo recupere los datos y sean mostrados. Para ello poder hacer esto vamos a seguir los siguientes pasos:

1. En el archivo activity_main donde definimos la ui de la primera pantalla se va a incluir un editText con el id editNombre

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <EditText
        android:id="@+id/edit_nombre"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:hint="Introduce tu nombre"
        android:layout_marginBottom="16dp"
        app:layout_constraintBottom_toTopOf="@+id/boton_pasar"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent" />

    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Pasar pantalla"
        android:id="@+id/boton_pasar"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintLeft_toLeftOf="parent"
        app:layout_constraintRight_toRightOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>

```

1. En la parte lógica de la pantalla (el archivo MainActivity.kt) cuando el botón se pulsado se va a recoger el dato del editText y se va a pasar junto con el intent creado en el ejemplo anterior utilizando el método putExtra()

```java
val intent = Intent(this, SecondActivity::class.java)
intent.putExtra("nombre", binding.editNombre.text.toString())
startActivity(intent)

```

Con este nuevo intent, además de la acción de pasar entre pantalla, se ha agregado un dato que tiene como clave asociada la palabra nombre. Esta clave será utilizada en la pantalla destino para poder capturar el dato.

1. En el archivo second_activity.xml se va a crear un textView donde se mostrará el dato pasado desde la primera pantalla.

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".SecondActivity">

    <TextView
        android:id="@+id/text_recoger"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent" />
</androidx.constraintlayout.widget.ConstraintLayout>

```

1. Una vez se tiene el elemento preparado, en la segunda pantalla se podrá capturar mediante el intent que ha arrancado la pantalla y el método getExtra, indicando la clave del dato que se quiere recuperar

```java
intent.extras?.getString("nombre").toString();

```

En este caso la ejecución de extras está declarado como null safety ya que es posible que se declara como null. Una vez el dato sea recibido, se puede utilizar para poder ponerlo dentro de la etiqueta declarada en el centro de la pantalla

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".SecondActivity">

    <TextView
        android:id="@+id/text_recoger"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent" />
</androidx.constraintlayout.widget.ConstraintLayout>

```

```java
class SecondActivity : AppCompatActivity() {

    private lateinit var binding: ActivitySecondBinding
    private lateinit var textoRecibido: String;
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivitySecondBinding.inflate(layoutInflater)
        val view: View = binding.root
        setContentView(view)
        capturarDatos()
        acciones()

    }

    private fun capturarDatos() {
        textoRecibido = intent.extras?.getString("nombre").toString();
    }

    private fun acciones() {
        binding.textRecoger.setText(textoRecibido)
    }

}

```

## Arrancar actividad esperando respuesta

Otra de las posibilidades que dan los intents es la de, además de arrancar una segunda pantalla, esperar obtener un resultado. Un ejemplo claro de esto es arrancar la cámara para poder hacer una foto, y volver a la pantalla anterior para poder mostrarla. El flujo sería el siguiente

1. Desde MainActivity (con un imageView y un botón) se pulsa un boton y se abre la cámara con un intent
2. Con la cámara se hace una foto y al hacerla se vuelve a la pantalla inicial
3. Una vez estamos en MainActivity, esta se encargará de recibir el dato (en este caso la foto) y ponerla dentro del image view

Para hacer este ejemplo seguiremos los siguientes pasos

1. Se creará una activity llamada IntentActivity, y en el xml se pondrá un botón con el id boton_camara y un imageview con el id imagen_camara

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".IntentActivity">

    <Button
        android:id="@+id/boton_camara"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hacer foto"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

    <ImageView
        android:id="@+id/imagen_camara"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toBottomOf="@+id/boton_camara"
        tools:srcCompat="@tools:sample/avatars" />
</androidx.constraintlayout.widget.ConstraintLayout>

```

1. En la parte lógica se programa la pulsación del botón para que cuando este sea pulsado se arranque un intent de apertura de la cámara

```java

```