#include <iostream>
using namespace std;
struct NODE
{
    int key;
    NODE *p_next;
};
struct List
{
    NODE *p_head;
    NODE *p_tail;
};
NODE *createNode(int data)
{
    NODE *a = new NODE;
    a->key = data;
    a->p_next = nullptr;
    return a;
}
void addHead(NODE *&pHead, int data)
{
    if (pHead)
    {
        NODE *a = createNode(data);
        a->p_next = pHead;
        pHead = a;
    }
    else
    {
        NODE *a = createNode(data);
        pHead = a;
    }
}
void addTail(NODE *&pHead, int data)
{
    if (!pHead)
        return;

    NODE *temp = pHead;
    while (temp->p_next)
    {
        temp = temp->p_next;
    }
    temp->p_next = createNode(data);
}
void removeHead(NODE *&pHead)
{
    if (!pHead)
        return;

    NODE *temp = pHead;
    pHead = pHead->p_next;
    delete temp;
}
void removeTail(NODE *&pHead)
{
    if (!pHead)
        return;

    NODE *temp = pHead;
    while (temp->p_next->p_next)
    {
        temp = temp->p_next;
    }
    NODE *temp2 = temp->p_next;
    temp->p_next = nullptr;
    delete temp2;
}
void removeAll(NODE *&pHead)
{
    if (!pHead)
        return;
    while (pHead->p_next)
    {
        NODE *temp = pHead;
        pHead = pHead->p_next;
        delete temp;
    }
    delete pHead;
}
void removeBefore(NODE *&pHead, int val)
{
    if (!pHead || pHead->key == val)
        return;
    if (pHead->p_next->key == val)
    {
        removeHead(pHead);
        return;
    }
    NODE *temp = pHead;
    while (temp->p_next->p_next->key != val)
    {
        temp = temp->p_next;
    }
    NODE *temp2 = temp->p_next->p_next;
    delete temp->p_next;
    temp->p_next = temp2;
}
void printList(NODE *pHead)
{
    while (pHead)
    {
        cout << pHead->key << " ";
        pHead = pHead->p_next;
    }
}
void removeAfter(NODE *&pHead, int val)
{
    if (!pHead)
        return;
    NODE *temp = pHead;
    while (temp->key != val)
    {
        temp = temp->p_next;
    }
    NODE *temp2 = temp->p_next->p_next;
    delete temp->p_next;
    temp->p_next = temp2;
}
bool addPos(NODE *&pHead, int data, int pos)
{
    if (!pHead)
        return 0;
    if (pos <= 0)
    {
        addHead(pHead, data);
        return 1;
    }
    int count = 0;
    NODE *temp = pHead;
    while (count + 1 < pos && temp->p_next)
    {
        temp = temp->p_next;
        count++;
    }
    if (count + 1 < pos)
        return 0;
    NODE *temp2 = temp->p_next;
    temp->p_next = createNode(data);
    temp->p_next->p_next = temp2;
    return 1;
}
void RemovePos(NODE *&pHead, int pos)
{
    if (!pHead || pos < 0)
        return;
    if (pos == 0)
    {
        removeHead(pHead);
        return;
    }
    NODE *temp = pHead;
    int count = 0;
    while (count + 1 < pos && temp->p_next)
    {
        temp = temp->p_next;
        count++;
    }
    if (count + 1 < pos)
        return;
    NODE *temp2 = temp->p_next->p_next;
    delete temp->p_next;
    temp->p_next = temp2;
}
void addBefore(NODE *&pHead, int data, int val)
{
    if (!pHead)
        return;
    if (pHead->key == val)
    {
        addHead(pHead, data);
        return;
    }
    NODE *temp = pHead;
    while (temp->p_next->key != val)
    {
        temp = temp->p_next;
    }
    NODE *temp2 = temp->p_next;
    temp->p_next = createNode(data);
    temp->p_next->p_next = temp2;
}
void addAfter(NODE *&pHead, int data, int val)
{
    if (!pHead)
        return;
    NODE *temp = pHead;
    while (temp->key != val)
    {
        temp = temp->p_next;
    }
    NODE *temp2 = temp->p_next;
    temp->p_next = createNode(data);
    temp->p_next->p_next = temp2;
}
int countElements(NODE *&pHead)
{
    int count = 0;
    if (!pHead)
        return count;
    NODE *temp = pHead;
    while (temp->p_next)
    {
        count++;
        temp = temp->p_next;
    }
    return count + 1;
}
int countAppearance(NODE *&pHead, int value)
{
    int count = 0;
    if (!pHead)
        return count;
    NODE *temp = pHead;
    while (temp)
    {
        if (temp->key == value)
            count++;
        temp = temp->p_next;
    }
    return count;
}

int main()
{
    List b;
    b.p_head = createNode(3);
    b.p_tail = createNode(5);
    b.p_head->p_next = b.p_tail;
    addHead(b.p_head, 7);

    addHead(b.p_head, 88);
    addHead(b.p_head, 41);

    printList(b.p_head);

    removeAll(b.p_head);

    return 0;
}