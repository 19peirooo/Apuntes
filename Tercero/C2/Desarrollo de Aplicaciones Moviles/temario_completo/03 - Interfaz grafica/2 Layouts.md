# 2. Layouts

Status: Not started
Type: Stations
🪴 Units: 3. Interfaz gráfica (../Unidades/3%20Interfaz%20gr%C3%A1fica%20c91eeadeed708332b4c50158c00c238d.md)

## Layouts: tipos y uso

Como se ha comentado anteriormente, los layouts son aquellos elementos invisibles que permiten organizar los elementos en el espacio. Siempre habrá uno que será el componente root del archivo xml, pudiendo utilizar tantos en su interior como se quiera (sin embargo no es muy recomendable hacer un anidamiento profundo). A continuación veremos los principales:

### LinearLayout

Se trata del layout más sencillo de utilizar, ya que dispone los elementos en una fila única bien sea en horizontal o en vertical

```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    tools:context=".MainActivity">

    <TextView
        android:id="@+id/texto_main"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Elementos interfaz"
      />

    <Button
        android:id="@+id/boton_pulsar"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Pulsar!!"
        />

    <CheckBox
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Opción a seleccionar"
        android:id="@+id/check_seleccionar"
        />

    <RadioButton
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Seleccionado"
        android:id="@+id/radio_individual"
        />

</LinearLayout>

```

Como se puede ver en el LineaLayout se ha declarado un atributo llamado orientation configurado a vertical. Esto quire decir que todos los componentes que están dentro se colocarán uno debajo del otro. En el caso de haberlo configurado como horizontal, los elementos se colocarían uno a la izquierda del otro.

Otra de las posibilidad tiene este layout es el de utilizar pesos (el atributo es layout_weigth). Este atributo permite indica el % de espacio que se reservará para el elemento el que se configura. Es importante tener en cuenta que la suma de todos los pesos tiene que ser 1

```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:gravity="center"
    tools:context=".MainActivity">

    <TextView
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:layout_weight="0.5"
        android:text="Etiqueta en 50%"
        android:gravity="center"
        android:textSize="50sp"
        />

    <Button
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:layout_weight="0.5"
        android:text="Boton en 50%"
        android:textSize="40sp"
        />

</LinearLayout>

```

Es importante tener en cuenta que aquel eje donde queramos que le afecte el peso debe estar configurado como 0dp, para que sea el peso el que realmente se aplique. El atributo de gravity aplicado al TextView indica que el contenido debe colocarse en el centro y el atributo de textSize indica el tamaño del texto que tendrá (siempre en sp)

### ConstraintLayout

Se trata del layout que más libertad permite a la hora de generar una interfaz, ya que los elementos se colocan en relación al resto o a los bordes de la pantalla. Para poder indicar estas restricciones se utilizan atributos con la construcción layout_constraint, indicando el id del elemento sobre el que queremos restringir o parent en el caso de querer hacerlo sobre la vista padre.

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout xmlns:android="<http://schemas.android.com/apk/res/android>"
    xmlns:app="<http://schemas.android.com/apk/res-auto>"
    xmlns:tools="<http://schemas.android.com/tools>"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <ImageView
        android:id="@+id/imageView"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginStart="24dp"
        android:layout_marginTop="24dp"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        tools:srcCompat="@tools:sample/avatars" />

    <TextView
        android:id="@+id/textView"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Nombre"
        android:textSize="24sp"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toEndOf="@+id/imageView"
        app:layout_constraintTop_toTopOf="@+id/imageView" />

    <TextView
        android:id="@+id/textView2"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Apellido"
        android:textSize="24sp"
        app:layout_constraintBottom_toBottomOf="@+id/imageView"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toEndOf="@+id/imageView"
        app:layout_constraintTop_toBottomOf="@+id/textView" />

    <EditText
        android:id="@+id/editTextTextEmailAddress"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="24dp"
        android:ems="10"
        android:hint="introduce email"
        android:inputType="textEmailAddress"
        android:minHeight="48dp"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toBottomOf="@+id/imageView" />

    <EditText
        android:id="@+id/editTextPhone"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="24dp"
        android:ems="10"
        android:hint="introduce télefono"
        android:inputType="phone"
        android:minHeight="48dp"
        app:layout_constraintEnd_toEndOf="@+id/editTextTextEmailAddress"
        app:layout_constraintStart_toStartOf="@+id/editTextTextEmailAddress"
        app:layout_constraintTop_toBottomOf="@+id/editTextTextEmailAddress" />

    <Button
        android:id="@+id/button"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="24dp"
        android:text="Guardar cambios"
        app:layout_constraintEnd_toEndOf="@+id/editTextPhone"
        app:layout_constraintStart_toStartOf="@+id/editTextPhone"
        app:layout_constraintTop_toBottomOf="@+id/editTextPhone" />
</androidx.constraintlayout.widget.ConstraintLayout>

```

En este ejemplo se muestra una pantalla de perfil donde se muestra una foto, un nombre, un apellido y unos campos de texto para poder meter datos. Como se puede ver en el código todos los elementos tienen configurado layout_constraint, indicando la posición relativa a que elemento se debe colocar. Si bien es importante trabajar siempre con código, al modificar tal cantidad de propiedades como tiene ConstraintLayout es uno de los pocos casos que se puede utilizar el modo diseñador y no perjudicar el tiempo de desarrollo.