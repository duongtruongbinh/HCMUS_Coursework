#include <iostream>
using namespace std;
struct NODE
{
    int key;
    NODE *p_next;
};
struct List
{
    NODE *head;
    NODE *tail;
};
List *createList(NODE *p_node)
{
    List *a = new List;
    a->head = p_node;
    a->tail = p_node;
    return a;
}
NODE *createNode(int data)
{
    NODE *a = new NODE;
    a->key = data;
    a->p_next = nullptr;
    return a;
}
bool addHead(List *&l, int data)
{
    if (!l->head)
    {
        l->head = createNode(data);
        if (!l->head)
            return 0;
        l->tail = l->head;
        return 1;
    }
    else
    {
        NODE *temp = createNode(data);
        if (!temp)
            return 0;
        temp->p_next = l->head;
        l->head = temp;
        return 1;
    }
}
bool addTail(List *&l, int data)
{
    if (!l->tail)
    {
        l->tail = createNode(data);
        if (!l->tail)
            return 0;
        l->head = l->tail;
        return 1;
    }
    else
    {
        NODE *temp = createNode(data);
        if (!temp)
            return 0;
        l->tail->p_next = temp;
        l->tail = temp;
        return 1;
    }
}
void removeHead(List *&l)
{
    if (!l->head)
        return;
    if (!l->head->p_next)
    {
        NODE *temp = l->head;
        l->head = l->tail = nullptr;
        delete temp;
    }
    NODE *temp = l->head;
    l->head = l->head->p_next;
    delete temp;
}
void removeTail(List *&l)
{
    if (!l->tail)
        return;

    NODE *temp = l->head;
    while (temp->p_next->p_next)
    {
        temp = temp->p_next;
    }
    NODE *temp2 = temp->p_next;
    temp->p_next = nullptr;
    l->tail = temp;
    delete temp2;
}
void printList(List *l)
{
    NODE *temp = l->head;
    while (temp)
    {
        cout << temp->key << " ";
        temp = temp->p_next;
    }
}
void removeAll(List *&l)
{
    if (!l->head)
        return;
    NODE *temp = l->head;
    while (temp)
    {
        NODE *temp2 = temp;
        temp = temp->p_next;
        delete temp2;
    }
    l->head = l->tail = nullptr;
}
void removeBefore(List *&l, int val)
{
    if (!l->head || l->head->key == val)
        return;
    NODE *temp = l->head;
    if (l->head->p_next->key == val)
    {
        removeHead(l);
        return;
    }
    while (temp->p_next->p_next->key != val)
    {
        temp = temp->p_next;
    }
    NODE *temp2 = temp->p_next->p_next;
    delete temp->p_next;
    temp->p_next = temp2;
}
void removeAfter(List *&l, int val)
{
    if (!l->head || l->tail->key == val)
        return;
    NODE *temp = l->head;
    while (temp->key != val)
    {
        temp = temp->p_next;
    }
    NODE *temp2 = temp->p_next->p_next;
    delete temp->p_next;
    temp->p_next = temp2;
}
bool addPos(List *&l, int data, int pos)
{
    if (pos <= 0)
    {
        addHead(l, data);
        return 1;
    }
    if (!l->head)
    {
        addHead(l, data);
        l->tail = l->head;
        return 1;
    }
    int count = 0;
    NODE *temp = l->head;
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
bool addBefore(List *&l, int data, int val)
{
    if (!l->head)
    {
        return 0;
    }
    if (l->head->key == val)
    {
        addHead(l, data);
        return 1;
    }
    NODE *temp = l->head;
    while (temp->p_next->key != val && temp)
    {
        temp = temp->p_next;
    }
    if (!temp)
        return 0;
    NODE *temp2 = temp->p_next;
    temp->p_next = createNode(data);
    temp->p_next->p_next = temp2;
    return 1;
}
bool addAfter(List *&l, int data, int val)
{
    if (!l->head)
        return 0;
    if (l->tail->key == val)
    {
        addTail(l, data);
        return 1;
    }
    NODE *temp = l->head;
    while (temp->key != val && temp)
    {
        temp = temp->p_next;
    }
    if (!temp)
        return 0;
    NODE *temp2 = temp->p_next;
    temp->p_next = createNode(data);
    temp->p_next->p_next = temp2;
    return 1;
}
int countElements(List *l)
{
    int count = 0;
    if (!l->head)
        return count;
    while (l->head)
    {
        count++;
        l->head = l->head->p_next;
    }
    return count;
}
int countAppearance(List *l, int value)
{
    int count = 0;
    if (!l->head)
        return count;
    NODE *temp = l->head;
    while (temp)
    {
        if (temp->key == value)
            count++;
        temp = temp->p_next;
    }
    return count;
}
struct stack
{
    NODE *head;
};
stack *createStack(int data)
{
    stack *a = new stack;
    a->head = createNode(data);
    return a;
}
bool isEmpty(stack *a)
{
    if (a->head)
        return 0;
    return 1;
}
void push(stack *l, int data)
{
    if (isEmpty(l))
    {
        l->head = createNode(data);
    }
    else
    {
        NODE *temp = createNode(data);
        temp->p_next = l->head;
        l->head = temp;
    }
}
void pop(stack *l)
{
    if (!isEmpty(l))
    {
        NODE *temp = l->head;
        l->head = l->head->p_next;
        delete temp;
    }
}
int countStack(stack *a)
{
    if (isEmpty(a))
        return 0;
    NODE *temp = a->head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->p_next;
    }
    return count;
}

struct queue
{
    NODE *head;
    NODE *tail;
};

bool isQueueEmpty(queue *a)
{
    if (a->head)
        return 0;
    return 1;
}

queue *createQueue(int data)
{
    queue *a = new queue;
    a->head = a->tail = createNode(data);
    return a;
}

void Enqueue(queue *a, int data)
{
    if (!isQueueEmpty(a))
    {
        a->tail->p_next = createNode(data);
        a->tail = a->tail->p_next;
    }
    else
    {
        a->tail = a->head = createNode(data);
    }
}

void Dequeue(queue *a)
{
    if (!isQueueEmpty(a))
    {
        if (!a->head->p_next)
        {
            delete a->head;
            a->head = a->tail = nullptr;
            return;
        }
        NODE *temp = a->head;
        a->head = a->head->p_next;
        delete temp;
    }
}

int countQueue(queue *a)
{
    if (isQueueEmpty(a))
        return 0;
    NODE *temp = a->head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->p_next;
    }
    return count;
}

int main()
{
    queue *a = createQueue(5);
    Enqueue(a, 10);
    Enqueue(a, 3);
    
    NODE *temp = a->head;
    while (temp)
    {
        cout << temp->key << " ";
        temp = temp->p_next;
    }
    cout << countQueue(a);
    return 0;
}