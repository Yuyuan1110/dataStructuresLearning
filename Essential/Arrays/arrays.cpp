#include <iostream>

using namespace std;

int main()
{
    int A[5] = {2, 4, 6, 8, 1};

    for (int i : A)
    {
        cout << i << endl;
    }

    int *p = A+1;
    cout << (*p)--;
    return 0;
}