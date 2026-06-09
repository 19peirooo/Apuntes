; This is a basic template file for writing 48K Spectrum code.

AppFilename             equ "NewFile"                   ; What we're called (for file generation)

AppFirst                equ $8000                       ; First byte of code (uncontended memory)

                        zeusemulate "48K","ULA+"        ; Set the model and enable ULA+


; Start planting code here. (When generating a tape file we start saving from here)

                        org AppFirst                    ; Start of application

AppEntry                LD ix, nums1                    ;Cargo en el ix los primeros numeros
                        LD iy, nums2                    ;Cargo en el iy los segundos numeros
                        LD hl, oper                     ;Cargo en los registros H y L los operadores
                        LD de, result                   ;Los resultados se guardaran en los registros D y E
                        LD B, 6                         ;Cargo un 6 en el registro B para que el bucle solo se repita 6 veces

                        EXX                             ;Cambio al segundo juego de registro
                        LD hl, result                   ;Cargo los resultados
                        LD de, 16                       ;Cargo un 16 en el de
                        ADC hl,de                       ;Sumo 16 al valor del hl para que se puede acceder al la posicion de memoria de 16 bytes mas adelante
                        EXX                             ;Vuelvo al juego original

bucle                   CALL Compara                    ;Llamo a la funcion compara
                        INC ix                          ;Incremento para acceder a los siguentes valores
                        INC iy
                        INC hl
                        INC de
                        djnz bucle                       ;Bucle que se repite hasta que B sea 0

fin                     halt
                        jp fin;

Compara                 LD a, (hl)                       ;Cargo el operador en el acumulador
                        CP 1;                            ;Comparo con el 1
                        jp z, Vale1                      ;Si es igual, sumo
                        jp nc, Vale2                     ;Sino, restro
                        ret

Vale1                   LD a,(ix)                        ;Cargo el primer numero en el acumulador
                        ADD a,(iy)                       ;Sumo el segundo
                        LD (de), a                       ;Guardo al resultado
                        ret

Vale2                   LD a,(ix)                        ;Cargo el primer numero
                        CP (iy)                          ;Comparo con el segundo
                        jp c, esNegativo                 ;Si el primero es mas pequeño que el segundo. El numero es negativo
                        jp nc, esPositivo                ;Si no lo es, el numero es positivo
                        jp z, esPositivo
                        ret

esNegativo              SUB a, (iy)                      ;Resto el segundo
                        LD (de),a                        ;Lo guardo
                        CPL
                        ADD a,1

                        ret

esPositivo              SUB a,(iy)
                        LD (de),a
                        ret

nums1                   DEFB 1,2,3,4,5,6
nums2                   DEFB 10,9,8,7,6,5
oper                    DEFB 1,2,1,1,2,2
result                  DEFS 6


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


