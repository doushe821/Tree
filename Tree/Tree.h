#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDEED

enum ErrCodes
{
    NO_ERRORS = 0,
    ALLOCATION_FAILURE = 1,
    NODE_NULL_POINTER = 2,
    ROOT_NULL_POINTER = 3,
    NODE_EXISTS = 4,
    NODE_CREATION_FAILURE = 5,
    FILE_CREATION_ERROR = 6,
    FILE_NULL_PTR = 7,
};
struct Node_t;

#ifndef NDEBUG
#include "../DBTools/DBTools.h"
#endif


Node_t* NodeInsert(Node_t* root, void* value, size_t valSize, int NodeDataCompar(void* a, void* b));
int DeleteNode(Node_t* node);
int NodeDtor(Node_t* node);
Node_t* CreateNode(void* value, size_t valSize);
int BurnTree(Node_t* root);
int PolishTree(Node_t* root, void DumpFunc(void* a, FILE* fp));
void NodePrint(Node_t* node, void DumpFunc(void* a, FILE* fp), FILE* fp, size_t rank, size_t ncounter);
int PrintTree(Node_t*root, FILE* dest, void(DumpFunc(void* a, FILE* fp)));

#endif