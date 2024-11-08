#ifndef NODE_STRUCT_H_INCLUDED
#define NODE_STRUCT_H_INCLUDED

struct Node_t
{
    void* data;
    Node_t* left;
    Node_t* right;
    size_t size;
};


#endif