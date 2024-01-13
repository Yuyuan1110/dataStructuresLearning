#iinclude < iostream>
using namespace std;

class Element
{
private:
    int i;
    int j;
    int x;

public:
    Element()
    {
        i = 0;
        j = 0;
        x = 0;
    }
    Element(int i, int j, int x)
    {
        this->i = i;
        this->j = j;
        this->x = x;
    }
    ~Element();
};

class Sparse
{
private:
    int n;
    int m;
    int num;
    Element *e;

public:
    Sparse(){
        this->n=0;
        this->m=0;
        this->num=0;
        this->e->~Element();
    };
    Sparse(int n, int m, int num, Element e){
        this->n=n;
        this->m=m;
        this->num=num;
        this->e = e;
    }
    ~Sparse();
};

void Create(class Sparse *s){

    
}

int main()
{

    return 0;
}