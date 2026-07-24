# 4. Modificación en tiempo real

Status: Not started
Type: Stations
🪴 Units: 3. Interfaz gráfica (../Unidades/3%20Interfaz%20gr%C3%A1fica%20c91eeadeed708332b4c50158c00c238d.md)

# Modificación de interfaces en tiempo real

En ocasiones es interesante independizar la interfaz a la configuración del disposición del dispositivo. En unidades anteriores ya se vio este tema con la internacionalización de las cadenas de texto, pero existen otras muchas posibilidades para poder hacer aplicaciones independientes. Una de las más utilizadas es la del cambio de orientación de pantalla, es decir que la aplicación se muestre diferente si el teléfono está en horizontal (landscape) o en vertical (portraint). Para poder hacer esto tendremos que crear tantos recursos xml como configuraciones queramos gestionar.

Antes de empezar a explicar como se realizan estas tareas, es importante recordar que cada vez que el teléfono sufre un cambio de configuración (bien sea de idioma, de giro, de aplicaciones a segundo plano como pueda ser recibir una llamada entrante), la aplicación vuelve a ejecutar el ciclo de vida, pasando por el método onCreate y volviendo a cargar toda la información. Esto es muy importante tenerlo en cuenta ya que se deberán gestionar estos cambios para que la información sea persistente cada vez que se producen. Para poder ver esto vamos hacer una aplicación que permita realizar pulsaciones con un botón y estas incremente o decrementen en uno un contador que será mostrado en un textview. El proyecto contará con una sola pantalla con el siguiente archivo xml

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <androidx.constraintlayout.widget.Guideline
        android:id="@+id/guideline2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:orientation="horizontal"
        app:layout_constraintGuide_percent="0.5" />

    <TextView
        android:id="@+id/text_contador"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="0"
        android:textSize="40sp"
        app:layout_constraintBottom_toTopOf="@+id/guideline2"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

    <Button
        android:layout_width="0dp"
        android:layout_height="0dp"
        android:text="+"
        android:textSize="40sp"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toStartOf="@+id/guideline3"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="@+id/guideline2"
        android:id="@+id/button_incremento"
        />

    <Button
        android:layout_width="0dp"
        android:layout_height="0dp"
        android:text="-"
        android:textSize="40sp"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="@+id/guideline3"
        app:layout_constraintTop_toTopOf="@+id/guideline2"
        android:id="@+id/button_decremento"/>

    <androidx.constraintlayout.widget.Guideline
        android:id="@+id/guideline3"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:orientation="vertical"
        app:layout_constraintGuide_percent="0.50121653" />

</androidx.constraintlayout.widget.ConstraintLayout>

```

Como se puede ver se han creado dos guías (una horizontal y otra vertical) para poder controlar el aspecto de la parte superior (50%) y la parte inferior (50%)

![t3_configuraciones1.png](4%20Modificaci%C3%B3n%20en%20tiempo%20real/t3_configuraciones1.png)

Una vez creado la interfaz gráfica se procede a incorporar todos los elementos en la parte lógica, quedando el archivo MainActivity.kt de la siguiente forma:

```java
class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater);
        val view: View = binding.root
        setContentView(view)
    }
}

```

A partir de este momento todos los elementos estarán disponibles en la clase. Lo siguiente será detectar las pulsaciones de los botones y setear en el textview un contador que tendrá una cuenta, Para ello se realizan los escuchadores y acciones vistas en los temas anteriores

```java
class MainActivity : AppCompatActivity(), View.OnClickListener {

    private lateinit var binding: ActivityMainBinding
    private var contador: Int = 0
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater);
        val view: View = binding.root
        setContentView(view)
        contador = 0;
        binding.textContador.text = contador.toString()
        acciones()
    }

    private fun acciones() {
        binding.buttonDecremento.setOnClickListener(this@MainActivity)
        binding.buttonIncremento.setOnClickListener(this@MainActivity)
    }

    override fun onClick(p0: View?) {
        when (p0?.id) {
            R.id.button_decremento -> contador--;
            R.id.button_incremento -> contador++
        }
        binding.textContador.text = contador.toString()
    }
}

