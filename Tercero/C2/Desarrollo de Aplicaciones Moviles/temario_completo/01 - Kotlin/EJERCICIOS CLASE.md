# EJERCICIOS CLASE

Status: Not started
🪴 Units: 1. Kotlin (../Unidades/1%20Kotlin%208f7eeadeed7083b7999681d83031c8ac.md)

## Sentencias de control

### Ejercicio 1: Planificador de tarifas eléctricas

Dada una hora del día y el día de la semana, calcula el precio por kWh según tramos (valle, llano, punta) y festivos. Usa when con rangos y múltiples condiciones compuestas. Devuelve además un texto explicativo del tramo aplicado.

### Ejercicio 2: Validador de contraseñas con reglas

Escribe una función que, dado un String contraseña, aplique reglas: longitud mínima, al menos 1 mayúscula, 1 minúscula, 1 dígito y 1 símbolo. Usa if/when y devuelve un sealed class Resultado { Valida | Invalida(errores: List<String>) } con todas las causas.

### Ejercicio 3: Analizador de notas con curvas

Dado un listado de notas 0..10, clasifícalas en Sobresaliente, Notable, Aprobado, Suspenso pero aplicando una curva según la media del grupo. Usa when y condiciones sobre media y desviación. Devuelve un resumen con porcentajes y el motivo de la curva.

### Ejercicio 4: Máquina expendedora

Simula un flujo de compra con saldo, selección de producto y cambio. Debes manejar errores con when: producto no válido, saldo insuficiente, falta de cambio. Devuelve códigos de estado y mensajes.

## Funciones

### Ejercicio 1: DSL de consultas sobre texto

Define funciones de orden superior que permitan construir consultas como: texto.buscar { contiene("kotlin") y empiezaCon("fun") o terminaCon(";") }. Usa funciones como infix y lambdas. Devuelve coincidencias y métricas.

### Ejercicio 2: Memoización genérica

Implementa una función memoize para funciones (T) -> R que cachee resultados según el argumento. Demuestra su uso con una función costosa como fibonacci y mide mejoras con System.nanoTime.

### Ejercicio 3: Pipeline con funciones parciales

Crea funciones parciales para procesar pedidos: validar -> aplicarDescuentos -> calcularImpuestos -> totalizar. Usa composición de funciones y parámetros por defecto. Permite activar o desactivar pasos con banderas.

### Ejercicio 4: Extensiones con reified y inline

Escribe una función inline reified T que convierta un Any a T? de forma segura usando when y reflexión mínima, y añade pruebas rápidas.

## Arrays y colecciones

### Ejercicio 1: Estadística descriptiva eficiente

Dado un IntArray grande, calcula media, mediana, moda, varianza y percentiles 25-50-75 en O(n log n) o mejor. Evita copias innecesarias y compara rendimiento con listas.

### Ejercicio 2: Índice invertido de palabras

Construye un Map<String, MutableSet<Int>> que mapee cada palabra a las líneas en las que aparece en un texto. Normaliza acentos y mayúsculas. Optimiza usando secuencias y chunked.

### Ejercicio 3: Ventana deslizante y máximos

Para una lista de enteros y una ventana k, calcula el máximo de cada ventana en O(n) usando una Deque. Proporciona versión basada en arrays y en listas.

### Ejercicio 4: Operaciones set y joins

Dados tres conjuntos A, B, C, calcula A ∩ B, (A ∪ B) − C y una intersección múltiple. Luego, realiza un join entre una lista de Personas y una lista de Compras por id usando asociarBy y groupBy.

## Clases, herencia y polimorfismo

### Ejercicio 1: Jerarquía de pagos con Strategy

Crea una jerarquía Pago con estrategias Tarjeta, Paypal y Cripto. Usa una interfaz Procesador con calcularComision() y aplicarPago(). Inyecta la estrategia en tiempo de ejecución y demuestra polimorfismo con una lista de pagos mixtos.

### Ejercicio 2: Inventario con herencia y equals/hashCode

Define una clase base Producto(nombre, precio) y subclases Perecedero(fechaCaducidad) y Digital(licencia). Implementa data classes cuando proceda y personaliza equals/hashCode para considerar lote o licencia. Usa conjuntos para evitar duplicados.

### Ejercicio 3: Árbol de componentes con Composite

Modela un sistema de archivos con Component, Archivo y Carpeta. Implementa operaciones tamañoTotal(), buscar(nombre) y prettyPrint(). Demuestra polimorfismo recorriendo una estructura anidada.

### Ejercicio 4: Polimorfismo exhaustivo con sealed

Crea una sealed class ResultadoCarga con estados Exito(datos), ErrorRed(código), ErrorFormato(detalle), Cancelado. Usa when exhaustivo en funciones que transformen y mapeen estos estados, y añade pruebas.