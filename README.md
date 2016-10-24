# Brainfuck
A brainfuck interpreter program written in C.

Brainfuck is a minimalist language. It consists of an array of bytes 
initialized to zero (this program uses 4096 bytes), and a pointer to its first byte.

Every operator consists of a single character :
  - '>' increment the pointer ;
  - '<' decrement the pointer ;
  - '+' increment the pointed byte ;
  - '-' decrement the pointed byte ;
  - '.' print the pointed byte on standard output ;
  - '[' go to the matching ']' if the pointed byte is 0 (while start) ;
  - ']' go to the matching '[' if the pointed byte is not 0 (while end).

Any other character is a comment.

To run the interpreter:

1. git clone this repository on to your local machine.

2. Compile the contents of the cloned repository using gcc.
    i.e gcc -Wall -Wextra -Werror -o brainfuck
    
3. The first argument read in after the executable file will be interpreted.
    i.e.  $>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
          Hello World!$
