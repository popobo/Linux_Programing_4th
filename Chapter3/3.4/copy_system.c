/* 必须先include unistd.h，因为它定义了与POSIX规范有关的标志 可能影响到其他头文件 */
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    /*
    char c;
    int in, out;
    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while (read(in, &c, 1) == 1)
    {
        write(out, &c, 1);
    }

    exit(0);
    */

    char block[1024];
    int in, out;
    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while (read(in, block, sizeof(block)) > 0)
    {
        write(out, block, sizeof(block));
    }

    exit(0);
}