# Sentencias de control

Status: Not started
Type: Worksheet
🪴 Units: 1. Kotlin (../Unidades/1%20Kotlin%208f7eeadeed7083b7999681d83031c8ac.md)

Las sentencias de control permiten maneja el flujo del programa de forma que el código no se ejecute de forma estructurada, sino que pueda dar "saltos" dependiendo de que es lo que ocurra dentro del programa. Las estructuras de control en Kotlin son muy similares a java, pero podemos encontrar alguna diferencia como por ejemplo la construcción del for o la sentencia switch que es sustituida por la sentencia when

## if

Esta estructura en kotlin es exactamente igual que en java, no existe diferencia

```java
fun main(arguments: Array<String>){
    print("Estructuras de control")
    val comienzo: Boolean = true
    if (comienzo) print("Comenzamos con el curso") else print("No estamos preparados")
}
```

En este caso la salida sera Comenzamos con el curso ya que la variable de la condición es true. Como se puede ver y al igual que pasa en java, si la sentencia if solo tiene una linea de ejecución no es necesario el uso de las llaves

```java
fun main(arg: Array<String>){

    println("Indica cual es tu nombre")
    val nombre: String? = readLine();
    println("Indica cual es tu edad")
    val edad: Int = readLine()!!.toInt();
    val comienzo: Boolean = true;

    if (comienzo && edad >17){
        print("Bienvenido ${nombre} el curso comenzará")
    } else if (comienzo && edad<18) {
        println("Han dado consentimiento tus padres")
        val consentimiento: String? = readLine();
        if (consentimiento.equals("SI")) println("Perfecto ${nombre} podemos empezar")
    } else {
        println("No podemos empezar el curso")
    }

}
```

Como veremos más adelante, kotlin cuenta con un mecanismo de null safety para poder garantizar que no se utiliza ninguna variable que pueda ser nula. De ahí el carácter ? y el carácter !!. Lo veremos más adelante pero para que podamos entender el código el ? indica que la variable puede ser nula y !! indica que se garantiza que la variable nunca va a ser nula. En el caso de estar declarada como posible nula, si se quiere utilizar se tiene que garantizar su no nulo

```java
    if (nombre?.length!! <= 0){
        print("No se ha introducido nada")
    }
```

## when

En kotlin no existe el uso de la sentencia de control swith. Esta ha sido sustituida por el uso de la sentencia when. El uso es muy parecido, cambiando la forma de escribirlo. Para poder utilizarlo se utiliza la siguiente construcción:

```java
when(condición){
    caso -> {ejecuciones}
    else -> {ejecuciones}
}
```

Como podemos ver se parece bastante al switch de java, con la diferencia que en este caso se pueden indicar multitud de posibilidades a la hora de evaluar un caso (además que el default no existe sino que existe un else). Un ejemplo sería el siguiente

```java
    val nota: Int= readLine()?.toInt() ?: 0;
    when (nota){
        !in 0..10 -> {print("Número incorrecto")}
        in 5..9 -> {
            print("Has aprobado")
        }
        in 3..4-> {
            print("Hay que estudiar más")
        }
        10 -> {
            print("Perfecto examen de matrícula")
        }
        else -> {
            print("El examen ha salidao muy mal")
        }
    }
```

En este caso existen cuatro casos

- que el número no esté comprendido entre un rango indicado mediante !in inicio..final
- que el número esté comprendido entre un rango indicado mediante in inicio..final
- que el número sea un caso concreto
- el resto de las posibilidades

Estos casos pueden ser cualquier cosa, incluso la salida de un método, donde uno de los casos sería

```java
        calcularMedia(nota) -> {
            print("El examen no da una media correcta")
        }
```

y la función sería

```java
fun calcularMedia(nota: Int): Int{
    return  nota/2;
}
```

## for

La estructura de repetición for permite realizar una tarea repetitiva un número de veces indicadas y/o recorrer una colección completa o en un rango específico. Para ello existen las siguientes estructuras

- for en un rango concreto creciente

```java
    for (i in 10..20){
        println(i)
    }

// SALIDA
10
11
12
13
14
15
16
17
18
19
20
```

Existe la posibilidad de indicar un numero determinado de paso (cantidad de incremento cada vez que se ejecute el for). Para ello es necesario indicarlo con step

```java
    for (i in 10..20 step 5){
        println(i)
    }

// SALIDA
10
15
20
```

- for en un rango concreto decreciente: es necesario indicar downTo para decir hasta que numero es necesario llegue

```java
    for (i in 10 downTo 1){
        println(i)
    }

// SALIDA
10
9
8
7
6
5
4
3
2
1
```

Al igual que en el caso anterior también es posible configurar la cantidad de pasos

- for de una colección de datos: en el caso de tener una colección es posible recorrerla indicando directamente la iteración sobre el elemento

```java
    for (i in (10..15))
    {
        println(i)
    }
// SALIDA
    10
    11
    12
    13
    14
    15
```

