#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

void printDir(char* dir, int depth)
{
    DIR* dp = NULL;
    struct dirent* entry = NULL;
    struct stat statBuf;
    if ((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr, "can not open directory: %s\n", dir);
        return;
    }

    chdir(dir);
    while((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name,&statBuf);
        if (S_ISDIR(statBuf.st_mode))
        {
            /* Found a directory, but ignore . and .. */
            if (strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
            {
                continue;
            }
            printf("%*s%s/\n", depth, "", entry->d_name);
            printDir(entry->d_name, depth + 4);
        }
        else
        {
            printf("%*s%s\n", depth, "", entry->d_name);
        }
    }
    chdir("..");
    closedir(dp);
}

int main(int argc, char* argv[])
{
    char* topdir = ".";
    if (argc >= 2)
    {
        topdir = argv[1];
    }

    printf("Directory scan of %s:\n", topdir);
    printDir(topdir, 0);
    printf("done.\n");

    exit(0);
}
