# PRÁCTICA: Trabajadores

Status: Not started
🪴 Units: 5. Diálogos y menús (../Unidades/5%20Di%C3%A1logos%20y%20men%C3%BAs%201a0eeadeed708261a57d0160f016c827.md)

Crear una aplicación para gestionar los trabajadores de una empresa. Para ello la aplicación contaría con una pantalla donde:

- En el 40% superior aparezca un formulario de introducir los datos del trabajador: Nombre, Apellidos, Correo, Edad, Puesto de trabajo (un spinner con las opciones administrativo, comercial, soporte, informática) y un botón de guardar. Al pulsar el botón se agregará un objeto de tipo usuario al RecyclerView de la parte inferior
- En el 60% restante mostrar un RecyclerView lineal donde irán apareciendo los usuarios que se introducen con el formulario de la parte superior. En dicho RecyclerView tan solo se mostrará el nombre y el apellido. Al pulsar en cualquier parte de la fila aparecerá un cuadro de diálogo con todos los detalles del usuario.