; Atari 5200 Framework
; Written by Sebastian Kotek (tdididit@gmail.com)
;
; Assemble with MADS 2.0.0
;
  		      icl 'inc/a5200.h'
  		      icl 'inc/5200macro.h'
	
		        opt f+h-
            org $0080
;************ Zero Page Variables ****************

            org $0300
;****************** Variables ********************
                        
            org $4000
ROMTOP  equ *	
;*************** Start of Code *******************
START:
        sei                     ;Disable interrupts
        cld                     ;Clear decimal mode

;************** Clear zero page and hardware ******

        ldx     #$00
        lda     #$00
crloop1    
        sta     $00,x           ;Clear zero page
        sta     DMACLT,x        ;Clear ANTIC  DMACTL   =   $D400
        sta     HPOSP0,x        ;Clear GTIA   HPOSP0   =   $C000
        sta     AUDF1,x         ;Clear POKEY  AUDF1    =   $EB00
        dex
        bne     crloop1

;************* Clear RAM **************************

        ldy     #$00            ;Clear Ram
        lda     #$02            ;Start at $0200
        sta     $81             
        lda     #$00
        sta     $80
crloop3
        lda     #$00
        sta     ($80),y         ;Store data
        iny                     ;Next byte
        bne     crloop3         ;Branch if not done page
        inc     $81             ;Next page
        lda     $81
        cmp     #$40            ;Check if end of RAM
        bne     crloop3         ;Branch if not

        lda     #$03            ;point IRQ vector
        sta     VIMIRQ          ;to BIOS routine
        lda     #$FC
        sta     VIMIRQ+1
        lda     #$B8            ;point VBI vector
        sta     VVBLKI          ;to BIOS routine
        lda     #$FC
        sta     VVBLKI+1
        lda     #$B2            ;point Deferred VBI
        sta     VVBLKD          ;to BIOS routine
        lda     #$FC
        sta     VVBLKD+1
         
;****** Main Routine after Startup Procedure ******

MAIN:

        brk


;************** Cart reset vector **************************

        org     $bfe7
.array signature [23] .byte = $00
[0] = $02                 ; $02 - PAL compatible / $00 - NTSC only
[1] = "   A52-FRAMEWORK"  ; Title
[21] = ":)" 			        ; Year on Atari logo splash screen 
                          ; $00FF = Don't display Atari logo
 
.enda
        .word   START     ; Start code at $4000
