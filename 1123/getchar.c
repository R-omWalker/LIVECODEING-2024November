/* getchar: 単一バッファ版　*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>
// int getchar(void)
// {
//   static char buf[BUFSIZ];
//   static char *bufp;
//   static int n = 0;

//   if(n == 0) { /* バッファはカラ */
//     n = read(0, buf, sizeof buf);
//     bufp = buf;
//   }
//   return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
// }

int _getchar(int fd)
{
  static char buf[BUFSIZ];
  static char *bufp;
  static int n = 0;

  if(n==0)
  {
    n = read(fd,buf,BUFSIZ);
    bufp = buf;
  }
  --n;
  if(n < 0)
    return EOF; 
  return (int)*bufp++;
}


char *get_next_line(int fd)
{
  char *line;

  line = malloc(BUFSIZ);
  if(!line)
    return NULL;


  int c = _getchar(fd);
  while(c>0)
  {
      c = _getchar(fd);


      if (c=='\n')
        return line;
  }
  return line;
}



int main(int argc, char const *argv[])
{
    static int ct = 0;
    int fd = open(argv[1],O_RDONLY);
    int c = _getchar(fd);
    while(c>0)
    {
        printf("ct %d %c\n",++ct,c);
        c = _getchar(fd);

    }
    close(fd);
    return 0;

}



