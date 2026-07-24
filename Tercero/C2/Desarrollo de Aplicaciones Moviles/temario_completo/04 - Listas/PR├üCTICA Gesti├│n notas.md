# PRÁCTICA: Gestión notas

Status: Not started
🪴 Units: 4. Listas (../Unidades/4%20Listas%20ff4eeadeed7082ad941d016823ffc6d8.md)

# Ejercicio: App Gestión de Notas de Alumnos

Desarrolla una aplicación Android llamada **GestorNotas** que permita gestionar una lista de alumnos y asignarles notas numéricas (de 0 a 10). La app debe simular un registro escolar básico donde el profesor visualiza alumnos, selecciona uno para editar su nota mediante un diálogo. Para la gestión de las notas, puedes utilizar un DataSet, de forma que todos los datos sean persistentes durante la ejecución de la aplicacion 

## Requisitos Funcionales

1. **Pantalla principal (MainActivity)**
    - Debe mostrar un **RecyclerView** con la lista de alumnos cargados desde la base de datos.
    - Cada ítem del RecyclerView debe mostrar:
        - El nombre del alumno.
        - Su nota actual en formato, por ejemplo: `Alumno 1 – Nota: 7.5`.
    - Al iniciar la app por primera vez, si los datos están vacíos, se deben insertar automáticamente al menos 10 alumnos de ejemplo (por ejemplo: “Alumno 1”, “Alumno 2”, …, con nota inicial 0.0)
2. **Interacción con el RecyclerView (callback)**
    - El Adapter del RecyclerView debe definir una **interfaz de callback** (por ejemplo, `OnAlumnoClickListener`)
    - Al pulsar sobre un ítem de la lista, se debe llamar a ese callback y notificar a la Activity qué alumno ha sido seleccionado para mostrar un cuadro de diálogo con la nota del alumno y la posibilidad de modificarla
3. **Edición de notas mediante cuadro de diálogo**
    - Al pulsar sobre un alumno, la MainActivity mostrará un **AlertDialog** que permita modificar la nota de ese alumno.
    - El diálogo debe contener:
        - Un `EditText` para introducir la nueva nota.
        - Un botón **Guardar**.
        - Un botón **Cancelar**.
    - Validaciones mínimas:
        - La nota debe ser numérica (double o float).
        - Debe estar entre 0.0 y 10.0.
        - Si el valor no es válido, se mostrará un mensaje de error (por ejemplo, con un Toast o un mensaje en el propio diálogo) y no se cerrará hasta que se introduzca un valor correcto.
    - Al pulsar **Guardar** y si la nota es válida:
        - Se debe actualizar la nota en la base de datos para ese alumno.
        - Se debe recargar la lista del RecyclerView para mostrar la nota actualizada sin reiniciar la Activity completa.
4. **Añadir nuevos alumnos (SecondActivity)**
    - En la MainActivity debe haber un menú con una opción donde al pulsarlase podrá añadir para añadir un nuevo alumno.
    - Al pulsar este menú, se abrirá una **SecondActivity** donde el usuario podrá introducir:
        - Nombre del nuevo alumno (EditText).
    - La nota inicial de los nuevos alumnos será 0.0 por defecto (no hace falta que el usuario la introduzca).
    - Al pulsar en un botón **Guardar** en esta segunda pantalla:
        - Se insertará el nuevo alumno en la base de datos.
        - Se cerrará la SecondActivity, devolviendo el control a MainActivity.
    - De vuelta en MainActivity, la lista del RecyclerView debe recargarse para mostrar el alumno recién añadido.