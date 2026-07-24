# Funciones

Status: Not started
🪴 Units: 1. Kotlin (../Unidades/1%20Kotlin%208f7eeadeed7083b7999681d83031c8ac.md)

**Documentación oficial:** [https://kotlinlang.org/docs/reference/functions.html](https://kotlinlang.org/docs/reference/functions.html)

Las funciones en kotlin se declaran con la palabra reservada `fun`

```kotlin
fun nombreFuncion(){}
```

La principal función y que es el punto de entrada de ejecución es la función main

```kotlin
fun main(arguments: Array<String>) {
}
```

Para poder declarar parámetros dentro de una función se definen con un nombre y el tipo del mismo

```kotlin
fun funcionParamentros(arg1: String, arg2: Int){
    println("$arg1 es el primer parámetro")
    println("$arg2 es el segundo parámetro")
}

fun main(arguments: Array<String>) {
    funcionParametros("Uno",2)
}
```

Una de las cosas que es muy diferente con respecto a java, es que se puede nombrar a los parámetros cuando se llama la función

```kotlin
fun main(arguments: Array<String>) {
    funcionParametros(arg1="Uno",arg2=2);
}
```

Del mismo modo, cuando se declarar argumentos dentro de una función, también se le pueden dar valores por defecto en el caso de que no sean pasados

```kotlin
fun funcionParametros(arg1: String="valor por defecto", arg2: Int=3){
    println("$arg1 es el primer parámetro")
    println("$arg2 es el segundo parámetro")
}

fun main(arguments: Array<String>) {
    funcionParametros()
}

// SALIDA
valor por defecto es el primer parámetro
```

En el caso de que la función solo tenga una linea, se puede crear junto con el operador =

```kotlin
fun sumaParametros (op1: Int, op2: Int) =  println(op1 + op2)
fun main(){
    suma(8,2);
}

// SALIDA
10

```

Si no se define que una función tenga un retorno concreto, este será Unit (es lo mismo que void en Java). En el caso de querer un retorno específico, se define después de los parámetros de la función y antes del cuerpo

```kotlin
fun declaracionFuncion(): String{
 // cuerpo de la funcion
 return "Retorno"
}

fun sumaRetorno(op1: Int, op2:Int): Int{
    return op1 + op2
}

fun main(arguments: Array<String>) {
    println("La función de suma ha retornado "+sumaRetorno(4,5));
}

// SALIDA
La función de suma ha retornado 9
```

## Funciones Lambda

Una función lambda es aquella que se define de forma directa, sin necesidad de declararla como las vistas en el punto anterior. Para ello se puede declarar con la siguiente sintaxis

```kotlin
{arg1: Tipo, arg2: Tipo) -> // cuerpo de la funcion}
```

En muchos de los casos la función lambda se suele asociar a una variable. Para ello se puede definir el tipo al que se le asigna.

```kotlin
var lambdaSuma = {arg1: Int, arg2: Int -> print("la suma entre $arg1 y $arg2 es "+arg1.plus(arg2))}
// la misma definición que el anterior, pero declarando el tipo
var lambdaSumaValida: (Int,Int)->Unit = {arg1: Int, arg2: Int -> print("la suma entre $arg1 y $arg2 es "+arg1.plus(arg2))}
```

En el caso de querer que la función lambda retorne algo, se puede indicar al igual que las funciones

```kotlin
var funcionLambdaNormal: ((Int) -> Int) = { argumento1: Int ->
    if (argumento1 > 0) {
        1
    } else {
        0
    }
}
```

Algún ejemplo de función lambda con diferentes configuraciones es:

```kotlin
// función lambda que tiene un parámetro obligatorio y que puede retornar nulo
var funcionLambdaNull: ((Int)->Int?) = {argumento1: Int-> if (argumento1>0) 6 else null}

// función lambda que tiene un parámetro obligatorio y que puede ser nula la funcion entera
var funcionLambdaNullEntera: ((Int)->Int)? = {argumento1: Int-> if (argumento1>0) 6 else 7}

// en el caso de funcion nula completa hay que utilizar invoke para llamarlo

fun main(arguments: Array<String>) {
    //println(funcionLambdaNull(0))
    println(funcionLambdaNullEntera?.invoke(-1));
}
```

# Ejercicios de clase

1. Crea una función que sume dos números enteros y retorne el resultado.
2. Crea una función que tome una lista de números enteros y retorne el número máximo de la lista.
3. Crea una función que tome un número entero y retorne verdadero si es par y falso si es impar.
4. Crea una función que tome una cadena y retorne el número de caracteres que tiene.
5. Crea una función que tome una lista de cadenas y retorne una cadena que contenga todas las cadenas de la lista separadas por espacios.
6. Crea una función que tome un número entero y que retorne una lista de los números enteros desde 1 hasta el número ingresado.
7. Crea una función que tome una lista de números enteros y que retorne una lista que contenga el cuadrado de cada número en la lista.
8. Crea una función que tome una lista de números enteros y que retorne la suma de todos los números en la lista.
9. Crea una función que tome una lista de cadenas y que retorne una lista de las cadenas que contengan la letra "a".
10. Crea una función que tome una lista de números enteros y que retorne el número menor de la lista.