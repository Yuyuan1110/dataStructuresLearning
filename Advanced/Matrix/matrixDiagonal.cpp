#include <iostream>
using namespace std;

class Matrix
{
private:
    int *A;
    int n;

public:
    Matrix()
    {
        A = new int[10];
        n = 5;
    }
    Matrix(int n)
    {
        if (n > 0)
        {
            A = new int[n];
            this->n = n;
        }
    }
    ~Matrix()
    {
        delete[] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Matrix::Set(int i, int j, int x)
{
    if (i > 0 && i <= this->n && j > 0 && j <= this->n)
    {
        if (i == j)
        {
            this->A[i - 1] = x;
        }
    }
}

int Matrix::Get(int i, int j){
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
}

void Matrix::Display(){
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
    struct Matrix m(4);
    
    m.Set(1, 1, 5);
    m.Set(2, 2, 8);
    m.Set(3, 3, 9);
    m.Set(4, 4, 12);
    m.Display();
    return 0;
}