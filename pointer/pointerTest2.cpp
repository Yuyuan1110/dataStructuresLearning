#include <iostream>
#include <stdlib.h>

using namespace std;


void swap(int &x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main(){

    int a[3] = {0,1,2};
    int *p=a+1;


    // cout << *p-- << endl;
    // cout << *--p << endl;
    // cout << (*p)-- << endl;
    // cout << --*p << endl;

    int j = 2; 
    int k = 4;

    swap(j, k);

    cout << j << endl << k << endl;
    return 0;
}