- Foreach. Se trata de una función de iteración dentro de una colección. El método nativo tan solo obtiene como parámetro el dato que se está iterando. En el caso de necesitar el índice, es necesario utilizar la función foreachIndexed

```java
(1..5).forEach({ item ->
        println(item)
    })

// SALIDA
1
2
3
4
5
```

```java
(1..5).forEachIndexed { index, value -> println(${index} - ${value} }
// SALIDA
0 - 1
1 - 2
2 - 3
3 - 4
4 - 5
```

- 

# Ejercicios de clase

### Ejercicio 1

Escribe un programa que lea un número entero y que indique si es par o impar.

Ejemplo:

```kotlin
// Entrada
Introduce un número: 7

// Salida
El número 7 es impar
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!.toInt()
    
    if (numero % 2 == 0) {
        println("El número $numero es par")
    } else {
        println("El número $numero es impar")
    }
}
```

### Ejercicio 2

Escribe un programa que lea un número entero y que indique si es positivo, negativo o cero.

Ejemplo:

```kotlin
// Entrada
Introduce un número: -15

// Salida
El número -15 es negativo
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!.toInt()
    
    when {
        numero > 0 -> println("El número $numero es positivo")
        numero < 0 -> println("El número $numero es negativo")
        else -> println("El número es cero")
    }
}
```

### Ejercicio 3

Escribe un programa que lea un número entero y que indique si es primo o no.

Ejemplo:

```kotlin
// Entrada
Introduce un número: 13

// Salida
El número 13 es primo
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!.toInt()
    
    if (esPrimo(numero)) {
        println("El número $numero es primo")
    } else {
        println("El número $numero no es primo")
    }
}

fun esPrimo(n: Int): Boolean {
    if (n <= 1) return false
    if (n <= 3) return true
    
    if (n % 2 == 0 || n % 3 == 0) return false
    
    var i = 5
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) return false
        i += 6
    }
    
    return true
}
```

### Ejercicio 4

Escribe un programa que lea un número entero y que muestre por pantalla todos los números primos menores o iguales al número leído.

Ejemplo:

```kotlin
// Entrada
Introduce un número: 10

// Salida
Los números primos menores o iguales a 10 son: 2, 3, 5, 7
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!.toInt()
    
    val primos = mutableListOf<Int>()
    
    for (i in 2..numero) {
        if (esPrimo(i)) {
            primos.add(i)
        }
    }
    
    println("Los números primos menores o iguales a $numero son: ${primos.joinToString(", ")}")
}

fun esPrimo(n: Int): Boolean {
    if (n <= 1) return false
    if (n <= 3) return true
    
    if (n % 2 == 0 || n % 3 == 0) return false
    
    var i = 5
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) return false
        i += 6
    }
    
    return true
}
```

### Ejercicio 5

Escribe un programa que lea un número entero y que calcule el factorial de ese número.

Ejemplo:

```kotlin
// Entrada
Introduce un número: 5

// Salida
El factorial de 5 es: 120
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!.toInt()
    
    var factorial = 1L
    
    for (i in 2..numero) {
        factorial *= i
    }
    
    println("El factorial de $numero es: $factorial")
}
```

### Ejercicio 6

Escribe un programa que lea un número entero y que calcule la suma de los primeros N números naturales.

Ejemplo:

```kotlin
// Entrada
Introduce un número: 4

// Salida
La suma de los primeros 4 números naturales es: 10
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val n = readLine()!!.toInt()
    
    // Utilizando la fórmula n * (n + 1) / 2
    val suma = n * (n + 1) / 2
    
    // Alternativamente, usando un bucle
    // var suma = 0
    // for (i in 1..n) {
    //     suma += i
    // }
    
    println("La suma de los primeros $n números naturales es: $suma")
}
```

### Ejercicio 7

Escribe un programa que lea un número entero y que calcule la suma de los dígitos de ese número.

Ejemplo:

```kotlin
// Entrada
Introduce un número: 153

// Salida
La suma de los dígitos de 153 es: 9
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!.toInt()
    
    var n = numero
    var suma = 0
    
    while (n > 0) {
        suma += n % 10
        n /= 10
    }
    
    // Alternativa usando manipulación de strings
    // val suma = numero.toString().map { it.toString().toInt() }.sum()
    
    println("La suma de los dígitos de $numero es: $suma")
}
```

### Ejercicio 8

Escribe un programa que lea un número entero y que muestre por pantalla su representación en binario.

Ejemplo:

```kotlin
// Entrada
Introduce un número: 25

// Salida
La representación binaria de 25 es: 11001
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!.toInt()
    
    // Usando método de la librería estándar
    val binario = numero.toString(2)
    
    // Alternativamente, implementación manual
    // var n = numero
    // var binario = ""
    // while (n > 0) {
    //     binario = (n % 2).toString() + binario
    //     n /= 2
    // }
    // if (binario.isEmpty()) binario = "0"
    
    println("La representación binaria de $numero es: $binario")
}
```

