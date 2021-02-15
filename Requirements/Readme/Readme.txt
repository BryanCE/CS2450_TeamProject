Readme

This progam, called UVSim, is a simulation of a machine programming to help computer science students. 
After starting the program, you input instructions into the console, and after inputting -99999, the program runs.

Instructions:
(** is memory locations 00-99)

I/O Operations
READ= 10**      Receive an input from the command line and place it in memory.
WRITE= 11**     Write the word from memory to the console.

Load/ Store Operations
LOAD= 20**     Load a word from memory into the accumulator.
STORE= 21**     Store a word from the accumulator into a memory location.

Arithmetic Operations
ADD= 30**       Add the value in the accumulator and the value in the memory location, and put the result in the accumulator
SUBTRACT= 31**  Subtract the value in the accumulator and the value in the memory location, and put the result in the accumulator
DIVIDE= 32**    Divide the value in the accumulator and the value in the memory location, and put the result in the accumulator
MULTIPLY= 33**  Multiply the value in the accumulator and the value in the memory location, and put the result in the accumulator

Control Operations
BRANCH= 40**    Branch to a specific memory location
BRANCHNEG= 41** Branch to a specific memory location if the accumulator is negative
BRANCHZERO= 42** Branch to a specific memory location if the accumulator is zero
HALT= 43**      Pause the program
