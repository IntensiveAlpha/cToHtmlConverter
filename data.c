#include "data.h"

void printData (const int* pInt)
{
    char dt[100];
    sprintf(dt, "%d", *pInt);
    fprintf(stdout, "%s", dt);
    putc('\n', stdout);
}