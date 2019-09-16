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

# Brainfuck Standard Documentation

There are only 8 operators in brainfuck:
* **>** Moves the data pointer to the right on the tape.
* **<** Moves the data pointer left on the tape.
* **+** Increments the cell pointed to by the data pointer.
* **-** Decrements the cell pointed to by the data pointer.
* **.** Prints ASCII character in current code (ie, 0x41 or 65 == 'A')
* **,** Reads ASCII character from STDIN and puts value on tape (ie, ,>,>, populates 3 cells, if we type 'ABC' when prompted for the input, it would write 65 66 67 (0x41 0x42 0x43) to the tape
* **[** BF Loop Open: all code contained within brackets will be looped, until the currently selected number on the tape reaches 0.
* **]** BF Loop Open: all code contained within brackets will be looped, until the currently selected number on the tape reaches 0.

# BFNet Extension Documentation
BFNet, a brainfuck extension for which this interpreter was built, is an extension of the standard brainfuck operators. To keep it as true to brainfuck's minimalist theory, I intend to have only one meaningful symbol added: **$**.

$ will read the current cell of memory, and perform 1 of 2 options based on that:

* **0**. 
  * $ will read the next 20 cells, and that will be the IP address to send to, dot-notated in ASCII. Unused bytes should be 0x00, and the last byte should be 0x00 
  * The next 6 cells will be the port number (in ASCII) and a null terminator.
  * The next 999 are for what you want to send.
  
 * **1**.
  * $ will read a response from a server into the next 999 cells.
  
