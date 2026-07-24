# Proyecto inicial

Status: Done
🪴 Units: Sin título (https://www.notion.so/36c86319a6574ff9ab8b500927150257?pvs=21)

## Resumen

- El proyecto inicial de Flutter requiere la instalación previa del plugin de Dart y Flutter en el IDE elegido
- La estructura del proyecto incluye carpetas específicas para cada plataforma (ios/web/macos/windows/android) y la carpeta lib para código común
- El archivo main.dart contiene la estructura básica con dos clases principales: MyApp (StatelessWidget) y MyHomePage (StatefulWidget)
- MyApp configura la aplicación usando MaterialApp, definiendo el tema y la pantalla principal
- MyHomePage implementa la funcionalidad de la pantalla usando Scaffold, que incluye AppBar, body y FloatingActionButton
- El ejemplo demuestra la gestión de estado usando setState() para actualizar un contador

Para poder crear un proyecto de flutter, lo primero que debemos tener es instalado el plugin de dart y flutter en el IDE que se vaya a utilizar. En nuestro caso, todo el desarrollo lo explicaremos mediante android studio. 

Una vez instalado se puede crear el proyecto de forma automática con el asistente, marcando las plataformas para las que se quiere hacer el desarrollo. Una vez realizado esto, se creará toda la estructura del mismo. Las carpetas que tienen relevancia son las siguientes:

- ios/web/macos/windows/android: Son las carpetas donde se ubicarán los proyectos de las plataformas específicas, teniendo que utilizarlas cuando se exporta el proyecto a cada una éstas, serán necesarios utilizarlas
- lib: en esta carpeta encontraemos todos los códigos “comúnes” al proyecto, pudiendo tener desde modelos, hasta componentes individuales para que sean accesibles de forma individual, pasando por pantallas completas.

Además de las carpetas, podemos encontrar ficheros sueltos de configuración.

Vamos a centrarnos en la carpeta lib. En ella, en el proyecto inicial encontraremos el fichero main.dart. Aqui podremos encontrar todo el código que renderiza la pantalla de la aplicación en un solo fichero. Las partes de este son las siguientes

- Un primer método main que es el encargado de ejecutar la aplicación. Este método llama al objeto MyApp, que es el elemento principal, digamos que es la pantalla

## Class MyApp

- class MyApp: representa la pantalla completa, extendiendo de la clase Stateless, ya que al representar la pantalla completa, no se quieren guardar datos “gloables”, sino que esto se hará de forma individual en cada uno de los elementos finales

```java
class MyApp extends StatelessWidget {
  const MyApp({super.key});
  
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      theme: ThemeData(

        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}
```

Al ser una clase que extienda de StatelessWidget, tenemos el método sobreescrito build. Este método se encarga de construir el elemento que quieremos pintar. Digamos que este método tiene que retornar el Widget completo, y en este caso se retorna MaterialApp, el cual representa e componente base que sigue las pautas de desarrollo de Google Material Design. Se podría utilizar CupertinoApp (visualización modo IOs), pero MaterialApp es más extendida

<aside>
💡

Si quieres ver todas las características del componente, puedes verlas en [https://docs.flutter.dev/ui/widgets/material](https://docs.flutter.dev/ui/widgets/material)

</aside>

En el ejemplo, las característcias que quedan configuradas por defecto con:

- theme: conjuto de colores, elementos , tipos de letra, etc…. que se aplica a toda la aplicación
- title: nombre que tendrá la aplicación cuando se instala
- home: característica básica, donde se indica cual es el emento principal de la app. En este case se hace una llamada a la clase MyHomePage. Si bien el componente princpal que estamos explicando representa toda la app, el componente que se llama dentro de home es la pantalla

<aside>
💡

Hay que darse cuenta, que en la mayoría de los casos, en flutter se utilizan los parámetros nominales 

</aside>

## Class MyHomePage

Al igual que la clasa anterior, MyHomePage, representa un componente de la aplicación, siendo la pantalla en este caso. En este caso estamos hablando de un StateFull, un componente que queremos que guarde un estado. En este ejemplo, se quiere guardar la cantidad de pulsaciones que se hace en un botón para poder guardar esta cuenta en un texto. Es por este motivo por el que un StateLess no tiene cabida en este ejemplo. La estructura del código es la siguiente

```java
class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}
```

A difenrencia del anterior, en este caso no tenemos la obligacion de sobreescribir el método build, sino que tenemos que sobreescribir el método createState(), teiendo que retornar de forma obligatoria un objeto de tipo State, creado en una clase adocional.

Antes de explicar esta clase, es importante darnos cuenta que se utiliza un consturctor que pide nominalmente deos elementos, la key y el title)

<aside>
💡

El state es el tipo de objeto que permite guardar datos, con la disponibilidad del método setState para guardar o gestionar los datos que se quieran implementar

</aside>

Como el método createState debe retornar un objeto de tipo State, es necesario crear una clase para poder gestionarlo

### Class _MyHomePageState

Esta clase representa el estado que tendrá el widget. Se trata de una clase igual que la anterior, pero que extienda de State, siendo obligatoria la soobreescritura, en este caso si,  del método build.

```java
class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;

  void _incrementCounter() {
    setState(() {

      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
      appBar: AppBar(

        backgroundColor: Theme.of(context).colorScheme.inversePrimary,

        title: Text(widget.title),
      ),
      body: Center(

        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text('You have pushed the button this many times:'),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headlineMedium,
            ),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: const Icon(Icons.add),
      ), // This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
```

Antes de ver los diferentes métodos de este widget, vamos a centrarlos en el método build. Acabamos de explicar que es necesario retornar un Widget. teniendo est caso la siguiente estructura:

```java
return Scaffold(
      appBar: ,
      body: ,
      floatingActionButton:
    );
```

El retorno es un Scaffold, que permite generar una estructura base para la pantalla (parte superior con barra, parte central y botón flotante). No es necesario utilizar este tipo de componentes pero si es muy recomendable, ya que utiliza una estructura clara y reconocible para la pantalla. En el caso de tan solo querer poner un tipo de elemento como Column, Center o algo similar, sertía totalmente vállido.

<aside>
💡

Si quieres ver todas las características del Scaffold, puedes verlo desde este [enlace](https://www.notion.so/1a79b610a38d80759abace1142f0381f?pvs=21) 

</aside>

Cada uno de los elementos del Scaffold está configurado de la siguiente forma:

- appBar: Parte superior de la aplicación, tambiénn llamada Toolbar o ActionBar. Flutter tiene un componente que representa este tipo de elementos y es llamado  AppBar (podemos encontrar todas sus características en este [enlace](Proyecto%20inicial%20e11eeadeed70822c954f81247209c053.md)). Por defecto las características que se configuran en el ejemplo son title (que a su vez tiene un widget de tipo Text dentro) y background (utilizando el color del tema configurado)

```java
appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text(widget.title),
      ),
```

En este caso en el titel tan solo hay un texto, pero en el caso de querer introducir otro tipo de elementos, se podría hacer combinando elementos:

```java
title: Row(children: [Text(widget.title), Icon(Icons.access_alarms)]),
```

- body: Parte dentral de la pantalla, donde se configuran todos los elementos que se verán en la aplicación. Esta parte, tan solo tendrá un hijo, que es el elemento que queremos representar. En el caso de querer representar mas de un elemento, será necesario utiliar algún elemento de tipo Layout que agrupe elementos. En el caso del ejemplo tenemos un Center

```java
body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text('You have pushed the button this many times:'),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headlineMedium,
            ),
          ],
        ),
      ),
```

En este caso el componente Center me permite centra un elemento, siendo un Column (con dos textos a su vez) el elemento interno. No tienen porque ser siempre el mismo, sino que se puede utilizar aquen que solvente las necesidades. Alguno de los ejemplos que se pueden utilizar son:

- **`Center`**: Cuando necesitas centrar un único widget.
- **`Column` y `Row`**: Para diseños simples de lista o fila de widgets.
- **`ListView`**: Cuando necesitas manejar una lista desplazable de elementos.
- **`GridView`**: Cuando necesitas una cuadrícula de elementos.
- **`Container`**: Cuando quieres personalizar un widget o aplicar estilos como padding, colores, bordes, etc.
- **`Form`**: Cuando necesitas capturar datos del usuario, como en un formulario.
- **`SingleChildScrollView`**: Cuando el contenido puede desbordar la pantalla o necesita ser desplazable.
- **`Stack`**: Cuando necesitas apilar widgets o posicionarlos de manera relativa.

Depende de cuál sea el uso que queremos dar a la aplicación podemos utilizar uno u otro. Lo que marcará cual de los elementos es necesario utilizar es la necesidad del mismo.

- floatingActionButton: Último elemento del componente Scaffold. Representa un botón con una acción correspondiente, indicando la función a ejecutar cuando la pulsción del mismo se produce

```java
floatingActionButton: FloatingActionButton(
        onPressed: _incrementCounter,
        tooltip: 'Increment',
        child: const Icon(Icons.add),
      ),
```

En este caso, como podemos ver, se está llamando a la función _incrementCounter tras la pulsación del botón. En este caso se ha definido la función en la parte superior de la clase, pero podría definirse directamente aquí puniendo el siguiente código 

`onPressed: (){},`

Si miramos en la parte superior, la funcion _incrementCounter hace lo siguiente:

```java
void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }
```

Ejecuta el método setState() (recordad que estamos dentro de un widget Statefull), actualizando la variable _counter;, la cual es renderizada en uno de los textos que forman parte de la columna. El aspecto que tendría la app es el siguiente:

![image.png](Proyecto%20inicial/image.png)

![image.png](Proyecto%20inicial/image%201.png)