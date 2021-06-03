# StackVMSharp
A stack and register based virtual machine which can compile and run arbitrary code in runtime.

Support for most common integer types like
- int8/uint8
- int16/uint16
- int32/uint32
- int64/uint64
- float
- double

The instructionset resembles x86 assembly, although it's not a 1 to 1 mapping which means any code written wouldn't work with any other assembler. My goal is to get more familiar with low level programming, and hopefully be able to create a higher level language which compiles down to my own instructions. In the end it would be interesting if it could be embedded into programs as a blazingly fast scripting language.

Keep in my mind that this is my hobby project, and it might contain code that hurts your eyes or worse. I do not follow any well layed out path so I'm learning as I go. 

# How it works
Feed the compiler a source file, load the output into the virtual machine and run it. See demo.asm for reference because I can't be bothered right now to write any guides. After all there's a big chance if you came across this repository that you are pretty comfortable diving into undocumented code.