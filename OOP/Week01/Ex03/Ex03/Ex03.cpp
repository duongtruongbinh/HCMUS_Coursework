#include "Header.h"
using namespace std;

int main()
{
    LinkedListQueue a;
    a.init(10);
    cout << a.getNum() << endl;
    a.push(3);
    cout << a.getNum() << endl;
    a.dequeue();
    a.push(7);
    a.push(2);
    a.push(9);
    a.push(4);

    a.travel();
    cout << a.peek() << endl;
    a.clear();
    a.travel();
}