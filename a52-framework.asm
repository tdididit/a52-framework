  		      icl 'inc/a5200.h'
  		      icl 'inc/5200macro.h'
	
		        opt f+h-
            org $0080
;************ Zero Page Variables ****************
            
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

;****** Main Routine after Startup Procedure ******

MAIN:

        brk


;************** Cart reset vector **************************

        org     $bffd
        .byte   $FF         ; $FF = Don't display Atari logo
        .word   START     ; Start code at $4000
