# PRÁCTICA: Llamadas

Status: Not started
🪴 Units: 1. Kotlin (../Unidades/1%20Kotlin%208f7eeadeed7083b7999681d83031c8ac.md)

Desarrollar una aplicación de control de llamadas realizadas en una centralita telefónica.

La centralita mostrará por pantalla todas las llamadas según las vaya registrando. Existen tres tipos de llamadas:

- Las llamadas locales que no tienen coste
- Las llamadas provinciales que cuestan 15 céntimos el segundo.
- Las llamadas nacionales que dependiendo de la franja horaria en la que se realicen cuestan: 20 céntimos en franja 1, 25 céntimos en franja 2 y 30 céntimos en franja 3, cada segundo.
- Todas las llamadas tienen como datos el número origen de la llamada, el número destino y su duración en segundos.

Con la centralita se podrá

- Registrar llamadas, mostrar llamadas realizadas (número origen, número destino, duración y coste)
- Mostrar Costes totales
- Mostrar llamadas realizadas

Para la realización de la práctica se desarrollarán las siguientes clases:

- Llamada (Abstracta): nOrigen, nDestino, coste
- LlamadaProvincial
- LlamadaLocal
- LlamadaNacional: franja
- Centralita: arraylist
- Entrada: main

Decide cuales son los métodos que se deberían de poner en herencia