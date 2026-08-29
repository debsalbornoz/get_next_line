<h1 align="center">Get Next Line</h1>

<div align="center">
  <img src="https://github.com/debsalbornoz/get_next_line/assets/119970138/ad029c4d-5e6b-4afb-b3a3-a97f4fe6bc97">
</div>

<div align="center">
<img alt="Static Badge" src="https://img.shields.io/badge/Status-Finished-green">
<img alt="Static Badge" src="https://img.shields.io/badge/42-Project-blue">
<img alt="Static Badge" src="https://img.shields.io/badge/Language-C-lightgrey">
</div>

## About

This repository contains an implementation of the `get_next_line` function in C, built as a project for **42 School**. `get_next_line` is an essential tool for file I/O operations, allowing a program to read a file (or any input source) one line at a time until reaching the end of the file. The function dynamically allocates memory for each line, ensuring efficient memory usage.

### Key Features

- **Efficient line-by-line reading** — reads one line at a time from files or input streams, optimizing data processing when handling information incrementally.
- **Dynamic memory allocation** — allocates memory for each line on demand, keeping memory usage efficient even with large text files.
- **Careful memory management** — processes large text files line by line without overloading system memory, ensuring smooth operation.
- **Easy integration** — drops seamlessly into any C project involving file operations, providing a reliable file-reading solution.

Feel free to explore the repository, test the code, and integrate this line-reading function into your own projects. If you run into any issues or have suggestions for improvements, contributions are always welcome! <3

## Table of Contents

- [How to Use](#how-to-use)
  - [Requirements](#requirements)
  - [Instructions](#instructions)

## How to Use

### Requirements

This project requires the `cc` compiler.

### Instructions

1. Clone the repository:

    ```bash
    git clone https://github.com/debsalbornoz/get_next_line.git
    ```

2. Add the repository files to your project folder and include the header in your source code:

    ```c
    #include "get_next_line.h"
    ```

3. Call the `get_next_line` function to read lines from a file. Here's a simple usage example:

    ```c
    #include "get_next_line.h"
    #include <stdio.h>
    #include <fcntl.h>

    int main(void)
    {
        int     fd;
        char    *line;

        // Opens the file for reading (file.txt must exist) and checks for errors
        fd = open("file.txt", O_RDONLY);
        if (fd == -1)
            return (-1);
        // Calls the function once, reads the first line of the file, and prints it
        line = get_next_line(fd);
        printf("%s", line);
        // Frees the memory allocated for the line and closes the file
        free(line);
        close(fd);
        return (0);
    }
    ```

4. Compile and run:

    ```bash
    cc -Wall -Wextra -Werror -o my_program my_program.c get_next_line.c get_next_line_utils.c && ./my_program
    ```

---

<p align="center">Built as part of the 42 curriculum 🖥️</p>
