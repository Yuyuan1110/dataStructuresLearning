#include <iostream>
using namespace std;

int fact(int n)
{

    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int nCr(int n, int r)
{
    int num, dem;
    num = fact(n);
    dem = fact(r) * fact(n - r);

    return num / dem;
}

int NCR(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

int main()
{
    cout << nCr << endl;
    return 0;
}