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
    int fd = open("text_files/endlonly.txt", O_RDONLY);
    if (fd < 0) {
        perror("text_files/endlonly.txt");
        return 1;
    }
    printf(MAGENTA "Test: get_next_line(\"text_files/endlonly.txt\") BUFFER_SIZE=%d\n\n" RESET, BUFFER_SIZE);
    // A nonpositive buffer returns NULL immediately; otherwise read the newline.
    char *line1 = get_next_line(fd);
    char *expected1 = BUFFER_SIZE <= 0 ? NULL : "\n";
    int result1 = expected1 ? (line1 && strcmp(line1, expected1) == 0) : line1 == NULL;
    printf("First call, expected: [%s], result: [%s] - %s\n", expected1 ? expected1 : "NULL", line1 ? line1 : "NULL", result(result1));
    free(line1);
    
    char *line2 = get_next_line(fd);
    int result2 = line2 == NULL;
    printf("Second call, expected: NULL, result: %s - %s\n", line2 ? line2 : "NULL", result(result2));
    free(line2);
    
    char *line3 = get_next_line(fd);
    int result3 = line3 == NULL;
    printf("Third call, expected: NULL, result: %s - %s\n", line3 ? line3 : "NULL", result(result3));
    free(line3);
    close(fd);
    return !(result1 && result2 && result3);
}

int main(void) {
    return run_tests();
}
