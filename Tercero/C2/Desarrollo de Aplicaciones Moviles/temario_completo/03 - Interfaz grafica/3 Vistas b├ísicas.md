# 3. Vistas básicas

Status: Not started
Type: Stations
🪴 Units: 3. Interfaz gráfica (../Unidades/3%20Interfaz%20gr%C3%A1fica%20c91eeadeed708332b4c50158c00c238d.md)

Las vistas son los elementos principales de la aplicación. Cada una de ellas tiene una función claramente definida, y sus atributos y funciones son particulares de cada una de ellas. 

## Button

Se trata de una de las vistas más utilizadas dentro de la interfaz. Ya se ha visto alguna de las construcciones en los temas anteriores.

```xml
    <Button
        android:id="@+id/boton_pulsar"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Pulsar!!"
        />

```

En el caso de querer crear un botón con un estilo personalizado se configuraría el atributo style. En el caso de querer ponerle una imagen al botón se utilizaría una vista de tipo ImageButton y se configuraría el atributo src.

El evento que los botones tienen asociados es el evento onClick, disparado cuando el botón es pulsado. Para ello se debe configurar un escuchador de tipo OnClickListener, el cual tan solo tiene el método comentado

```java
        binding.botonPulsar.setOnClickListener { view: View ->
            Snackbar.make(
                view,
                "Bot´´on pulsado",
                Snackbar.LENGTH_SHORT
            ).show()
        }

```

## EditText

Los EditText representan uno de los elementos más utilizados en las interfaces gráficas de android, ya que permiten recoger datos introducidos por el usuario en el campo de texto. Cuando se quiere declarar un elemento xml se realizaría de la siguiente forma:

```xml
    <EditText
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:id="@+id/edit_texto"
        android:hint="Por favor introduce un dato"
        android:inputType="text"
        />

```

El atributo hint representa la pista que pone en el edit nada más arrancar y que desaparecerá cuando se seleccione el elemento. El atributo inputType marca los elementos que se podrán poner dentro de campo (números, letras, etc...). En el caso de querer recoger el texto que tenga dentro el edit se realizará mediante el atributo text de la siguiente forma (al pulsar un botón por ejemplo):

```java
binding.botonPulsar.setOnClickListener { view: View ->
            if (binding.editTexto.text.isEmpty()){
                Snackbar.make(
                    view,
                    "El edit está vacío",
                    Snackbar.LENGTH_SHORT
                ).show()
            } else {
                Snackbar.make(
                    view,
                    "El contenido del edit es ${binding.editTexto.text}",
                    Snackbar.LENGTH_SHORT
                ).show()
            }

```

A la hora de trabajar con eventos, los Edit son elementos que aunque tienen la capacidad de hacerlo, no es muy práctico escuchar eventos en funcionamiento. Lo que hay veces que si es util es utilizar EditText modificados que dan alguna funcionalidad avanzada como por ejemplo

### EditText autocompletables

Son aquellos que según vas escribiendo se van mostrando las opciones de autocompletado. Este tipo de vistas se llaman AutoCompleteTextView y requieren tanto de parte gráfica (xml) como de parte lógica (los elementos que mostrará en autocompletar). Para empezar a utilizarlo es necesario declararlo en el xml de la siguiente forma

```xml
		<AutoCompleteTextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:hint="Por favor introduce un pais"
        android:id="@+id/edit_autocomplete"
        />
```

Una vez está declarado el elemento en la parte gráfica ya sería funcional, pudiendo recoger su texto de la misma forma que un edit normal. Sin embargo no autocompletaría según se va escribiendo ya que para eso es necesario agregarle en la parte lógica un adaptador, el cual junta la parte lógica de los datos autocompletables con el elemento gráfico. Para poder declarar este objeto de tipo ArrayAdapter es necesario pasarle en contexto (vale con this), un layout que indica la forma en la que se mostrará la lista de elementos autocompletables y una lista con los elementos que se podrán autocompletar

```java
val paises = arrayOf("Argentina","Brasil","Canada","Dinamarca","España","Francia","Grecia","Hungria","Italia");
val adapter = ArrayAdapter(this,android.R.layout.simple_list_item_1,paises)

```

Adicionalmente también podríamos incluir aquí un elemento llamado TextInputLayout, pero reservaremos su explicación para el capítulo dedicado a Material Design

## CheckBox

Se trata de una vista que consta de dos vistas: estado seleccionado y estado no seleccionado. Esta vista es un tipo de botón, por lo que muchas de las opciones que se pueden incluir en los button también se pueden utilizar aquí. Para poder utilizarlo se utilizaría el siguiente código xml

