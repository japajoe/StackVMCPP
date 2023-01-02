; Directive 	Purpose 	        Storage Space
; DB 	        Define Byte 	    allocates 1 byte
; DW 	        Define Word 	    allocates 2 bytes
; DD 	        Define Doubleword 	allocates 4 bytes
; DQ 	        Define Quadword 	allocates 8 bytes

; Numbers greater than zero are unsigned, numbers less than or equal to zero are signed
; Following are some examples of using define directives

; letter		    DB	'y'         char
; choice1		    DB	1           uchar
; direction		    DB	-1          char
; number		    DW	12345       uint16
; neg_number	    DW	-12345      int16
; big_number1	    DQ	123456789   uint64
; big_number1	    DQ	-123456789  int64

; real_number1	    DD	1024        uint32
; real_number2	    DD	-1024       int32
; real_number3	    DD	1.234       float
; real_number4	    DQ	123.456     double

; Take note that I haven't extensively tested this yet. Usage is on your own risk.

section .data
    iteration dd : 0
    iterations dd : 10

section .text
    
start:    
    push ' '
    push '!'
    push 'd'
    push 'l'
    push 'r'
    push 'o'
    push 'w'
    push ' '
    push 'o'
    push 'l'
    push 'l'
    push 'e'
    push 'H'
    push 13
    call print    
    push iteration
    call printnum
    call endline
    inc iteration
    cmp iteration, iterations
    jne start
    hlt
