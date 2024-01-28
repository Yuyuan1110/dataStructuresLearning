#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};


template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}


    ~DoublyLinkedList() {

        Node<T>* current = head;
        Node<T>* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    
    void append(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {

            head = newNode;
            tail = newNode;
        } else {

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void prepend(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void printList() const {
        Node<T>* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList<int> myList;
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.prepend(0);

    myList.printList();

    return 0;
}