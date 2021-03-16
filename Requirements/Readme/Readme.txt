Readme

This progam, called UVSim, is a simulation of a machine programming to help computer science students. 
After starting the program, you input instructions into the console, and after inputting -99999, the program runs.

User Instructions:
When starting the simulator you will be given a prompt and a memory address number which will be filled with your BasicML instruction. Enter each BasicML instruction you would like. Each instruction is entered into the simulator memory in consecutive order. These instructions make up your own BasicML program which can be used to add numbers for example. When done entering BasicML instructions into your program simply enter -99999 which will stop instruction entry and start the compilation of your program. Depending on what instructions you have entered the simulator may ask you for input, complete each request as needed to run the BasicML simulation. When the simulation is complete it will display your memory and stop running. Press Enter to stop the simulator.


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
