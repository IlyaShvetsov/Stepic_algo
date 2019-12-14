/// task 2.4

#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

template <typename T>
class StackWithMax {
public:
    T top() const {
        return stack.top();
    }
    T max() const {
        return maxStack.top();
    }
    void push(T value) {
        stack.push(value);
        maxStack.push(maxStack.empty() ? value : std::max(value, maxStack.top()));
    }
    void pop() {
        stack.pop();
        maxStack.pop();
    }

private:
    std::stack<T> stack;
    std::stack<T> maxStack;
};



int main() {
    StackWithMax<int> stackWithMax;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        string request;
        std::cin >> request;
        if (request == "push") {
            int value;
            std::cin >> value;
            stackWithMax.push(value);
        }
        if (request == "pop") {
            stackWithMax.pop();
        }
        if (request == "top") {
            std::cout << stackWithMax.top() << std::endl;
        }
        if (request == "max") {
            std::cout << stackWithMax.max() << std::endl;
        }
    }

    return 0;
}
