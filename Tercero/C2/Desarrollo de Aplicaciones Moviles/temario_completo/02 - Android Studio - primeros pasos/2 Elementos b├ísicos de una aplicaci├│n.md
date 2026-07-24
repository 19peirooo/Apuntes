# 2. Elementos básicos de una aplicación

Status: Not started
Type: Stations
🪴 Units: 2. Android Studio: primeros pasos (../Unidades/2%20Android%20Studio%20primeros%20pasos%201c2eeadeed70829a8199011feab9aa2b.md)

Antes de empezar a crear aplicaciones o servicios que ejecuten determinadas funcionalidad hay que tener muy claro cuales son las partes que pueden constituir un proyecto de android. A diferencia de cualquier programa desarrollado en un lenguaje de programación puro, las librerías de android tienen una serie de elementos que son utilizados sobre un marco común para poder dar funcionalidad conjunta. Los elementos que nos podemos encontrar en una aplicación android son:

### **Activity**

Se trata del componente principal de la aplicación si esta tiene interfaz gráfica. Normalmente se suelen asociar a las pantallas que están dentro de una aplicación . De forma genérica tendremos una activity por cada una de las pantallas que formen la aplicación.

```kotlin
class MainActivity : AppCompatActivity {
     override onCreate(savedInstanceState) {
        
    }
}
```

### **View**

Son los componentes gráficos que están dentro de una pantalla. Podemos encontrar multitud de componentes con funcionalidades diversas: campos de texto, etiquetas, listas, desplegables, layouts, etc…

```kotlin
<TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Hello World!" />
```

### **Service**

Los servicios son componentes que pueden formar parte de la aplicación y realizar un trabajo específico pero que no tienen interfaz gráfica, se ejecutan en segundo plano sin mostrar nada a priori.

```
public class DummyService : Service {

    override  onCreate() {

    }

    override onStartCommand(Intent intent, int flags, int startId): Int {

        return null;
    }

   
    override onBind(Intent arg0): IBinder {
        return null;
    }

    @Override
    public void onDestroy() {

    }
}
```

### **Content Provider**

Los content provider o provedores de contenidos son los elementos encargados de actuar de nexo de unión entre dos aplicaciones que necesitan intercambiar datos de forma directa

```
class DummyContentProvider extends ContentProvider {

    override  onCreate(): Boolean {
        return false;
    }

    @Nullable
    @Override
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        return null;
    }

    @Nullable
    @Override
    public String getType(Uri uri) {
        return null;
    }

    @Nullable
    @Override
    public Uri insert(Uri uri, ContentValues values) {
        return null;
    }

    @Override
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        return 0;
    }

    @Override
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        return 0;
    }

```

### **Broadcast Reciver**

Los broadcast reciver son los elementos encargados de escuchar si la aplicación ha recibido algún tipo de notificación desde otra aplicación o servicio y actuar ante dicha situación

```
public class DummyBroadcastReciver extends BroadcastReceiver {

    @Override
    public void onReceive(Context context, Intent intent) {

    }
}
```

### **Intent**

Los intent o acciones son tareas de comunicación que se producen entre pantallas de la misma activity o lanzadores de acciones sobre alguna aplicación instalada en nuestro teléfono móvil. Ejemplos como realizar una llamada, mandar un sms, abrir google maps con una localización específica, etc…

```
Intent i = new Intent(Intent.ACTION_CALL);
i.setData( Uri.parse("tel:111111111"));
startActivity(i);
```

La creación de la mayoría de estos elementos además de tener su clase propia o código dentro de la clase que extiende del tipo concreto (Service, Activity, ContentProvider, etc….) también tendrán que estar definido dentro del fichero AndroidManifest.xml ya que será el punto de entrada de la aplicación. Esto se irá tratando en cada uno de los elementos.