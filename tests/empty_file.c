#define MAGENTA "\x1b[35m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char *result(int pass)
{
  if (pass)
    return (GREEN "PASS" RESET);
  return (RED "FAIL" RESET);
}

void run_tests() {
    int fd = open("text_files/empty.txt", O_RDONLY);
    printf(MAGENTA "Test: get_next_line(\"text_files/empty.txt\") BUFFER_SIZE=%d\n\n" RESET, BUFFER_SIZE);

    char *line = get_next_line(fd);
    int pass = line == NULL;
    printf("Reading empty file, expected: NULL, result: %s - %s\n", line ? line : "NULL", result(pass));
    if (line)
        free(line);
    close(fd);
}

int main() {
    run_tests();
    return 0;
}
