#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int i = 0, r = 0;
    char *line = malloc(10000);
    int len = 0;

    if (fd < 0 || BUFFER_SIZE <= 0 || !line)
        return (NULL);
    while (1)
    {
        if (i >= r)
        {
            i = 0;
            r = read(fd, buf, BUFFER_SIZE);
            if (r <= 0)
                break;
        }
        line[len++] = buf[i++];
        if (line[len - 1] == '\n')
            break;
    }
    line[len] = '\0';
    if (len == 0)
    {
        free(line);
        return (NULL);
    }
    return (line);
}

