#include <iostream>
#include <queue>
using namespace std;

struct NODE
{
    int key;
    NODE *left;
    NODE *right;
};

NODE *createNode(int data)
{
    NODE *a = new NODE;
    a->key = data;
    a->left = a->right = NULL;
    return a;
}

void Insert(NODE *&pRoot, int x)
{
    if (pRoot == NULL)
        pRoot = createNode(x);
    if (pRoot->key == x)
        return;
    if (pRoot->key > x)
        Insert(pRoot->left, x);
    else
        Insert(pRoot->right, x);
}

void NLR(NODE *pRoot)
{
    if (pRoot == NULL)
        return;
    cout << pRoot->key << " ";
    NLR(pRoot->left);
    NLR(pRoot->right);
}

void LNR(NODE *pRoot)
{
    if (pRoot == NULL)
        return;
    LNR(pRoot->left);
    cout << pRoot->key << " ";
    LNR(pRoot->right);
}

void LRN(NODE *pRoot)
{
    if (pRoot == NULL)
        return;
    LRN(pRoot->right);
    LRN(pRoot->left);
    cout << pRoot->key << " ";
}

void LevelOrder(NODE *pRoot)
{
    if (!pRoot)
        return;
    queue<NODE *> a;
    a.push(pRoot);
    while (!a.empty())
    {
        NODE *temp = a.front();
        cout << temp->key << " ";
        a.pop();
        if (temp->left)
            a.push(temp->left);
        if (temp->right)
            a.push(temp->right);
    }
}

int Height(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return 1 + max(Height(pRoot->left), Height(pRoot->right));
}

int countNode(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return 1 + countNode(pRoot->left) + countNode(pRoot->right);
}

int sumNode(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    return pRoot->key + sumNode(pRoot->left) + sumNode(pRoot->right);
}

NODE *Search(NODE *pRoot, int x)
{
    if (pRoot == NULL)
        return NULL;
    if (pRoot->key == x)
        return pRoot;
    if (pRoot->key > x)
        return Search(pRoot->left, x);
    else
        return Search(pRoot->right, x);
}

void Remove(NODE *&pRoot, int x)
{
    if (pRoot == NULL)
        return;
    if (pRoot->key < x)
        return Remove(pRoot->right, x);
    if (pRoot->key > x)
        return Remove(pRoot->left, x);

    if (!pRoot->left && !pRoot->right)
    {
        delete pRoot;
        pRoot = NULL;
    }
    else if (!pRoot->left)
    {
        NODE *temp = pRoot;
        pRoot = pRoot->right;
        delete temp;
    }
    else if (!pRoot->right)
    {
        NODE *temp = pRoot;
        pRoot = pRoot->left;
        delete temp;
    }
    else
    {
        NODE *temp = pRoot->right;
        while (temp->left)
            temp = temp->left;

        pRoot->key = temp->key;
        Remove(pRoot->right, temp->key);
    }
}

NODE *createTree(int a[], int n)
{
    NODE *pRoot = createNode(a[0]);
    for (int i = 1; i < n; i++)
    {
        Insert(pRoot, a[i]);
    }
    return pRoot;
}

void removeTree(NODE *&pRoot)
{
    NODE *temp = pRoot;
    removeTree(pRoot->left);
    removeTree(pRoot->right);
    delete temp;
}

int heightNode(NODE *pRoot, int value)
{
    NODE *temp = Search(pRoot, value);
    if (!temp)
        return -1;
    return Height(temp);
}

int Level(NODE *pRoot, NODE *p)
{
    NODE *temp = pRoot;
    int count = 1;
    while (temp && temp != p)
    {
        if (temp->key < p->key)
            temp = temp->right;
        else
            temp = temp->left;
        count++;
    }
    if (!temp)
        return -1;
    return count;
}

int countLeaf(NODE *pRoot)
{
    if (pRoot == NULL)
        return 0;
    if (!pRoot->left && !pRoot->right)
        return 1;
    return countLeaf(pRoot->right) + countLeaf(pRoot->left);
}

int countLess(NODE *pRoot, int x)
{
    if (!pRoot)
        return 0;
    if (pRoot->key >= x)
        return countLess(pRoot->left, x);
    return 1 + countLess(pRoot->right, x) + countLess(pRoot->left, x);
}

int countGreater(NODE *pRoot, int x)
{
    if (!pRoot)
        return 0;
    if (pRoot->key <= x)
        return countGreater(pRoot->right, x);
    return 1 + countGreater(pRoot->left, x) + countGreater(pRoot->right, x);
}

bool isBST(NODE *pRoot)
{
    if (!pRoot)
        return 1;
    if (pRoot->left)
        if (pRoot->left->key > pRoot->key)
            return 0;

    if (pRoot->right)
        if (pRoot->right->key < pRoot->key)
            return 0;
    return isBST(pRoot->left) && isBST(pRoot->right);
}

bool isFullBST(NODE *pRoot)
{
    if (!pRoot)
        return 1;
    if (!isBST(pRoot))
        return 0;
    if ((pRoot->left && !pRoot->right) || (pRoot->right && !pRoot->left))
        return 0;
    return isFullBST(pRoot->left) && isFullBST(pRoot->right);
}

int main()
{
    int a[] = {5, 9, 2, 1, 7, 6, 4};
    NODE *pRoot = createTree(a, 7);

    LevelOrder(pRoot);
    removeTree(pRoot);
}