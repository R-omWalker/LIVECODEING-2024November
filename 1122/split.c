#include <stdlib.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>


#include <stdio.h>
#include <string.h>
#define __LOG__  printf("%s %d\n",__func__,__LINE__)

int count_word(char *str, char sep)
{
    int ret = 0;
   
    while(*str)
    {
        while(*str==sep)
            str++;
        if (*str)
            ret++;
        while(*str && *str!=sep)
            str++;
    }
    return ret;
}

int wordlen(char *str,char sep)
{
    int i = 0;
    while(str[i] && str[i]!=sep)
        i++;

    return i;
}

char *ft_strndup(char *str, int size)
{
    char *ret;
    ret = malloc(size+1);
    if (!ret)
        return NULL;
    ret[size] = 0;
    while(size--)
        ret[size] = str[size];
    return ret;
}



char **allfree(char **words)
{
    if (!words)
        return NULL;
    while(*words)
    {
        free(*words);
        *words = NULL;
        words++;
    }
    free(words);
    return NULL;
}

char **split(char *str, char sep)
{
    char **ret;
    int word_cnt = count_word(str,sep);
    ret = malloc(sizeof(char *) * (word_cnt + 1));

    int i = 0;
    while(i<word_cnt)
    {
        while(*str==sep)
            str++;
        ret[i] = ft_strndup(str,wordlen(str,sep));
        if (ret[i] == NULL)
            return allfree(ret);

        str += wordlen(str,sep);
        i++;
    }
    ret[i] = 0;
    return ret;
}







int main()
{
    char *str = "  Hello Nice to meet you!!!   ";
    char **words = split(str,' ');

    char **ptr = words;
    while(*ptr)
    {
        printf("%s\n",*ptr);
        free(*ptr);
        ptr++;
    }
    free(words);


    return 0;
}