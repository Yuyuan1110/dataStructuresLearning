#include <iostream>
using namespace std;

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal()
    {
        A = new int[10];
        n = 5;
    }
    Diagonal(int n)
    {
        if (n > 0)
        {
            A = new int[n];
            this->n = n;
        }
    }
    ~Diagonal()
    {
        delete[] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Diagonal::Set(int i, int j, int x)
{
    if (i > 0 && i <= this->n && j > 0 && j <= this->n)
    {
        if (i == j)
        {
            this->A[i - 1] = x;
        }
    }
}

int Diagonal::Get(int i, int j){
    if (i > 0 && i <= this->n && j > 0 && j <= this->n)
    {
        if (i == j)
        {
            return this->A[i - 1];
        }
        else
        {
            return 0;
        }
    }
    return -1;
}

void Diagonal::Display(){
    int i, j;
    for (i = 0; i < this->n; i++)
    {
        for (j = 0; j < this->n; j++)
        {
            if (i == j)
            {
                cout << this->A[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    class Diagonal d(4);
    
    d.Set(1, 1, 5);
    d.Set(2, 2, 8);
    d.Set(3, 3, 9);
    d.Set(4, 4, 12);
    d.Display();
    return 0;
}