### Ejercicio 9

Escribe un programa que lea un número entero y que muestre por pantalla su representación en hexadecimal.

Ejemplo:

```kotlin
// Entrada
Introduce un número: 255

// Salida
La representación hexadecimal de 255 es: FF
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!.toInt()
    
    // Usando método de la librería estándar
    val hexadecimal = numero.toString(16).uppercase()
    
    // Alternativamente, implementación manual
    // val digitos = "0123456789ABCDEF"
    // var n = numero
    // var hexadecimal = ""
    // while (n > 0) {
    //     hexadecimal = digitos[n % 16] + hexadecimal
    //     n /= 16
    // }
    // if (hexadecimal.isEmpty()) hexadecimal = "0"
    
    println("La representación hexadecimal de $numero es: $hexadecimal")
}
```

### Ejercicio 10

Escribe un programa que lea un número entero y que muestre por pantalla su representación en octal.

Ejemplo:

```kotlin
// Entrada
Introduce un número: 64

// Salida
La representación octal de 64 es: 100
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!.toInt()
    
    // Usando método de la librería estándar
    val octal = numero.toString(8)
    
    // Alternativamente, implementación manual
    // var n = numero
    // var octal = ""
    // while (n > 0) {
    //     octal = (n % 8).toString() + octal
    //     n /= 8
    // }
    // if (octal.isEmpty()) octal = "0"
    
    println("La representación octal de $numero es: $octal")
}
```

### Ejercicio 11

Escribe un programa que lea un número entero N y que dibuje un triángulo rectángulo de altura N usando asteriscos.

Ejemplo:

```kotlin
// Entrada
Introduce la altura del triángulo: 4

// Salida
*
**
***
****
```

### Solución

```kotlin
fun main() {
    print("Introduce la altura del triángulo: ")
    val altura = readLine()!!.toInt()
    
    for (i in 1..altura) {
        for (j in 1..i) {
            print("*")
        }
        println()
    }
}
```

### Ejercicio 12

Escribe un programa que lea un número entero N y que compruebe si es un número palíndromo (se lee igual de izquierda a derecha que de derecha a izquierda).

Ejemplo:

```kotlin
// Entrada
Introduce un número: 12321

// Salida
El número 12321 es palíndromo
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!
    
    val reverso = numero.reversed()
    
    if (numero == reverso) {
        println("El número $numero es palíndromo")
    } else {
        println("El número $numero no es palíndromo")
    }
}
```

### Ejercicio 13

Escribe un programa que lea un número entero N y calcule la serie de Fibonacci hasta el N-ésimo término.

Ejemplo:

```kotlin
// Entrada
Introduce un número: 7

// Salida
Serie de Fibonacci hasta el término 7: 0, 1, 1, 2, 3, 5, 8
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val n = readLine()!!.toInt()
    
    val fibonacci = mutableListOf<Int>()
    
    for (i in 0 until n) {
        when (i) {
            0 -> fibonacci.add(0)
            1 -> fibonacci.add(1)
            else -> fibonacci.add(fibonacci[i-1] + fibonacci[i-2])
        }
    }
    
    println("Serie de Fibonacci hasta el término $n: ${fibonacci.joinToString(", ")}")
}
```

### Ejercicio 14

Escribe un programa que lea dos números y muestre su máximo común divisor (MCD).

Ejemplo:

```kotlin
// Entrada
Introduce el primer número: 24
Introduce el segundo número: 36

// Salida
El MCD de 24 y 36 es: 12
```

### Solución

```kotlin
fun main() {
    print("Introduce el primer número: ")
    val a = readLine()!!.toInt()
    print("Introduce el segundo número: ")
    val b = readLine()!!.toInt()
    
    val mcd = calcularMCD(a, b)
    
    println("El MCD de $a y $b es: $mcd")
}

fun calcularMCD(a: Int, b: Int): Int {
    var num1 = a
    var num2 = b
    var temp: Int
    
    while (num2 != 0) {
        temp = num2
        num2 = num1 % num2
        num1 = temp
    }
    
    return num1
}
```

### Ejercicio 15

Escribe un programa que lea un número entero positivo y determine si es un número perfecto (igual a la suma de sus divisores propios).

Ejemplo:

```kotlin
// Entrada
Introduce un número: 28

// Salida
El número 28 es perfecto
```

### Solución

```kotlin
fun main() {
    print("Introduce un número: ")
    val numero = readLine()!!.toInt()
    
    var sumaDivisores = 0
    
    for (i in 1 until numero) {
        if (numero % i == 0) {
            sumaDivisores += i
        }
    }
    
    if (sumaDivisores == numero) {
        println("El número $numero es perfecto")
    } else {
        println("El número $numero no es perfecto")
    }
}
```