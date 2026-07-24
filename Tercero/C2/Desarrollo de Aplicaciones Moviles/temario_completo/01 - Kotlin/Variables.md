# Variables

Status: Not started
Type: Stations
🪴 Units: 1. Kotlin (../Unidades/1%20Kotlin%208f7eeadeed7083b7999681d83031c8ac.md)

# Conceptos básicos

Alguno de los conceptos básicos de kotlin y que los diferencia con java son:

- Los ficheros tienen una extension de .kt
- Las clases por defecto son privadas, a no ser que se declaren como `open`
- No existe el conepto de static
- El nombre del fichero no tiene porque coincidir con el nombre de la clase.
- Un fichero puede contener una o varias clases
- Un fichero puede contener variables y funciones (únicamente)

Los tipos de modificadores de visibilidad son:

- private
- protected
- internal
- public (por defecto)

## Efecto de modificadores de visibilidad a nivel de **paquete**

Hay 4 elementos que se pueden definir a nivel de paquete: propiedades, funciones, clases y objetos. Asi les afectan los modificadores de visibilidad en este nivel:

- public: visible de manera global, desde cualquier elemento del programa
- internal: visible para los elementos del mismo paquete.
- private: visible solo en el mismo fichero y/o clase.
- protected: visible para las subclases

# Variables

