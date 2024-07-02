#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int size;
    int front;
    int rear;
    int capacity;
    int *CQ;

public:
    CircularQueue(int capacity)
    {
        this->capacity = capacity;
        front = size = 0;
        rear = capacity - 1; // not set to -1 because that can avoid negative number process.
        CQ = new int[capacity];
    }

    ~CircularQueue()
    {
        delete[] CQ;
    }

    bool isFull();
    bool isEmpty();
    void enqueue(int item);
    int dequeue();
    int frontItem();
    int rearItem();
};

bool CircularQueue::isFull()
{
    return (size == capacity);
}

bool CircularQueue::isEmpty()
{
    return (size == 0);
}

void CircularQueue::enqueue(int item)
{
    if (isFull())
    {
        cout << "Queue is full." << endl;
        return;
    }
    rear = (rear + 1) % capacity; // rear init to capacity - 1, so there can make circle calcular easier
    CQ[rear] = item;
    size++;
}

int CircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty." << endl;
        return -1;
    }
    int item = CQ[front];
    front = (front + 1) % capacity;
    size--;
    return item;
}

int CircularQueue::frontItem()
{
    if (isEmpty())
    {
        cout << "Queue is Empty." << endl;
        return -1;
    }
    return CQ[front];
}

int CircularQueue::rearItem()
{
    if (isEmpty())
    {
        cout << "Queue is Empty." << endl;
        return -1;
    }
    return CQ[rear];
}

int main()
{
    CircularQueue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    cout << "Front item is " << queue.frontItem() << endl;
    cout << "Queue elements: ";
    while (!queue.isEmpty())
    {
        cout << queue.dequeue() << " ";
    }
    cout << endl;
    return 0;
}