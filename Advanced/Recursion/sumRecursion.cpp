#include <iostream>
using namespace std;


int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {

        return sum(n - 1) + n;
    }
}
int main()
{
    int x = 20;
    int r = sum(x);
    cout << r << endl;
    return 0;
}
