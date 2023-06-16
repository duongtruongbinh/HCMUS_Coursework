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
	if (pRoot->key < x)
		Insert(pRoot->right, x);
}

NODE *createTree(int a[], int n)
{
	NODE *pRoot = createNode(a[0]);
	for (int i = 1; i < n; i++)
		Insert(pRoot, a[i]);
	return pRoot;
}

void LNR(NODE *pRoot)
{
	if (!pRoot)
		return;
	LNR(pRoot->left);
	cout << pRoot->key << " ";
	LNR(pRoot->right);
}

void NLR(NODE *pRoot)
{
	if (!pRoot)
		return;
	cout << pRoot->key << " ";
	NLR(pRoot->left);
	NLR(pRoot->right);
}
void LRN(NODE *pRoot)
{
	if (!pRoot)
		return;
	NLR(pRoot->left);
	NLR(pRoot->right);
	cout << pRoot->key << " ";
}
int Height(NODE *pRoot)
{
	int h = 0;
	if (!pRoot)
		return 0;
	h = 1 + max(Height(pRoot->left), Height(pRoot->right));
	return h;
}
void levelOrder(NODE *pRoot)
{
	if (!pRoot)
		return;
	queue<NODE *> q;
	q.push(pRoot);
	while (!q.empty())
	{
		NODE *temp = q.front();
		cout << temp->key << " ";
		q.pop();
		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
	}
}
int countNode(NODE *pRoot)
{
	if (pRoot == NULL)
		return 0;
	else
		return 1 + countNode(pRoot->left) + countNode(pRoot->right);
}
int sumNode(NODE *pRoot)
{
	if (pRoot == NULL)
		return 0;
	else
		return pRoot->key + sumNode(pRoot->left) + sumNode(pRoot->right);
}

NODE *search(NODE *pRoot, int x)
{
	if (pRoot == NULL)
		return NULL;
	if (x == pRoot->key)
		return pRoot;
	else if (x < pRoot->key)
		return search(pRoot->left, x);
	else
		return search(pRoot->right, x);
}

void remove(NODE *&pRoot, int x)
{
	if (pRoot == NULL)
		return;
	if (pRoot->key > x)
		remove(pRoot->left, x);
	else
		remove(pRoot->right, x);

	if (pRoot->key == x)
	{
		if (pRoot->left == NULL && pRoot->right == NULL)
		{
			delete pRoot;
			pRoot = NULL;
		}
		else if (pRoot->left == NULL && pRoot->right != NULL)
		{
			NODE *p = pRoot;
			pRoot = pRoot->right;
			delete p;
		}
		else if (pRoot->left != NULL && pRoot->right == NULL)
		{
			NODE *p = pRoot;
			pRoot = pRoot->left;
			delete p;
		}
		else if (pRoot->left != NULL && pRoot->right != NULL)
		{
			NODE *p = pRoot->left;
			while (p->right != NULL)
				p = p->right;
			pRoot->key = p->key;
			remove(pRoot->left, p->key);
		}
	}
}

void removeTree(NODE *&pRoot)
{
	if (pRoot != NULL)
	{
		removeTree(pRoot->left);
		removeTree(pRoot->right);
		delete pRoot;
		pRoot = NULL;
	}
}

int HeightNode(NODE *pRoot, int value)
{
	NODE *p = search(pRoot, value);
	if (p == NULL)
		return -1;
	return Height(p);
}

int Level(NODE *pRoot, NODE *p)
{
	int count = 1;
	NODE *currNode = pRoot;
	int val = p->key;

	while (currNode != p && currNode)
	{
		if (val > currNode->key)
			currNode = currNode->right;
		else
			currNode = currNode->left;
		++count;
	}

	if (!currNode)
		return -1;
	return count;
}

int main()
{
	int a[] = {4, 7, 8, 2, 6};
	NODE *pRoot = createTree(a, 5);
	// LNR(pRoot);
	// NLR(pRoot);
	// cout << endl;
	// levelOrder(pRoot);
	// LRN(pRoot);
	// cout << endl;
	// cout << Height(pRoot) << endl;
	// cout << countNode(pRoot) << endl;
	// cout << sumNode(pRoot) << endl;
	// NODE* temp = search(pRoot, 2);
	// cout << temp->key;
	// remove(pRoot, 2);
	// LNR(pRoot);
	// removeTree(pRoot);
	// if (pRoot == NULL)
	// cout << "Removed";
	system("pause");
}