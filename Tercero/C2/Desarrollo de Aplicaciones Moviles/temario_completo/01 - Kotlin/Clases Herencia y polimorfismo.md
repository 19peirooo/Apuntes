# Clases. Herencia y polimorfismo

Status: Not started
🪴 Units: 1. Kotlin (../Unidades/1%20Kotlin%208f7eeadeed7083b7999681d83031c8ac.md)

# Clases

**Documentación oficial:** [https://kotlinlang.org/docs/reference/classes.html](https://kotlinlang.org/docs/reference/classes.html)

Las clases representan la posibilidad de objetos. Una de las cosas más importantes en kotlin es que en una clase se pueden crear varias clases. Al igual que en java toda clase tiene un constructor por defecto, por lo que se puede crear un objeto de la clase

```kotlin
fun main(arg: Array<String>){
    var clase: ClaseA = ClaseA();
}

class ClaseA

```

Si se quiere crear un constructor con parámetros, se utiliza la palabra reservada `constructor`

```kotlin
class ClaseA{
    var nombre: String;
    constructor(nombre: String){
        this.nombre = nombre;
    }
}

```

Si tan solo se quiere utilizar un constructor se puede obviar la palabra `constructor` indicando los parámetros al lado del nombre de la clase, quedando la creación de la clase de la siguiente forma

```
fun main(arg: Array<String>){
    var clase: ClaseA = ClaseA("Ejemplo");
}

class ClaseA (var nombre: String){

}

```

Si se quisieran tener constructores secundarios, si sería necesario utilizar la palabra reservada `constructor`. Hay que recordad que si se utiliza un constructor con parámetros, el constructor por defecto desparecería. Adicionalmente a esto si se utilizan constructores adicionales es necesario que estos devuelven el primer constructor definido

```kotlin

fun main(arg: Array<String>){
var lenguaje = Lenguaje("java","multi",18)
println(lenguaje.plataforma);
}

class Lenguaje{
    var nombre: String
    var plataforma: String;
    var version: Int;
    constructor(nombre: String, plataforma: String, version: Int)  {
        this.nombre = nombre
        this.plataforma = plataforma;
        this.version = version;
    }
}

```

En este primer ejemplo se tiene una clase llamada Lenguaje que para poder crearla se necesita un constructor con tres parámetros que son obligatorios: nombre, plataforma y versión. Sin embargo si se quieren utilizar constructores múltiples se puede pasando por parámetros aquellos que se necesiten, pero teniendo en cuenta que aquellas propiedades que no estén incluidas deberán estar configuradas como null safety

```kotlin
class Lenguaje{
    var nombre: String
    var plataforma: String;
    var version: Int?=null;
    constructor(nombre: String, plataforma: String, version: Int)  {
        this.nombre = nombre
        this.plataforma = plataforma;
        this.version = version;
    }

    constructor(nombre: String, plataforma: String){
        this.nombre = nombre;
        this.plataforma = plataforma;
    }
}

fun main(arg: Array<String>) {
    var java = Lenguaje("java", "multi", 18)
    var kotlin = Lenguaje( nombre="Kotlin", plataforma = "multi")
    println(java.plataforma);
    println(kotlin.version)
}

// SALIDA
multi
null

```

En este ejemplo se ha creado un segundo lenguaje de programación llamado kotlin con el constructor que admite dor parámetros. En este caso la versión es null ya que no se ha especificado. (se ha utilizado la creación del objeto nombrando las variables a modo de prueba para ver más opciones de creación de objetos)

Otra de las posibilidades a la hora de crear varios constructores es la de tener uno base, sobre el cual el resto depende. Para ello se utiliza la notación corta para el constructor "base" y la palabra constructor para el resto de constructores, teniendo en cuenta que todos deberán de devolver un objeto de la clase. En este ejemplo se creará un constructor base que recibe un parámetro String que representará el nombre. Adicionalmente se utilizarán dos constructores, uno que además aportará la plataforma, y otro que aportará la plataforma y la versión

```kotlin
fun main(arg: Array<String>) {
    var java = Lenguaje("java", "multi", 18)
    var kotlin = Lenguaje( nombre="Kotlin", plataforma = "multi")
    var cSharp = Lenguaje ("C#");
    println(java.plataforma);
    println(kotlin.version);
    println(cSharp.plataforma)
}

class Lenguaje (var nombre: String){
    var plataforma: String? = null;
    var version: Int? = null;

    constructor(nombre: String, plataforma: String, version: Int): this(nombre) {
        this.plataforma = plataforma;
        this.version = version;
    }

    constructor(nombre: String, plataforma: String): this(nombre){
        this.plataforma = plataforma;
    }
}

```

En este caso como se ha utilizado un constructor base ocurren dos cosas:

- Todas las propiedades de la case se tienen que inicializar con un valor (existe la posibilidad de utilizar lateinit que se verá más adelante)
- Todos los constructores adicionales tienen que devolver el constructor base, y que además realizarán las acciones que hayan definido en su definición

Al igual que se pueden crear constructores, también se pueden crear tantas funciones como sean necesarias dentro de una clase, para así poder utilizarlo

```kotlin
fun main(arg: Array<String>) {
    var java = Lenguaje("java", "multi", 11)
    var kotlin = Lenguaje( nombre="Kotlin", plataforma = "multi")
    var cSharp = Lenguaje ("C#");
    java.clasificar()
    java.mostrarDatos()
    kotlin.mostrarDatos()
    cSharp.mostrarDatos()
}

class Lenguaje (var nombre: String){
    var plataforma: String? = null;
    var version: Int? = null;

    constructor(nombre: String, plataforma: String, version: Int): this(nombre) {
        this.plataforma = plataforma;
        this.version = version;
    }

    constructor(nombre: String, plataforma: String): this(nombre){
        this.plataforma = plataforma;
    }

    fun clasificar(){
        if (this.nombre.lowercase().equals("java")){
            if (this.version?:12<14){
                println("versión obseleta")
            }
        }
    }

    fun mostrarDatos(){
        println("Nombre ${this.nombre}")
        println("Plataforma ${this.plataforma?: "no definida"}")
        println("Versión ${this.version?: "no definida"}")
    }
}

// SALIDA
versión obseleta
Nombre java
Plaraforma multi
Versión 11
Nombre Kotlin
Plaraforma multi
Versión no definida
Nombre C#
Plaraforma no definida
Versión no definida

```

En este ejemplo, en el método clasificar se evalúa que el nombre del lenguaje sea java. En caso de serlo, si la versión es inferior a 14 se mostrará el mensaje de "versión obsoleta". En esta construcción como la propiedad versión se ha inicializado a null (por obligación al utilizar constructores secundarios) se ha realizado una sustitución de en el caso de ser nula se sustituirá por el número 12. Lo mismo pasa en el método mostrarDatos. Como las propiedades plataforma y versión pueden ser nulas, en el caso de serlo se sustituirán por la palabra "no definida"

Por último, existe la posibilidad de inicializar las variables de forma postergada, no en el constructor. Para ello se utiliza la palabra reservada `lateinit`. En el ejemplo de la clase Lenguaje, imaginemos que existe una propiedad llamada propietario, la cual no se quiere inicializar en el constructor ya que no solo no es obligatoria, sino que en necesario que el lenguaje de programación exista para que una vez esté creado tenga un propietario. Para ello se crea la propiedad y se declara como lateinit

```kotlin
class Lenguaje (var nombre: String){
    var plataforma: String? = null;
    var version: Int? = null;
    lateinit var propietario: String

    constructor(nombre: String, plataforma: String, version: Int): this(nombre) {
        this.plataforma = plataforma;
        this.version = version;
    }

    constructor(nombre: String, plataforma: String): this(nombre){
        this.plataforma = plataforma;
    }

    fun clasificar(){
        if (this.nombre.lowercase().equals("java")){
            if (this.version?:12<14){
                println("versión obseleta")
            }
        }
    }

    fun mostrarDatos(){
        println("Nombre ${this.nombre}")
        println("Plaraforma ${this.plataforma?: "no definida"}")
        println("Versión ${this.version?: "no definida"}")
    }
}

```

Es muy importante que esta propiedad no sea inicializada en ninguno de los constructores, ya que con el modificador lateinit se indica que no se hará ahí. Sin embargo si sería necesario un método que inicialice dicha propiedad a modo de setter

```kotlin
class Lenguaje (var nombre: String){
    var plataforma: String? = null;
    var version: Int? = null;
    lateinit var propietario: String

    constructor(nombre: String, plataforma: String, version: Int): this(nombre) {
        this.plataforma = plataforma;
        this.version = version;
    }

    constructor(nombre: String, plataforma: String): this(nombre){
        this.plataforma = plataforma;
    }

    fun asignarPropietario (propietario: String){
        this.propietario = propietario;
    }

    fun clasificar(){
        if (this.nombre.lowercase().equals("java")){
            if (this.version?:12<14){
                println("versión obseleta")
            }
        }
    }

    fun mostrarDatos(){
        println("Nombre ${this.nombre}")
        println("Plaraforma ${this.plataforma?: "no definida"}")
        println("Versión ${this.version?: "no definida"}")
        println("Propietario "+propietario)
    }
}

```

Como en el método mostrarDatos se utiliza la variable, si este es utilizando antes de inicializar la variable propietario, el programa obtendrá una excepción de `UninitializedPropertyAccessException`

```kotlin
fun main(arg: Array<String>) {
    var java = Lenguaje("java", "multi", 11)
    var kotlin = Lenguaje( nombre="Kotlin", plataforma = "multi")
    var cSharp = Lenguaje ("C#");
    // Esta llamada provocaría un error al utiliza una variable no inicializada
    cSharp.mostrarDatos()
    cSharp.asignarPropietario("Microsoft")
    // Esta llamada no provocaría ningún error ya que la variable se ha inicializado antes de utilizarla
    cSharp.mostrarDatos()
}

```

Como se ha visto, se pueden utiliza constructores primarios (aquel definido en la firma del método) o constructores secundarios (aquellos definidos con la palabra `constructor`). En el caso de utilizar primarios, estos tan solo inicializan las variables al valor pasado, pero nada más. En el caso de querer que el constructor (todos, tanto primarios como secundarios) haga algo más, se puede utilizar el bloque reservado `init`

```kotlin
// Archivo diferente
class Lenguaje(var nombre: String) {
    var plataforma: String? = null;
    var version: Int? = null;
    lateinit var propietario: String

    init {

        if (nombre.lowercase() == "java") propietario = "Oracle" else if (nombre.lowercase() == "c#") propietario =
            "Microsoft" else propietario = "din definir"
    }

    constructor(nombre: String, plataforma: String, version: Int) : this(nombre) {
        this.plataforma = plataforma;
        this.version = version;
    }

    constructor(nombre: String, plataforma: String) : this(nombre) {
        this.plataforma = plataforma;
    }

    fun asignarPropietario(propietario: String) {
        this.propietario = propietario;
    }

    fun clasificar() {
        if (this.nombre.lowercase().equals("java")) {
            if (this.version ?: 12 < 14) {
                println("versión obseleta")
            }
        }
    }

    fun mostrarDatos() {
        println("Nombre ${this.nombre}")
        println("Plaraforma ${this.plataforma ?: "no definida"}")
        println("Versión ${this.version ?: "no definida"}")
        println("Propietario " + propietario)
    }
}
//Archivo diferente

fun main(arg: Array<String>) {
    var java = Lenguaje("java")
    var cSharp = Lenguaje("C#");
    var kotlin = Lenguaje(nombre = "Kotlin", plataforma = "multi")
    java.mostrarDatos()
    cSharp.mostrarDatos()
    kotlin.mostrarDatos()

// SALIDA

Nombre java
Plaraforma no definida
Versión no definida
Propietario Oracle
Nombre C#
Plaraforma no definida
Versión no definida
Propietario Microsoft
Nombre Kotlin
Plaraforma multi
Versión no definida
Propietario din definir
}

```

En este ejemplo, se han utilizado tanto constructores primarios como constructores secundario. Los tres utilizados han realizado la inicialización de variables y el bloque `init` se ha encargado de inicializar la variable `lateinit propietario`, por lo que al ejecutar el método mostrarDatos no ha dado ninguna excepción (sin la necesidad de llamar al método asignarPropietario)

Hay otra posibilidad de crear clases. Aquella que solo tienen datos y no funciones y demás pueden ser declaradas como data

```kotlin
data class PersonaData(val nombre : String, val apellido : String)

fun main(args : Array<String>) {
    val persona = PersonaData("Pedro", "Herrera")

```

Para que una clase pueda ser definida como data se deben cumplir los siguientes elementos:

- El constructor primario debe tener como mínimo un parámetro.
- Todos los parámetros del constructor primario deben estar definidas con var o val.
- No pueden ser abstract, open, sealed ni inner.

Una de las cosas importantes que permiten las clases data, es que las variables pueden ser deconstruidas

```kotlin
package herencia_trabajadores
fun main(arg: Array<String>){

    var (nombre,apellido) = personaData;
    println(nombre)
    println(apellido)
}

// SALIDA
Pedro
Herrera

```

## Herencia

Al igual que pasa en java, kotlin es un lenguaje de programación que da la posibilidad de configurar herencia entre clases para que estas aprovechen propiedades y funciones de una clase superior. Sin embargo, a diferencia de java, en kotlin por defecto las clases no pueden heredad entre si a no se que se ponga el modificador `open` antes del nombre de la clase, ya que si no esta será `final`

```kotlin
package herencia_trabajadores

open class Persona (var nombre: String) {

     var apellido: String?=null;
     var dni: String?=null

    constructor(): this("Sin definir"){

    }

    constructor(nombre: String, apellido: String, dni: String): this(nombre){
        this.apellido = apellido;
        this.dni = dni;
    }

    fun mostrarDatos(){
        println("nombre: $nombre")
        println("apellido")
        println("dni: $dni")
    }
}

```

En este caso se ha creado una clase llamada Persona con un constructor base llamado nombre y dos constructores adicionales, uno que es el vacío con un dato por defecto y otro que admite un apellido y un dni. Adicionalmente se identificado que la clase es `open` para que esta pueda ser superclase de otra. El siguiente paso será crear una clase que herede de esta. Para ello se utiliza el operados `:`seguido del nombre de la clase de la que se quiere heredar en un archivo nuevo

```kotlin
class Trabajador: Persona() {

}

```

En este caso la clase Trabajador hereda de la clase Persona y utiliza el constructor por defecto de la misma (ya que se ha indicado con los paréntesis). Si se quieren sobreescribir constructores secundarios, es necesario indicarlo sin los paréntesis en la extensión de la clase

```kotlin
class Trabajador: Persona {
    constructor(): super()
    constructor(nombre: String) : super(nombre)
    constructor(nombre: String, apellido: String, dni: String) : super(nombre, apellido, dni)
}

```

Si se quiere añadir propiedades a la clase se puede hacer e inicializarla en alguno de los constructores que se tengan

```kotlin
class Trabajador : Persona  {
    var numeroSS: Int?=null

    constructor(nombre: String, apellido: String, dni: String, numeroSS: Int) : super(nombre, apellido, dni){
        this.numeroSS = numeroSS;
    }
}

```

En este caso tan solo se sobreescribe el conctructores que admite tres parámetros, al cual se le ha añadido el de la nueva propiedad incluida en la clase. Si se quieren cambiar la definición de algún método de los creados en superclases es necesario dos cosas:

- Que el método cuando se define tenga la palabra reservada `open` (obligatorio aunque la clase sea `open`)
- En el método que se quiera sobreescribir utilizar la palabra reservada override antes de la definición de la función

```kotlin

//Archivo diferente
open class Persona (var nombre: String) {

     var apellido: String?=null;
     var dni: String?=null

    constructor(): this("Sin definir"){

    }

    constructor(nombre: String, apellido: String, dni: String): this(nombre){
        this.apellido = apellido;
        this.dni = dni;
    }

    open fun mostrarDatos(){
        println("nombre: $nombre")
        println("apellido $apellido")
        println("dni: $dni")
    }
}

//Archivo diferente
class Trabajador : Persona  {
    var numeroSS: Int?=null

    constructor(nombre: String, apellido: String, dni: String, numeroSS: Int) : super(nombre, apellido, dni){
        this.numeroSS = numeroSS;
    }

    override fun mostrarDatos(){
        super.mostrarDatos()
        println("Número SS: $numeroSS")
    }

}

//Archivo diferente
fun main(arg: Array<String>){
    var persona = Persona("Pedro")
    //persona.mostrarDatos()
    var trabajador = Trabajador("Pedro","Herrera","123123A",111111);
    trabajador.mostrarDatos()
}

```

En muchas ocasiones no interesa tener una clase para que pueda ser creada como objeto, sino que se necesita como la base para el resto de subclases que irán por debajo en la linea de herencia. Para ello existe el concepto de clase abstracta, la cual puede tener entre 0 y n métodos abstractos (solo con firma y sin definición). Para poder crear una clase abstracta se debe utilizar antes del nombre de la clase la palabra reservada `abstract`, siendo open por defecto. En el caso de tener un método abstracto se utilizar la misma palabra reservada antes de la declaración del método

```kotlin
// Archivo diferente
abstract class Persona (var nombre: String) {

     var apellido: String?=null;
     var dni: String?=null

    constructor(): this("Sin definir"){

    }
    constructor(nombre: String, apellido: String, dni: String): this(nombre){
        this.apellido = apellido;
        this.dni = dni;
    }
    abstract fun mostrarDatos();

// Archivo diferente
class Trabajador : Persona  {
    var numeroSS: Int?=null

    constructor(nombre: String, apellido: String, dni: String, numeroSS: Int) : super(nombre, apellido, dni){
        this.numeroSS = numeroSS;
    }

    override fun mostrarDatos(){
        println("Nombre: $nombre")
        println("Apellido: $apellido")
        println("DNI: $dni")
        println("Número SS: $numeroSS")
    }

}

```

En este ejemplo la clase persona se ha marcado como abstracta, donde se cuenta con un método abstracto que no tiene definición. En el caso de querer crear un objeto de tipo Persona no se podría al ser abstracta. La clase trabajador extiende de persona y tiene la obligación de sobrescribir el método mostrarDatos ya que en la clase Persona es abstracto.

## Interfaces

**Referencia documentación oficial:** [https://kotlinlang.org/docs/reference/interfaces.html](https://kotlinlang.org/docs/reference/interfaces.html)

Uno de los puntos que no permite kotlin (al igual que java) es la herencia múltiple. Para paliar esta desventaja existe el concepto de interfaz, utilizando la palabra reservada `interface` en vez del de `class`. Hay que recordad que una interfaz tienen un conjunto de métodos no definidos (por defecto abstractos) que serán declarados en aquellas clases donde sean utilizadas las interfaces.

```kotlin
interface Directivo {

    fun realizarVoto(voto: Int);
}

```

Una vez se tiene declarada la interfaz, en el caso de querer utilizarla se pone detrás de los : que se utiliza para la herencia.

```kotlin
package herencia_trabajadores

class Jefe:Persona, Directivo {

    constructor(nombre: String) : super(nombre)
    constructor() : super()
    constructor(nombre: String, apellido: String, dni: String) : super(nombre, apellido, dni)

    override fun realizarVoto(voto: Int) {
        var numero = (0..10).random()
        println("El vóto emitido es de $voto")
        println("$numero")
        println("El resultado con el random obtenido es de ${numero*voto}")

    }

    override fun mostrarDatos() {
        println("Nombre: $nombre")
        println("Apellido: $apellido")
        println("DNI: $dni")
    }
}

```

En la clase Jefe, se ha extendido de la superclase Persona, utilizando sus constructores y sobreescribiendo el método mostrar datos que era abstracto. Además se ha implementado la interfaz Directivo, por lo que se ha obligado a sobreescribir el método realizar voto.