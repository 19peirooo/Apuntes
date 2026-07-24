# PRÁCTICA: adivinación cartas

Status: Not started
Type: Lab
🪴 Units: 2. Android Studio: primeros pasos (../Unidades/2%20Android%20Studio%20primeros%20pasos%201c2eeadeed70829a8199011feab9aa2b.md)

Realiza una aplicación de juego de cartas. Para ello la aplicación contará con dos
pantallas con la siguiente funcionalidad:

- Pantalla inicial: en ella se podrá introducir un nombre mediante un EditText.
    - En el caso de pulsar el botón empezar y no tener nombre introducido aparecerá un SnackBar con el aviso de “Por favor introduce nombre”
    - En el caso de pulsar el botón y tener un nombre introducido aparecerá un SnackBar con el mensaje, “Perfecto Borja, quieres empezar” y una acción con el botón OK
- Pantalla juego: en ella aparecerá un juego de up&down, donde con un fondo de
carta, se tendrá que adivinar el valor futuro de la carta. Antes de empezar el
juego, aparecerá un Snackbar con el mensaje “Bienvenido” y el nombre
introducido en la primera pantalla y un botón para poder empezar. Cuando se
pulsa se iniciará la mecánica de juego. Nada pulsar aparecerá una carta
aleatoria. Al pulsar en el botón arriba o abajo, en el caso de aceptar se modificará
la carta. En el caso de fallar aparecerá un Snackbar con el valor de los puntos con un botón donde al pulsarlo la pantalla se cerrará

![cartas1.png](PR%C3%81CTICA%20adivinaci%C3%B3n%20cartas/cartas1.png)

![cartas2.png](PR%C3%81CTICA%20adivinaci%C3%B3n%20cartas/cartas2.png)

<aside>
💡 A la hora de realizar la adivinación de cartas tener en cuenta que se necesitan dos números: el actual y el futuro. Ambos números serán generados aleatoriamente

</aside>

<aside>
💡 Si las cartas las ponéis en un array, podréis capturarlas por posiciones (asociadas al numero generado)

</aside>

<aside>
💡 En el caso de sacar una carta igual que la actual, no se perderá, ni se sumará punto, pero si saltará un aviso en forma de SnackBar

</aside>

<aside>
💡 De forma optativa, hacer que la apariencia en land y port sea diferente

</aside>

<aside>
💡 De forma optativa, al perder, aparecerá un Snackbar donde muestra la puntuación obtenida y una acción donde al pulsarla volverá a la primera pantalla

</aside>

Los archivos necesarios para la realización de la práctica son los siguientes: 

[recursos_cartas.zip](PR%C3%81CTICA%20adivinaci%C3%B3n%20cartas/recursos_cartas.zip)

La entrega se realizará mediante aula virtual con los siguientes archivos: 

- Link del repositorio GitHub (privado) previamente compartido
- Video con captura de pantalla mostrando el funcionamiento. No hay que explicar código, ni comentar el uso, tan solo mostrar el funcionamiento de la aplicación. El nombre del video será nombre_apellido