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

$ will act as an extension, allowing the user to send and recieve data via the network. If brainfuck can be thought of as a very simple computer, the BFNet extension can be thought about as an external network device. This device can read information from the same tape as the BF program, and handles input/output via the network. 

# Development Progress

### Brainfuck Standard- working!

So far, brainfuck appears to adequately handle standard BF input. It's successfully run the few programs I have.

### BFNet Extension

At this time, the $ extension is half functional. The format to send data via network is as follows:

**Target IP Address**
* The first 17 cells from the data pointer hold the IP Address (IPv4) of our target. This allows a maximum of 16 characters (ie, `127.111.111.111`), null-terminated. This string should be null terminated and failure to do so can cause malfunctions. This string must be started at the start of the cells and padded with nulls to fill the end.

**Port number**
* The next 6 cells of data are the ASCII value of the port number. In this implementation of the interpreter, the ASCII gets converted to an int, and then uses that in the appropriate socket functions. 6 cells allows for up to 5 characters and a null terminator (ie, `65533` + 0x00).

**Message**
* The next 256 characters are the message sent to `address:port`. This should also be null-terminated.

**To-Do:**

* Right now, bf's tape doesn't handle the response. Response routine must be updated so that:
    * If a request is made, we must be at the end of the area of the tape where memory was allocated for the request's input. We are past the cells that contain the target's IP, port number, and 512 cell payload buffer. 










