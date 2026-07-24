# Arrays y colecciones

Status: Not started
🪴 Units: 1. Kotlin (../Unidades/1%20Kotlin%208f7eeadeed7083b7999681d83031c8ac.md)

# Arrays

Los arrays en kotlin son elementos de tipo Array. Para poder crear un array existen diferentes posibilidades.

```kotlin
var arrayEmpty = emptyArray<String>();
var arrayNull = arrayOfNulls<String>(5);
var arrayCosas = arrayOf(1,2,3,4,5,6,true);
var arrayNumeros = intArrayOf(1,2,3,4,5,6,7);

```

En el código anterior las inicializaciones son diferentes en los siguientes sentidos:

- La primera inicialización crea un array vario de String, sin ninguna posición y sin un tamaño definido.
- La segunda inicialización crea un array de Nulls (creado para String) con un tamaño de 5 posiciones.
- La tercera inicialización crea un array de cualquier tipo (Any en kotlin) con elementos ya guardados
- La cuarta inicialización crea un array de Int con datos ya guardados. Es importante tener en cuenta que este tipo de inicialización no crea un objeto de tipo Array, sino de IntArray. Pasa exactamente igual con el resto de los tipos

Otra forma de poder inicializar un array con datos ya guardaros es la siguiente:

```kotlin
var arrayInicializado = Array<Int>(6) { (it + 1) };
// 1,2,3,4,5,6

```

De esta forma se puede indicar el tamaño del array (en este caso 6) y con la función indicar el valor de cada uno de los elementos. PAra ello el argumento it es el indice que se utiliza para recorrer

En el caso de querer acceder y modificar las posiciones del array, se utiliza la forma normal que tiene java, pudiendo también utilizar la funcion get y set para acceder y modificar posiciones respectivamente

```kotlin
    println(arrayEmpty[0])
    println(arrayEmpty.get(0))
    println(arrayNull.get(0))
    println(arrayNull.set(0,"Primer elemento"))

```

Si se quiere recorrer de forma completa un array se puede utilizar un for, un foreach o un fereach con indice

```kotlin
for (cosa in arrayCosas) {
        println(cosa);
    }
arrayNumeros.forEach { it -> print(it) }
arrayNumeros.forEachIndexed({index: Int, it:Int->println("$index - $it")})

```

## Operaciones de búsqueda en arrays

Cuando se quiere buscar elementos dentro de un array, en java se tiene que recorrer el array de forma completa. Sin embargo en kotlin existen una serie de métodos que realizan todo el trabajo de búsqueda de firma directa. El primero de ellos es el método find. Este método retorna el primer elemento del array que se encuentre con la condición indicada, para lo que se utiliza un argumento dentro de la función lambda

```kotlin
var lenguajes = arrayOf("Java", "Kotlin", "C#", "Python", "JavaScript", "PowerScript");
var encontrado = lenguajes.find { elemento: String -> elemento.contains("Script") }
println(encontrado)

// SALIDA
JavaScript

```

El otro método que permite realizar una búsqueda es filter. En este caso el retorno del método es un array con los elementos que cumplen la condición indicada en el predicado

```kotlin
var busqueda = lenguajes.filter { elemento -> elemento.length> 5 }
busqueda.forEach { println(it) }

// SALIDA
Kotlin
Python
JavaScript
PowerScript
```

## Ejercicios de clase

1. Crea un array de Strings con los nombres de 5 compañeros. A continuación, recorre el array y escribe el nombre de cada persona en la consola.
2. Crea un array de enteros con la serie de Fibonacci de los primeros 20 números. A continuación, recorre el array y escribe cada número en la consola.
3. Crea un array de enteros con los números del 1 al 10. A continuación, utiliza el método `filter` para obtener sólo los números impares. Escribe los números impares en la consola.
4. Crea un array de Strings con los nombres de tus profesores de la universidad. A continuación, utiliza el método `find` para obtener el primer nombre que contenga la letra 'a'. Escribe el nombre en la consola.
5. Crea un array de enteros con los números del 1 al 5. A continuación, utiliza el método `map` para multiplicar cada número por 2. Escribe los números resultantes en la consola.
6. Crea un array de enteros con los números del 1 al 10. A continuación, utiliza el método `reduce` para obtener la suma de todos los números. Escribe el resultado en la consola.
7. Crea un array de Strings con los nombres de tus 5 películas favoritas. A continuación, utiliza el método `joinToString` para unir los nombres en una sola cadena, separados por comas. Escribe la cadena resultante en la consola.
8. Crea un array de enteros con los números del 1 al 5. A continuación, utiliza el método `sortedDescending` para ordenar los números de forma descendente. Escribe los números resultantes en la consola.
9. Crea un array de enteros con los números del 1 al 10. A continuación, utiliza el método `slice` para obtener los elementos de la posición 2 a la posición 6. Escribe los números resultantes en la consola.
10. Crea un array de enteros con los números del 1 al 5. A continuación, utiliza el método `all` para comprobar si todos los números son menores que 10. Escribe el resultado en la consola.

# Colecciones

Al igual que pasa en java, los arrays pueden quedar algo cortos debido a su poca mutabilidad. Esto quiere decir que en el caso de tern un array con 5 posiciones, este no puede crecer y tan solo podría ser modificados los valores que están guardados en las posiciones. Para poder paliar este tipo de carencia, existe lo que se conoce como colecciones o listas mutables. En este apartado veremos el uso de los ArrayList

Para poder crear un arraylist, no es necesario indicar cual es el tamaño inicial, ni siquiera que elementos forman parte del mismo. Basta con crear el objecto con su constructor

```java
var lista: ArrayList<String> = ArrayList<String>()
```

Lo que si es obligatorio es indicar el tipo del dato que va a guardad dentro.En el ejemplo anterior se indica que se procede a guardar datos de tipo String. Una vez está creado la colección, los principales métodos que se pueden utilizar son los siguientes:

- add o addAll: Permite agregar un elemento en una posición determinada. En el caso de no indicar cual es la posición donde se agrega el elemento, este se podrá al final de la lista. El tipo de retorno es boolean, indicando si la tarea se ha realizado correctamente.

```java
var lista: ArrayList<String> = ArrayList<String>()
    lista.add("Primer")
    lista.add("elemento")
    lista.add("de")
    lista.add("la")
    lista.add("lista")

// SALIDA
Primer, elemento, de, la, lista

```

- remove o removeAt: Permite borra elemento de la lista indicado. También se puede borrar por posición. El tipo de retorno es booleano, indicando si se ha hecho la acción correctamente.

```java
// siendo lista = Primer, elemento, de, la, lista
    lista.removeAt(0);
    lista.remove("de")
// SALIDA
Primer, elemento, la, lista
```

- get: Permite obtener un elemento concreto, siendo buscado por posición.

```java
// siendo lista = Primer, elemento, de, la, lista
println(lista.get(0));
// Salida
Primer
```

Otros métodos interesantes son:

```java
// obtiene el primer elemento que cumple una condición
lista.filter { it.length == 2 }
// elimina de la lista todos aquellos elmeentos que cumplen una condición
lista.removeIf { it.length == 3 }
```