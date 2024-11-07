#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDEED

enum ErrCodes
{
    NO_ERRORS = 0,
    ALLOCATION_FAILURE = 1,
    NODE_NULL_POINTER = 2,
    ROOT_NULL_POINTER = 3,
};
struct Node_t;

#ifndef NDEBUG
#include "DBTools/DBTools.h"
#endif

#endif