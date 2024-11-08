#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DBTools/DBTools.h"
#include "Tree/Tree.h"

int IntCompar(void* a, void* b);
void DumpFuncInt(void* a, FILE* fp);

int main()
{
    int val0 = 10;
    Node_t* node0 = NodeInsert(NULL, &val0, 4, IntCompar);
    int val1 = 15;
    Node_t* node1 = NodeInsert(node0, &val1, 4, IntCompar);
    int val2 = 7;
    Node_t* node2 = NodeInsert(node0, &val2, 4, IntCompar);
    MEOW("Adresses: 0 = %p, 1 = %p, 2 = %p\n", node0, node1, node2);
    FILE* fp = fopen("Dumps/dumpTreeTest1.dot", "w+b");
    PrintTree(node0, fp, DumpFuncInt);
    BurnTree(node0);
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

void DumpFuncInt(void* a, FILE* fp)
{
    int b = 0;
    memcpy(&b, a, sizeof(int));
    fprintf(fp, "%d", b);
}