#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char readchar()
{
    static int index = 0;
    const char *text = "Welcome to my Channel!!\n";
    return text[index++];
}



int main(int argc, char const *argv[])
{
    char *line = NULL;
    int line_size = 1;
    int index = 0;
    line = realloc(line , line_size*2);
    char c;
    c = readchar();

    while(c)
    {
        if (index>=line_size)
        {
           line_size*=2;
           line = realloc(line , line_size);
           printf("currents size: %d\n", line_size);
        }
        strncat(line,&c,1);
        c = readchar();
        index++;
    }
    int count = 0;
    printf("ct: %d %s\n",++count,line);
    return 0;
}
