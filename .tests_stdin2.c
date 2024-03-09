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
    int fd = 0;
    printf(MAGENTA "Test: get_next_line(\".empty.txt\") BUFFER_SIZE=%d\n\n" RESET, BUFFER_SIZE);
    // Tests : Reading beyond the end of the file should return NULL
    char *line1 = get_next_line(fd);
    printf("%s", line1);
    if (line1)
    	free(line1);
    
    char *line2 = get_next_line(fd);
    printf("%s", line2);
    if (line2)
    	free(line2);
    
    char *line3 = get_next_line(fd);
    printf("%s", line3);
    if (line3)
    	free(line3);
    
    char *line4 = get_next_line(fd);
    printf("%s", line4);
    if (line4)
    	free(line4);
}

int main() {
    run_tests();
    return 0;
}
