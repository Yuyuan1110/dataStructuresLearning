#include <iostream>
using namespace std;
// this just a junior class, will create the more completely class in classTest3.

class Rectangle
{
public: // in the class, all the thing are private, so need declare to public.
    int length;
    int breadth;
    // };

    // initial Rectangle
    void initialise(int l, int b)
    {
        length = l;
        breadth = b;
    }

    // there are function
    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

// main
int main()
{
    Rectangle r;

    int l, b;
    cout << "please input the length and breadth: ";
    cin >> l >> b;

    r.initialise(l, b);

    int RA = r.area();
    int RP = r.perimeter();
    cout << "area: " << RA << endl
         << "perimeter: " << RP << endl;

    return 0;
}