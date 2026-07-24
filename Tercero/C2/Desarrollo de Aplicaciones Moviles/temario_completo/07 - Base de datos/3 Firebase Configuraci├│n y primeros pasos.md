# 3. Firebase. Configuración y primeros pasos

Status: Not started
🪴 Units: 7. Base datos (../Unidades/7%20Base%20datos%20343eeadeed7082648c4f817840eb78e6.md)

Si bien una de las posibilidades es utilizar una base de datos local como la que hemos visto en el punto anterior, también es posible utilizar un servicio externo que permita las mismas características pero metiendo una capa de abstracción eliminando gran parte de la complejidad. Firebase es uno de esos servicios.

Desarrollado por google, firebase ofrece multitud de servicios como bases de datos, almacenamiento web, autenticación, notificaciones, etc... En este punto vamos a ver como poder configurar un proyecto para que esá asociado a un servicio firebases y utilizar sus principales características.

## Configuraciones necesarias

Antes de empezar a utilizar las características del servicio, lo primero que tenemos que hacer es tanto crear el proyecto en la plataforma web como asociarlo a nuestro proyecto de android studio. Para ello tendremos que seguir los siguientes pasos.

1. Crear el proyecto dentro de la consola de firebase. Para ello iremos a la web [https://console.firebase.google.com/](https://console.firebase.google.com/) iniciando sesión con nuestra cuenta de google
    1. Seleccionaremos add proyect, indicando el título que tendrá el proyecto. En mi caso firebase-develop
    2. Activaremos / desactivaremos analytics para el proyecto. Esto permitirá evaluar rendimiento y uso del proyecto.
    3. Una vez seleccionados estos elementos el proyecto quedara creado, viendo la consola general del proyecto con todas las características disponibles

![proyecto_overview.png](3%20Firebase%20Configuraci%C3%B3n%20y%20primeros%20pasos/proyecto_overview.png)

1. Con el proyecto creado el siguiente paso es asociarlo a un proyecto android. Para ello seguimos el asistente que podemos sacar desde android studio en tools -> firebase. Los pasos que tendremos que seguir son los siguientes:
    1. Seleccionar cualquiera de los servicios. En este caso seleccionaremos RealTime Database y le daremos a get started
    2. Pulsando sobre la opción de Connect to Firebase el proyecto descargará las librerías necesarias para ello y mediante el navegador seleccionaremos el proyecto con el que queremos conectar. Este paso en realidad lo que hace es guardar un archivo llamado google-service.json en la raíz del módulo
    3. Por último queda ir seleccionando cada uno de los servicios e ir incorporando dependencias dentro del proyecto

Con todo esto, el proyecto está conectado a nuestro proyecto firebase, por lo que en los siguientes puntos veremos como poder utilizarlos.

## RealTime Database

Uno de los principales servicios de firebase es el de las bases de datos. Cuenta con dos tipos:

- RealTime Database: se trata de bases de datos en tiempo real con una estructura de nodos, por lo tanto no SQL. Es la base de datos más simple pero al mismo tiempo la más efectiva si queremos guardad una cantidad de información pequeña
- Firestore Database: se trata de de una base de datos basada en colecciones, donde cada una de esta guarda documentos con propiedades y valores individuales. Es lo más parecido a una base de datos mongo. Se utiliza cuando la cantidad de información que se quiere guardar es lo suficientemente grande

Hay que recordad que ambas bases de datos son no relacionales, por lo que la información guardada en ellas no tienen ninguna relación, a no ser que nosotros como programadores marquemos la lógica, pero siempre sin claves

Para poder utilizar el servicio de RealTime Database tenemos que primero activarlo desde la consola de Firebase. Para ello iremos a la vista general del proyecto, seleccionaremos RealTime Database y pulsamos a CreateDatabase. Pedirá ubicación del servidor donde quedará alojada la base de datos y las reglas que se aplicarán a la base de datos. Por defecto seleccionaremos test mode, aunque lo cambiaremos más adelante. Con esto nuestra base de datos quedará creada

![realtime_database.png](3%20Firebase%20Configuraci%C3%B3n%20y%20primeros%20pasos/realtime_database.png)

Como se puede ver en la imagen la base de datos siempre tiene un nodo general que está configurado con una url, siendo este el nodo root. Lo que se puede hacer sobre el es crear nodos y sobre estos crear nodos adicionales donde se guardan valores

![nodos.png](3%20Firebase%20Configuraci%C3%B3n%20y%20primeros%20pasos/nodos.png)

Como se puede ver en la imagen cada uno de los nodos está asociado a una key y a un valor, cada uno de los cuales puede ser de un tipo diferente

Una vez está habilitado el servicio de RealTime Database dentro de la consola, el siguiente paso es la habilitación dentro de nuestro proyecto android. Recordad que previamente ya habíamos conectado los proyectos mediante el asistente. Para poder hablilitar el servicio y desde el mismo asistente que en el punto anterior seleccionamos la opción de Add the realtime database to your app. Este paso lo que hará es incluir en los archivos de gradle todas las dependencias necesarias para que el servicio esté disponible. Una vez hecho esto la base de datos es accesible