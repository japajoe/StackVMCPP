; Directive 	Purpose 	        Storage Space
; DB 	        Define Byte 	    allocates 1 byte
; DW 	        Define Word 	    allocates 2 bytes
; DD 	        Define Doubleword 	allocates 4 bytes
; DQ 	        Define Quadword 	allocates 8 bytes

; Numbers greater than zero are unsigned, numbers less than or equal to zero are signed
; Following are some examples of using define directives

; letter		    DB	'y'         char
; choice1		    DB	1           char
; direction		    DB	-1          uchar
; number		    DW	12345       uint16
; neg_number	    DW	-12345      int16
; big_number1	    DQ	123456789   int64
; big_number1	    DQ	-123456789  uint64

; real_number1	    DD	1024        int32
; real_number2	    DD	-1024       uint32
; real_number3	    DD	1.234       float
; real_number4	    DQ	123.456     double

; Take note that I haven't extensively tested this yet. Usage is on your own risk.
; Opcodes that take 2 operands are not supported yet

section .data

    numChars DD : 13
    iteration DD : 0
    iterations DD : 10

section .text

_print:
    pushi8 '\n'
    pushi8 '!'
    pushi8 'd'
    pushi8 'l'
    pushi8 'r'
    pushi8 'o'
    pushi8 'w'
    pushi8 ' '
    pushi8 'o'
    pushi8 'l'           
    pushi8 'l'
    pushi8 'e'           
    pushi8 'H'
    pushi32 numChars ;You can also use an integer literal but this example uses a variable
    print
    inc iteration
    cmp iteration, iterations    
    jne 0 ;labels are not yet supported but you can jump to any instruction providing you know its index
    hlt