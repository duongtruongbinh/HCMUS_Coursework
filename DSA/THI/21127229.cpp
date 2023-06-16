#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Node
{
    int x, y;
    Node *left;
    Node *right;
};

Node *createNode(int x, int y)
{
    Node *a = new Node;
    a->x = x;
    a->y = y;
    a->left = a->right = NULL;
    return a;
}

bool compare(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return 0;
    if ((x1 + y1 < x2 + y2) || ((x1 + y1 == x2 + y2) && x1 < x2))
        return -1;

    else
        return 1;
}

void RR(Node *&pRoot)
{
    if (pRoot == NULL)
        return;
    Node *temp = pRoot->left;
    pRoot->left = temp->right;
    temp->right = pRoot;
    pRoot = temp;
}

void LR(Node *&pRoot)
{
    if (pRoot == NULL)
        return;
    Node *temp = pRoot->right;
    pRoot->right = temp->left;
    temp->left = pRoot;
    pRoot = temp;
}

int Height(Node *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return 1 + max(Height(pRoot->left), Height(pRoot->right));
}

void balance(Node *&pRoot)
{
    if (pRoot == NULL)
        return;
    int bal = Height(pRoot->left) - Height(pRoot->right);
    if (bal > 1)
    {
        if (Height(pRoot->left->left) >= Height(pRoot->left->right))
            RR(pRoot);
        else
        {
            LR(pRoot->left);
            RR(pRoot);
        }
    }
    if (bal < -1)
    {
        if (Height(pRoot->right->right) >= Height(pRoot->right->left))
            LR(pRoot);
        else
        {
            RR(pRoot->right);
            LR(pRoot);
        }
    }
}

void Insert(Node *&pRoot, int x, int y)
{
    if (pRoot == NULL)
        pRoot = createNode(x, y);
    else if (compare(pRoot->x, pRoot->y, x, y) == 0)
        return;
    else if (compare(pRoot->x, pRoot->y, x, y) == 1)
        Insert(pRoot->left, x, y);
    else if (compare(pRoot->x, pRoot->y, x, y) == -1)
        Insert(pRoot->right, x, y);

    balance(pRoot);
}

void levelOrder(Node *pRoot)
{
    if (pRoot == NULL)
        return;
    queue<Node *> a;
    a.push(pRoot);

    while (!a.empty())
    {
        Node *temp = a.front();

        a.pop();
        if (temp->left)
            a.push(temp->left);
        if (temp->right)
            a.push(temp->right);
        cout << "(" << temp->x << "," << temp->y << ")" << endl;
    }
}

void remove(Node *&pRoot, int x, int y)
{
    if (pRoot == NULL)
        return;
    if (compare(pRoot->x, pRoot->y, x, y) == 1)
        remove(pRoot->left, x, y);
    if (compare(pRoot->x, pRoot->y, x, y) == -1)
        remove(pRoot->right, x, y);
    if (compare(pRoot->x, pRoot->y, x, y) == 0)
    {
        if (pRoot->left == NULL && pRoot->right == NULL)
        {
            delete pRoot;
            pRoot = NULL;
        }
        else if (pRoot->left && pRoot->right == NULL)
        {
            Node *temp = pRoot;
            pRoot = pRoot->left;
            delete temp;
        }
        else if (pRoot->right && pRoot->left == NULL)
        {
            Node *temp = pRoot;
            pRoot = pRoot->right;
            delete temp;
        }
        else if (pRoot->right && pRoot->left)
        {
            Node *temp = pRoot->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            pRoot->x = temp->x;
            pRoot->y = temp->y;
            remove(pRoot->right, pRoot->x, pRoot->y);
        }
    }
    if (pRoot == NULL)
        return;
    balance(pRoot);
}

Node *createTree()
{
    fstream file("inputAVL.txt");

    Node *pRoot = NULL;
    while (!file.eof())
    {
        int tx, ty;
        file >> tx >> ty;
        Insert(pRoot, tx, ty);
    }
    file.close();
    return pRoot;
}

int main()
{

    Node *root = createTree();

    levelOrder(root);
    return 0;
}
