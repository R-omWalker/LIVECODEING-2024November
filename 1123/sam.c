#include <unistd.h>
int main(int argc, char const *argv[])
{
    write(2,"stderror",7);
    return 0;
}
