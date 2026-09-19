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

int run_tests(void) {
    int fd = STDIN_FILENO;
    printf(MAGENTA "Test: get_next_line() < text_files/stdin_long.txt BUFFER_SIZE=%d\n\n" RESET, BUFFER_SIZE);

    char *line1 = get_next_line(fd);
    int len1 = line1 ? (int)strlen(line1) : -1;
    int first1 = line1 && line1[0] == 'A';
    int last1 = line1 && len1 > 0 && line1[len1 - 1] == '\n';
    int result1 = (line1 != NULL && len1 == 2101 && first1 && last1);
    printf("long line: len=%d first=%c last=%c -> %s\n", len1, line1 ? line1[0] : '?', len1 > 0 ? line1[len1 - 1] : '?', result(result1));
    if (line1)
        free(line1);

    char *line2 = get_next_line(fd);
    int result2 = (line2 != NULL && strcmp(line2, "\n") == 0);
    printf("empty line: %s -> %s\n", line2 ? line2 : "NULL", result(result2));
    if (line2)
        free(line2);

    char *line3 = get_next_line(fd);
    int result3 = line3 == NULL;
    printf("expected: NULL, result: %s - %s\n", line3 ? line3 : "NULL", result(result3));
    if (line3)
        free(line3);

    return !(result1 && result2 && result3);
}

int main(void) {
    return run_tests();
}
