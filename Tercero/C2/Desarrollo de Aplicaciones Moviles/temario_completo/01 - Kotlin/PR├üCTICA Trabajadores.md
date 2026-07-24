# PRÁCTICA: Trabajadores

Status: Not started
🪴 Units: 1. Kotlin (../Unidades/1%20Kotlin%208f7eeadeed7083b7999681d83031c8ac.md)

Realizar una aplicación para la gestión de trabajadores. La aplicación podrá registrar trabajadores (asalariados, autónomos y/o jefes). Cada uno de los anteriores tiene las siguientes características:

- Jefes: nombre, apellido, dni, acciones, beneficio, sueldo. Los jefes tendrán la capacidad de despedir un trabajador.
- Asalariados: nombre, apellido, dni, sueldo, número de pagas, contratado (booleano), coutaSS
- Autónomo: nombre, apellido, dni, sueldo, contratado (booleano)

Cada uno de los trabajadores tendrá la capacidad de calcular su salario mensual. Para ello cada uno realizará el calculo de la siguiente forma: 

- Asalariados: su salario mensual es su salario (quitándole el 21%) dividido entre el número de pagas
- Autónomos: su salario mensual es su salario total menos la multiplicación de 12 por la couta de la ss, dividido todo entre 12
- Jefe su salario mensual será el salario total entre 12

Adicionalmente existirá una clase Empresa que tendrá una lista de trabajadores, donde se podrán registrar todos los trabajadores de la empresa

- La aplicación tendrá la capacidad de:
- Registrar un trabajador. Para ello preguntará si se quiere registrar un asalariado, autónomo o jefe y pedirá los datos del trabajador
- Listar trabajadores. Para ello preguntará si se quiere listar los asalariados, los autónomos o todos
- Mostrar datos de trabajador. Para ello pedirá el DNI y mostrará los datos:
- Despedir trabajador: Para ello pide el dni del jefe y del trabajador a despedir y elimina a de la lista

El formato de salida para cada uno de los usuarios es el siguiente:

- Si es jefe:

Nombre: XXX Apellido: XXX DNI: XXX Acciones: XXX Beneficio: XXX

- Si es asalariado:

Nombre: XXX Apellido: XXX DNI: XXX Salario Anual: XXX Salario Mensual: XXX Número de Pagas: XX

- Si es autónomo

Nombre: XXX Apellido: XXX DNI: XXX Salario Anual: XXX

- Realizar un menú para gestionar todos los casos anteriores, teniendo en cuenta las siguientes restricciones:
- En una empresa no pueden existir dos trabajadores con el mismo DNI
- En una empresa no puede haber registrado más que un jefe
- Para poder despedir un trabajador, solo lo puede hacer un jefe
- Utilizar la herencia y el polimorfismo para juntar el máximo de propiedades y métodos