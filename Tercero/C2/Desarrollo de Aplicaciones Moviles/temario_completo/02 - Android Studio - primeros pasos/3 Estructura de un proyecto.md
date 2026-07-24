# 3. Estructura de un proyecto

Status: Not started
Type: Stations
🪴 Units: 2. Android Studio: primeros pasos (../Unidades/2%20Android%20Studio%20primeros%20pasos%201c2eeadeed70829a8199011feab9aa2b.md)

Cuando se crea un proyecto de Android estudio se genera una cantidad de contenido importante de forma automática. Muchas veces, uno de los principales problemas es no entender cual es el uso que se le tiene que dar a cada uno de los archivos / directorios creados o como poder generar nuevos del mismo tipo. Antes de empezar a comentar la estructura hay que tener en cuenta que todo aquello que sea utilizado por el proyecto tendrá que estar enlazado o bien mediante archivos colocados en su sitio o bien mediante librerías / conexiones de red.

Una vez creado el proyecto, habiendo creado una EmptyActivity (se trata de una actividad que no tienen ningún tipo de funcionalidad pero tiene la base para poder empezar a trabajar), en la parte de la izquierda del espacio de trabajo aparecen todos los elementos generados

![](http://www.developandsys.es/wp-content/uploads/2017/04/estructura-300x198.png)

Dependiendo de cual sea la vista seleccionada aparecerán más o menos elementos. En el caso de tener seleccionada la vista android solo aparecerán los elementos que tienen contenido. Si cambiaremos a la vista proyect aparecerían todos los elementos del proyecto aunque no tengan contenido

### **AndroidManifest.xml**

Se trata del archivo más importante dentro de un proyecto android ya que sin él la aplicación no sería capaz de comprender los elementos que forman parte del proyecto. Podemos decir que se trata del punto de entrada de la aplicación donde se declaran parte de los contenidos de la aplicación. Por defecto se crea este fichero y solo habrá que ir añadiendo elementos de forma manual. Los elementos se definen mediante etiquetas donde cada una tiene sus propios atributos. Es importante saber que al menos debe existir una activity que sea main y launcher para así poder arrancar el proyecto cuando se pinche el icono de la aplicación

```xml
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="developandsystem.componentesinicial">

    <uses-permission android:name="android.permission.CALL_PHONE" />

    <application
        android:allowBackup="true"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:supportsRtl="true"
        android:theme="@style/AppTheme">
        <activity android:name=".MainActivity">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>
</manifest>
```

Cada una de las activitys generadas dentro de la aplicación tendrán que estar reflejadas indicando sus particularidades si las tienen. Además también se declararán en este archivo elementos como servicios, permisos, vbroadcast, etc…

### kotlin **-Nombre del paquete (sin categorizar)**

En esta parte se situarán todos los archivos .java que darán funcionalidad al proyecto. Es muy recomendable crear subpaquetes para organizar el código de forma lógica ya que cuando existan numerosos elementos la claridad en el código y en el proyecto será básica. Inicialmente nos encontramos con un archivo MainActivity.java que hace referencia a la empty activity que hemos generado al crear el proyecto y dará funcionalidad lógica a la pantalla. Además de este archivo, toda activity va a estar asociada a un layout situado dentro de la carpeta res el cual dará el aspecto visual a la pantalla, linkado mediante el método setContentView

```
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}
```

### **Res**

Se trata de la carpeta donde se van a ubicar todos los archivos utilizados como recursos dentro del proyecto, como son las imágenes, strings, valores constantes, menús, layouts, etc… Inicialmente tan solo aparecen 4 elementos dentro de esta carpeta res

***Drawable***: Se guardarán gráficos que pueden ser rescalados dentro la activity dependiendo de cosas como densidad de pixels, posición, tamaño de pantalla, etc…Pueden aparecer elementos en png o archivos en xml que definan el comportamiento de una imagen (animación)

***Layout***: Se puede definir como la interfaz gráfica que muestra los elementos de una pantalla. Por lo general está asociado a una activity pero multitud de elementos utilizan este tipo de archivo: fragments, adaptadores, etc… Está escrito en xml y se puede manejar o bien de forma gráfica o bien mediante código.

```
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@+id/activity_main"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:paddingBottom="@dimen/activity_vertical_margin"
    android:paddingLeft="@dimen/activity_horizontal_margin"
    android:paddingRight="@dimen/activity_horizontal_margin"
    android:paddingTop="@dimen/activity_vertical_margin"
    tools:context="developandsystem.componentesinicial.MainActivity">
    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hello World!" />
</RelativeLayout>
```

***MipMap***

: Muy parecida a la carpeta de drawable, con la diferencia que aquí se guardarán elementos gráficos que no queremos que sean rescalados. Para evitar que se puedan rescalar los elementos, dentro de esta carpeta se crearán subcarpetas con categorizados para asignar elementos dependiendo de factores (p.e tamaño de pantalla)    

![](http://www.developandsys.es/wp-content/uploads/2017/04/estructura_mipmap.png)

***Values***: Se guardarán todos los datos que sean constantes y accedido de forma repetida por la aplicación. Inicialmente se crea un fichero string.xml donde se guardan todas las palabras que son utilizadas, dimens.xml donde se guardan todas las dimensiones que son utilizadas, colors.xml donde se guardarán todos los colores que son utilizados y styles.xml donde se guardan la definición de todos los estilos utilizados. Es importante utilizar muy bien estos ficheros ya que si no metemos constantes, a la hora de trabajar en determinados aspectos como son la internacionalización o la modificación masiva de elementos el trabajo se verá incrementado de forma muy considerable

```
<resources>

    <!-- Base application theme. -->
    <style name="AppTheme" parent="Theme.AppCompat.Light.DarkActionBar">
        <!-- Customize your theme here. -->
        <item name="colorPrimary">@color/colorPrimary</item>
        <item name="colorPrimaryDark">@color/colorPrimaryDark</item>
        <item name="colorAccent">@color/colorAccent</item>
    </style>

</resources>
```