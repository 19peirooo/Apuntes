; This is a basic template file for writing 48K Spectrum code.

AppFilename             equ "NewFile"                   ; What we're called (for file generation)

AppFirst                equ $8000                       ; First byte of code (uncontended memory)

                        zeusemulate "48K","ULA+"        ; Set the model and enable ULA+


; Start planting code here. (When generating a tape file we start saving from here)

                        org AppFirst                    ; Start of application

AppEntry                LD D, 5
                        LD IX, arr1
                        LD IY, resul
bucle                   LD BC, 7   ;Tamaño del array en el ue queremos buscar
                        LD A, (IX)      ;Valor que queremos buscar
                        LD HL, arr2    ;Array en el que queremos buscar
                        CPIR     ;Z = 1 si lo encuentra, Z = 0 si no lo encuentra
                        CALL Z, encontrado
                        INC IX
                        INC IY

                        DEC D
                        LD A, 0
                        CP D
                        JP NZ, bucle
                        HALT




encontrado              LD (IY), 1
                        RET

                        jp AppEntry                     ;

arr1                    defb 1,2,3,4,5   ;Si el numero de arr1 está en arr2, guardar un 1 en esa posición de resul
arr2                    defb 8,4,9,2,1,10,20
resul                   defs 5


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


