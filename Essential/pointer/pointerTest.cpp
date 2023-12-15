#include <iostream>
#include <stdlib.h>

using namespace std;
int main(){
    int a = 5;
    int* p;
    p = &a;
    cout << *&a << endl;

    int A[5] = {1, 3, 5, 6,7};
    cout << A << endl;


    p = (int*) malloc(5*sizeof(int));
    p[0] = 5;
    p[1] = 6;
    p[2] = 7;
    p[3] = 8;
    p[4] = 9;

    for (int i =0; i<5; i++){
        cout << p[i] << endl;
    }
    cout << "_____________________" << endl;

    p = new int[5];
    p[0] = 5;
    p[1] = 6;
    p[2] = 7;
    p[3] = 8;
    p[4] = 9;
    for (int i =0; i<5; i++){
        cout << p[i] << endl;
    }

    delete [] p;

    return 0;
}