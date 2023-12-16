//  What is recursion
//  recursion is mean the function calling it self.
//  recursion function will work at stack in memory

#include <iostream>
#include <stdio.h>
using namespace std;

void headRecursion(int n)
{
    if (n > 0)
    {
        headRecursion(n - 1);
        cout << n << endl;
        
    }
}

void tailRecursion(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        tailRecursion(n - 1);
    }
}

// if the function call itself over 2 times, we can say that function is tree recursion.
// time O(2^n), space O(n) in this case.
void treeRecursion(int n){
    if (n > 0){
        cout << n << endl;
        treeRecursion(n-1);
        treeRecursion(n-1);
    }
}



int main()
{
    int x = 3;
    cout << "show the headRecursion output:" << endl;
    headRecursion(x);
    cout << "show the tailRecursion output:" << endl;
    tailRecursion(x);
    cout << "show the treeRecursion output:" << endl;
    treeRecursion(x);
    return 0;
}