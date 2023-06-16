#include <iostream>
using namespace std;
int squaresum_recursion(int n, int &countCompare, int &countAssign)
{

    if (++countCompare && n < 1)
        return 0;
    else
        return n * n + squaresum_recursion(n - 1, ++countCompare, ++countAssign);
}
void analyst()
{
    int countCompare = 0, countAssign = 0;
    for (int i = 0; i <= 500; i += 50)
    {
        squaresum_recursion(i, countCompare, countAssign);
        cout << i << " " << countAssign << " " << countCompare << endl;
    }
}
int main()
{
    analyst();
    return 0;
}