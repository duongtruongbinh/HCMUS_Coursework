#include <iostream>
using namespace std;
struct node
{
    int key;
    node *next;
    node *prev;
};

struct list
{
    node *head;
    node *tail;
};

node *createNode(int data)
{
    node *a = new node;
    a->key = data;
    a->prev = nullptr;
    a->next = nullptr;
    return a;
}

list *createList(node *p_node)
{
    list *a = new list;
    a->head = p_node;
    a->tail = p_node;
    return a;
}

bool addHead(list *&l, int data)
{
    if (l->head)
    {
        node *temp = createNode(data);
        if (!temp)
            return 0;
        temp->next = l->head;
        l->head->prev = temp;
        l->head = temp;
        return 1;
    }
    else
    {
        l->head = l->tail = createNode(data);
        if (!l->head || !l->tail)
            return 0;
        return 1;
    }
}

bool addTail(list *&l, int data)
{
    if (l->tail)
    {
        l->tail->next = createNode(data);
        if (!l->tail)
            return 0;
        l->tail->next->prev = l->tail;
        l->tail = l->tail->next;
        return 1;
    }
    else
    {
        l->tail = l->head = createNode(data);
        if (!l->head || !l->tail)
            return 0;
        return 1;
    }
}

void removeHead(list *&l)
{
    if (l->head)
    {
        if (l->head->next)
        {
            node *temp = l->head;
            l->head = l->head->next;
            l->head->prev = nullptr;
            delete temp;
        }
        else
        {
            node *temp = l->head;
            delete temp;
            l->head = l->tail = nullptr;
        }
    }
}

void removeTail(list *&l)
{
    if (l->tail)
    {
        if (l->tail->prev)
        {
            node *temp = l->tail;
            l->tail = l->tail->prev;
            l->tail->next = nullptr;
            delete temp;
        }
        else
        {
            node *temp = l->tail;
            l->tail = l->head = nullptr;
            delete temp;
        }
    }
}

void removeAll(list *&l)
{
    node *temp = l->head;
    while (temp != nullptr)
    {

        node *temp2 = temp;
        temp = temp->next;
        delete temp2;
    }
    l->head = l->tail = nullptr;
}

void removeBefore(list *&l, int val)
{
    node *temp = l->head;
    if (l->head->key == val || !l->head)
        return;
    if (temp->next->key == val)
    {
        removeHead(l);
        return;
    }

    while (temp->next && temp->next->key != val)
    {
        temp = temp->next;
    }

    if (temp->key != val) // when the val is not in the list
        return;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void removeAfter(list *&l, int val)
{
    node *temp = l->head;
    if (l->tail->prev->key == val)
    {
        removeTail(l);
        return;
    }

    while (temp->next && temp->key != val)
    {
        temp = temp->next;
    }
    if (temp == l->tail)
        return;
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete temp2;
}

bool addPos(list *&l, int data, int pos)
{
    node *temp = l->head;
    if (!l->head)
    {
        addHead(l, data);
        l->tail = l->head;
        return 1;
    }
    if (pos <= 0)
    {
        addHead(l, data);
        return 1;
    }

    int count = 0;
    while (count + 1 < pos && temp->next)
    {
        temp = temp->next;
        count++;
    }
    if (count + 1 < pos)
        return 0;

    node *temp2 = temp->next;
    temp->next = createNode(data);
    temp->next->prev = temp;
    temp->next->next = temp2;
    if (temp2)
        temp2->prev = temp->next;
    return 1;
}

int countElements(list *l)
{
    node *temp = l->head;
    int result = 0;
    if (!temp)
        return result;
    while (temp)
    {
        temp = temp->next;
        result++;
    }
    return result;
}


void printList(list *l)
{
    while (l->head)
    {
        cout << l->head->key << " ";
        l->head = l->head->next;
    }
}

int main()
{
    list *l = createList(createNode(2));

    addHead(l, 8);
    addTail(l, 4);
    addHead(l, 5);
    addPos(l, 1, 6);
    printList(l);
    cout << countElements(l);
    return 0;
}