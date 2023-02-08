## About

**TL;DR:** It's just a big one dimension character array where all values are set to 0 and you can control the pointer with its 8 commands. A character holds ASCII values, so by increasing a value one by one(like a caveman) you can get to characters such as 'a', '1', 'space'. 

| Commands | Meaning 
|----------|:---------
| **.** | Print what is in the pointer
| **+** | Increase the char by one  
| **-** | Decrease the char by one 
| **>** | Move the pointer to the right
| **<** | Move the pointer to the left 
| **[** | Start a loop
| **]** | End a loop if the pointer is 0, otherwise, go back where **[** was and loop again

For more details [see](https://en.wikipedia.org/wiki/Brainfuck). 

[Some tests](http://www.brainfuck.org/tests.b) I'm using to test my implementation, feel free to use it too.