```xml
    <CheckBox
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Opción a seleccionar"
        android:id="@+id/check_seleccionar"
        />

```

A la hora de manejar sus eventos, tenemos dos posibilidades principales: actuar cuando el elemento es pulsado para lo que utilizaremos el mismo método onClick que hemos visto antes o actuar cuando la propiedad seleccionado del elemento cambia. Hay que tener en cuenta que el primero de los métodos se ejecutaría cuando el check es pulsado, mientras que el segundo método se ejecutaría cuando la selección del check cambia (que puede no ser con una pulsación del mismo). En el primer caso el código no cambia mucho con respecto al anterior, ya que el listener es exactamente el mismo.

```java
        binding.checkSeleccionar.setOnClickListener { view: View -> Snackbar.make(
            view,
            "El check ha sido selecciondo y su estado es ${binding.checkSeleccionar.isChecked}",
            Snackbar.LENGTH_SHORT
        ).show() }

```

Sin embargo, en el segundo caso el listener si cambia ya que no se ejecutará cuando el check sea pulsado, sino cuando el estado se cambie. Para ello el listener recibe dos parámetros: la visa que genera el evento (siembre será el propio check) y un booleano que representa el estado actual en el que se encuentra

```java
binding.checkSeleccionar.setOnCheckedChangeListener({ view: CompoundButton, checked: Boolean ->
            Snackbar.make(
                view,
                "El estado del check ha sido cambiado y ahora es $checked",
                Snackbar.LENGTH_SHORT
            ).show()
        })

binding.botonPulsar.setOnClickListener { view: View ->
	binding.checkSeleccionar.isChecked = !binding.checkSeleccionar.isChecked
}

```

En este ejemplo el código del listener OnCheckedChange se ejecutará tanto si el listener es pulsado (ya que la pulsación cambia el estado) como si el botón es pulsado ya que también cambia el estado

## RadioButton

Se trata de un componente muy parecido al visto anteriormente. Cuenta con dos posibles estados: seleccionado y no seleccionado. La diferencia con los checkbox es que su uso por lo general está asociado a un grupo y además el usuario tan solo puede seleccionarlo, no deseleccionarlo. En el caso de querer utilizarlo de forma individual se declararía en el xml de la siguiente forma

```xml
    <RadioButton
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Seleccionado"
        android:id="@+id/radio_individual"
        />

```

Como se puede ver existe la posibilidad de declarlo d¡individualmente, lo que pasa es que no tiene mucho uso real, ya que como se ha dicho en el momento que se selecciona el radio, no podría deseleccionarse. Lo que si tiene mucho uso es declararlo dentro de un grupo de elementos:

```xml
	<RadioGroup
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:orientation="vertical"
        android:id="@+id/grupo_radios">

        <RadioButton
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Opción 1"
            android:id="@+id/radio_uno"/>
        <RadioButton
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Opción 2"
            android:id="@+id/radio_dos"/>
        <RadioButton
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Opción 3"
            android:id="@+id/radio_tres"/>
    </RadioGroup>

```

Como se puede ver, todos los elementos de tipo Radio están englobados dentro de una etiqueta de tipo RadioGroup. Tanto los elementos finales como el grupo tienen id, ya que a la hora de trabajar los eventos disponibles se puede: analizar el click en un radio, analizar el cambio de estado de un radio (ambas opciones funcionan exactamente igual que los casos vistos en los componentes anteriores) o también se puede analizar el cambio de selección de algún elemento del RadioGroup. Para ello es necesario utilizar un listerner setOnCheckedChangeListener, el cual tiene como parámetros el RadioGroup que ha generado el evento y un Int que representa el id del RadioButton que ha sido seleccionado

```java
binding.grupoRadios.setOnCheckedChangeListener { radioGroup, i ->  }

```

Con este listener se podría desde sacar cual es el radio seleccionado hasta sacar cual es el texto que tiene el radio seleccionado

```java
binding.grupoRadios.setOnCheckedChangeListener { radioGroup, i ->
// de esta forma sacaríamos el texto del radio seleccionado
val radio: RadioButton = findViewById(i);
Snackbar.make(radio,radio.text,Snackbar.LENGTH_SHORT).show()
// de esta forma sacaríamos un texto dependiendo de la seleccion realizada
	when(i){
		R.id.radio_uno->{Snackbar.make(radio,"Seleccionado uno",Snackbar.LENGTH_SHORT).show()}
		R.id.radio_dos->{Snackbar.make(radio,"Seleccionado dos",Snackbar.LENGTH_SHORT).show()}
		R.id.radio_tres->{Snackbar.make(radio,"Seleccionado tres",Snackbar.LENGTH_SHORT).show()}
		}
}

```

