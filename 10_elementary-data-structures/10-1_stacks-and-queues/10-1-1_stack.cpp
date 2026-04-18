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
    stack.Push(4);
    stack.Push(1);
    stack.Push(3);
    stack.Pop();
    stack.Push(8);
    stack.Pop();
    return 0;
}