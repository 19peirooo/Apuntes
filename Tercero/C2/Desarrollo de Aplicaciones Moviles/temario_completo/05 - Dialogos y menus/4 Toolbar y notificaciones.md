# 4. Toolbar y notificaciones

Status: Not started
Type: Stations
🪴 Units: 5. Diálogos y menús (../Unidades/5%20Di%C3%A1logos%20y%20men%C3%BAs%201a0eeadeed708261a57d0160f016c827.md)

Todo lo explicado anteriormente es válido, pero sin embargo existe una posibilidad cada vez más utilizada que es la de sustituir la parte superior por la de Toolbar. Esto otorgará al programador muchas más posibilidades de funcionalidad además de las que ya tiene el ActionBar. En el caso de querer utilizar un elemento de tipo ToolBar lo primero necesario es quitar el ya existente, ya que sino se duplicaría en espacio. Para ello, dentro de los estilos debemos seleccionar un estilo hijo de NoActionBar

```xml
<style name="Theme.Menus" parent="Theme.MaterialComponents.DayNight.NoActionBar">

```

A partir de este momento nuestra pantalla no mostrará una parte superior. Para incluir un toolbar es necesario agregarlo como elemento gráfico (en el xml), por lo que el layout de la actividad quedará de la siguiente forma

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <androidx.appcompat.widget.Toolbar
        android:id="@+id/toolbar"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:background="?attr/colorPrimary"
        android:minHeight="?attr/actionBarSize"
        android:theme="?attr/actionBarTheme"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

    <Button
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Pulsar"
        android:id="@+id/boton_contextual"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent" />

</androidx.constraintlayout.widget.ConstraintLayout>

```

Hay que tener en cuenta que dependiendo del layout que utilicemos esta disposición puede cambiar. También es posible incluirlo dentro de un fichero separado e incrustarlo dentro del layout con la etiqueta include (para así poder reutilizarlo). Una vez hecho esto tan solo falta setear esta toolbar como elemento que actúe como parte superior. Para ello es necesario ejecutar el siguiente código

```java
setSupportActionBar(binding.toolbar)

```

Tras la ejecución de este código podremos agregar tantas características y elementos a la barra superior, ya que siempre estaremos haciendo referencia a la parte superior de la activity

```java
setSupportActionBar(binding.toolbar)

```

A partir de este momento, todos lo métodos se creación de menú y gestión de la pulsación de los elementos del menú ser realiza automáticamente, por lo que tendríamos que aplicar los métodos vistos en los puntos anteiores

## Configurar el botón home de la barra superior

Toda action bar tiene por defecto un título que viene puesto por defecto con el nombre del proyecto, un espacio reservado para el menu que hemos utilizado en el punto anterior, y un botón de home para que al ser pulsado realice una acción específica (de forma genérica es volver a la pantalla que ha sido marcada como main). Para poder activar dicho botón es necesario ejecutar el siguiente código

```java
supportActionBar?.setDisplayHomeAsUpEnabled(true)

```

La variable actionBar viene creada por defecto y apunta al action bar de la pantalla. Es necesario indicar que es posible nulo ya que en algunas ocasiones puede no estar presente si el programador la ha quitado intencionadamente. Por último, para poder evaluar su pulsación es necesario indicar un caso dentro del método onOptionsItemSelected, utilizando el id que ofrece Android para poder evaluar su pulsación

```java
    override fun onOptionsItemSelected(item: MenuItem): Boolean {

        when (item.itemId) {

            android.R.id.home ->{
                Snackbar.make(binding.root, "Pulsado boton home", Snackbar.LENGTH_SHORT).show()
            }
        }
    }

```

En el caso de que queramos que la acción correspondiente se la de ir a una actividad padre, es necesario marcar cual es dentro del manifest.

```xml
    <activity
        android:name=".SecondActivity"
        android:label="@string/title_activity"
        android:parentActivityName="com.example.MainActivity" />

```

Una vez hecho esto no sería necesario recoger la pulsación dentro del método onOptionsItemSelected. En el caso de querer hacerlo con pulsación, el código del caso sería el siguiente

```java
var intent = Intent(this, MainActivity::class.java)
intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP)
startActivity(intent)

