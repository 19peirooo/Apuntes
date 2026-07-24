# 3. Menús

Status: Not started
Type: Stations
🪴 Units: 5. Diálogos y menús (../Unidades/5%20Di%C3%A1logos%20y%20men%C3%BAs%201a0eeadeed708261a57d0160f016c827.md)

## Creación de un menu de opciones

Para poder trabajar con un menu de opciones, lo primero necesario es crearlos. Se puede crear programaticamente o como recurso. En este caso lo vamos a ver como recurso, ya que de esta forma el menu puede estar disponible para diferentes sitios. Para ello lo primero necesario es crear una carpeta dentro de res donde se vayan a alojar los recurso, por lo que con el botón derecho ya pulsado seleccionamos new --> android resource directory indicando como nombre menu y como tipo menu. Una vez hecho esto se crea una carpeta dentro de res con el nombre indicado. Es aquí donde se van a ubicar todos los recursos de tipo menu. Para poder crear un recurso de tipo menu, seleccionaremos con botón derecho crear un nuevo recurso de menu al cual se indicaremos el nombre, en este caso menu_principal. Esta acción crea un xml con el recurso del menu y si lo abrimos podemos tratarlo tanto gráficamente como por código. Mediante código nos encontraremos con los siguiente:

```xml
<?xml version="1.0" encoding="utf-8"?>
<menu xmlns:android="<http://schemas.android.com/apk/res/android>">
</menu>

```

Dentro de la etiquete menu tendremos que indicar todas las opciones que queramos que tenga nuestro menu, creando un elemento de tipo item para cada una de ellas

```xml
    <item android:title="Información"
        android:id="@+id/menu_informacion"
        />

```

El atributo title es el único obligatorio y es el que recoge el string que aparecerá asociado al elemento (puede estar declarado dentro de string.xml). Ek id es muy recomendable ya que será la forma de asociarlo a la pulsación desde la parte lógica. Además de estas opciones se pueden poner algunas adicionales:

```xml
    <item android:title="Agregar dato"
        android:id="@+id/menu_agregar"
        android:icon="@android:drawable/ic_dialog_info"
        app:showAsAction="always"
        android:checkable="false"
        />

```

De estas opciones destacar showAsAction que permite poder indicar que la opción aparecerá como icono en la barra superior (las posibles configuraciones son always (siempre) ifRoom (solo si hay espacio) never (nunca)) y la de checkable la cual indica si la opción aparecerá como una opción con estilo RadioButton. Además de esto podemos tener submenus, para lo cual es necesario no autocerrar el item sino dejarlo abierto y meter un elemento de tipo menu dentro. Un ejemplo completo podría ser el siguiente

```xml
<?xml version="1.0" encoding="utf-8"?>
<menu xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>">

    <item
        android:id="@+id/menu_agregar"
        android:checkable="false"
        android:icon="@android:drawable/ic_dialog_info"
        android:title="Agregar dato"
        app:showAsAction="always" />
    <item android:title="Navegación">
        <menu>
            <item
                android:id="@+id/menu_navegacion_1"
                android:title="Ir a la pantalla 1"
                />
            <item
                android:id="@+id/menu_navegacion_2"
                android:title="Ir a la pantalla 2"
                />
        </menu>
    </item>
    <item
        android:id="@+id/menu_salir"
        android:title="Salir" />

</menu>

```

## Configurar menu en la activity

Con el recurso creado el siguiente paso sería la configuración dentro de la aplicación del mismo. Para ello existen varias posibilidades, siempre dependiendo del tipo de barra superior con el que cuente la activity. Como se ha dicho el principio, por defecto la barra con la que se cuenta es una barra de ActioBar, la cual tienen una configuración muy sencilla pero tiene una personalización muy baja. Para poder poner un menú dentro de este tipo de barras basta con sobreescribir el método onCreateOptionMenu

```java
    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        return super.onCreateOptionsMenu(menu)
    }

```

