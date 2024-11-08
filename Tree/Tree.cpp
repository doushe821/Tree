#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Tree.h"
#include "NodeStruct.h"

Node_t* NodeInsert(Node_t* root, void* value, size_t valSize, int NodeDataCompar(void* a, void* b))
{
    Node_t* node = CreateNode(value, valSize);
    if(node == NULL)
    {
        fprintf(stderr, "Failed to create node\n");
        return NULL;
    }
    if(root == NULL)
    {
        return node;
    }
    Node_t* parentNode = NULL;
    int relation = 0;
    while(root != NULL)
    {
        if(NodeDataCompar(value, root->data) > 0)
        {
            parentNode = root;
            relation = 1;
            root = root->right;
        }
        else if(NodeDataCompar(value, root->data) < 0)
        {
            parentNode = root;
            relation = -1;
            root = root->left;
        }
        else
        {
            return root;
        }
    }
    if(relation == 1)
    {
        parentNode->right = node;
    }
    else
    {
        parentNode->left = node;
    }
    return node;
}

//!!!!!!!!!!!!!
//
// User has to set pointer to node to NULL manually after using @function
//
//!!!!!!!!!!!!!

int BurnTree(Node_t* root)
{
    if(root != NULL)
    {
        if(root->left != NULL)
        {
            BurnTree(root->left);
            root->left = NULL;
            MEOW("Destroyed root->left ptr = %p\n", root->left);
        }
        if(root->right != NULL)
        {
            BurnTree(root->right);
            root->right = NULL;
            MEOW("Destroyed root->right ptr = %p\n", root->right);
        }
    }
    fprintf(stderr, "Freeing adress = %p\n", root);
    NodeDtor(root);
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
    fprintf(stderr, "%s freein adress = %p\n", __func__, node);
    free(node);
    return NO_ERRORS;
}

Node_t* CreateNode(void* value, size_t valSize)
{
    Node_t* node = (Node_t*)calloc(1, sizeof(Node_t));

    if(node == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        return NULL;
    }
    node->data = calloc(1, valSize);
    memcpy(node->data, value, valSize);
    node->size = valSize;
    return node;
}



/*int PolishTree(Node_t* root, void DumpFunc(void* a, FILE* fp))
{
    system("mkdir Dump");
    FILE* dump = fopen("Dump/dump.dot", "w+b");
    if(dump == NULL)
    {
        fprintf(stderr, "Can't create file\n");
        return FILE_CREATION_ERROR;
    }
    return NO_ERRORS;
}*/

int PrintTree(Node_t*root, FILE* dest, void(DumpFunc(void* a, FILE* fp)))
{
    if(dest == NULL)
    {
        fprintf(stderr, "Can't write in file pointed by NULL pointer\n");
        return FILE_NULL_PTR;
    }

    fprintf(dest, 
    "digraph g {\n"
    "fontname=\"Helvetica,Arial,sans-serif\""
    "node [fontname=\"Helvetica,Arial,sans-serif\"]\n"
    "graph [\n"
    "rankdir = \"LR\"\n"
    "];\n"
    "node [\n"
    "fontisze = \"16\"\n"
    "shape = \"ellipse\"\n"
    "];\n"                );

    NodePrint(root, DumpFunc, dest, 0, 0);
    return NO_ERRORS;
}
void NodePrint(Node_t* node, void DumpFunc(void* a, FILE* fp), FILE* fp, size_t rank, size_t ncounter)
{
    rank++;
    ncounter++;
    if(node != NULL)
    {
        fprintf(fp, "\"node%zu\" [\n", ncounter);
        fprintf(fp, "\"label\" = \"<f0> DATA = ");
        DumpFunc(node->data, fp);
        fprintf(fp, "|<f1> left = %p|<f2> right = %p\"\n", node->left, node->right);
        fprintf(fp, "shape = \"record\"\n");
        fprintf(fp, "];\n");
        if(node->left != NULL)
        {
            NodePrint(node->left, DumpFunc, fp, rank, ncounter);
        }
        if(node->right != NULL)
        {
            NodePrint(node->right, DumpFunc, fp, rank, ncounter);
        }
    }
    else
    {
        fprintf(stderr, "Tried printing NULL-pointed node\n");
        return;
    }
}