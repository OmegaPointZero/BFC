# BFC
Brainfuck Interpreter in C++ (and reference project for BFAsm).

There are 2 distinct goals for this project:

* Implement all standard brainfuck functions
  * ignore any characters that are not ><.,[]
  * Execute instructions successfully
  * Execute nested loops
* Add networking functions
  * Additional symbol must be added, and less is better
  * If only one, use $. Make a standard so the next n bytes are the IP, next n are the port, and remaining x bytes are what is sent in the raw
  * This way brainfuck can prepare a message later in the tape, and create a message for the user to input a target address and port, and jump back to the proper spot to input the characters correctly.
