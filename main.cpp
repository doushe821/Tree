#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DBTools/DBTools.h
#include "Tree.h"

int IntCompar(void* a, void* b);

int main()
{
    return 0;
}

int IntCompar(void* a, void* b)
{
    int aVal = 0;
    int bVal = 0;
    memcpy(&aVal, a, sizeof(int));
    memcpy(&bVal, b, sizeof(int));
    return aVal - bVal;
}