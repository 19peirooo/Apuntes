# 1. Conceptos SQLite y Room

Status: Not started
🪴 Units: 7. Base datos (../Unidades/7%20Base%20datos%20343eeadeed7082648c4f817840eb78e6.md)

Para poder trabajar con base de datos SQLite existen dos posibilidades:

- Utilización de objetos SQLIteOpenHelper y SQLite con ejecución de sentencias querys normales
- Utilización de la librería Room que mete una capa de abstracción al uso de la base de datos

En este caso utilizaremos la librería Room ya que es muy sencilla al eliminar gran parte de la complejidad de la creación y tratamiento de las tablas.

## Configuración de dependencias.

Lo primero que debemos hacer para poder utilizar la librería room dentro de nuestro proyecto, es indicar las dependencias dentro del fichero build.gradle. Para ello pondremos las siguientes implementaciónes

```java
    implementation "androidx.room:room-ktx:2.4.3"
    kapt "androidx.room:room-compiler:2.4.3"

```

y aplicaremos el siguiente plugin

```java
apply plugin: 'kotlin-kapt'

```

Una vez implementada la librería necesaria, podremos utilizarla dentro dentro de nuestro proyecto. El siguiente paso es utilizar y configurar cada uno de los elementos de los que se compone la librería

## Configuración de los elementos

Gracias a que room introduce una capa de abstracción, las tareas de configuración, creación y trabajo sobre una base de datos local se reducen bastante. Pero antes de empezar a trabajar, es necesario entender muy bien cada uno de los objetos que forman parte de dicha configuración. Son los siguientes:

- Entity: representa cada una de las tablas o entidades que se guardarán dentro de la base de datos. Están representadas por data class
- DAO: representa cada una de las acciones que se pueden realizar sobre la base de datos. Son las querys que se aplicarán sobre las tablas. Están representadas por interfaces
- RoomDatabase: La clase principal que engloba las entitys y DAO los cuales conforman la base de datos.

### Entitys

Como ya se ha definido, las entitys representan las tablas que formarán parte de la base de datos. Para poder crear una entity es necesario crear una clase con el decorador @Entity, donde en el constructor se indicará cada uno de los elementos que formarán parte de la tabla. Para poder definir estos elementos cabe destacar los siguientes configuradores:

- @PrimaryKey: define la propiedad como clave principal. Es posible poner la anotación autogenerate (boolean) para indicar que la clave sea generada automáticamente y por lo tanto autoincremental
- @ColumnInfo: define información adicional acerca de la propiedad donde se configura. En el caso de no poner un column info la columna tomará el nombre de la propiedad
- @Ignore: indica que la propiedad sobre la que se configura no será tomada en cuenta en la base de datos, y lo tanto no la guardará.
- @ForeingKey: Indica que el campo donde se configure tendrá una relación con la clave primaria de otra tabla
Un ejemplo de tabla sería el siguiente:

```java
@Entity
data class Usuario(
    @PrimaryKey (autoGenerate = true) val id: Long, @ColumnInfo (name = "name") val nombre: String, val apellido: String, @ColumnInfo (name = "email") val correo: String)

```

En el caso de querer marcar la primary key como autoincremental, es necesario marcarla fuera del constructor, ya que sino siempre la pedirá al crear un usuario

```java
@Entity
data class Usuario(
    @ColumnInfo(name = "name") val nombre: String, val apellido: String,
    @ColumnInfo(name = "email") var correo: String
) {
@PrimaryKey (autoGenerate = true) var id: Long =0;
}

```

### DAO

En este caso, los DAO representan cada una de las acciones que se pueden hacer sobre las tablas de la base de datos. Lo bueno que tiene este tipo de objetos (representados mediante interfaces) es que en muchos de los casos no es necesario escribir la sentencia, ya que la librería room se encarga de interpretarla. Como ya se ha dicho, para poder crear un DAO es necesario crear una interfaz con el decorador @DAO y tantos métodos como se consideren necesarios, donde cada uno de ellos tiene el decorador @Query con la sentencia que debe ejecutar, a excepción del @insert @delete y @update, los cuales serán explicados más adelante. Un ejemplo de DAO sería el siguiente

```java
@Dao
interface UsuarioDAO{
    @Query("Select * from Usuario")
    fun selectAll(): List<Usuarios>

    @Query("Select * from Usuario Where name = :name")
    fun getByName(name: String): List<Usuario>

    @Query("Delete from Usuario Where name = :name")
    fun deleteByName(name: String)

    @Query("Update Usuario set email= :newMail WHERE email= :oldMail")
    fun updateByEmail(oldMail: String, newMail: String)

    @Insert
    fun insert(usuario: Usuario): Long

    @Delete
    fun delete(usuario: Usuario)
}

```

En aquellas funciones donde no se define una query (como en el @insert o @delete), las operaciones se realizan sobre el id o prímary key del objeto.

### Database

Una vez se han creado tanto las entidades como las operaciones que se pueden hacer sobre ella, el siguiente paso es crear la base de datos PAra ello es necesario crear una clase abstracta que herede de RoomDatabase sobre la cual se aplica el decorador @Database, indicando las entidades que la forman, el número de versión que tiene la base de datos y los dao que se aplicarán sobre la base de datos. Un ejemplo con la clase usuario creada anteriormente sería:

```java
@Database (entities = [Usuario::class], version = 1, exportSchema = false)
abstract class UsuariosBD: RoomDatabase(){
    abstract fun usuarioDAO(): UsuarioDAO
}

```