Este método tiene como parámetro un objeto de tipo menu, el cual es el menu que toda barra tiene, pero que solo es visible cuando se le pone algo. En el momento en el que se le pone el recurso que creamos en el punto anterior directamente aparecerá como menu de la aplicación. Para poder ponerlo, lo primero que se debe hacer es acceder al recurso mediante un objeto de tipo MenuInflater (muy similar al layout inflater que utilizamos constantemente en con binding) e indicar mediante el método inflate lo que queremos inflar (nuestro xml) y donde lo queremos poner (el menu que nos dan como parámetro)

```java
    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu_principal,menu)
        return true
    }

```

Como se pude ver en la firma del método el método debe devolver true si se quiere mostrar el menu

Más delante veremos como poder configurar los menus y sus funcionalidades dentro de un Toolbar

## Configurar las pulsaciones dentro de un menu

Para poder configurar las pulsaciones tendremos que sobreescribir el método onOptionsItemSelected

```java
    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        return super.onOptionsItemSelected(item)
    }

```

Dicho método tiene como parámetro un objeto de tipo menuItem, que será el elemento seleccionado dentro del menu que previamente hemos rellenado con el método el punto anterior. Al igual que hacemos con la evaluación de la pulsación de un menu, en este caso evaluaremos el id del menuItem pulsado, para así poder decidir que acción es la que queremos ejecutar

```java
    override fun onOptionsItemSelected(item: MenuItem): Boolean {

        when(item.itemId){
            R.id.menu_salir->{
                // accion para el menu salir
            }
            R.id.menu_navegacion_1->{
                // accion para el menu nav1
            }
            R.id.menu_navegacion_2->{
                // accion para el menu nav2
            }
            R.id.menu_salir->{
                // accion para el menu salir
            }
        }

        return true
    }

```

En cada una de las acciones podemos configurar diferentes acciones, como por ejemplo salir de la aplicación, saltar diálogos, navegar a diferentes pantallas, etc...

## Creación de menus contextuales

Los menus contextuales son aquellos que aparecen tras la pulsación larga de una vista. En ocasiones pueden ser útiles siempre y cuando cada vista esté vinculada a acciones separadas. Sin embargo su uso puede resultar confuso, ya que el usuario puede no saber de su existencia. Para poder utilizarlo, hay que tener en cuenta que cada menú contextual va asociado a una vista en concreto, y esta asociación es necesaria hacerla en el método onCreate. Imaginemos que tenemos un botón en nuestra interfaz y queremos que al pulsarlo aparezca un menú contextual con varias opciones. Lo primero que debemos hacer es tener creado el xml donde dejamos reflejado el propio menú

```xml
// menu_contextual.xml
<?xml version="1.0" encoding="utf-8"?>
<menu xmlns:android="<http://schemas.android.com/apk/res/android>">

    <item android:title="Opcion 1"
        android:id="@+id/menu_context_1"/>

    <item android:title="Opcion 2"
        android:id="@+id/menu_context_2"/>

</menu>

```

Este archivo representa el menu, por lo que el siguiente paso es asociarlo a una vista en concreto. Para ello ejecutamos el método registerForContextMenu sobre la vista que queramos en el método onCreate

```java
registerForContextMenu(binding.botonContextual)

```

Una vez hecho esto tan solo falta por indicar que menu es el que tiene que sacar. Para ello se sobreescribe el método onCreateContextMenu, el cual recibe como parámetros el menu que será el que se muestre, la vista que ha generado la pulsación para sacar el menu y la información del mismo

```java
    override fun onCreateContextMenu(
        menu: ContextMenu?,
        v: View?,
        menuInfo: ContextMenu.ContextMenuInfo?
    ) {
        super.onCreateContextMenu(menu, v, menuInfo)
        when(v!!.id){
            R.id.boton_contextual->{
                menuInflater.inflate(R.menu.menu_contextual,menu)
            }
        }
    }

```

El igual que vimos en los menus normales, utilizando el menuinflater podemos asociar el archivo que se ha creado con el menú donde se mostrará. Por último, para poder evaluar la pulsación de la opción del menú contextual se sobreescribe el método onContextItemSelected evaluando el id del menu seleccionado

```java
    override fun onContextItemSelected(item: MenuItem): Boolean {
        when(item.itemId){
            R.id.menu_context_1->{}
            R.id.menu_context_2->{}
        }
        return true
    }

```