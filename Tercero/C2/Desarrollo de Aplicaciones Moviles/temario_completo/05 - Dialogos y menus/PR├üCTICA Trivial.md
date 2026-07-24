# PRÁCTICA: Trivial

Status: Not started
🪴 Units: 5. Diálogos y menús (../Unidades/5%20Di%C3%A1logos%20y%20men%C3%BAs%201a0eeadeed708261a57d0160f016c827.md)

Realiza una aplicación que simule el funcionamiento del trivial. Para ello la aplicación constará delos siguientes elementos:

- ActivityLogin
- ActivityRegister
- GameActivity
- QuestionDialog
- RecordDialog
- FilterDialog
- MainMenu
- GameMenu

Cada una de estos elementos realizará la siguiente funcionalidad

- ActivityLogin: Formulario de inicio de sesión con los campos que consideres oportunos, mínimo deberán tener campos para correo y pass.Además, esta pantalla contará con un menu con la opción de ver record. Esta opción no se mostrará en forma de texto, sino que lo hará en forma de icono

- ActivityRegister: Formulario de registro de los usuarios con los campos que consideres. No se podrán registrar dos usuarios con el mismo nick ni con el mismo correo. Además la contraseña deberá contar con al menos 6 caracteres

> Para poder hacer el login y registro, este se realizará desde un DataSet, donde se ubicará una lista de usuarios en un companion object
> 

- GameActivity: Pantalla donde se desarrollará el juego. La disposición de esta pantalla puedes plantearla como quieres, siempre y cuando se cumplan los siguientes requisitos:
    - En la parte superior (toolbar) apareceré el mensaje de Jugando XXX, donde XXX es el nick del usuario que ha iniciado sesión
    - En la parte superior se mostrará un menú con las siguientes opciones:
        - Cerrar sesión: se mostrará también como icono y llevará a la pantalla de inicio de sesión
        - Información: mostrará un cuadro de diálogo donde se mostrarán datos del usuario como: nombre, correo, nick, número de veces jugadas, mayor número de aciertos
    - En la parte central se podrá indicar el número de preguntas que se quieren jugar, un botón para iniciar el juego así como un campo para ver los aciertos que se llevan en la sesión
    
    Al pulsar el botón iniciar se cargarán las preguntas con las que el jugador arrancará el juego. Para ello se consultará al siguiente JSON: [https://opentdb.com/api.php?amount=20](https://opentdb.com/api.php?amount=20), donde la variable amount muestra el número de preguntas que tiene la petición. Una vez cargadas, se irán arrancando tantos cuadros de diálogo como preguntas existan. 
    
- QuestionDialog: Se mostrará un cuadro de diálogo por pregunta. Donde se mostrará en el título la pregunta y una lista de opciones con las posibles respuestas. Tras aceptar la respuesta, en el caso de acertarla se sumará un punto. Cuando se conteste una pregunta, de forma automática, se lanzará el siguiente cuadro de diálogo (siempre y cuando haya preguntas por mostrar)

- RecordDialog: Cuadro de diálogo que se podrá sacar desde la pantalla de login, con la pulsación del menú. En este cuadro de diálogo, se mostrar el nick y numero de aciertos del usuario que haya contestados más preguntas de forma correcta en una sola sesión