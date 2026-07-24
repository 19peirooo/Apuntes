# PRÁCTICA: Vuelos

Status: Not started
Type: Lab
🪴 Units: 5. Diálogos y menús (../Unidades/5%20Di%C3%A1logos%20y%20men%C3%BAs%201a0eeadeed708261a57d0160f016c827.md)

Realiza una aplicación de reserva de vuelos. El contenido de dicha aplicación será el siguiente: 

Una única activity, donde se dividirá el diseño principal en dos partes

- 30% superior
    - Seleccionar ciudad origen y ciudad destino mediante dos spinner personalizados con la imagen de la ciudad y su nombre
    - Fecha salida y fecha vuelta: mediante un TextView donde al pulsarlo saltará un cuadro de diálogo DatePicker. Al seleccionar la fecha se pondrá la fecha seleccionada con el formato dd/mm/aa
    - Hora salida y hora vuelta: mediante un TextView donde al pulsarlo saltará un cuadro de diálogo TimePicker. Al seleccionar la hora se pondrá la hora seleccionada con el formato hh:mm (en formato 24)
    - Activar si es solo vuelo de ida (se deshabilitará la parte de la salida) mediante un CheckBox
    - Botón agregar el viaje seleccionado
- 40% inferior
    - Ver todos los vueltos en el recycler, con la forma que se muestra en la imagen. Las imágenes deberán ser cargadas con glide. Cada carta tendrá un toolbar con el nombre de las ciudades presentes en la reserva así como su imagen
    - En cada una de las cartas se podrá además ver el detalle del vuelo, apareciendo un diálogo personalizado con imágenes y datos de los vuelos (fechas) al pulsar en el botón ver detalle
- Buscador (menú) ubicado en un toolbar en la activity permitiendo filtrar de alguna forma el recycler de vuelos (ciudad, solo ida, etc...la forma la elegís vosotros)
- 

![ciudades1.png](PR%C3%81CTICA%20Vuelos/ciudades1.png)

![ciudades2.png](PR%C3%81CTICA%20Vuelos/ciudades2.png)

Los recursos necesarios para realizar la práctica no son necesarios, ya que las imágenes se cargan por glide (debéis buscar vosotros los links). Se adjuntan algunas imágenes de muestra para que podáis probar la app

[cuidades.zip](PR%C3%81CTICA%20Vuelos/cuidades.zip)

<aside>
💡 A la hora de seleccionar las fechas, el sistema no debería permitir seleccionar una fecha de llegada posterior a la de salida. Para eso tenéis que utilizar objetos de tipo Date y SimpleDateFormat. En caso de producirse saltaría un dialogo de alerta

</aside>

<aside>
💡 A la hora de seleccionar los vuelos, no se debería poder seleccionar una ciudad de destino igual que la de origen. En caso de producirse saltaría un dialogo de alerta

</aside>

<aside>
💡 Es necesario crear un objeto de tipo reserva (o como lo queráis llamar) con todos los datos necesarios

</aside>

La entrega se realizará mediante aula virtual con los siguientes archivos: 

- Link del repositorio GitHub (privado) previamente compartido
- Video con captura de pantalla mostrando el funcionamiento. No hay que explicar código, ni comentar el uso, tan solo mostrar el funcionamiento de la aplicación. El nombre del video será nombre_apellido