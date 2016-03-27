Y2K       .LOCAL
SPLASH:
        lda #$F8
        sta CHBASE
        ldx #$0B
nscp_loop:
        lda $FE95,x
        sta $0200,x
        dex
        bpl nscp_loop
        
        lda #$3C
        sta $12
        lda #0
        sta $11
        
        ldx #$0C
        tay
nsclr_loop:
        sta ($11),y
        dey
        bne nsclr_loop
        dec $12
        dex
        bpl nsclr_loop
        
;build display list

        lda #$0d      ; Antic mode 13
        ldx #$4d
nsbld_loop:
        sta $2007,x
        dex
        bpl nsbld_loop
        
        ldx #$06
nsbld_loop2:
        lda $fec8,x
        sta $2000,x
        dex
        bpl nsbld_loop2
        
        ldx #$04
nsbld_loop3:
        lda $fecf,x
        sta $2055,x
        dex
        bpl nsbld_loop3
            
        lda #$00
        sta SDLSTL
        lda #$20
        sta SDLSTH
        
        lda #$22
        sta SDMCTL
        
        lda #$30
        tay
        lda #$28
        ldx #$36
nsptr_loop:        
        sta $1100,x
        pha
        tya
        sta $1000,x
        pla
        dex
        bmi ns_fuji
        clc
        adc #$28
        bcc nsptr_loop
        iny
        bcs nsptr_loop
ns_fuji:
        ldx #$13
        stx $17
        inx
        stx $18
        lda #$20
        sta $13
ns_fuji_fdb9:
        lda #$01
        sta $15
        lda #$40
        sta $16
ns_fuji_fdc1:        
        dec $13
        bmi ns_atari
        ldx $13
        lda $fee8,x
        sta $14
        lda $ff08,x
        tax
ns_fuji_loop3:
        cpx $14
        beq ns_fuji2
        lda $1100,x
        sta $11
        lda $1000,x
        sta $12
        ldy $17
        lda $15
        ora ($11),y
        sta ($11),y
        ldy $18
        lda $16
        ora ($11),y
        sta ($11),y
        inx
        bne ns_fuji_loop3
ns_fuji2:            
        asl $15
        asl $15
        bcs ns_fuji_fdfd
        lsr $16
        lsr $16
        bcc ns_fuji_fdc1
ns_fuji_fdfd:
        dec $17
        inc $18
        bcs ns_fuji_fdb9  
        
ns_atari:
        lda #$11
        sta $11
        lda #$39
        sta $12
        lda #$13
        sta $13
        lda #$00
        sta $15
ns_atari_fe13:        
        lda #$01
        ldy #$0A
ns_atari_fe17:
        sta $18
        ldx $15
        inc $15
        lda $ff28,x
        beq ns_atari_fe4c
        tax
        and #$0f
        sta $16
        txa
        lsr
        lsr
        lsr
        lsr
        tax
        lda $18
ns_atari_fe2f:
        asl
        asl
        bcc ns_atari_fe38
        sta ($11),y
        iny
        lda #$01
ns_atari_fe38:        
        dex
        bpl ns_atari_fe2f
        ldx $16
ns_atari_fe3d:        
        sec
        rol
        asl
        bcc ns_atari_fe47
        
        sta ($11),y
        iny                                                                           
        lda #$01
ns_atari_fe47:        
        dex
        bpl ns_atari_fe3d
        bmi ns_atari_fe17
ns_atari_fe4c:        
        lda $18
ns_atari_fe4e:        
        asl
        asl        	
        bcc ns_atari_fe4e
        sta ($11),y
        lda $11
        clc
        adc #$28
        sta $11
        bcc ns_atari_fe5f
        inc $12
ns_atari_fe5f:
        dec $13
        bpl ns_atari_fe13

        ldx #$13
ns_copyright:
        lda $FED4,x
        sta $3c94,x
        lda $bfe8,x
        sta $3c80,x
        dex
        bpl ns_copyright
        
// put year into screen memory
        lda #"2"
        sta $3c9e
        
        lda $BFFC
count100:
        cmp #100
        bmi count10
        sec
        sbc #100
        inc $20
        jmp count100
count10:
        cmp #10
        bmi count1
        sec
        sbc #10
        inc $21
        jmp count10
count1:
        cmp #1
        bmi count_done
        sec
        sbc #1
        inc $22
        jmp count1
count_done:
        ldx #2
ns_year:
        lda $20,x
        clc
        adc #$10
        sta $3c9f,x
        dex
        bpl ns_year
        
        lda #$0f
        sta COLOR1
        lda #$C0
        sta NMIEN	              ;Enable DLI and VBI 
        lda #$02
        sta SKCTL
ns_kbdloop:
        cpx $02
        bne ns_kbdloop
        rts
              

.ENDL