```

Nada más arrancar la aplicación se inicializa la variable contador a 0 y se pone en el textView. También se ha programado las pulsaciones de ambos botones para que cada vez que uno se pulsado la cantidad que tiene la variable se incremente o decremente dependiendo del valor y se ponga nuevamente dentro del texto. Con este código funcionaría perfectamente si no realizásemos ningún cambio de configuración (orientación por ejemplo).

![t3_configuraciones2.png](4%20Modificaci%C3%B3n%20en%20tiempo%20real/t3_configuraciones2.png)

En el caso de realizar un cambio de orientación pasan dos cosas:

1. Que la disposición de los elementos de la pantalla sigue siendo la misma cuando el tamaño de la pantalla en horizontal ha cambiado
2. Que el contador se ha puesto automáticamente a 0 ya que ha detectado un cambio de configuración.

Para solucionar ambos casos vamos a ver como hacerlo de forma individual

## Gestionar la orientación

Para poder gestionar los cambios de orientación y que al girar el dispositivo se pueda mostrar de forma adecuada pantalla y no como se hace en vertical, es necesario crear un nuevo archivo xml llamado de la misma forma que el layout (en este caso activity_main.xml). Esto se puede hacer creándolo manualmente o creándolo desde el asistente. Para ello vamos a la carpeta res/layout botón derecho -> new layout resource file he indicamos el mismo nombre del archivo que queremos rotar (en nuestro caso activity_main.xml). Además de esto es necesario indicar en la listar de cualificadores de la parte inferior el de ortientation y dentro de este el de landscape

![t3_configuraciones3.png](4%20Modificaci%C3%B3n%20en%20tiempo%20real/t3_configuraciones3.png)

Esto lo que hará será crear un archivo idéntico al anterior pero con el sufijo *land* (indicando que será el que tiene que coger cuando el dispositivo está en horizontal). En el nuevo archivo creado se copiarán los mismos elementos que en el archivo inicial y se realizará la nueva disposición que se quiera.

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <androidx.constraintlayout.widget.Guideline
        android:id="@+id/guideline2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:orientation="horizontal"
        app:layout_constraintGuide_percent="0.5" />

    <TextView
        android:id="@+id/text_contador"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="0"
        android:textSize="40sp"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toStartOf="@+id/guideline3"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

    <Button
        android:id="@+id/button_incremento"
        android:layout_width="0dp"
        android:layout_height="0dp"
        android:text="+"
        android:textSize="40sp"
        app:layout_constraintBottom_toTopOf="@+id/guideline2"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="@+id/guideline3"
        app:layout_constraintTop_toTopOf="parent" />

    <Button
        android:id="@+id/button_decremento"
        android:layout_width="0dp"
        android:layout_height="0dp"
        android:text="-"
        android:textSize="40sp"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="@+id/guideline3"
        app:layout_constraintTop_toTopOf="@+id/guideline2" />

    <androidx.constraintlayout.widget.Guideline
        android:id="@+id/guideline3"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:orientation="vertical"
        app:layout_constraintGuide_percent="0.50121653" />

</androidx.constraintlayout.widget.ConstraintLayout>

```

En este caso se ha realizado el mismo diseño pero cambiando las restricciones para que los botones se muestren en horizontal

![t3_configuraciones4.png](4%20Modificaci%C3%B3n%20en%20tiempo%20real/t3_configuraciones4.png)

Con este simple cambio ya se ha realizado el ajuste de la pantalla dependiendo de la orientación del teléfono. Esto se debe a que cuando el teléfono cambia de configuración, el ciclo de vida se ejecuta nuevamente y el método onCreate es ejecutado directamente, por lo que el método setContentView asocia el layout nuevamente (en este caso cogiendo el que tiene el sufijo land ya que es el de la orientación que tiene). Lo mismo pasaría con el resto de cambios de configuración (idioma, disposición de teclado, etc...).

Además de ejecutarse el método onCreate, se ejecuta por defecto el método onConfiguracionChanged(), el cual debería ser sobreescrito si se quiere utilizar

```java
    override fun onConfigurationChanged(newConfig: Configuration) {
        super.onConfigurationChanged(newConfig)
        Log.v("configuracion", "cambio detectado en la configuración")
        Log.v("configuracion", newConfig.toString())
    }

```

En el caso de no querer que los cambios de configuración le afecten a una activity, sería necesario indicar que cambio no afecta en el fichero AndroidManifest.xml

```xml
        <activity
            android:name=".MainActivity"
            android:configChanges="orientation|locale"
            android:exported="true" >
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>

```

Indicando esto tanto los cambios de orientación como los de localización no se verán afectados automáticamente y los tendremos que manejar nosotros en el código

