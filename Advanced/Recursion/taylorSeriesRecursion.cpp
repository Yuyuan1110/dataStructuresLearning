#include <iostream>
using namespace std;

float taylorSeriesRecursion(int x, int n)
{
    static int p=1, f=1;
    int r;
    if (n == 0)
        return 1;
    if(n > 0){
        r = taylorSeriesRecursion(x, n-1);
        p = p*x;
        f = f*n;
        return r+p/f;
    }
}

int main()
{
    taylorSeriesRecursion(5, 2);
    return 0;
}