#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle()
    {
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return length * breadth;
    }
    int perimeter()
    {
        return 2 * (length + breadth);
    }
    void setLength(int l){length = l};
    void setBreadth(int b){breadth = b};
    int getLength
};

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