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

section .text

_print:
    PUSHI8 '\n'
    PUSHI8 '!'
    PUSHI8 'd'
    PUSHI8 'l'
    PUSHI8 'r'
    PUSHI8 'o'
    PUSHI8 'w'
    PUSHI8 ' '
    PUSHI8 'o'
    PUSHI8 'l'           
    PUSHI8 'l'
    PUSHI8 'e'           
    PUSHI8 'H'
    PUSHI32 numChars ;You can also use an integer literal but this example uses a variable
    PRINT
    HLT