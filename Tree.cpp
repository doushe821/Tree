#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Tree.h"
#include "NodeStruct.h"


int CreateNode(Node_t* node, void* value, size_t valSize)
{
    node = (Node_t*)calloc(1, sizeof(Node_t));

    if(node == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        return ALLOCATION_FAILURE;
    }
    
    node->data = calloc(1, valSize);
    memcpy(node->data, value, valSize);
    node->size = valSize;
    return NO_ERRORS;
}

int AddNode(Node_t* root, Node_t** node, void* value, int(NodeDataCompar)(void* a, void* b))
{
    if(root == NULL)
    {
        fprintf(stderr, "Root node is pointed by NULL pointer\n");
        return ROOT_NULL_POINTER;
    }
    
    while(node != NULL)
    {
        root = NodeDataCompar(value, root->data) ? root = root->right: root->left;
    }
    return NO_ERRORS;
}


int DeleteNode(Node_t* node)
{
    while(node != NULL)
    {
        DeleteNode(node->right);
        DeleteNode(node->left);
    }
    NodeDtor(node);
    return NO_ERRORS;
}

int NodeDtor(Node_t* node)
{
    if(node == NULL)
    {
        fprintf(stderr, "Tried to destruct uninitialised or already destructed node\n");
        return NODE_NULL_POINTER;
    }
    if(node->data != NULL)
    {
        free(node->data);
    }
    if(node->left != NULL)
    {
        free(node->left);
    }
    if(node->right != NULL)
    {
        free(node->right);
    }
    free(node);
    return NO_ERRORS;
}

int BurnTree(Node_t** nodesArray)
{
    // TODO
    return NO_ERRORS;
}

int TreeGraph(Node_t* node)
{
    return NO_ERRORS;
}