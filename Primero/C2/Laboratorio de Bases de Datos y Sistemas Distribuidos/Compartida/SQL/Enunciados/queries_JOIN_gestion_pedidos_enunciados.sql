## Queries TIPO JOIN para gestion_pedidos

## Si estuvieramos desde el cliente de  MariaDB (mysql) ejecutar.
## show databases;
## use  GestionPedidos;
## show tables;

## En DBeaver, establcer conexión con BD y ejecutar script

## INNER JOIN
## 1) Consultar los clientes (id_cliente, su nombre) que tengan pedidos y añadir a la consulta el identificador 
## del pedido y la descripción 

   
## LEFT JOIN 
## 2) Seleccionar todos los clientes incluyendo en la consulta el id_cliente, su nombre, el id del pedido  y  
## la descripción del (incluyendo en la lista los clientes que no tengan pedidos)
   
   
## LEFT JOIN
## 3) Para todos los proveedores de la tabla proveedores obtener el stock de cada uno de los articulos existentes en el alamcen

   
## RIGHT JOIN 
## 4) Obtener los nombres de los todos los proveedores indicando cuales de ellos están en la tabla almacen y cuales no


## RIGHT JOIN
##5)Obtener el id articulo y la descripción del articulo de los articulos contenidos en los pedidos. Muestra también la identidad 
## del pedido. Podría haber articulos no incluidos en ningun pedido

## 6) seleccior cantidad de cada articulo del almacen - sumar el stock acumulado por articulo
## mostrar el id_articulo y su stock total



