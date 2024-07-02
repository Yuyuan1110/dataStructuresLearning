#include <iostream>
using namespace std;

class Deque
{
private:
    int capacity;
    int size;
    int front;
    int rear;
    int *array;

public:
    Deque(int capacity) : capacity(capacity), size(0), front(-1), rear(-1), array(new int[capacity]) {}
    ~Deque()
    {
        delete[] array;
    }
    bool isFull();
    bool isEmpty();
    void insertFront(int item);
    void insertRear(int item);
    int deleteFront();
    int deleteRear();
    int getFront();
    int getRear();
};

bool Deque::isFull()
{
    return (size == capacity);
}

bool Deque::isEmpty()
{
    return (size == 0);
}

void Deque::insertFront(int item)
{
    if (isFull())
    {
        cout << "Queue is full." << endl;
        return;
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = capacity - 1;
    }
    else
    {
        front--;//front = front - 1;
    }

    array[front] = item;
    size++;
}

void Deque::insertRear(int item)
{
    if (isFull())
    {
        cout << "Queue is full." << endl;
        return;
    }
    else if (rear == -1)
    {
        rear = 0;
        front = 0;
    }
    else if (rear = capacity - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    array[rear] = item;
    size++;
}

int Deque::deleteFront()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }

    int tmp = array[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == capacity - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    size--;

    return tmp;
}

int Deque::deleteRear()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    int tmp = array[rear];

    if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else if (rear == 0)
    {
        rear = capacity - 1;
    }
    else
    {
        rear--;
    }
    size--;
    return tmp;
}

int Deque::getFront()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return array[front];
}

int Deque::getRear()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return array[rear];
}

int main()
{
    Deque dq(5);

    cout << "Insert element at rear end  : 5 \n";
    dq.insertRear(5);

    cout << "Insert element at rear end  : 10 \n";
    dq.insertRear(10);

    cout << "Rear end element: " << dq.getRear() << endl;

    dq.deleteRear();
    cout << "After delete rear element new rear become : " << dq.getRear() << endl;

    cout << "Inserting element at front end : 15 \n";
    dq.insertFront(15);

    cout << "Front end element: " << dq.getFront() << endl;

    dq.deleteFront();

    cout << "After delete front element new front become : " << dq.getFront() << endl;
    return 0;
}