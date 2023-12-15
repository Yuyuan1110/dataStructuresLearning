#include <iostream>
#include <stdlib.h>

using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    Rectangle r = {5, 10};
    cout << &r << endl;
    Rectangle *p = &r;
    

    return 0;
}