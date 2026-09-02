
#Buscar el nombre del cliente
SELECT nombre_cl FROM cliente c

#Buscar el nombre y el saldo del cliente
SELECT nombre_cl,saldo_cl  FROM cliente c

#Buscar toda la informacion de los clientes
SELECT * FROM cliente c

#Consultar nombre,ciudad y saldo y ordenado por saldo(orden descendiente)
SELECT nombre_cl,ciudad_cl,saldo_cl  FROM cliente c ORDER BY saldo_cl DESC 

#Consultar nombre,ciudad y saldo y ordenado por saldo(orden ascendiente)
SELECT nombre_cl,ciudad_cl,saldo_cl  FROM cliente c ORDER BY saldo_cl ASC

SELECT nombre_cl,(saldo_cl+credito_cl) AS total  FROM cliente c ORDER BY total 

SELECT nombre_cl,ciudad_cl,saldo_cl  FROM cliente c ORDER BY saldo_cl  ASC LIMIT 3

SELECT nombre_cl,pais_cl,saldo_cl  FROM cliente c WHERE pais_cl = 'España' AND saldo_cl > 50

SELECT nombre_cl,pais_cl,ciudad_cl,credito_cl  FROM cliente c WHERE pais_cl = 'Francia' AND ciudad_cl = 'Paris' AND credito_cl > 100

SELECT nombre_cl,pais_cl,saldo_cl  FROM cliente c WHERE  (pais_cl = 'España' OR pais_cl = 'Francia') AND saldo_cl > 100

SELECT nombre_cl,saldo_cl  FROM cliente c WHERE saldo_cl NOT BETWEEN 10 AND 400

SELECT nombre_cl,ciudad_cl FROM cliente c  WHERE  nombre_cl LIKE 'J%'

SELECT nombre_cl,ciudad_cl FROM cliente c WHERE ciudad_cl LIKE 'M%' ORDER BY nombre_cl desc

SELECT id_cliente,nombre_cl,ciudad_cl FROM cliente c WHERE id_cliente IN (6,7,8)

SELECT  nombre_cl FROM cliente c WHERE direccion_cl IS NULL 

SELECT * FROM almacen a WHERE stock_articulo_almacen > 100

SELECT DISTINCT pais_cl FROM cliente c 

SELECT ciudad_cl ,COUNT(id_cliente) as numClientes FROM cliente c GROUP BY ciudad_cl ORDER BY numClientes DESC LIMIT 1

SELECT COUNT(*) as totalClientes,COUNT(direccion_cl) as direccionNoNula, MIN(saldo_cl) as saldoMinimo, AVG(descuento_cl) as mediaDescuento, SUM(credito_cl) as totalCredito  FROM cliente c 


