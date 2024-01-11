#include <iostream>
using namespace std;

class Triangular
{
private:
    int *A;
    int n;

public:
    Triangular()
    {
        A = new int[5];
        this->n = 5;
    }
    Triangular(int n)
    {
        A = new int[n*(n+1)/2];
        this->n = n;
    }
    ~Triangular()
    {
        delete[] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void Triangular::Set(int i, int j, int x)
{
    if (i >= j)
    {
        A[i * (i - 1) / 2 + j - 1] = x;
    }
}

int Triangular::Get(int i, int j)
{
    if (i >= j)
    {
        return A[i * (i - 1) / 2 + j - 1];
    }
    return 0;
}

void Triangular::Display()
{
    int i, j;
    for (i = 1; i <= this->n; i++)
    {
        for (j = 1; j <= this->n; j++)
        {
            if (i >= j)
            {
                cout << this->A[i * (i - 1) / 2 + j - 1] << " ";
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

    class Triangular t(6);
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            t.Set(i, j, i + j);
        }
    }

    t.Display();
    return 0;
}