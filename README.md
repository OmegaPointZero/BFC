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
  * $ will read the next 17 cells, and that will be the IP address to send to, dot-notated in ASCII. It is important this string is null terminated.
  * The next 6 cells will be the port number (in ASCII) and a null terminator.
  * The next 512 are for what you want to send.
  
 * **1**.
  * $ will create a socket and wait for connection, and read the input into 

# Development Progress

### Brainfuck Standard- working!

So far, brainfuck appears to adequately handle standard BF input. It's successfully run the few programs I have.

### BFNet Extension

At this time, the $ extension doesn't work. I only just programmed it to send a payload to a waiting nc instance. 

* **To-Do**

    * Read IP, PORT and payload from tape
    * Verify that user input standard works according to BFNet documentation
    * Right now, bf's tape doesn't handle the response. Response routine must be updated so that:
        * If a request is made, we must be at the end of the area of the tape where memory was allocated for the request's input. We are past the cells that contain the target's IP, port number, and 512 cell payload buffer. 
        * The next 514 bytes (one for padding at the start to ensure null termination, 512 to handle input from a client, 1 null termination)
    * Routine for providing a 1 when calling $:
        * Set up a listener, print the data, and resume execution at the end of the listened to data on the tape










