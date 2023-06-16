#include <iostream>
using namespace std;
int somesum(int n, int &countCompare, int &countAssign)
{
    int sum = 0, i = 1, j;
    countCompare = 0;
    countAssign = 2;
    while (++countCompare && i <= n)
    {

        j = n - i;
        countAssign++;
        while (++countCompare && j <= i * i)
        {
            sum = sum + i * j;
            j += 1;
            countAssign += 2;
        }
        i += 1;
        countAssign++;
    }
    return sum;
}
void analyst()
{
    int countCompare, countAssign;
    for (int i = 0; i <= 500; i+=50)
    {
        somesum(i, countCompare, countAssign);
        cout << i << " " << countCompare << " " << countAssign << endl;
    }
}
int main()
{
    analyst();
    return 0;
}