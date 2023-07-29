#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("wrong use\n");
        exit(-1);
    }

    char* filename = argv[1];
    struct stat statBuf;

    stat(filename, &statBuf);
    mode_t modes = statBuf.st_mode;

    if (!S_ISDIR(modes) && (modes & S_IRWXU) != 0)
    {
        printf("%s is file and excutable\n", filename);
    }
    else
    {
        printf("%s is not file or excutable\n", filename);
    }

    exit(0);
}
