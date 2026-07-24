# Ejercicio tienda

Status: Not started
🪴 Units: 7. Base datos (../Unidades/7%20Base%20datos%20343eeadeed7082648c4f817840eb78e6.md)

Desarrolla una aplicación móvil de **tienda de productos** para Android utilizando **Firebase** como backend. La aplicación permitirá a los usuarios **registrarse e iniciar sesión**, explorar productos, agregar productos a favoritos y realizar compras. Además, contará con un **panel de administración** para gestionar los productos desde Firebase. La funcionalidad de la aplicación será:

### **1. Autenticación de Usuarios**

Implementa **registro e inicio de sesión** con Firebase Authentication (correo/contraseña o Google).

Permitir a los usuarios cerrar sesión y recuperar su contraseña.

### **2. Gestión de Productos (Administrador)**

Usa **Firebase RealTime o Firestore** para almacenar productos con los siguientes datos:

### **3. Catálogo de Productos (Usuarios)**

Mostrar un listado de productos en una pantalla principal.

Permitir **filtrar por categoría** y **buscar productos**.

### **4. Favoritos**

Permitir a los usuarios **marcar productos como favoritos**.

Guardar los productos favoritos en **Firebase Firestore** bajo el usuario autenticado.

Mostrar una pantalla donde el usuario pueda ver sus favoritos.

### **5. Compra de Productos**

Permitir que los usuarios **agreguen productos al carrito**.

Mostrar el total del carrito y la opción de **finalizar compra**.

Al comprar, guardar la información en Firestore y mostrar un mensaje de confirmación.

Los fragments que tendrá la aplicación son:

- FragmentLogin
- FragmentRegistro
- FragmentListado
- FragmentDetalle
- FragmentFavoritos
- FragmentCarrito

Para poder hacer los cambios de fragment, utiliza la navegación entre fragments y cuadros de diálogo

> Se valorará el uso de toolbar, menús y cuadros de diálogo para completar la navegación
> 

> Para la última modificación se deberá agregar SQLIte incorporando:
> 
> 
> un check donde aparece un recordar usuario. 
> 
> - Si está seleccionado, al arrancar la app se iniciará directamente el con el usuario
> - En el caso de deseleccionarlo, cerrar sesión, se vaciará la tabla donde se guarda el usuario
> 
> una tabla donde se guardan los productos del carrito
> 
> - Al cerrar sesión o la aplicación, la tabla quedará vacía