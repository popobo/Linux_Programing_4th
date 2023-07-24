#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
    int c;
    FILE* in;
    FILE* out;

    in = fopen("file.in", "r");
    out = fopen("file.out", "w");
    
    while(( c = fgetc(in)) != EOF)
    {
        fputc(c, out);
    }

    exit(0);
*/

    char buf[1024];
    FILE* in;
    FILE* out;
    
    in = fopen("file.in", "r");
    out = fopen("file.out", "w");

    while(fread(buf, sizeof(char), sizeof(buf), in) > 0)
    {
        fwrite(buf, sizeof(char), sizeof(buf), out);
    }

    exit(0);
}