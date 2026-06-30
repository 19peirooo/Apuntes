// 1. Clonar un array con spread
// let arr1 = [1,2,3]
// let arr2 = [...arr1]
// console.log("Ejercicio 1: ")
// console.log("Array 1: ", arr1)
// console.log("Array 2: ", arr2)

// 2. Combinar arrays con spread
// let arr1 = [1,2,3]
// let arr2 = [4,5,6]
// let arr3 = [...arr1,...arr2]
// console.log("Ejercicio 2: ")
// console.log("Array 1: ", arr1)
// console.log("Array 2: ", arr2)
// console.log("Array 3: ", arr3)

//3. Añadir elementos con spread
// let arr1 = [10,20,30]
// let arr2 = [5,...arr1,40]
// console.log("Ejercicio 3: ")
// console.log("Array 1: ", arr1)
// console.log("Array 2: ", arr2)

//4. Extraer el primer elemento y guardar el resto en otra variable con rest
// let arr1 = [1,2,3,4,5]
// let arr2 = [first, ...resto] = arr1
// console.log("Ejercicio 4: ")
// console.log("Primer Elemento: ", first)
// console.log("Resto: ", resto)

//6. Multiplica por 2 cada elemento con map
// let arr1 = [1,2,3,4]
// let arr2 = arr1.map(x => x*2)
// console.log("Ejercicio 6: ")
// console.log("Array 1: ", arr1)
// console.log("Array 2: ", arr2)

//7. Filtrar los numeros pares
// let arr1 = [1,2,3,4,5,6]
// let arr2 = arr1.filter(x=> x%2==0)
// console.log("Ejercicio 7: ")
// console.log("Array 1: ", arr1)
// console.log("Array 2: ", arr2)

//8. Encontrar el primer numero mayor que 10
// let arr1 = [4,9,16,25,36]
// let num = arr1.find(x => x > 10)
// console.log("Ejercicio 8: ")
// console.log("Array 1: ", arr1)
// console.log("Primer Numero Mayor que 10: ", num)

//9. Comprueba si hay algun numero mayor que 15
// let arr1 = [5,8,12,20]
// let mayorQue15 = arr1.some(x => x > 15)
// console.log("Ejercicio 9: ")
// console.log("Array 1: ", arr1)
// console.log("Numero mayor que 15: ", mayorQue15)

//10. Comprueba si todos los numeros son pares
let arr1 = [2,4,6,8]
let pares = arr1.every(x => x%2 == 0)
console.log("Ejercicio 10: ")
console.log("Array 1: ", arr1)
console.log("Son todos pares: ", pares)

//11. 