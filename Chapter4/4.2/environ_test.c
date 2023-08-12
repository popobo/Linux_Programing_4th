#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char* var;
    char* value;

    if (argc != 2 && argc != 3)
    {
        fprintf(stderr, "usage: environ_test var [value]\n");
        exit(1);
    }

    var = argv[1];
    value = getenv(var);
    if (value)
        printf("Variable %s has value %s\n", var, value);
    else
        printf("Variable %s has not value\n", var);

    if (argc == 3)
    {
        value = argv[2];
        char* string = (char*)malloc(strlen(var) + strlen(value) + 2);
        if (!string)
        {
            fprintf(stderr, "out of memory\n");
            exit(1);
        }

        strcpy(string, var);
        strcat(string, "=");
        strcat(string, value);
        printf("Calling putenv with %s\n", string);
        if (putenv(string) != 0)
        {
            fprintf(stderr, "putenv failed\n");
            free(string);
            exit(1);
        }
        value = getenv(var);
        if (value)
            printf("New value of %s is %s\n", var, value);
        else
            printf("New value of %s is NULL??\n", var);
    }
    exit(0);
}