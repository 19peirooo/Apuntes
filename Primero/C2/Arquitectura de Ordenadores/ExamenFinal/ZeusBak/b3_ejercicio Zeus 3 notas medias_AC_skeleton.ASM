; U-tad. Estructura de Ordenadores. Plantilla para el examen final. Mayo de 2024
;        Computer Architecture. Template for the final exam. May 2024

AppFilename             equ "AVG"                       ;  DO NOT TOUCH THIS LINE!
AppFirst                equ $8190                       ;  First byte of code (uncontended memory)
                        zeusemulate "48K","ULA+"        ;  Set the model and enable ULA+

                        org AppFirst                    ;  DO NOT TOUCH THIS LINE!
; ATENCION, tienes que cambiar el contenido de las variables BIRTH y MyFamilyName
; BEWARE, you have to modifify the contents of variables BIRTH and MyFamilyName
FOOTPRINT               defw 0                          ;  DO NOT TOUCH THIS LINE!

BIRTH                   defm "08/07/2005"               ;  Cambiar por tu fecha de nacimiento "DD/MM/AAAA"
                                                        ;  Replace by your birth date "DD/MM/YYYY"


MyFamilyName            defm "peiro"                    ;  Cambiar por tu primer apellido en minúsculas y sin acentos
                                                        ;  Replace by your family name, small caps

Clover                  defs 12                         ;  DO NOT TOUCH THIS LINE!
CHALLENGE               equ Clover-MyFamilyName         ;  DO NOT TOUCH THIS LINE!
DoNotTouch              defs Clover-MyFamilyName        ;  DO NOT TOUCH THIS LINE!
AppEntry                LD A,(BIRTH)                    ;  DO NOT TOUCH THIS LINE!
                        PUSH AF                         ;  DO NOT TOUCH THIS LINE!
                        call APOCALYPSE                 ;  DO NOT TOUCH THIS LINE!
                        POP AF                          ;  DO NOT TOUCH THIS LINE!


; EMPIEZA TU CÓDIGO DESPUÉS DE ESTE COMENTARIO / START WRITING YOUR CODE AFTER THIS COMMENT
MyCode                  LD ix, nums1                    ;Asigno ix como puntero a la direccion de memoria de nums1
                        LD iy, nums2                    ;Asigno iy como puntero a la direccion de memoria de nums2
                        LD hl, medias                   ;Asigno hl como puntero a la direccion de memoria donde se guardaran los resultado
                        LD b,7                          ;Cargo en B el valor 7 ya que tengo 7 numeros

bucle                   ld a,(ix)
                        add (iy)
                        SRA
                        ld (hl),a
                        djnz bucle;                     ;Salta hasta la etiqueta bucle mientra que el registro b no sea 0

fin                     halt                            ;  DO NOT TOUCH THIS LINE!
                        jp fin                          ;  DO NOT TOUCH THIS LINE!

nums1                   DEFB 7,4,8,10,3,0,7
nums2                   DEFB 5,6,9,10,1,0,4
medias                  DEFS 7

; DO NOT TOUCH THIS PIECE OF CODE !!!!
APOCALYPSE              RRCA                            ; DO NOT TOUCH THIS LINE!
                        LD HL,CHALLENGE                 ; DO NOT TOUCH THIS LINE!
                        LD B,L                          ; DO NOT TOUCH THIS LINE!
                        LD IX,MyFamilyName               ; DO NOT TOUCH THIS LINE!
                        LD IY,BIRTH
LOOPY                   NEG                             ; DO NOT TOUCH THIS LINE!
                        INC IY                          ; DO NOT TOUCH THIS LINE!
                        DJNZ LOOPY                      ; DO NOT TOUCH THIS LINE!
                        XOR A,A                         ; DO NOT TOUCH THIS LINE!
                        ADD (IX+1)                      ; DO NOT TOUCH THIS LINE!
                        XOR $00
                        LD (FOOTPRINT),A                ; DO NOT TOUCH THIS LINE!
                        RET                             ; DO NOT TOUCH THIS LINE!
; DO NOT TOUCH THIS PIECE OF CODE !!!


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


