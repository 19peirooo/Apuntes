; This is a basic template file for writing 48K Spectrum code.

AppFilename             equ "NewFile"                   ; What we're called (for file generation)

AppFirst                equ $8000                       ; First byte of code (uncontended memory)

                        zeusemulate "48K","ULA+"        ; Set the model and enable ULA+


; Start planting code here. (When generating a tape file we start saving from here)

                        org AppFirst                    ; Start of application

AppEntry                LD B,5
                        LD ix, nums1
                        LD iy, nums2
                        LD hl, resultado

bucle                   LD C, (ix)
                        LD D, (iy)
                        CALL compara
                        INC ix
                        INC iy
                        inc hl
                        djnz bucle
fin                     halt
                        jp fin

compara                 LD A,C
                        CP D
                        jp Z, iguales
                        jp C, menor
                        jp NC, mayor
                        ret

iguales                 LD hl,0
                        ret
menor                   LD hl,-1
                        ret
mayor                   LD hl,1
                        ret


nums1                   DEFB 1,5,2,7,4
nums2                   DEFB 6,3,1,7,7
resultado               DEFS 5


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


