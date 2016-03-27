; OS EQUATES
; ----------
;
; Syntax:
; Use '=' for addresses
; and '#' for values
;
; DISPLAY LIST EQUATES
;
ADLI     #   $80
AVB      #   $40
ALMS     #   $40
AVSCR    #   $20
AHSCR    #   $10
AJMP     #   $01
AEMPTY1  #   $00
AEMPTY2  #   $10
AEMPTY3  #   $20
AEMPTY4  #   $30
AEMPTY5  #   $40
AEMPTY6  #   $50
AEMPTY7  #   $60
AEMPTY8  #   $70
;
; OS VARIABLES FOR 5200
;
; PAGE 0
;
POKMSK   =   $00
RTCLOKH  =   $01
RTCLOKL  =   $02
CODFLG   =   $03
ATRACT   =   $04
SDLSTL   =   $05
SDLSTH   =   $06
SDMCTL   =   $07
PCOLR0   =   $08
PCOLR1   =   $09
PCOLR2   =   $0A
PCOLR3   =   $0B
COLOR0   =   $0C
COLOR1   =   $0D
COLOR2   =   $0E
COLOR3   =   $0F
COLOR4   =   $10
;
; PAGE 2
;
VIMIRQ   =   $0200
VVBLKI   =   $0202
VVBLKD   =   $0204
VDLI     =   $0206
VKEYBD   =   $0208
VKEYPAD  =   $020A
VBREAK   =   $020C
VBRK     =   $020E
VSERIN   =   $0210
VSEROR   =   $0212
VSEROC   =   $0214
VTIMR1   =   $0216
VTIMR2   =   $0218
VTIMR4   =   $021A
;
; PAL COMPATIBILITY
;
PALCOMP  =   $BFE7
;
; HARDWARE REGISTERS
;
; GTIA
;
HPOSP0   =   $C000
HPOSP1   =   $C001
HPOSP2   =   $C002
HPOSP3   =   $C003
HPOSM0   =   $C004
HPOSM1   =   $C005
HPOSM2   =   $C006
HPOSM3   =   $C007
SIZEP0   =   $C008
SIZEP1   =   $C009
SIZEP2   =   $C00A
SIZEP3   =   $C00B
SIZEM    =   $C00C
GRAFP0   =   $C00D
GRAFP1   =   $C00E
GRAFP2   =   $C00F
GRAFP3   =   $C010
GRAFM    =   $C011
COLPM0   =   $C012
COLPM1   =   $C013
COLPM2   =   $C014
COLPM3   =   $C015
COLPF0   =   $C016
COLPF1   =   $C017
COLPF2   =   $C018
COLPF3   =   $C019
COLBK    =   $C01A
PRIOR    =   $C01B
VDELAY   =   $C01C
GRACTL   =   $C01D
HITCLR   =   $C01E
CONSOL   =   $C01F
;
; PIA
;
PORTA    =   $D300
PORTB    =   $D301
PACTL    =   $D302
PBCTL    =   $D303
;
; ANTIC
;
DMACLT   =   $D400
CHACTL   =   $D401
DLISTL   =   $D402
DLISTH   =   $D403
HSCROL   =   $D404
VSCROL   =   $D405
PMBASE   =   $D407
CHBASE   =   $D409
WSYNC    =   $D40A
VCOUNT   =   $D40B
PENH     =   $D40C
PENV     =   $D40D
NMIEN    =   $D40E
NMIRES   =   $D40F
;
; POKEY
;
AUDF1    =   $EB00
AUDC1    =   $EB01
AUDF2    =   $EB02
AUDC2    =   $EB03
AUDF3    =   $EB04
AUDC3    =   $EB05
AUDF4    =   $EB06
AUDC4    =   $EB07
AUDCTL   =   $EB08
STIMER   =   $EB09
SKREST   =   $EB0A
POTGO    =   $EB0B
SEROUT   =   $EB0D
IRQEN    =   $EB0E
SKCTL    =   $EB0F
