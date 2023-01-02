section .data
    iterations dq : 20
    counter dq : 0
    num1 dq : 0
    num2 dq : 1

    tempA dq : 0
    tempB dq : 0

section .text
start:
    cmp counter, iterations
    jge end
    inc counter

    mov tempA, num1
    add tempA, num2
    mov tempB, tempA
    mov tempA, num1
    mov num2, tempA
    mov tempA, tempB
    mov num1, tempA

    push num1
    call printnum
    call endline
    
    jmp start
end:
    hlt