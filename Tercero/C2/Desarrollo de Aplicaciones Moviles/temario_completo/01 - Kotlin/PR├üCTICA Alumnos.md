# PRÁCTICA: Alumnos

Status: Not started
🪴 Units: 1. Kotlin (../Unidades/1%20Kotlin%208f7eeadeed7083b7999681d83031c8ac.md)

Crea una aplicación que permita gestionar el funcionamiento de un centro escolar. Para ello se pide la creación de las siguientes clases

## Alumno

Esta clase representa uno de los objeto que podrá gestionar el centro escolar. Los atributos con los que cuenta la clase son los siguientes:

- id: único . Todos los alumnos tendrán un id
- nombre: Todos los alumnos tendrán este atributo.
- apellido: Todos los alumnos tendrán este atributo
- telefono: Tan solo aquellos alumnos que indiquen dicho dato lo tendrán, el resto tendrá asignado un null
- correo: Tan solo aquellos alumnos que indiquen dicho dato lo tendrán, el resto tendrá asignado un null
- calificacion: Todos los alumnos tendrán este atributo, con un valor inicial de 0;
- matriculado: Todos los alumnos tendrán este atributo, inicializado a true por defecto

En cuanto a los métodos de la clase tendrán lo siguientes

- mostrarDatos: Se mostrarán todos los datos del alumno. En el caso de no contar con alguno, se mostrará “dato no disponible”
- desmatricular: Cambiará el valor de la propiedad matriculado false
- calificar: Asignará el número pasado por parámetros a la variable calificación

## Colegio

Esta clase representa la funcionalidad general de la aplicación, donde se gestionarán todos los elementos del colegio. Los atributos con los que cuenta la clase son los siguientes:

- listado: cantidad de alumnos que están matriculados en el centro escolar.

En cuanto a los métodos que tiene, serán los siguientes:

- agregar alumno: encargado de agregar un alumno a la lista. Es importante tener en cuenta que no pueden existir dos alumnos con el mismo id
- calificar alumno: encargado de calificar el alumno cuyo id se ha pasado por parámetros
- listar alumno:  encargado de mostrar todos los alumnos. Este método podrá listar todos los alumnos, solo los que están matriculados o los que no están matriculados
- calificar alumno: encargado de poner la nota al alumno cuyo id es pasado por parámetros
- dar de baja alumno: encargado de desmatricular el alumno cuyo id es el indicado.

<aside>
💡 Todos los datos son introducidos en la entrada.

</aside>