**Documentación oficial:** [https://kotlinlang.org/docs/reference/basic-syntax.html#defining-local-variables](https://kotlinlang.org/docs/reference/basic-syntax.html#defining-local-variables)

Para poder definir variables en kotlin se utiliza el nombre: tipo = valor

```java
var numero: Int = 0;
```

En muchas ocasiones el tipo se puede obviar, ya que el compilador otorgará el tipo más adecuado.

En cuanto a los tipos de variables que pueden existir en kotlin, son principalmente dos las que nos podemos encontrar: var y val. Var se trata de una variable "normal", la cual puede alterar su valor a lo largo del programa, mientras que val se trata de una variable constante que no puede cambiar su valor una vez ha sido asignado

```java
var numero: Int = 0;
val VARIABLE_CONSTANTE = "VALOR FIJO"

fun main(arg: Array<String>) {

    // esto provocaría un fallo de compilación
    VARIABLE_CONSTANTE = "Cambio de valor"
    // esto reasigna el valor de la variable a 9
    numero = 9;
}
```

A la hora de declarar variables, kotlin tiene un mecanismo para evitar las excepciones de nullpointer. Se conoce como null safety y permite asignar un posible valor nulo a una variable sin que al utilizarlo se rompa la ejecución. Para ello se utiliza el símbolo de ? después del tipo de la variable;

```java
var nombre: String? = null
```

Esto indica que la variable tiene asignada un valor de null. Con esta declaración cada vez que se quiera utilizar la variable se tendrá que indicar la posibilidad de obtener un null en la ejecución

```java
var nombre: String? = null
fun main(arg: Array<String>) {
    println(nombre?.length)
}

SALIDA
null
```

Hay en otros casos que no se puede obviar el fallo por uso de null. En estos casos es necesario indicar al compilador que si se encuentra con un elemento null que continue con la ejecución normal

```java
var totalFacturado: Int? = null
fun main(arg: Array<String>) {
    if (totalFacturado!! <0){
        println("Estamos en perdidas");
    }
}
```

En el caso de querer utilizar el null safety indicado anteriormente también se podría, siempre teniendo que llamar a una función después de la variable que puede ser nula

```java
fun main(arg: Array<String>) {
    if (totalFacturado?.compareTo(0) ==0){
        println("Estamos en perdidas");
    }
}
```

En algunas ocasiones puede ser muy interesante sustituir el valor del posible null por otro valor. Para ello se utiliza lo que se conoce como el operador Elvis, poniendo ?: = valor cuando es null

```kotlin
totalFacturado?.compareTo(0) ?: -1

```

En este caso se está intentando utilizar el método comparteTo de la variable totalFacturado y comparándolo con 0. En el caso en el que la variable sea null, el valor se sustituirá por -1. Un ejemplo con un estamento completo sería el siguiente

```java
var totalFacturado: Int? = null;

fun main(arg: Array<String>) {

    println(totalFacturado?.compareTo(0));
    if (totalFacturado?.compareTo(0) ?: -1  ==0){
        print("El valor es nulo")
    } else if (totalFacturado?.compareTo(0)==0){
        println("El total facturado es un número igual al indicado")
    } else {
        println("El total facturado es diferente")
    }
}

// SALIDA

El valor es nulo

```

Las propiedades son elementos que quedan declarados y se puede acceder a ellos gracias a sus métodos get y set. Para declarar esos métodos se hace justo después de crear la propiedad y se definen como un método normal. Hay que tener en cuenta que el uso de la palabra reservada field hace referencia al apropio valor

```java

var propiedad = 0
    get() = field
    set(value) {
        field = value
    }

var variable = "Hola"

fun main(arg: Array<String>) {
    println(propiedad)

    println(variable)
}

```

En el ejemplo la variable propiedad tiene declarado dos métodos (get y set) el primero de los cuales al tener solo una linea se hace con una función de linea

# Ejercicios de clase

### Ejercicio 1: Declaración y Modificación de Variables

Crea un programa en Kotlin que declare dos variables: una variable `var` llamada `contador` inicializada a 0, y una constante `val` llamada `LIMITE` con valor 10. Implementa un bucle que incremente el contador hasta que alcance el límite y muestre el valor en cada iteración.

Ejemplo de salida:

```kotlin
Contador: 0
Contador: 1
Contador: 2
...
Contador: 10
Límite alcanzado
```

### Ejercicio 2: Manejo de Nullables

Escribe un programa que declare una variable nullable `var nombre: String?` que inicialmente sea `null`. Luego, intenta imprimir la longitud del nombre usando el operador de llamada segura (`?.`). Después, asigna un valor a la variable y vuelve a imprimir su longitud.

Ejemplo de entrada/salida:

```kotlin
// Primera impresión (cuando nombre es null)
Longitud del nombre: null

// Después de asignar "Juan" a nombre
Longitud del nombre: 4
```

### Ejercicio 3: Uso del Operador Elvis

Crea una función que reciba un precio como parámetro nullable (`Int?`) y calcule el descuento aplicable. Si el precio es nulo, usa el operador Elvis para asignar un valor predeterminado de 100. El descuento será del 10% si el precio es mayor que 50, o del 5% en caso contrario.

Ejemplo de entrada/salida:

```kotlin
// Llamada con precio null
El precio base es: 100
El descuento aplicado es: 10.0
El precio final es: 90.0

// Llamada con precio 30
El precio base es: 30
El descuento aplicado es: 1.5
El precio final es: 28.5
```

### Ejercicio 4: Propiedades Personalizadas

Define una clase `Temperatura` que tenga una propiedad `celsius` con métodos personalizados get y set. El método get debe devolver el valor actual, mientras que el set debe validar que la temperatura esté entre -273.15°C (cero absoluto) y 100°C. Si el valor está fuera de este rango, asigna el valor límite más cercano e imprime un mensaje de advertencia.

Ejemplo de entrada/salida:

```kotlin
// Asignando temperatura = 25
Temperatura en Celsius: 25.0

// Asignando temperatura = -300
Advertencia: La temperatura no puede ser menor que -273.15°C
Temperatura en Celsius: -273.15

// Asignando temperatura = 150
Advertencia: La temperatura no puede ser mayor que 100°C
Temperatura en Celsius: 100.0
```

### Ejercicio 5: Modificadores de Visibilidad

Crea un fichero Kotlin con dos clases: `Vehiculo` y `Coche` (que hereda de `Vehiculo`). Implementa propiedades y métodos con diferentes modificadores de visibilidad (public, private, protected, internal) y comenta qué elementos son accesibles desde otra clase en el mismo fichero, desde otra clase en otro fichero del mismo paquete, y desde una subclase.

Ejemplo de entrada/salida:

```kotlin
// Ejecutando el programa
La velocidad del coche es: 120 km/h
Intentando acceder a método privado desde la subclase: Error de compilación
Accediendo a método protected desde la subclase: Correcto
Accediendo a método internal desde otro paquete: Error de compilación
```