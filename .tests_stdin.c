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
    int fd = open(".poem.txt", O_RDONLY);
    printf(MAGENTA "Test: get_next_line() < poem.txt BUFFER_SIZE=%d\n\n" RESET, BUFFER_SIZE);
    // Test 1: Reading the first line
    char *line1 = get_next_line(fd);
    char *expected1 = "In 42's halls, where coders roam,\n";
    int result1 = (strcmp(line1, expected1) == 0);
    printf("expected: %sresult: %s1st line - %s\n", expected1, line1, result(result1));
    free(line1);

    // Test 2: Reading the second line
    char *line2 = get_next_line(fd);
    char *expected2 = "No grades, just code, a learning dome.\n";
    int result2 = (strcmp(line2, expected2) == 0);
    printf("expected: %sresult: %s2nd line - %s\n", expected2, line2, result(result2));
    free(line2);

    // Test 3: Reading the third line
    char *line3 = get_next_line(fd);
    char *expected3 = "Keys click, minds tick, in binary chrome,\n";
    int result3 = (strcmp(line3, expected3) == 0);
    printf("expected: %sresult: %s3rd line - %s\n", expected3, line3, result(result3));
    free(line3);

    // Test 4: Reading the fourth line
    char *line4 = get_next_line(fd);
    char *expected4 = "At 42 campus, where brilliance finds its home.\n";
    int result4 = (strcmp(line4, expected4) == 0);
    printf("expected: %sresult: %s4th line - %s\n", expected4, line4, result(result4));
    free(line4);

    // Test 5: Reading beyond the end of the file should return NULL
    char *line5 = get_next_line(fd);
    int result5 = line5 == NULL;
    printf("expected: NULL, result: %s - %s\n", line5, result(result5));

    // Test 6: Reading beyond the end of the file should return NULL
    char *line6 = get_next_line(fd);
    int result6 = line6 == NULL;
    printf("expected: NULL, result: %s - %s\n", line6, result(result6));

    close(fd);
}

int main() {
    run_tests();
    return 0;
}
