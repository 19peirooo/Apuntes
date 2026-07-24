# 1. Vistas

Status: Not started
Type: Stations
🪴 Units: 3. Interfaz gráfica (../Unidades/3%20Interfaz%20gr%C3%A1fica%20c91eeadeed708332b4c50158c00c238d.md)

# Vistas: uso y manejo de eventos

Ya se ha visto que toda pantalla en android cuenta tanto con una parte lógica como con un parte gráfica. La lógica está representada por un archivo .kt y la gráfica con un archivo .xml. Esta asociación entre ambas se realiza mediante el método setContentView ejecutado en el método onCreate

```kotlin
class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }
}

```

Este método es el encargado de asociar la parte lógica a la parte gráfica. Una vez se ha ejecutado esto, para poder traer elementos del xml y declarados en el archivo es necesario ejecutar el método findViewById, indicando el id de la vista que queramos traer. Por ejemplo si tenemos el siguiente xml asociado a la activity MainActivity

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hello World!"
        android:id="@+id/texto_main"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintLeft_toLeftOf="parent"
        app:layout_constraintRight_toRightOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>

```

Podemos ver que el elemento TextView tiene como atributo id `texto_main` indicado como @+id ya que se está creando en ese mismo momento. Con esta vista configurada podríamos declararla dentro del archivo MainACtivity.kt para poder utilizarla como quisiésemos con el método comentado anteriormente

```java
class MainActivity : AppCompatActivity() {

    private lateinit var texto: TextView;
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        texto = findViewById(R.id.texto_main) as TextView
    }
}

```

De esta forma la variable texto guardaría la vista y se podría utilizar como se quisiese

*Recordar que también podría utilizar el binding de código, lo cual evitaría hacer la inicialización de las variables*

```java
class MainActivity : AppCompatActivity() {

    private lateinit var texto: TextView;
    private lateinit var binding: ActivityMainBinding
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        val view: View = binding.root;
        setContentView(view)
        binding.textoMain
    }
}

```

Una vez visto el mecanismo para pode asociar una parte lógica con una parte gráfica, vamos a ver ahora cuales son los principales elementos  y el manejo de sus eventos. Los siguientes elementos que se verán a continuación son elementos básicos, es decir se excluyen las listas avanzadas con los adaptadores de datos que se verán en los siguientes temas. Las vistas que se verán son:

- Layouts: principalmente veremos tres; LinearLayout, ConstraintLayout y FrameLayout
- Button: botones normales
- EditText: campos de texto
- CheckBox: casillas de verificación
- RadioButton: casillas de verificación con interfaz redonda y posibilidad de formar un grupo
- Spinner: desplegable de selección

Antes de empezar a explicar cada una de ellas, en el siguiente punto vamos a explicar una serie de atributos que tienen todas y son obligatorios. En todos los casos es necesario indicar a cada una de las vistas que tamaño ocupan tanto en alto como en ancho. Estos dos atributos dentro de la definición xml de las vistas son layout_width y layout_height. Las configuraciones posibles para ambos atributos son:

- match_parent: esto indicará que el tamaño será el máximo posible. Por ejemplo si este atributo se lo ponemos a un layout root, esto indicará que se pegará a su padre, siendo este la pantalla. En el caso de declararse a una vista que está dentro del layout, la vista se pegará al tamaño máximo de su padre.
- wrap_content: se trata de la configuración contraria a la anterior. El elemento que tenga configurado el atributo con wrap_content tan solo ocupará lo necesario para mostrarse es decir el tamaño que necesita, ni más ni menos

El resto de atributos, como veremos en cada uno de los elementos más adelante pueden ir cambiando