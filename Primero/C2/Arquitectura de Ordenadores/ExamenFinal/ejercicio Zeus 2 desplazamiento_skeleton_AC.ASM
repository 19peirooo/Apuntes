; U-tad. Estructura de Ordenadores. Plantilla para el examen final. Mayo de 2024
;        Computer Architecture. Template for the final exam. May 2024

AppFilename             equ "DEPLZ"                     ;  DO NOT TOUCH THIS LINE!
AppFirst                equ $8500                       ;  First byte of code (uncontended memory)
                        zeusemulate "48K","ULA+"        ;  Set the model and enable ULA+

                        org AppFirst                    ;  DO NOT TOUCH THIS LINE!
; ATENCION, tienes que cambiar el contenido de las variables BIRTH y MyFamilyName
; BEWARE, you have to modifify the contents of variables BIRTH and MyFamilyName
FOOTPRINT               defw 0                          ;  DO NOT TOUCH THIS LINE!


BIRTH                   defm "08/07/2005"               ;  Cambiar por tu fecha de nacimiento "DD/MM/AAAA"
                                                        ;  Replace by your birth date "DD/MM/YYYY"


MyFamilyName            defm "peiro"                    ;  Cambiar por tu primer apellido en minúsculas y sin acentos
                                                        ;  Replace by your family name, small caps

Clover                  defs 25                         ;  DO NOT TOUCH THIS LINE!
CHALLENGE               equ Clover-MyFamilyName         ;  DO NOT TOUCH THIS LINE!
DoNotTouch              defs Clover-MyFamilyName        ;  DO NOT TOUCH THIS LINE!
AppEntry                LD A,(BIRTH)                    ;  DO NOT TOUCH THIS LINE!
                        PUSH AF                         ;  DO NOT TOUCH THIS LINE!
                        call HIDDEN                     ;  DO NOT TOUCH THIS LINE!
                        POP AF                          ;  DO NOT TOUCH THIS LINE!

; EMPIEZA TU CÓDIGO DESPUÉS DE ESTE COMENTARIO / START WRITING YOUR CODE AFTER THIS COMMENT
MyCode                  LD C, 10000000b                 ;Cargo el valor en c

desplaza                LD a,c                          ;Cargo C en el acumulador
                        CP 0b                           ;Comparo si el registro es 0
                        JP Z, fin                       ;Si es 0, acaba el programa
                        SLA c                           ;Sino, desplazo a la izquierda
                        INC h                           ;Sumo uno al valor del registro h
                        jp desplaza                     ;Repito hasta que c este vacio

fin                     halt                            ; DO NOT TOUCH THIS LINE!
                        jp fin                          ; DO NOT TOUCH THIS LINE!

; DO NOT TOUCH THIS PIECE OF CODE !!!!
HIDDEN                  RRCA                            ; DO NOT TOUCH THIS LINE!
                        LD HL,CHALLENGE                 ; DO NOT TOUCH THIS LINE!
                        LD B,L                          ; DO NOT TOUCH THIS LINE!
                        LD IX,BIRTH                     ; DO NOT TOUCH THIS LINE!
                        LD IY,BIRTH-10
LOOPY                   NEG                             ; DO NOT TOUCH THIS LINE!
                        INC IY                          ; DO NOT TOUCH THIS LINE!
                        DJNZ LOOPY                      ; DO NOT TOUCH THIS LINE!
                        XOR A,A                         ; DO NOT TOUCH THIS LINE!
                        ADD (IX)                        ; DO NOT TOUCH THIS LINE!
                        ADD CHALLENGE                   ; DO NOT TOUCH THIS LINE!
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


