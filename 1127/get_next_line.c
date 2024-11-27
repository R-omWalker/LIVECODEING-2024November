#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



#define __LOG__ printf("%s  %dline\n",__func__,__LINE__)


/*
*return -1 if EOF else single char
*if read error return errornumber
*/
int readchar(int fd)
{
    const char *buf = "sample buffer\nsecondline";
    static int index = 0;
    static int buf_size;
    buf_size = strlen(buf);


    if (index >= buf_size)
    {
        //read
        printf("end of buffer\n");
        return -2;
    }
    return buf[index++];
}


char *get_next_line(int fd)
{
    __LOG__;
    char *line;
    int index = 0;

    line = malloc(2);
    if(line == NULL)
        return NULL;
    while(1)
    {
        int c = readchar(fd);
        //read error
        if (c == -2)
        {
            free(line);
            return NULL;
        }
        //EOFは詰めないでbreak
        if (c == EOF)
            break;
        line[index++] = c;
        //改行を詰めてからbreak
        if (c == '\n')
            break;
    }
    line[index] = '\0';
    return line;
}



int main(int argc, char const *argv[])
{
    //まずはファイルをopen
    
    int fd = (argc == 1)? 0 : open(argv[1],O_RDONLY);
    if (fd == -1)
        return 1;

    char *line;
    while(1)
    {
        line = get_next_line(fd);
        printf("line: %s \n",line);
        if (line == NULL)
            break;
        // free(line);
    }
    
    __LOG__;
    close(fd);
    return 0;
}
