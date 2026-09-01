import MySQLdb
import os

conexion = None
cursor = None

def conectar_bd():
    global conexion, cursor
    usuario = input("Introduce el usuario: ")
    password = input("Introduce el password: ")
    conexion = MySQLdb.connect(
        host="localhost",
        user=usuario,
        passwd=password,
        db="classicmodels"
    )
    cursor = conexion.cursor()
    print("Conexión exitosa a la base de datos.")

def mostrar_directivos():
    print("\n*** Listado de Empleados ***")
    query = """
        SELECT employeeNumber, lastName, firstName, email, jobTitle
        FROM employees
        WHERE jobTitle LIKE '%Manager%' OR jobTitle LIKE '%Director%' OR jobTitle LIKE '%President%';
    """
    cursor.execute(query)
    resultados = cursor.fetchall()
    for fila in resultados:
        print(f"{fila[0]},{fila[1]},{fila[2]},{fila[3]},{fila[4]}")

def mostrar_top_clientes():
    print("\n*** Listado de Top 10 de Clientes ***")
    query = """
        SELECT c.customerNumber, c.customerName, SUM(p.amount) AS TOTAL_PAGOS
        FROM customers c
        JOIN payments p ON c.customerNumber = p.customerNumber
        GROUP BY c.customerNumber, c.customerName
        ORDER BY TOTAL_PAGOS DESC
        LIMIT 10;
    """
    cursor.execute(query)
    resultados = cursor.fetchall()
    for fila in resultados:
        print(f"{fila[0]},{fila[1]},{fila[2]:.2f}")

def menu():
    while True:
        print("\n**************** MENU PRINCIPAL ****************")
        print("0. Borrar la pantalla.")
        print("1. Introducir usuario y password para conectarse a la BBDD classicmodels.")
        print("2. Mostrar el listado de Directivos de la empresa classicmodels (lastName, FirstName, email, jobTitle).")
        print("3. Mostrar el Top 10 de Clientes (customerNumber, CustomerName, TOTAL_PAGOS) que más pagos han hecho.")
        print("4. Salir.")
        opcion = input("Elige una opción: ")

        if opcion == "0":
            os.system('cls' if os.name == 'nt' else 'clear')
        elif opcion == "1":
            conectar_bd()
        elif opcion == "2":
            if cursor:
                mostrar_directivos()
            else:
                print("Debe conectarse primero a la base de datos (opción 1).")
        elif opcion == "3":
            if cursor:
                mostrar_top_clientes()
            else:
                print("Debe conectarse primero a la base de datos (opción 1).")
        elif opcion == "4":
            if cursor:
                cursor.close()
            if conexion:
                conexion.close()
            print("Saliendo del sistema...")
            break
        else:
            print("Opción no válida.")

menu()
