#include <iostream>
#include <array>
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