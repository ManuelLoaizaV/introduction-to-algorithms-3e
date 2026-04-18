#include <iostream>
#include <stdexcept>

const int MAX_CAPACITY{32};

template<typename T, int max_capacity = MAX_CAPACITY>
struct Stack {
    int top_index{-1};
    T data[max_capacity];

    bool Empty(void) {
        return top_index == -1;
    }

    void Push(T x) {
        if (top_index + 1 == max_capacity) {
            throw std::overflow_error("Stack overflow.");
        }
        top_index++;
        data[top_index] = x;
    }

    T Pop(void) {
        if (top_index == -1) {
            throw std::underflow_error("Stack underflow.");
        }
        top_index--;
        return data[top_index + 1];
    }
};

int main(void) {
    Stack<int, 6> stack;

    std::cout << "Pushing elements to capacity" << std::endl;
    for (int i = 0; i < 6; ++i) {
        stack.Push(i * 10);
    }

    std::cout << "Attempting to push to a full stack" << std::endl;
    try {
        stack.Push(60);
    } catch (const std::overflow_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "Popping elements" << std::endl;
    std::cout << "Pop: " << stack.Pop() << std::endl;
    std::cout << "Pop: " << stack.Pop() << std::endl;

    std::cout << "Pushing again after pops" << std::endl;
    stack.Push(40);
    stack.Push(50);

    std::cout << "Emptying the stack" << std::endl;
    while (!stack.Empty()) {
        std::cout << "Pop: " << stack.Pop() << std::endl;
    }

    std::cout << "Attempting to pop from an empty stack" << std::endl;
    try {
        stack.Pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "Testing with std::string" << std::endl;
    Stack<std::string, 3> string_stack;
    string_stack.Push("alpha");
    string_stack.Push("beta");
    string_stack.Push("gamma");

    while (!string_stack.Empty()) {
        std::cout << "Pop: " << string_stack.Pop() << std::endl;
    }

    return 0;
}