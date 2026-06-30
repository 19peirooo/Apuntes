import LoginManager as lm
import random

NUM_ELEMS_TEST = 5

def main():
    print("=== INICIO DE TESTS ===")

    # Limpiar la BBDD de prioridad
    lm.helpDesk.flushdb()

    # ---------------------------------------------------------
    # 1. Insertar elementos en la cola con distintas prioridades
    # ---------------------------------------------------------
    print("\n-- Insertando elementos con distintas prioridades --")

    for i in range(NUM_ELEMS_TEST):
        priority = random.randint(1,20)
        lm.priorityHelp(f"user_{i}",priority)
        print(f"Añadiendo usuario con prioridad {priority}")
    
    print("Resultado en cache: ")
    for el in lm.helpDesk.zrange("priority_set",0,-1):
        print(el)
    
    print("\n-- Atendiendo usuarios en funcion de su prioridad --")
    for _ in range(NUM_ELEMS_TEST):
        user = lm.handleUsr()
        print(f"Atendiendo usuario: {user}")

    print("\n-- Probando el timeout --")
    try:
        result = lm.handleUsr() #Habra que esperar 60s
        print(f"Resultado tras timeout: {result}")
    except TypeError:
        print("No se ha devuelto ningun usuario")

    print("\n=== FIN DE TESTS ===")

if __name__ in '__main__':
    main()