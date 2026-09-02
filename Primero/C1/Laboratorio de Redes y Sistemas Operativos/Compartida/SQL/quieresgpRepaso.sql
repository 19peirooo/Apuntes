 ## 1) Obtener el numero de articulos del alamcen, el stock máximo, el minimo y la media del precio unitario
SELECT COUNT(id_proveedor_almacen) as numArticulos, MAX(stock_articulo_almacen) as stockMaximo, MIN(stock_articulo_almacen) as stockMinimo, AVG(precio_unitario) as mediaPrecio
FROM almacen a 

## 2) obtener lo solicitado en  el punto 1 pero para cada articulo
SELECT id_articulo_almacen , COUNT(id_proveedor_almacen) as numArticulos, MAX(stock_articulo_almacen) as stockMaximo, MIN(stock_articulo_almacen) as stockMinimo, AVG(precio_unitario) as mediaPrecio
FROM almacen a 
GROUP BY id_articulo_almacen 

## 3) Cruzarlo con la información del articulo para tener el nombre de dicho articulo
SELECT a2.descripcion_articulo  , COUNT(a.id_proveedor_almacen) as numArticulos, MAX(a.stock_articulo_almacen) as stockMaximo, MIN(a.stock_articulo_almacen) as stockMinimo, AVG(a.precio_unitario) as mediaPrecio
FROM almacen a JOIN articulo a2 on a.id_articulo_almacen = a2.id_articulo 
GROUP BY id_articulo_almacen 

## 4) Por cada cliente (idntificador y nombre) el total de pedidos que ha realizado
SELECT c.id_cliente , c.nombre_cl , COUNT(p.id_cliente_ped) as numPedidos
FROM cliente c JOIN pedido p ON c.id_cliente = p.id_cliente_ped
GROUP BY p.id_cliente_ped 

## 5) Indicar, el número de clientes, el saldo medio y el descuento más alto de los clientes de Madrid
SELECT COUNT(id_cliente), AVG(saldo_cl), MAX(descuento_cl)
FROM cliente c 
WHERE ciudad_cl = 'Madrid'

## 6) Insertar dos nuevos clientes en la BD de los que solo se conocen los siguientes datos: 
## Cliente 1 --> Nombre: Luis Pedreira, Ciudad: Murcia, Pais: España
## Cliente 2 --> Nombre: Laura Boix, Ciudad: Barcelos, País: España
INSERT 
INTO cliente(nombre_cl,ciudad_cl,pais_cl)
VALUES ('Luis Pedreira','Murcia','España'),('Laura Boix','Barcelona','España');

## 7) Actualizar el saldo, el credito y el descuento de los clientes Luis Pedreira y Luara Boix. Los valores en ambos clientes serán:
## saldo=100, credito=500, descuento=10
UPDATE cliente 
SET saldo_cl = 100,credito_cl = 500, descuento_cl = 10
WHERE nombre_cl = 'Luis Pedreira' OR nombre_cl = 'Laura Boix';

## 8) Insertar un en el almacen un nuevo producto cuyo codigo es 11 y el código de su proveedor es 3 
INSERT 
INTO almacen(id_proveedor_almacen, id_articulo_almacen)
VALUES ('PROV3','AA11')

## 9) Actualiza la tabla alamcen para añdir al articulo y proveedor insertados en la sentencia anterior los valores de stock_articulo_almacen
## y de precio_unitario. Los valores deben ser 100 y 37 respectivamente. 
UPDATE almacen 
SET stock_articulo_almacen = 100 , precio_unitario = 37
WHERE id_proveedor_almacen = 'PROV3' AND id_articulo_almacen = 'AA11';

## 10) Eliminar del almacen aquellos articulos cuyo stock sea inferior a 30 unidades
DELETE a
FROM almacen a
WHERE stock_articulo_almacen < 30;

##11) Crear una vista con la informacion del identificador y el nombre del cliente así como con los identificadores 
## de los pedidos que ha realizado y su descripción

CREATE VIEW PedidosRealizados AS
SELECT c.id_cliente , c.nombre_cl, p.id_pedido, p.descripcion_pedido
FROM cliente c JOIN pedido p ON c.id_cliente = p.id_cliente_ped;

## 12)  Obtner todos los campos de la vista creada en la query anterior
SHOW COLUMNS FROM PedidosRealizados 