```

# Notificaciones de barra

[Volver arriba](4%20Toolbar%20y%20notificaciones%20d62eeadeed7083d7955e818249bee04d.md)

Otro de los elementos que permiten gestión de la información que de inicio están ocultos, son las notificaciones de barra de estado. Estas notificaciones permiten mostrar un globo con conctenido en momentos concretos de la aplicación. Si bien es cierto que cuando trabajamos con una aplicación que tienen conexión de red este tipo de notificaciones cobran mucho más sentido, también pueden ser útiles cuando trabajamos con una aplicación local. Para poder crear este tipo de notificaciones es necesario cumplir dos pasos: crear el canal de notificaciones y crear/lanzar la propia notificación

## Crear un canal de notificaciones

Desde android 8.0 es obligatorio crear y registrar el canal de notificaciones antes de poder lanzarla. Este canal de notificaciones representa el sitio donde las notificaciones serán mostradas, por lo tanto sin su existencia es literalmente imposible utilizarlas. Para crearlas se utiliza un objeto de tipo NotificationChannel

```java
val canal = NotificationChannel("mi_canal","canal1",NotificationManager.IMPORTANCE_DEFAULT)

```

Los parámetros que admite este constructor son:

- id: nombre sobre el cual luego podremos lanzar las notificaciones
- nombre: nombre que obtendrá el canal
- nivel prioridad: para poder gestionar varios canales en el caso de que están activos al mismo tiempo

Como esto es obligatorio desde la version Android Oreo, es necesario hacer una evaluación antes de crear el canal.

```java
    fun createChannel(): Unit {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O){
            val canal = NotificationChannel("mi_canal","canal1",NotificationManager.IMPORTANCE_DEFAULT)
            val notificationManager: NotificationManager = getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
            notificationManager.createNotificationChannel(canal)
        }
    }

```

El registro se hace a traves del sistema de notificaciones del sistema operativo. Este método creado se tendrá que ejecutar en el método onCreate para que el canal esté disponible nada más arrancar la aplicación (en el caso de que así se quiera)

## Crear y lanzar una notificación

Una vez está el canal creado y activado, tan solo falta crear la notificación y lanzarla sobre el canal que se quiera. Para ello es necesario utilizar un objeto NotificationManager.Builder

```java
val notificacion =  NotificationCompat.Builder(this, "mi_canal");

```

Para poder crearla es necesario indicar el contexto y el id del canal a traves del cual se mostrará la notificación. Una vez creada se pueden utilizar numerosos métodos para configurarla, donde destacan

- setContentTitle: pone el título
- setContentText: pone el contenido del texto
- setSmallIcon: pone el icono
- priority: indica la prioridad
- setContentIntent: pone la acción a realizar al pulsar la notificación. Se hace a través de un objeto de tipo pendingIntent

```java
val notificacion =  NotificationCompat.Builder(this, "mi_canal");
notificacion.setContentTitle("Notificación general")
notificacion.setContentText("Cuerpo de la notificación")
notificacion.setSmallIcon(R.drawable.challenge)
notificacion.priority = NotificationManager.IMPORTANCE_HIGH
val intent = Intent(applicationContext, MainActivity::class.java)
val pedingIntent = PendingIntent.getActivity(this, 0,intent, PendingIntent.FLAG_UPDATE_CURRENT)
notificacion.setContentIntent(pedingIntent)

```

Una vez la notificación se crea, tan solo falta lanzarla mediante un objeto de tipo NotificationManager y el método notify

```java
val notificationManager = NotificationManagerCompat.from(this)
notificationManager.notify(1,notificacion.build())

```

Los parámetros del método notify son un ID para poder gestionar varios tipos de notificaciones y la creación de la propia notificación. Un ejemplo completo de lanzamiento de notificación desde la pulsación de un elemento de menu contextuales el siguiente:

```java
    override fun onContextItemSelected(item: MenuItem): Boolean {
        when(item.itemId){
            R.id.menu_context_1->{
                val notificacion =  NotificationCompat.Builder(this, "mi_canal");
                notificacion.setContentTitle("Notificación general")
                notificacion.setContentText("Cuerpo de la notificación")
                notificacion.setSmallIcon(R.drawable.challenge)
                notificacion.priority = NotificationManager.IMPORTANCE_HIGH
                val intent = Intent(applicationContext, MainActivity::class.java)
                val pedingIntent = PendingIntent.getActivity(this, 0,intent, PendingIntent.FLAG_UPDATE_CURRENT)
                notificacion.setContentIntent(pedingIntent)
                lanzarNotificacion(notificacion)
            }
            R.id.menu_context_2->{}
        }
        return true
    }

    fun lanzarNotificacion(notificacion: NotificationCompat.Builder): Unit {
        val notificationManager = NotificationManagerCompat.from(this)
        notificationManager.notify(1,notificacion.build())
    }

```