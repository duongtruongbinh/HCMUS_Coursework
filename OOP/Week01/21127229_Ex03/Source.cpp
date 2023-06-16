#include "Header.h"

using namespace std;

void LinkedListQueue::init(int capacity)
{
    setHead(NULL);
    setTail(NULL);
    this->setCapacity(capacity);
    this->setNum(0);
}

bool LinkedListQueue::isEmpty()
{
    Node* tail = this->getTail();
    Node* head = this->getHead();
    int num = getNum();
    return (tail == NULL && head == NULL && !num);
}

void LinkedListQueue::push(int x)
{
    Node* tail = this->getTail();
    Node* temp = new Node;
    temp->key = x;

    if (this->isEmpty())
    {
        setHead(temp);
        setTail(temp);
    }
    else
    {
        tail->next = temp;
        setTail(temp);
    }
    setNum(getNum() + 1);
}

int LinkedListQueue::dequeue()
{
    Node* head = this->getHead();
    int res;
    if (isEmpty())
        return -99;
    else if (head->next == NULL)
    {
        res = head->key;
        delete head;
        setHead(NULL);
        setTail(NULL);
    }
    else
    {
        res = head->key;
        Node* temp = head->next;
        delete head;
        setHead(temp);
    }
    this->setNum(this->getNum() - 1);
    return res;
}

int LinkedListQueue::peek()
{
    Node* head = this->getHead();
    int res;
    if (isEmpty())
        res = -99;
    res = head->key;
    return res;
}

bool LinkedListQueue::isFull()
{
    int num = getNum();
    int cap = getCapacity();
    return num == cap;
}

void LinkedListQueue::clear()
{
    Node* head = getHead();
    if (isEmpty())
        return;
    while (head != NULL)
    {
        Node* temp = head->next;
        delete head;
        head = temp;
        setHead(temp);
    }
    setNum(0);
    setTail(NULL);
}

void LinkedListQueue::travel()
{
    if (this->isEmpty()) 
    {
        cout << "Queue is empty.";
        return;
    }
    Node* temp = this->getHead();
    while (temp != NULL)
    {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}