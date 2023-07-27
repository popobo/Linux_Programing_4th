#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct {
    int integer;
    char string[24];
} RECORD;

#define NRECORD (100)
#define RECORD_FILE ("records.dat")

int main()
{
    RECORD record, *mapped;
    int i = 0;
    int f = 0;
    FILE* fp = NULL;

    fp = fopen(RECORD_FILE, "w+");
    for (i = 0; i < NRECORD; i++)
    {
        record.integer = i;
        sprintf(record.string, "RECORD-%d", i);
        fwrite(&record, sizeof(record), 1, fp);
    }
    fclose(fp);

    fp = fopen(RECORD_FILE, "r+");
    fseek(fp, 43 * sizeof(record), SEEK_SET);
    fread(&record, sizeof(record), 1, fp);

    record.integer = 143;
    sprintf(record.string, "RECORD-%d", record.integer);
    
    fseek(fp, 43 * sizeof(record), SEEK_SET);
    fwrite(&record, sizeof(record), 1, fp);
    fclose(fp);

    f = open(RECORD_FILE, O_RDWR);
    mapped = (RECORD *)mmap(0, NRECORD * sizeof(record), PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
    mapped[43].integer = 243;
    sprintf(mapped[43].string, "RECORD-%d", mapped[43].integer);
    
    msync((void *)mapped, NRECORD * sizeof(record), MS_ASYNC);
    munmap((void *)mapped, NRECORD * sizeof(record));
    close(f);

    exit(0);
}
