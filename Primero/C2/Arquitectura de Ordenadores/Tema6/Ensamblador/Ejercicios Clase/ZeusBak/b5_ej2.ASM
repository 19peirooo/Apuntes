; This is a basic template file for writing 48K Spectrum code.

AppFilename             equ "NewFile"                   ; What we're called (for file generation)

AppFirst                equ $8000                       ; First byte of code (uncontended memory)

                        zeusemulate "48K","ULA+"        ; Set the model and enable ULA+


; Start planting code here. (When generating a tape file we start saving from here)

                        org AppFirst                    ; Start of application

AppEntry                LD A,1H
                        LD B,2H
                        LD C,3H
                        LD D,4H
                        LD E,5H
                        LD H,6H
                        LD L,7H
                        LD IX,8H
                        LD IY,9H
                        EXX
                        LD A,0AH
                        LD B,0BH
                        LD C,0CH
                        LD D,0DH
                        LD E,0EH
                        LD H,0FH
                        LD L,10H
                        EXX
                        LD IX,nums
                        ld (IX),A
                        inc IX
                        ld (IX),B
                        inc IX
                        ld (IX),C
                        inc IX
                        ld (IX),D
                        inc IX
                        ld (IX),E
                        inc IX
                        ld (IX),H
                        inc IX
                        ld (IX),L
                        EXX
                        inc IX
                        ld (IX),A
                        inc IX
                        ld (IX),B
                        inc IX
                        ld (IX),C
                        inc IX
                        ld (IX),D
                        inc IX
                        ld (IX),E
                        inc IX
                        ld (IX),H
                        inc IX
                        ld (IX),L

fin                     halt
                        jp fin



nums                    DEFS 16


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


