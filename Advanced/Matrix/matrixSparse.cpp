#include <iostream>
using namespace std;

class Element
{
private:
    int i;
    int j;
    int x;

public:
    Element() : i(0), j(0), x(0)
    {
    }
    Element(int i, int j, int x) : i(i), j(j), x(x)
    {
    }
    int getI(){
        return i;
    }

    int getJ(){
        return j;
    }

    int getX(){
        return x;
    }

    void setI(int i){
        this->i = i;
    }
    void setJ(int j){
        this->j = j;
    }
    void setX(int x){
        this->x = x;
    }

};

class Sparse
{
private:
    int n;
    int m;
    int num;
    Element *e;

public:
    Sparse(int n, int m, int num, Element *e) : n(n), m(m), num(num)
    {
        this->e = new Element[num];
        for (int i = 0; i < num; i++)
        {
            this->e[i] = e[i];
        }
    }
    int getM() const
    {
        return m;
    }

    int getN() const
    {
        return n;
    }

    int getNUM() const
    {
        return num;
    }

    Element *getE() const
    {
        return e;
    }

    void setM(int value)
    {
        m = value;
    }

    void setN(int value)
    {
        n = value;
    }

    void setNUM(int value)
    {
        num = value;
    }

    void setE(Element *elements, int count)
    {
        delete[] e; // 釋放原有的內存
        e = new Element[num];
        for (int i = 0; i < count; i++)
        {
            e[i] = elements[i];
        }
    }
};

void Create(class Sparse *s)
{
    int n, m, num;
    cout << "Enter Dimensions: " << endl;
    cin >> m >> n;
    s->setM(m);
    s->setN(n);
    cout << "Number of non-zero: " << endl;
    cin >> num;
    s->setNUM(num);

    Element e[num];
    for (int k = 0; k < num; k++)
    {
        int i, j, x;
        cin >> i, j, x;
        e[k] = Element(i,j,x);
    }
    s->setE(e, num);
}

void Display(Sparse s){
    int i,j,k=0;
    for(i=0; i < s.getM(); i++){
        for(j=0; j < s.getN(); j++){
            if(i == s.getE()[k].getI() && j == s.getE()[k].getJ()){
                cout << s.getE()[k++].getX() << " ";
            }else{
                cout << "0 " ;
            }
        }
        cout << endl;
    }
}

int main()
{
    Sparse s = new Sparse();

    return 0;
}