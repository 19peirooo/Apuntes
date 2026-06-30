//Archivo math.js

//Exportar normal
export const sumar = (a,b) => a+b
export const restar = (a,b) => {return a-b} //Return solo si llaves

//Exportar Default
export default class Calculadora {

    constructor(a,b) {
        this.num1 = a
        this.num2 = b
    }

    sumar() {
        return this.num1 + this.num2
    }

    restar() {
        return this.num1 - this.num2
    }

}