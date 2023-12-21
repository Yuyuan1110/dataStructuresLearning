#include <iostream>
using namespace std;
// #include <stdlib.h>

 
int main(){
    int A[3][4]={{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    cout << A[2][3] << endl;

    int *B[3];
    B[0] = new int [4];
    B[1] = new int [4];
    B[2] = new int [4];

    int **C;
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    return 0;
}