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
    int fd = open(".joke.txt", O_RDONLY);
    printf(MAGENTA "Test: get_next_line(\".joke.txt\") BUFFER_SIZE=%d\n\n" RESET, BUFFER_SIZE);
    // Test 1: Reading the first line
    char *line1 = get_next_line(fd);
    char *expected1 = "Why did the 42 campus student become a gardener?\n";
    int result1 = (strcmp(line1, expected1) == 0);
    printf("expected: %sresult: %s1st line - %s\n", expected1, line1, result(result1));
    free(line1);

    // Test 2: Reading the second line
    char *line2 = get_next_line(fd);
    char *expected2 = "\n";
    int result2 = (strcmp(line2, expected2) == 0);
    printf("expected: %sresult: %s2nd line - %s\n", expected2, line2, result(result2));
    free(line2);

    // Test 3: Reading the third line
    char *line3 = get_next_line(fd);
    char *expected3 = "Because they heard it's a great way to understand recursion – \n";
    int result3 = (strcmp(line3, expected3) == 0);
    printf("expected: %sresult: %s3rd line - %s\n", expected3, line3, result(result3));
    free(line3);

    // Test 4: Reading the fourth line
    char *line4 = get_next_line(fd);
    char *expected4 = "planting a seed, waiting for it to grow, \n";
    int result4 = (strcmp(line4, expected4) == 0);
    printf("expected: %sresult: %s4th line - %s\n", expected4, line4, result(result4));
    free(line4);

    // Test 5: Reading the fourth line
    char *line5 = get_next_line(fd);
    char *expected5 = "and then planting the seeds of the next generation!\n";
    int result5 = (strcmp(line5, expected5) == 0);
    printf("expected: %sresult: %s5th line - %s\n", expected5, line5, result(result5));
    free(line5);

    // Test 6: Reading beyond the end of the file should return NULL
    char *line6 = get_next_line(fd);
    int result6 = line6 == NULL;
    printf("expected: NULL, result: %s - %s\n\n", line6, result(result6));

    close(fd);
}

int main() {
    run_tests();
    return 0;
}
