# StackVMCPP
A stack and register based virtual machine which can compile and execute arbitrary code in runtime.

Support for most common integer types like
- int8/uint8
- int16/uint16
- int32/uint32
- int64/uint64
- float
- double

# Dependencies
- None

# Update as of 01/01/2023
- There are some major differences, so please review them carefully if you intend to pull in changes.
- The CALLF instruction has become obsolete, as the CALL function now is capable of either jumping to labels, or calling registered functions in your application. The CALLF opcode will remain usable but will eventually be removed.
- The stack has been rewritten entirely, which should make it more useful and safer.
- StackVM functions now require to return an integer which signals either an error or success.
- The Compiler::Execute function returns an ExecutionStatus

# Instructions
**MOV**
Move a value into a register or into a variable. Registers are able to store any type, variables are constrained to only contain the type they are defined as.
- mov eax, ebx
- mov eax, myVariable
- mov eax, 10
- mov myVariable, eax
- mov myVariable, anotherVariable
- mov myVariable, 123.45

**INC**
Increments the value stored in a register or variable with 1.
- inc eax
- inc myVariable

**DEC**
Decrements the value stored in a register or variable with 1.
- dec eax
- dec myVariable

**ADD**
Adds a value to a value stored in a register or variable.
- add eax, 30
- add eax, myVariable
- add myVariable, 30
- add myVariable, eax

**SUB**
Subtract a value from a value stored in a register or variable.
- sub eax, 30
- sub eax, myVariable
- sub myVariable, 30
- sub myVariable, eax

**MUL**
Multiplies a value stored in a register or variable with another value.
- mul eax, 30
- mul eax, myVariable
- mul myVariable, 30
- mul myVariable, eax

**DIV**
Divides a value stored in a register or variable with another value.
- div eax, 30
- div eax, myVariable
- div myVariable, 30
- div myVariable, eax

**PUSH**
Pushes a value to the stack. This value can be of any type.
- push eax
- push myVariable
- push 10
- push 0.5

**PUSHI8**
Pushes a int8 to the stack.
- pushi8 eax
- pushi8 myVariable
- pushi8 'H'

**PUSHU8**
Pushes a uint8 to the stack.
- pushu8 eax
- pushu8 myVariable
- pushu8 'H'

**PUSHF**
Pushes a float to the stack.
- pushf eax
- pushf myVariable
- pushf 0.33

**PUSHD**
Pushes a double to the stack.
- pushd eax
- pushd myVariable
- pushd 0.33

**PUSHI32**
Pushes a int32 to the stack.
- pushi32 eax
- pushi32 myVariable
- pushi32 -100

**PUSHU32**
Pushes a uint32 to the stack.
- pushu32 eax
- pushu32 myVariable
- pushu32 100

**PUSHI16**
Pushes a int16 to the stack.
- pushi16 eax
- pushi16 myVariable
- pushi16 -100

**PUSHU16**
Pushes a uint16 to the stack.
- pushu16 eax
- pushu16 myVariable
- pushu16 100

**PUSHI64**
Pushes a int64 to the stack.
- pushi64 eax
- pushi64 myVariable
- pushi64 -100

**PUSHU64**
Pushes a int64 to the stack.
- pushu64 eax
- pushu64 myVariable
- pushu64 100

**POP**
Pops any 8 byte value off the top of the stack. This instruction might be removed because of its limited usefulness.
- pop
- pop eax
- pop myVariable

**POPI8**
Pops a int8 from the top of the stack.
- popi8
- popi8 eax
- popi8 myVariable

**POPU8**
Pops a uint8 from the top of the stack.
- popu8
- popu8 eax
- popu8 myVariable

**POPF**
Pops a float from the top of the stack.
- popf
- popf eax
- popf myVariable

**POPD**
Pops a double from the top of the stack.
- popd
- popd eax
- popd myVariable

**POPI32**
Pops a int32 from the top of the stack.
- popi32
- popi32 eax
- popi32 myVariable

**POPU32**
Pops a uint32 from the top of the stack.
- popu32
- popu32 eax
- popu32 myVariable

**POPI16**
Pops a int16 from the top of the stack.
- popi16
- popi16 eax
- popi16 myVariable

**POPU16**
Pops a uint32 from the top of the stack.
- popu32
- popu32 eax
- popu32 myVariable

**POPI64**
Pops a int64 from the top of the stack.
- popi64
- popi64 eax
- popi64 myVariable

**POPU64**
Pops a uint64 from the top of the stack.
- popu64
- popu64 eax
- popu64 myVariable

**CMP**
Compares 2 values for equality and sets a flag whether the lefthandside is less than, greater than, or equal to the righthandside.
- cmp eax, ebx
- cmp eax, myVariable
- cmp eax, 99
- cmp myVariable, ebx
- cmp myVariable, anotherVariable
- cmp myVariable, 45

**CALL**
Makes a jump to a specific label defined by the user. A label can be defined above any instruction and it could be seen like a function identifier. After the CALL instruction the instructionpointer is set to the first instruction after the label. When  instructions have been executed and the RET instruction has been reached, the instructionpointer is set to the instruction after the CALL instruction. This is useful when you need to run a specific routine and then return to where you came from and continue with other instructions.
- call doWork
- call printInfo
- call doCalculation

**CALLF**
(Obsolete) The CALLF instruction calls predefined functions inside the library and should not be confused with regular CALL. CALLF does not work on labels. There are a number of these predefined functions which can either return a value on top of the stack, or just do something and return nothing. Some functions require that you push their arguments on the stack, then the function takes care of popping them off. For a better overview of which functions are available and what parameters to pass see StandardLibrary.hpp and StandardLibrary.cpp
- callf sin
- callf printf
- callf getTimeStamp

**RET**
The RET instruction sets the instructionpointer back to the instruction that comes right after the CALL instruction.

**JMP**
Unconditional jump to a label
- jmp someLabel

**JE**
Jump to label if CMP instruction evaluated to equal.
- je someLabel

**JNE**
Jump to label if CMP instruction evaluated to not equal.
- jne someLabel

**JG**
Jump to label if CMP instruction evaluated to greater than.
- jg someLabel

**JGE**
Jump to label if CMP instruction evaluated to greater than or equal.
- jge someLabel

**JL**
Jump to label if CMP instruction evaluated to less than.
- jl someLabel

**JLE**
Jump to label if CMP instruction evaluated to less than or equal.
- jle someLabel

**JZ**
Jump to label if result of a add/sub/mul/div instruction equals to zero.
- jz someLabel

**JNZ**
Jump to label if result of a add/sub/mul/div instruction does not equal zero.
- jz someLabel

**NOP**
This opcode literally does nothing. In x86 assembly it can be used to disable instructions by overwriting them with NOP instructions

**HLT**
This sets the instructionpointer to nullptr and it effectively stops the program.
