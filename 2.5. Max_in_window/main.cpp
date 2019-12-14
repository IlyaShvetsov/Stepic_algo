/// task 2.5

#include <iostream>
#include <stack>
#include <vector>

using std::stack;

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
    bool isEmpty() const {
        return stack.empty();
    }

private:
    std::stack<T> stack;
    std::stack<T> maxStack;
};

template <typename T>
class QueueWithMax {
public:
    T front() const {
        if (out.isEmpty()) {
            shift();
        }
        return out.top();
    }
    T max() const {
        if (out.isEmpty()) {
            return in.max();
        }
        if (in.isEmpty()) {
            return out.max();
        }
        return std::max(in.max(), out.max());
    }
    void push(T value) {
        in.push(value);
    }
    void pop() {
        if (out.isEmpty()) {
            shift();
        }
        out.pop();
    }

private:
    StackWithMax<T> in;
    StackWithMax<T> out;

    void shift() {
        while (!in.isEmpty()) {
            out.push(in.top());
            in.pop();
        }
    }
};

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        int item;
        std::cin >> item;
        sequence.push_back(item);
    }
    std::cin >> m;
    QueueWithMax<int> queue;
    for (int i = 0; i < m; ++i) {
        queue.push(sequence[i]);
    }
    std::cout << queue.max() << " ";
    for (int i = m; i < n; ++i) {
        queue.pop();
        queue.push(sequence[i]);
        std::cout << queue.max() << " ";
    }
    return 0;
}