Por último, para terminar este punto vamos a imaginar que en en layout de la parte horizontal hay un botón que no está presente en la parte vertical. Tan solo tendríamos que incluirlo en la parte horizontal

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <androidx.constraintlayout.widget.Guideline
        android:id="@+id/guideline2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:orientation="horizontal"
        app:layout_constraintGuide_percent="0.5" />

    <TextView
        android:id="@+id/text_contador"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="0"
        android:textSize="40sp"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toStartOf="@+id/guideline3"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

    <Button
        android:id="@+id/button_incremento"
        android:layout_width="0dp"
        android:layout_height="0dp"
        android:text="+"
        android:textSize="40sp"
        app:layout_constraintBottom_toTopOf="@+id/button_decremento"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="@+id/guideline3"
        app:layout_constraintTop_toTopOf="parent" />

    <Button
        android:id="@+id/button_decremento"
        android:layout_width="0dp"
        android:layout_height="0dp"
        android:text="-"
        android:textSize="40sp"
        app:layout_constraintBottom_toTopOf="@+id/button_reset"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="@+id/guideline3"
        app:layout_constraintTop_toBottomOf="@+id/button_incremento" />

    <Button
        android:id="@+id/button_reset"
        android:layout_width="0dp"
        android:layout_height="0dp"
        android:text="Reset"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="@+id/guideline3"
        app:layout_constraintTop_toBottomOf="@+id/button_decremento" />

    <androidx.constraintlayout.widget.Guideline
        android:id="@+id/guideline3"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:orientation="vertical"
        app:layout_constraintGuide_percent="0.50121653" />

</androidx.constraintlayout.widget.ConstraintLayout>

```

En este caso se ha incluido un tercer botón llamado botton_reset que lo que hará será resetear el contador y ponerlo a 0 nuevamente. Una vez se tiene declarado el elemento en la parte gráfica tan solo sería necesario utilizarlo en la parte lógica

```java
    private fun acciones() {
        binding.buttonDecremento.setOnClickListener(this@MainActivity)
        binding.buttonIncremento.setOnClickListener(this@MainActivity)
        binding.buttonReset?.setOnClickListener(this@MainActivity)
    }

    override fun onClick(p0: View?) {
        when (p0?.id) {
            R.id.button_decremento -> contador--
            R.id.button_incremento -> contador++
            R.id.button_reset -> contador = 0

        }
        binding.textContador.text = contador.toString()
    }

```

En este caso, el método de las acciones ha incluido una nueva línea, indicando que la pulsación del nuevo botón también se regirá sobre el escuchador onClick. La diferencia con antes es que se ha incluido un ? para indicar que puede ser nulo (recordemos que si el móvil está en vertical el botón no estará), de forma que si el botón provoca un null la aplicación no se detendrá.

![t3_configuraciones5.png](4%20Modificaci%C3%B3n%20en%20tiempo%20real/t3_configuraciones5.png)

## Mantenimiento de datos

Una vez se ha solucionado el problema de la interfaz, vamos ahora al problema de los datos que se pueden resetear. En la aplicación que estamos haciendo, cada vez que el dispositivo detecta un cambio de configuración el contador vuelve a 0. Esto pasa porque como ya se ha comentado el cambio de configuración provoca que se ejecute de nuevo el método onCreate y este inicializa el contador a 0 y lo setea. Si queremos que los datos sean guardados cada vez que se produce un cambio tendremos que hacer dos cosas:

1. Guardarlos con el método onSavedInstanceState y su objeto de tipo Bundel

Este método sobreescrito es ejecutado justo antes del cambio de configuración. El parámetro outState de tipo Bundel guarda datos con un par clave - valor (tal y como vimos en el paso de parámetros entre pantallas), por lo que si queremos enviar algo para que luego sea recuperado primero debemos guardarlo en este objeto

```java
    override fun onSaveInstanceState(outState: Bundle) {
        super.onSaveInstanceState(outState)
        outState.putInt("contador",contador);
    }

```

En este caso cuando se detecte un cambio de configuración se guardará en el estado saliente el valor de la variable contador, que irá asociada a la palabra contador

1. Recuperarlos con el objeto de tipo Bundel del método onCrete

Una vez producido el cambio de configuración se ejecutará el método onCreate. Este método cuenta con un parámetro de tipo Bundel, que representa el estado entrando (por si alguien ha mandado algún estado como en el punto uno) y se utiliza para recuperar los datos con un par clave valor

```java
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater);
        val view: View = binding.root
        setContentView(view)

        /*
        sería lo mismo que en la línea siguiente
        if (savedInstanceState!=null){
            contador = savedInstanceState.getInt("contador")
        }*/

        contador = savedInstanceState?.getInt("contador") ?: 0
        binding.textContador.text = contador.toString()
        acciones()
    }

```

## Modo display