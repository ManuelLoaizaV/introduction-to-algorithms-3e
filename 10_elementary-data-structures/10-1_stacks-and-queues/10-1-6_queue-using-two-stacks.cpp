#include <array>
#include <iostream>
#include <stdexcept>

const int MAX_CAPACITY{32};

// Stack implementation from problem 10-1-1
template<typename T, int max_capacity = MAX_CAPACITY>
struct Stack {
    int top_index{-1};
    std::array<T, max_capacity> data;

    bool Empty(void) {
        return top_index == -1;
    }

    int Size(void) {
        return top_index + 1;
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

template<typename T, int max_capacity = MAX_CAPACITY>
struct Queue {
    Stack<T, max_capacity> push_into, pop_from;
    int Size(void) {
        return push_into.Size() + pop_from.Size();
    }

    bool Empty(void) {
        return Size() == 0;
    }

    void Enqueue(T x) {
        if (Size() == max_capacity) {
            throw std::overflow_error("Queue overflow");
        }
        push_into.Push(x);
    }

    T Dequeue(void) {
        if (Empty()) {
            throw std::underflow_error("Queue underflow");
        }
        if (pop_from.Empty()) {
            while (!push_into.Empty()) {
                pop_from.Push(push_into.Pop());
            }
        }
        return pop_from.Pop();
    }
};

int main(void) {
    Queue<int, 5> queue;

    std::cout << "Filling queue to capacity" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        queue.Enqueue(i * 10);
    }

    std::cout << "Attempting to Enqueue to a full queue" << std::endl;
    try {
        queue.Enqueue(60);
    } catch (const std::overflow_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "Dequeuing two elements" << std::endl;
    std::cout << "Dequeue: " << queue.Dequeue() << std::endl;
    std::cout << "Dequeue: " << queue.Dequeue() << std::endl;

    std::cout << "Testing wrap-around by Enqueuing more elements" << std::endl;
    queue.Enqueue(60);
    queue.Enqueue(70);

    std::cout << "Emptying queue to check FIFO order and wrap-around" << std::endl;
    while (!queue.Empty()) {
        std::cout << "Dequeue: " << queue.Dequeue() << std::endl;
    }

    std::cout << "Attempting to Dequeue from an empty queue" << std::endl;
    try {
        queue.Dequeue();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "Testing with double type" << std::endl;
    Queue<double, 3> double_queue;
    double_queue.Enqueue(1.1);
    double_queue.Enqueue(2.2);
    std::cout << "Dequeue: " << double_queue.Dequeue() << std::endl;
    std::cout << "Dequeue: " << double_queue.Dequeue() << std::endl;

    return 0;
}