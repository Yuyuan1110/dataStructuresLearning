#include <iostream>
#include <stdexcept>

template <typename T, int MaxSize>
class ArrayStack {
private:
    T stackArray[MaxSize];
    int top; // 指向堆疊頂部的索引

public:
    // 構造函數
    ArrayStack() : top(-1) {}

    // 判斷堆疊是否為空
    bool isEmpty() const {
        return top == -1;
    }

    // 判斷堆疊是否已滿
    bool isFull() const {
        return top == MaxSize - 1;
    }

    // 將元素壓入堆疊
    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Stack is full");
        }

        stackArray[++top] = value;
    }

    // 從堆疊彈出元素
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }

        return stackArray[top--];
    }

    // 獲取堆疊頂部元素的值
    T topValue() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }

        return stackArray[top];
    }
};

int main() {
    // 測試基於Array的堆疊
    ArrayStack<int, 5> myStack;

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