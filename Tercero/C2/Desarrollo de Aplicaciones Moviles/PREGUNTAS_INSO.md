# Preguntas Únicas - Examen DAM INSO

## 1. ¿Cuál es la forma correcta de acceder a un recurso de color definido en colors.xml desde activity_main.xml?

- A) `@colors/my_color` ✅
- B) `getColor(R.color.my_color)`
- C) `R.color.my_color`
- D) `resources.getColor(R.color.my_color)`

---

## 2. ¿Cuál de las siguientes es una implementación y no una extensión?

- A) `abstract class Clase : Implementacion()`
- B) `final class Clase : Implementacion()`
- C) `class Clase : Implementacion()`
- D) `class Clase : Implementacion` ✅

---

## 3. Si utilizamos ConstraintLayout, ¿cuál es la única restricción que debe cumplir un elemento?

- A) Que tenga id
- B) Que al menos tenga una restricción por eje
- C) Que tenga id y que al menos tenga restricción en un eje
- D) Que tenga id y que al menos tenga una restricción por eje ✅

---

## 4. ¿Cuál de los siguientes métodos del ciclo de vida de una Activity se encarga de asociar la parte gráfica con la parte lógica?

- A) onCreateView
- B) onStop
- C) onCreate ✅
- D) onStart

---

## 5. Si tenemos `saludo(String texto, {var nombre})` en Dart, ¿cuál es el uso correcto?

- A) `saludo("hola", nombre="Juan")` ✅
- B) `saludo(texto="hola", nombre="Juan")`
- C) `saludo(nombre="Juan")`
- D) `saludo("hola", "Juan")`

---

## 6. ¿Cuál es la diferencia entre `final` y `const` en Dart?

- A) `final` se asigna en tiempo de ejecución, `const` en tiempo de compilación ✅
- B) `final` se asigna en tiempo de compilación, `const` en tiempo de ejecución
- C) `final` permite valores cambiantes, `const` no
- D) `const` puede cambiar su valor en tiempo de ejecución

---

## 7. ¿Cuál de las siguientes afirmaciones sobre un Action Bar es correcta?

- A) Tan solo permite poner menú y un título
- B) Es menos útil que un Toolbar ✅
- C) Es necesario modificar el diseño original para que pueda aparecer
- D) Hay que declararla dentro del XML

---

## 8. ¿Cuál de los siguientes métodos del ciclo de vida de un Fragment es necesario para que tenga parte gráfica?

- A) onAttach
- B) onViewCreated
- C) onCreateView ✅
- D) onCreate

---

## 9. En Dart, si queremos usar varios constructores en un objeto, ¿es posible?

- A) Sí, siempre y cuando exista una sobrecarga del constructor
- B) No, en Dart solo existe un constructor primario
- C) Sí, siempre y cuando se utilicen constructores adicionales nominales ✅
- D) Sí, definiendo junto al nombre de la clase el primario y el resto con la palabra constructor

---

## 10. En Dart, existe el operador null safety y se utiliza de la siguiente forma:

- A) `println("El siguiente dato puede ser nulo {dato ? "sin valor"}")`
- B) `println("El siguiente dato puede ser nulo {dato ?: "sin valor"}")`
- C) `println("El siguiente dato puede ser nulo {dato ?? "sin valor"}")` ✅
- D) `println("El siguiente dato puede ser nulo {dato ??: "sin valor"}")`

---

## 11. Los Fragments representan:

- A) Un elemento lógico que sustituye a una Activity
- B) Un elemento que permite comunicar dos pantallas entre sí
- C) Una característica de Android para poder hacer comunicaciones de red
- D) Una parte gráfica que se puede ocultar / mostrar en un momento determinado ✅

---

## 12. ¿Qué método del ciclo de vida de una Activity es llamado justo antes de que la UI sea visible al usuario?

- A) onPause()
- B) onResume()
- C) onCreate()
- D) onStart() ✅

---

## 13. En Flutter, si queremos utilizar un StatefulWidget tendremos:

- A) Una clase que implementa State
- B) Una sola clase que extiende de Stateful
- C) Una clase que extiende de State
- D) Una clase que extiende de Stateful y otra que extienda de State ✅

---

## 14. ¿Cuál de los siguientes métodos no pertenece al ciclo de vida de una Activity?

- A) onCreateOptionMenu ✅
- B) onPause
- C) onCreate
- D) onDestroy

---

## 15. ¿Cuál es el comportamiento de una Activity cuando el dispositivo rota?

- A) Solo se recrea la vista actual
- B) La Activity se destruye y se vuelve a crear ✅
- C) No ocurre ningún cambio
- D) Se llama a onPause() y luego a onStop(), pero no a onDestroy()

---

## 16. ¿Qué operador se utiliza en Kotlin para ejecutar una expresión solo si el valor no es nulo?

- A) `?.` ✅
- B) `let`
- C) `!!`
- D) `?:`

---

## 17. Indica cuál afirmación es falsa sobre XML y componentes en Android.

- A) El atributo id es obligatorio para definir un componente en XML ✅
- B) Si no se indica orientation en LinearLayout, es horizontal por defecto
- C) Un RecyclerView puede tener scroll vertical u horizontal
- D) El atributo layout_height puede ser wrap_content, match_parent o 0dp

---

## 18. Para representar una lista de datos, ¿qué elemento es mejor?

- A) Cualquiera de las anteriores
- B) ListView
- C) RecyclerView ✅
- D) GridView

---

## 19. ¿Qué hace el widget Expanded en Flutter?

- A) Hace que su child ocupe solo el espacio necesario
- B) Muestra un widget después de forma centrada
- C) Indica que el child ocupará todo el espacio disponible en su eje principal ✅
- D) Oculta su hijo hasta que se presione

---

## 20. Indica el tipo de retorno de la siguiente función definida en Dart: `realizarSuma({int operado1, int operando2})`

- A) dynamic ✅
- B) int
- C) double
- D) void

---

## 21. En un menú XML, ¿cuál atributo es indispensable para crear un menú item?

- A) Todas las anteriores
- B) showAsAction
- C) id ✅
- D) title

---

## 22. ¿Cuál afirmación sobre Kotlin es falsa?

- A) Las variables pueden ser mutables o no mutables
- B) Sirve para crear aplicaciones multiplataforma
- C) Es una transpilación de Java ✅
- D) Es un lenguaje totalmente independiente

---

## 23. ¿Cuál es el propósito del archivo AndroidManifest.xml?

- A) Almacenar cadenas para internacionalización
- B) Declarar componentes y permisos ✅
- C) Controlar diseño de la interfaz
- D) Definir rutas de navegación

---

## 24. ¿Cuál es el propósito del archivo build.gradle en un proyecto Android?

- A) Definir el diseño de la interfaz de usuario
- B) Especificar los componentes del manifiesto
- C) Configurar dependencias y opciones de compilación del proyecto ✅
- D) Gestionar las traducciones de la app