#include <iostream>
using namespace std;
// create a Rectangle struct and have some function to calculating area and perimeter.
// Then converts to class method into classTest2.

struct Rectangle
{
    int length;
    int breadth;
};

// initial Rectangle
void initialise(Rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}

// there are function
int area(Rectangle r)
{
    return r.length * r.breadth;
}

int perimeter(Rectangle r)
{
    return 2 * (r.length + r.breadth);
}

// main
int main()
{
    Rectangle r = {0, 0};

    int l, b;
    cout << "please input the length and breadth: ";
    cin >> l >> b;

    initialise(&r, l, b);

    int RA = area(r);
    int RP = perimeter(r);
    cout << "area: " << RA << endl
         << "perimeter: " << RP << endl;

    return 0;
}