## Spinner

Se trata de elementos desplegables que pueden contener tanto elementos de una lista o array declarado en el código como de un recurso de tipo string-array declarado dentro de la carpeta res. Para poder utilizarlo, gráficamente se debería utilizar el siguiente código dentro del fichero xml

```xml
    <Spinner
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:id="@+id/spinner_seleccion"
        />

```

Una vez está declarado elemento, es necesario llevarlo a la parte lógica y añadirle la parte de datos. Esta parte de datos es lo que se conoce como adaptador (ya lo vimos en elementos anteriores) y permite juntar un elemento gráfico con una parte de datos. Para ello es necesario crear el objeto ArrayAdapter y asociarlo mediante el método setAdater

```java
val paises = arrayOf("Argentina","Brasil","Canada","Dinamarca","España","Estonia","Francia","Grecia","Hungria","Italia");
val adapter = ArrayAdapter(this,android.R.layout.simple_list_item_1,paises)
adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
binding.spinnerSeleccion.setAdapter(adapter)

```

Este código asociará la lista de países al spinner cuya id es spinnerSeleccion. En el caso de querer asociar el spinner a unos datos que ya existan como recursos de la aplicación lo primero necesario que dicho recurso exista. Para ello se creará un array de string dentro del fichero string.xml con el siguiente código

```xml
<string-array name="paises">
        <item>España</item>
        <item>Italia</item>
        <item>Francia</item>
        <item>Brasil</item>
        <item>Argentina</item>
</string-array>

```

Una vez hecho esto ya se podrá crear la asociación desde este recurso con el siguiente código

```java
val adapter = ArrayAdapter.createFromResource(this,R.array.paises,android.R.layout.simple_spinner_item)
adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
binding.spinnerSeleccion.setAdapter(adapter)

```

Como se puede ver es una creación muy similar a la anterior, con la diferencia que el array no se declara en la clase, sino que se coge como recurso.
Una ves se ha creado el array, lo siguiente sería tratar sus eventos. En este caso el tratamiento no sería el de un onClick, ya que no estamos hablando de una pulsación simple, sino que sería el de una selección (que junta desplegar el spinner y seleccionar un elemento). PAra ello se utiliza un listener llamado onItemSelectedListener. En este caso y a diferencia de los vistos anteriormente, la interfaz del escuchador trae varios métodos (en concreto 2), por lo que hay que declararlo de forma diferente igualando el escuchador a un objeto con los dos métodos

```java
binding.spinnerSeleccion.onItemSelectedListener = object : AdapterView.OnItemSelectedListener{
	override fun onItemSelected(p0: AdapterView<*>?, p1: View?, p2: Int, p3: Long) {
	}
	override fun onNothingSelected(p0: AdapterView<*>?) {
	}
}

```

Ambos métodos serán ejecutados cuando una acción se produzca sobre el spinner. El primero de ellos se ejecutará cuando algo en el spinner esté seleccionado y el segundo cuando el spinner se desplegado y no cambie la selección del mismo. En el primero de los métodos se reciben como parámetros la vista que ha provocado el evento (p0), la vista que ha sido pulsada (p1), la posición pulsada (p2) y el id de la posición pulsada (p3). En el segundo de los métodos yan solo se recibe la vista que ha provocado el evento (p0)

```java
binding.spinnerSeleccion.onItemSelectedListener = object : AdapterView.OnItemSelectedListener{
            override fun onItemSelected(p0: AdapterView<*>?, p1: View?, p2: Int, p3: Long) {
                Snackbar.make(p0!!,"La posición del spinner seleccionada es $p2",Snackbar.LENGTH_SHORT).show()
            }

override fun onNothingSelected(p0: AdapterView<*>?) {
                Snackbar.make(p0!!,"El spinner se ha desplegado pero nada ha sido seleccionado",Snackbar.LENGTH_SHORT).show()
            }
        }

```

Ambos métodos se ejecutarán con una acción que se produzca en el spinner directamente, pero en el caso de querer sacar el dato seleccionado del spinner con otra acción diferente (por ejemplo la pulsación de un botón) el código sería el siguiente

```java
        binding.botonPulsar.setOnClickListener { view: View ->
            Snackbar.make(
                view,
                "El elemento seleccionado del spinner es ${binding.spinnerSeleccion.adapter.getItem(binding.spinnerSeleccion.selectedItemPosition)}",
                Snackbar.LENGTH_SHORT
            ).show()

        }

```

Como veremos en el siguiente tema, los spinner pueden tener un aspecto personalizado mediante adaptadores avanzados, lo que hace que sean mucho más personalizables