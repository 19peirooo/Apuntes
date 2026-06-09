; EJERCICIO DE PAR/IMPAR SOLUCIONADO. EL ALUMNO DEBE CAMBIAR LA FECHA DE NACIMIENTO Y EL NOMBRE DE PILA
; EL ENUNCIADO PEDIRÁ QUE INDIQUE EL VALOR DE LA VARIABLE FOOTPRINT AL FINAL DE LA EJECUCION, QUE ES LA
; LONGITUD DEL NOMBRE MULTIPLICADA POR 3

; U-tad. Estructura de Ordenadores. Plantilla para el examen final. Mayo de 2024
;        Computer Architecture. Template for the final exam. May 2024

AppFilename             equ "EVENODD"                   ; DO NOT TOUCH THIS LINE!
AppFirst                equ $8008                       ; First byte of code (uncontended memory)
                        zeusemulate "48K","ULA+"        ; Set the model and enable ULA+

MyFirstName             defm "antonio"                  ;  Cambiar por tu primer nombre en minúsculas y sin acentos
                                                        ;  Replace by your first name, small caps
Dandelion               defb 010B                       ;  DO NOT TOUCH THIS LINE!
DoNotTouch              defs Dandelion-MyFirstName      ;  DO NOT TOUCH THIS LINE!
                        org AppFirst+DoNotTouch         ;  DO NOT TOUCH THIS LINE!

BIRTH                   defm "20/02/2004"               ; Cambiar por tu fecha de nacimiento "DD/MM/AAAA"
                                                        ; Replace by your birth date "DD/MM/YYYY"

FOOTPRINT               defw 0                          ; DO NOT TOUCH THIS LINE!
SOWHAT                  equ Dandelion-MyFirstName       ; DO NOT TOUCH THIS LINE!
AppEntry                LD A, Dandelion                 ; DO NOT TOUCH THIS LINE!
                        PUSH AF                         ; DO NOT TOUCH THIS LINE!
                        call MISTERY                    ; DO NOT TOUCH THIS LINE!
                        POP AF                          ; DO NOT TOUCH THIS LINE!

; EMPIEZA TU CÓDIGO DESPUÉS DE ESTE COMENTARIO / START WRITING YOUR CODE AFTER THIS COMMENT
MyCode                  ld A, 0                         ; Esta línea está solo como referencia, puedes cambiarla
                                                        ; This line is just a reference you may modify it
                                                        ;
                                                        ;
                                                        ; Your code here
                                                        ;
                                                        ;

fin                     halt                            ; DO NOT TOUCH THIS LINE!
                        jp fin                          ; DO NOT TOUCH THIS LINE!

; DO NOT TOUCH THIS PIECE OF CODE !!!!
MISTERY                 LD HL,SOWHAT                    ; DO NOT TOUCH THIS LINE!
                        LD B,L                          ; DO NOT TOUCH THIS LINE!
                        XOR A,A                         ; DO NOT TOUCH THIS LINE!
                        LD IY,FOOTPRINT                 ; DO NOT TOUCH THIS LINE!
                        DEC IY                          ; DO NOT TOUCH THIS LINE!
MLOOP                   LD HL,(IY)                      ; DO NOT TOUCH THIS LINE!
                        ADD 3                           ; DO NOT TOUCH THIS LINE!
                        DEC IY                          ; DO NOT TOUCH THIS LINE!
                        DJNZ MLOOP                      ; DO NOT TOUCH THIS LINE!
                        LD (FOOTPRINT),A                ; DO NOT TOUCH THIS LINE!
                        RET                             ; DO NOT TOUCH THIS LINE!
; DO NOT TOUCH THIS PIECE OF CODE !!!

; Stop planting code after this.
AppLast                 equ *-1                         ; The last used byte's address

; Generate some useful debugging commands

                        profile AppFirst,AppLast-AppFirst+1 ; Enable profiling for all the code

; Setup the emulation registers, so Zeus can emulate this code correctly

Zeus_PC                 equ AppEntry                    ; Tell the emulator where to start
Zeus_SP                 equ $FF40                       ; Tell the emulator where to put the stack

; These generate some output files

                        ; Generate a SZX file
                        output_szx AppFilename+".szx",$0000,AppEntry ; The szx file

                        ; If we want a fancy loader we need to load a loading screen
;                        import_bin AppFilename+".scr",$4000            ; Load a loading screen

                        ; Now, also generate a tzx file using the loader
                        output_tzx AppFilename+".tzx",AppFilename,"",AppFirst,AppLast-AppFirst,1,AppEntry ; A tzx file using the loader


