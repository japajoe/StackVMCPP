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
    iterations dd : 1000
    PI2 dd : 6.28318530718
    freq dd : 440
    sampleRate dd : 44100
    amp dd : 10.0

section .text

update:
    call calculateSineWave
    call displayInfo    
    inc iteration    
    cmp iteration, iterations
    jne update
    jmp end

calculateSineWave:
    popu64 ebp
    mov eax, PI2
    mul eax, iteration
    mul eax, freq
    div eax, sampleRate
    pushf eax
    callf sin
    popf eax
    mul eax, amp
    pushu64 ebp
    ret

displayInfo:
    popu64 ebp
    pushf eax
    pushi32 2   ;0 is int32, 1 is int64, 2 is float
    callf printnum
    callf endline
    pushu64 ebp
    ret

end:
    hlt
