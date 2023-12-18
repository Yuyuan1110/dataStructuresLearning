#include <iostream>
using namespace std;


int sum(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {

        return sum(n - 1) * n;
    }
}
int main()
{
    int x = 12;
    auto r = sum(x);
    cout << r << endl;
    return 0;
}
