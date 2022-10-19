#include <stdio.h>
#include "data.h"

int data = 999;

int main (int argc, char* argv[])
{
    if (argc > 1)
        for (int i = 1; i < argc; i++)
            printf("%s\n", argv[i]);
            
    fprintf(stdout, "Hello world!");
    fprintf(stdout, " This day is vibrant!");
    putc('\n', stdout);
    printData(&data);
    return 0;
}
