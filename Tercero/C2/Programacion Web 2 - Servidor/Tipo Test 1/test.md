# Test Web Final

## 2 En express5 si no existe req.user en este codigo y hay middleware de errores:
```js
export const miControlador = (req, res) => {
    console.log(req.user.id);
    res.status(200).json({message: 'ok'});
};
```

- **A** El middleware captura la excepción (Correcta)
- **B** El middleware no puede capturar la excepción pero la aplicación sigue
- **C** El middleware no captura la excepción porque no se ha capturado con try/catch

## 3 Cual de estas afirmaciones NO es correcta
- **A** CommonJs incorpora el top-level await (Correcta)
- **B** V8 ejecuta el código Javascript en un único hilo
- **C** ESM es compatible con navegadores
- **D** type:module indica que trabajamos con ESM

## 4 Como importo esta funcion: export default miFuncion
- **A** Esta opcion sería valida: import cambio from 'miFichero.js' (Correcta)
- **B** Esta opcion sería valida: import {cambio} from 'miFichero.js'
- **C** Siempre con: import miFuncion from 'miFichero.js' 
- **D** Siempre con: import {miFuncion} from 'miFichero.js'

## 5 En jests el método describe
- **A** se utiliza para agrupar tests (Correcta)
- **B** en jest no existe describe
- **C** se utiliza para describir la funcionalidad de un test complejo

## 6 Cuando un jwt contiene en el payload información de un usuario
- **A** Esa información está cifrada y únicamente es accesible con la SECRET_KEY (Correcta)
- **B** Esa información es pública para cualquiera que acceda al token

## 7 ¿Qué ocurre si la validación falla con zod?
- **A** Devuelve solo los campos validados, ignorando los demás
- **B** Se lanza una excepción (Correcta)

## 9 Cuando utilizamos zod refine:
- **A** Se utiliza para pasar una funcion y validar con ella (Correcta)
- **B** Se utiliza para personalizar el mensaje de error
- **C** Se utiliza para pasar una funcion y que modifique los datos

## 10 Para que un paquete aparezca en el package.json en la zona de **dependencies**
- **A** hay que instalarlo con --save-dev
- **B** hay que instalarlo con -D
- **C** hay que instalarlo normal, con npm install (Correcta)

## 11 En Prisma para indicar distintos atributos de los campos se utiliza:
- **A** : (por ejemplo :id, :unique)
- **B** @ (por ejemplo @id, @unique) (Correcta)
- **C** [] (por ejemplo [id], [unique])

## 12 Si no usas populate ¿qué veras normalmente en un campo con referencia?
- **A** el ObjectId (Correcta)
- **B** Un array vacío
- **C** Un error de MongoDB
- **D** El documento completo 

## 13 ¿Como se define correctamente un párametro name en una ruta de Express?
- **A** /user/{name}
- **B** /user/:name (Correcta)

## 14 ¿Donde se definen las Github Actions?
- **A** En una carpeta dentro de .github (Correcta)
- **B** En archivos .json
- **C** En package.json
- **D** No se definen en un fichero, se modifica en la plataforma

## 15 Hablando de ws y socket.io, cual de estas afirmaciones es correcta?
- **A** ws no incorpora salas ni namespaces (Correcta)
- **B** socket.io es un método del paquete ws
- **C** ws es nativo y no hace falta instalarlo en el servidor

## 16 Que metodo es equivalente conceptualmente a populate en bases de datos SQL
- **A** DISTINCT
- **B** GROUP BY
- **C** JOIN (Correcta)

## 17 Ex express, un middleware que recibe tres parametros (req, res, next)
- **A** No es un middleware de error (Correcta)
- **B** No es un middleware, es un controlador
- **C** Es un middleware de error

## 18 Que comando genera el package.json en un proyecto
- **A** npm install
- **B** npm init (Correcta)
- **C** npm package

## 19 En un middleware
- **A** se utiliza next para pasar un error y se hace return para pasar al siguiente middleware o controlador
- **B** se utiliza para pasar al siguiente middleware y return para llegar al controlador
- **C** se utiliza next para pasar al siguiente middleware o controlador (Correcta)

## 20 Para arrancar swagger
- **A** hay que arrancar la aplicación de swagger con npm
- **B** hay que arrancar el servidor (Correcta)
- **C** es necesario definirlo en el script de arranque del package.json

## 21 Cual de las siguientes afirmaciones es correcta
- **A** Se puede añadir typescript en ficheros con extensión .js
- **B** En Typescript los arrays tienen que ser de elementos del mismo tipo
- **C** Los tipos se instalan unicamente en desarrollo (Correcta)

## 22 Que codigo devuelve una petición POST cuando se ha creado un recurso con exito (escribir respuesta)
- 201

## 23 Si tengo esta información en una gitAction:
```js
name: tests

on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main

jobs:
  build-and-test:
    runs-on: ubuntu-latest
```
Qué ocurre si no pasan los tests y se hace un push directo a main

- **A** Github no permite un push directo a main con esa acción
- **B** Al hacer un push directo a main se ejecuta el push pero aparece una notificación de error (Correcta) 
- **C** Al hacer un push directo a main, se bloquea el commit porque da error 

## 24 ¿Qué devuelve al cliente este codigo al hacer una petición a /profile?
```js
router.get('/:id', (req, res) => {
    res.send('ID Route');
});

router.get('/profile', (req, res) => {
    res.send('Profile Route');
});

router.get('/profile/:id', (req, res) => {
    res.send('Profile param route');
})
```

- **A** 'Profile param route' porque esta esperando el id
- **B** 'ID route' porque es el que está escrito antes y coincide (Correcta)
- **C** Nada, falta el return
- **D** 'Profile route' porque coincide con la ruta

## 25 Cuando utilizamos multer para subir archivos en local. El archivo:
- **A** multer lo guarda en local y le pasa la información al controlador (Correcta)
- **B** se queda en req.file para que el controlador lo guarde
- **C** se queda en req.params.file para que el controlador lo guarde