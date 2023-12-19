#include <iostream>
using namespace std;

float taylorSeriesRecursion(int x, int n)
{
    static int p = 1, f = 1;
    float r;
    if (n == 0)
        return 1;
    if (n > 0)
    {
        r = taylorSeriesRecursion(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}

double advance(int x, int n){
    static double s=1;
    if(n==0) return s;
    s = 1+x*s/n;
    return advance(x, n-1);
}

int main()
{
    cout << taylorSeriesRecursion(5, 2) << endl;
    return 0;
}