#include <array>
#include <iostream>
#include <stdexcept>

const int MAX_CAPACITY{32};

template<typename T, int max_capacity = MAX_CAPACITY>
struct Queue {
    std::array<T, max_capacity> data;
    int head_index{0};
    int tail_index{0};
    int length{0};

    bool Empty(void) {
        return length == 0;
    }

    int Size(void) {
        return length;
    }

    void Enqueue(T x) {
        if (length == max_capacity) {
            throw std::overflow_error("Queue overflow");
        }
        data[tail_index] = x;
        length++;
        if (tail_index == max_capacity - 1) {
            tail_index = 0;
        } else {
            tail_index++;
        }
    }

    T Dequeue(void) {
        if (Empty()) {
            throw std::underflow_error("Queue underflow");
        }
        T x = data[head_index];
        if (head_index == max_capacity - 1) {
            head_index = 0;
        } else {
            head_index++;
        }
        length--;
        return x;
    }
};

template<typename T, int max_capacity = MAX_CAPACITY>
struct Stack {
    Queue<T, max_capacity> helper, queue;

    bool Empty(void) {
        return queue.Empty();
    }

    void Push(T x) {
        if (queue.Size() == max_capacity) {
            throw std::overflow_error("Stack overflow");
        }
        queue.Enqueue(x);
    }

    T Pop(void) {
        if (queue.Empty()) {
            throw std::underflow_error("Stack underflow");
        }
        while (queue.Size() > 1) {
            helper.Enqueue(queue.Dequeue());
        }
        T x = queue.Dequeue();
        std::swap(helper, queue);
        return x;
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