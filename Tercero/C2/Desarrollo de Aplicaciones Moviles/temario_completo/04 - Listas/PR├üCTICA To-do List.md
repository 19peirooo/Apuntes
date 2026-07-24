# PRÁCTICA: To-do List

Status: Not started
🪴 Units: 4. Listas (../Unidades/4%20Listas%20ff4eeadeed7082ad941d016823ffc6d8.md)

Realiza una aplicación que permita mediante un RecyclerView mostrar una lista de tareas. Para ello la estructura de la aplicación será la siguiente: 

En la parte superior se mostrará dos spinner: 

- Un primer spinner personalizado donde aparecerá un icono junto con un texto: baja, media y prioritaria
- Un segundo spinner personalizado donde aparecerá un icono junto con un texto: por hacer, haciendo, hecho

En la parte central aparecerá un RecyclerView con tareas (previamente cargadas en una lista). La lista mostrará un icono, el título de la tarea y la fecha de creación. Al pulsar en cualquier parte de la fila se abrirá una segunda activity. Cuando se produzca un cambio en las selecciones de los spinner se realizará un filtrado en la lista a mostrar

La segunda activity mostrará el detalle de la tarea seleccionada, mostrando en pantalla todos los datos de la misma

<aside>
💡 Los spinner de filtrado funcionan automáticamente, es decir que en el momento de existir un cambio de selección, la lista se modifica. Incluir una opción dentro de los spinner para poder volver a la lista inicial

</aside>

<aside>
💡 Se debe crear un objeto de tipo tarea con al menos los siguientes campos: tipo, prioridad, fecha, titulo, descripción, estado

</aside>

<aside>
💡 La lista de tareas deberá existir nada más crear la aplicación, por lo que debéis crear al menos 10 tareas con diferentes tipos.

</aside>

<aside>
💡 El diseño de las pantallas es personalizado, siendo lo más amigable posible

</aside>

# Modificación de la práctica

Una vez realiza la parte anterior, realizar las siguientes modificaciones:

1. Añadir un formulario en la parte superior con dos campos (EditText para el título y Spinner para el tipo de prioridad) y un botón. Al pulsar el botón añadir se agregará la tarea a la lista
2. Si se deja pulsado una tarea en formato largo, la tarea se marcará como completada. En el caso de mostrar el icono de estado en el recycler view, este deberá cambiar también. Además de esto, deberá aparecer un Snackbar con el aviso de tarea completada

Recursos necesarios para realizar la práctica

[todo recursos.zip](PR%C3%81CTICA%20To-do%20List/todo_recursos.zip)

La entrega se realizará mediante aula virtual con los siguientes archivos: 

- Link del repositorio GitHub (privado) previamente compartido
- Video con captura de pantalla mostrando el funcionamiento. No hay que explicar código, ni comentar el uso, tan solo mostrar el funcionamiento de la aplicación. El nombre del video será nombre_apellido