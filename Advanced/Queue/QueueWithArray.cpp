#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int s = 10) : size(s), front(-1), rear(-1)
    {
        Q = new int[size];
    }

    ~Queue()
    {
        delete[] Q;
    }

    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
    {
        cout << "Queue Full";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = 1;
    if (front == rear)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::Display(){
    for(int i=front+1; i <= rear; i++){
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(10);
    q.enqueue(10);

    q.Display();
    return 0;
}