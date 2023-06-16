#include "stdio.h"
#include "stdlib.h"
#include "algorithm"
#include "iostream"

struct NODE
{
    int key;
    NODE *left;
    NODE *right;
    int height;
};

// Initialize a NODE from a given value
NODE* createNode(int data)
{
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int height(NODE *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

void RightRotate(NODE *&pRoot)
{
    NODE *p = pRoot->left; 
    pRoot->left = p->right;
    p->right = pRoot;
    pRoot->height = std::max(height(pRoot->left), height(pRoot->right)) + 1;
    p->height = std::max(height(p->left), pRoot->height) + 1;
    pRoot = p;
    return;
}

void LeftRotate(NODE *&pRoot)
{
    NODE *p = pRoot->right;
    pRoot->right = p->left;
    p->left = pRoot;
    pRoot->height = std::max(height(pRoot->left), height(pRoot->right)) + 1;
    p->height = std::max(height(p->right), pRoot->height) + 1;
    pRoot = p;
    return;
}

void Balance(NODE *&pRoot)
{ 
    if (pRoot == NULL)
        return;
    int balance = height(pRoot->left) - height(pRoot->right);
    if (balance > 1)
    {
        if (height(pRoot->left->left) > height(pRoot->left->right))
            RightRotate(pRoot);
        else
        {
            LeftRotate(pRoot->left);
            RightRotate(pRoot);
        }
    }
    else if (balance < -1)
    {
        if (height(pRoot->right->right) > height(pRoot->right->left))
            LeftRotate(pRoot);
        else
        {
            RightRotate(pRoot->right);
            LeftRotate(pRoot);
        }
    }
    pRoot->height = std::max(height(pRoot->left), height(pRoot->right)) + 1;
    return;
}

// Add a NODE with given value into a given AVL tree (Notify if the given value existed)
void Insert(NODE* &pRoot, int x)
{
    if (pRoot == NULL)
    {
        pRoot = createNode(x);
        return;
    }

    if (x < pRoot->key)
        Insert(pRoot->left, x);
    else if (x > pRoot->key)
        Insert(pRoot->right, x);
    else
        return;

    Balance(pRoot);
}

void Remove(NODE* &pRoot, int x)
{
    if (pRoot == NULL)
        return;

    if (x < pRoot->key)
        Remove(pRoot->left, x);
    else if (x > pRoot->key)
        Remove(pRoot->right, x);
    else
    {
        if (pRoot->left == NULL && pRoot->right == NULL)
        {
            free(pRoot);
            pRoot = NULL;
            return;
        }
        else if (pRoot->left == NULL)
        {
            NODE *p = pRoot;
            pRoot = pRoot->right;
            free(p);
            return;
        }
        else if (pRoot->right == NULL)
        {
            NODE *p = pRoot;
            pRoot = pRoot->left;
            free(p);
            return;
        }
        else
        {
            NODE *p = pRoot->right;
            while (p->left != NULL)
                p = p->left;
            pRoot->key = p->key;
            Remove(pRoot->right, p->key);
        }
    }

    Balance(pRoot);
}