/*
Repeated calls to get_next_line should enable sequential reading 
of the text file pointed to by the file descriptor, 
processing one line at a time. The function returns the read line
or NULL if there is nothing else to read or if an error occurs.

Ensure that the function works seamlessly for both file reading and standard input.
*/

char	*get_next_line(int fd)
{
    if (fd == -1)
        return (0);
    close(fd);
}
