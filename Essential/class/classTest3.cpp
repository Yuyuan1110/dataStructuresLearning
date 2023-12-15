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
        this->length = l;
        this->breadth = b;
    }
    int area();
    int perimeter();
    void setBreadth(int l);
    void setLength(int l);
    int getBreadth();
    int getLength();
    ~Rectangle()
    {
        cout << "Destructor";
    }
};
int Rectangle::area()
{
    return length * breadth;
}
int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}
void Rectangle::setLength(int l) { length = l; };
void Rectangle::setBreadth(int b) { breadth = b; };
int Rectangle::getLength() { return length; };
int Rectangle::getBreadth() { return breadth; };

int main()
{
    Rectangle r(10, 5);

    cout << "Area: " << r.area() << endl;
    return 0;
}