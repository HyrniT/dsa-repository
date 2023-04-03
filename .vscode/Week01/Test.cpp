#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack;

    // Thêm các phần tử vào stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Hiển thị phần tử đầu tiên trong stack
    std::cout << "Top element: " << myStack.top() << std::endl;
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}