#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Constructor
    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedListStack {
private:
    Node<T>* top; // 指向堆疊頂部的節點

public:
    // Constructor
    LinkedListStack() : top(nullptr) {}

    // Destructor
    ~LinkedListStack() {
        // 釋放節點記憶體
        Node<T>* current = top;
        Node<T>* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // 判斷堆疊是否為空
    bool isEmpty() const {
        return top == nullptr;
    }

    // 將元素壓入堆疊
    void push(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    // 從堆疊彈出元素
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }

        Node<T>* poppedNode = top;
        T poppedValue = poppedNode->data;
        top = poppedNode->next;
        delete poppedNode;

        return poppedValue;
    }

    // 獲取堆疊頂部元素的值
    T topValue() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }

        return top->data;
    }
};

int main() {
    // 測試基於 linked list 的堆疊
    LinkedListStack<int> myStack;

    // 將元素壓入堆疊
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // 輸出堆疊頂部元素
    std::cout << "Top of the stack: " << myStack.topValue() << std::endl;

    // 彈出元素
    std::cout << "Pop: " << myStack.pop() << std::endl;

    // 輸出堆疊是否為空
    std::cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
