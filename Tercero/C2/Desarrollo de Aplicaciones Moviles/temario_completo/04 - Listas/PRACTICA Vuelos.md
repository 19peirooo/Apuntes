# PRACTICA: Vuelos

Status: Not started
🪴 Units: 4. Listas (../Unidades/4%20Listas%20ff4eeadeed7082ad941d016823ffc6d8.md)

Realiza una aplicación que permita gestionar reservas de vuelos. Para ello, la aplicación contará con los siguientes elementos:

- Una pantalla de Login: donde aparecerá un formulario de inicio de sesión mediante correo y contraseña
- Una pantalla de Registro: donde aparecerá un formulario de registro para que el usuario introduzca los datos mediante edit: nombre, correo, pass, spinner para seleccionar el perfil (admin o user) y edad. Es importante no permitir que dos usuarios tengan el mismo correo.
- Una pantalla principal: aparecerá tras un login correcto, donde se mostrará:
    - Una parte superior donde aparecerán dos spinner para seleccionar ciudad origen y ciudad destino y un botón para agregar el vuelo
    - Una parte central donde aparecerá un recyclerview mostrando los siguientes elementos:
        - un toolbar donde en el título ponga la ciudad de origen y la ciudad de destino. Además el toolber tendrá un menú con las siguientes opciones:
            - marcar favorito: se marcará el vuelo correspondiente como favorito
            - ver detalles: se cargará una cuarta pantalla.
        - dos imágenes combinadas donde se mostrará la imagen de la ciudad de origen y la ciudad de destino
    - En la barra superior, habrá un menú con las siguientes opciones:
        - Cerrar sesión: tras pulsarlo se volverá a la pantalla login
        - Ver favoritos: mostrará una pantalla con los vuelos favoritos del usuario
- Una pantalla de detalles: donde se mostrará información sobre el vuelo seleccionado
- Una pantalla de favoritos: donde se mostrará un recycler con los vuelos favoritos de usuario que esté registrado

<aside>
💡

Crea todos los objetos / modelos necesarios para poder realizar la app

</aside>

<aside>
💡

Organiza la interfaz gráfica de la mejor forma posible

</aside>

<aside>
💡

Para el almacenamiento, utiliza un Dataset con una lista metida en un objeto de tipo companion

</aside>