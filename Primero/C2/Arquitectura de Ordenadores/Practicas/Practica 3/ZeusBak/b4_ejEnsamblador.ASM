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

bucle                   CALL Compara
                        INC ix
                        INC iy
                        INC hl
                        INC de
                        djnz bucle

fin                     halt
                        jp fin;

Compara                 LD a, (hl)
                        CP 1;
                        jp z, Vale1
                        jp nc, Vale2
                        ret

Vale1                   LD a,(ix)
                        ADD a,(iy)
                        LD (de), a
                        ret

Vale2                   LD a,(ix)
                        CP (iy)
                        jp c, esNegativo
                        jp nc, esPositivo
                        jp z, esPositivo
                        ret

esNegativo              SUB a, (iy)
                        LD (de),a
                        CPL
                        ADD a,1
                        EX de,hl
                        INC de
                        INC de
                        LD (de), a
                        EX de,hl
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


