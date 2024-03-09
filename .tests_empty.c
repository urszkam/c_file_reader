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
    int fd = open(".empty.txt", O_RDONLY);
    printf(MAGENTA "Test: get_next_line(\".empty.txt\") BUFFER_SIZE=%d\n\n" RESET, BUFFER_SIZE);
    // Tests : Reading beyond the end of the file should return NULL
    char *line1 = get_next_line(fd);
    char *expected1 = "\n";
    int result1 = strcmp(line1, expected1) == 0;
    printf("expected: %sresult: %s1st line - %s\n", expected1, line1, result(result1));
    free(line1);
    
    char *line2 = get_next_line(fd);
    int result2 = line2 == NULL;
    printf("Reading empty txt expected: NULL, result: %s - %s\n", line2, result(result2));
    
    char *line3 = get_next_line(fd);
    int result3 = line3 == NULL;
    printf("Reading empty txt expected: NULL, result: %s - %s\n", line3, result(result3));
    close(fd);
}

int main() {
    run_tests();
    return 0;
}
