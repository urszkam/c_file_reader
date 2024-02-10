# Project Description

This project entails the implementation of the get_next_line function, which reads a line from a file descriptor. The function is designed to be versatile, allowing users to read a text file or input from the standard input one line at a time through repeated calls.

# Prerequisites

Before using the get_next_line function, make sure you have the necessary prerequisites in place:
- C compiler (e.g., GCC)
- Standard C library

# Library

This project relies on the following standard C libraries:

- unistd.h: For the read function
- stdlib.h: For memory allocation and deallocation using malloc and free

# Usage Example

Here's a simple example of how to use the get_next_line function:

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        // Process the line as needed
        // ...
        free(line);
    }

    close(fd);
    return 0;
}
```

