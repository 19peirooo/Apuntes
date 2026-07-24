# 2. Spinner

Status: Not started
🪴 Units: 4. Listas (../Unidades/4%20Listas%20ff4eeadeed7082ad941d016823ffc6d8.md)

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

##