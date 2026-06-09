; This is a basic template file for writing 48K Spectrum code.

AppFilename             equ "NewFile"                   ; What we're called (for file generation)

AppFirst                equ $8000                       ; First byte of code (uncontended memory)

                        zeusemulate "48K","ULA+"        ; Set the model and enable ULA+


; Start planting code here. (When generating a tape file we start saving from here)

                        org AppFirst                    ; Start of application

AppEntry                LD ix, nums1                    ;Cargo en el ix la direccion de memoria de los primeros numeros
                        LD iy, nums2                    ;Cargo en el iy la direccion de memoria de los segundos numeros
                        LD hl, oper                     ;Cargo en los registros H y L direccion de memoria donde estan los operadores
                        LD de, result                   ;Cargo la direccion de memoria de los resultados en los registros DE
                        LD B, 6                         ;Cargo un 6 en el registro B para que el bucle solo se repita 6 veces

                        EXX                             ;Cambio de los registro normales por el segundo juego
                        LD hl, result                   ;Cargo la direccion de memoria de los resultados en el hl del segundo juego
                        LD de,16                        ;Cargo el valor 16 en el registro DE
                        ADC hl,de                       ;Sumo 16 la posicion de memoria de los resultados para guardar los valores positivos de las resta
                        EXX                             ;Vuelvo al juego original de registros

                                                        ;Inicio bucle
bucle                   CALL Compara                    ;Llamo a la funcion para comparar
                        INC ix                          ;Incremento la memoria de los 4 regitros para acceder los siguentes numeros
                        INC iy
                        INC hl
                        INC de
                        djnz bucle                      ;Resta uno al registro B y salta hasta la etiqueta bucle.
                                                        ;El bucle no acaba hasta que B no sea cero

fin                     halt                            ;Finaliza el programa
                        jp fin

Compara                 LD a, (hl)                      ;Cargo el operador en el acumulador
                        CP 1                            ;Lo comparo con el uno
                        jp z, Vale1                     ;Si es igual, llamo a la funcion para sumar
                        jp nc, Vale2                    ;Si es mayor, es el 2 y llamo a la funcion de resta
                        ret                             ;Vuelvo al bucle principal

Vale1                   LD a,(ix)                       ;Cargo el primer numero en el acumulador
                        ADD a,(iy)                      ;Le sumo el segundo
                        LD (de), a                      ;Lo guardo en la posicion de memoria de los resutados
                        ret                             ;Vuelvo a la funcion anterior

Vale2                   LD a,(ix)                       ;Cargo el primer numero en el acumulador
                        CP (iy)                         ;Lo comparo con el segundo
                        jp c, esNegativo                ;Si el segundo es mayor que el primero. El resultado es negativo.
                                                        ;Salto a la funcion esNegativo
                        jp nc, esPositivo               ;Si no lo es. El resultado es positivo.Salto a la funcion esPositivo
                        jp z, esPositivo
                        ret                             ;Vuelvo a la funcion anterior

esNegativo              SUB a, (iy)                     ;Resto el segundo al primero
                        LD (de),a                       ;Guardo el resultado
                                                        ;Hago el Ca2 del resultado
                        CPL                             ;Hago el complemento a 1
                        ADD a,1                         ;Sumo 1
                        EXX                             ;Cambio al segundo juego de registro
                        LD (hl),a                       ;Guardo el nuevo numero 16 posiciones de memoria mas adelante
                        INC hl                          ;Incremento para guardar en la siguente espacio
                        EXX                             ;Vuelvo al juego de registros original
                        ret                             ;Vuelvo a la funcion anterior

esPositivo              SUB a,(iy)                      ;Resto el segundo al primero
                        LD (de),a                       ;Guardo el resultado
                        ret                             ;Vuelvo a la funcion anterior

nums1                   DEFB 1,2,3,4,5,6                ;Reservo memoria para el primer set de numeros
nums2                   DEFB 10,9,8,7,6,5               ;Reservo memoria para el seegundo set de numeros
oper                    DEFB 1,2,1,1,2,2                ;Reservo memoria para guardar los results
result                  DEFS 6                          ;Reserva de memoria de resultados


; Stop planting code after this. (When generating a tape file we save bytes below here)
AppLast                 equ *-1                         ; The last used byte's address

; Generate some useful debugging commands

                        profile AppFirst,AppLast-AppFirst+1     ; Enable profiling for all the code

; Setup the emulation registers, so Zeus can emulate this code correctly

Zeus_PC                 equ AppEntry                            ; Tell the emulator where to start
Zeus_SP                 equ $FF40                               ; Tell the emulator where to put the stack

; These generate some output files

                        ; Generate a SZX file
                        output_szx AppFilename+".szx",$0000,AppEntry    ; The szx file

                        ; If we want a fancy loader we need to load a loading screen
;                        import_bin AppFilename+".scr",$4000            ; Load a loading screen

                        ; Now, also generate a tzx file using the loader
                        output_tzx AppFilename+".tzx",AppFilename,"",AppFirst,AppLast-AppFirst,1,AppEntry ; A tzx file using the loader


