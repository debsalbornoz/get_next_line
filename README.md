<h1 align="center"> Get next line </h1>



<div align="center">
 <img src="https://github.com/debsalbornoz/get_next_line/assets/119970138/ad029c4d-5e6b-4afb-b3a3-a97f4fe6bc97">
</div> 
<div align="center">
<img alt="Static Badge" src="https://img.shields.io/badge/Status-Finished-green">
</div>
  
<h2>About</h2>
<p align= "left">This repository hosts an implementation of the get_next_line function in C. The get_next_line function is a vital tool in file input/output operations, enabling the program to read one line at a time from a file or an input source until it reaches the end of the file. This function dynamically allocates memory for each line, ensuring efficient memory usage.</p>


<h4> Key Features: </h4>

•Efficient Line-by-Line Reading: Reads one line at a time from files or input streams, optimizing data processing by handling information incrementally.

•Dynamic Memory Allocation: Dynamically allocates memory for each line, promoting efficient memory usage, even when dealing with extensive text files.

•Memory Resource Management: Process large text files line by line without straining the system's memory, ensuring smooth operation.

•Easy Integration: Seamlessly integrate into a variety of C projects involving file operations, providing a reliable solution for reading files.

•Improved Code Structure: Enhance code readability and maintainability by encapsulating file reading logic within a modular function, promoting organized and comprehensible code.

Feel free to explore the repository, experiment with the code, and seamlessly incorporate this line-reading function into your projects. If you encounter any issues or have suggestions for enhancements, your contributions are highly appreciated!

<h2>How to use</h2>


•Clone the repository


```
git clone https://github.com/debsalbornoz/get_next_line.git
```

•Include the files of the repository in your project folder and in your source code include the header 

```
#include "get_next_line.h>
```

•Call the get_next_line function to read lines from the file. Here is an simple example of how to use:

```
#include "get_next_line.h"
#include <stdio.h> 
#include <fcntl.h>

int main(void)
{
    int fd;
    char   *line;
    fd = open("file.txt", O_RDONLY); //opens the file for reading only
    
    line = get_next_line(fd); //calls once get_next_line and reads the first line of the file
    printf("%s",line); //prints the line
    free(line); //frees allocated memory
    close(fd); //close the file
  return(0); //Ends the program
}
```

•Compile and execute


```
cc  -Wall -Wextra -Werror -o my_program my_program.c get_next_line.c get_next_line_utils.c && ./my_program 
```




