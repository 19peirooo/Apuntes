# PRÁCTICA: Compras

Status: Not started
🪴 Units: 5. Diálogos y menús (../Unidades/5%20Di%C3%A1logos%20y%20men%C3%BAs%201a0eeadeed708261a57d0160f016c827.md)

Realiza una aplicación que permita realizar compras sobre una lista de productos. 

Para ello, la aplicación constará de las siguientes pantallas:

## MainActivity

Será la pantalla principal de la aplicación con los siguientes elementos

- Barra de menus con los siguientes elementos
    - Filtrar: arrancará un cuadro de diálogo de selección multiple con todas las categorias de los productos. Es opcional cárgalos mediante JSON con la peticion a la siguiente [URL](https://dummyjson.com/products/categories). Tras seleccionar las categorías se volverá a la pantalla principal mostrando en la lista los productos que cumplan dicha categoría
    - Buscar: arrancará un cuadro de diálogo donde se podrá introducir una palabra de búsqueda. Una vez pulsado aceptar, se mostrará en el listado aquellos productos que cumplan la condición de búsqueda mediante la siguiente [URL](PR%C3%81CTICA%20Compras%20605eeadeed70834885b0810701f184b0.md)
    - Resetear filtro: Quitará todos los filtros de búsqueda sobre los productos y volverá a mostrar la lista inicial
    
    <aside>
    💡 La URL que muestra todos los productos se obtienen mediante el siguiente [link](https://dummyjson.com/products)
    
    </aside>
    
    <aside>
    💡 En la URL de búsqueda hay que sustituir phone por la palabra que se quiere buscar
    
    </aside>
    
- Un ImageButton con un carrito de compra acompañado de un contador, donde se mostrará el número de elementos en el carrito. Al pulsar el botón del carrito se cargará la pantalla de compra.
- RecyclerView donde se mostrarán todos los productos cargados, con o sin filtro. Cada uno de los items del listado mostrará además de la imagen y el nombre, dos botones: uno que podrá agregar el producto al carrito y otro para ver detalles y cargar la siguiente activity

## DetailActivity

En esta pantalla se cargará tras pulsar el botón de detalle existente en cada una de las filas del listada de la pantalla MainActivity. Esta pantalla constará de los elementos necesarios para mostrar los siguientes datos del producto seleccionado: 

- imágenes del producto (con un Recycler horizontal)
- nombre
- precio
- categoría
- stock
- descripción

## ShoppingActivity

En esta pantalla se cargará todos los productos del carrito de compra. Para ello, la pantalla tendrá los siguientes elementos

- Una barra de menú con una opción que sea comprar. Tras pulsar el item se mostrará un snackbar con el siguiente mensaje: “Estás seguro que quieres realizar la compra por valor de XXX€”. Tras pulsar la acción se mostrá un mensaje de  “Compra realizada” y el carrito se vaciará
- ReyclerView, mostrando además de la imagen, el nombre y precio de cada uno de los productos del carrito