#include <iostream>
#include <array>
#include <stdexcept>

const int MAX_CAPACITY{32};

template<typename T, int max_capacity = MAX_CAPACITY>
struct Deque {
    std::array<T, max_capacity> data;
    int head_index{0};
    int tail_index{0};
    int length{0};

    bool Empty(void) {
        return length == 0;
    }

    void PushFront(T x) {
        if (length == max_capacity) {
            throw std::overflow_error("Deque overflow");
        }
        if (head_index == 0) {
            head_index = max_capacity - 1;
        } else {
            head_index--;
        }
        data[head_index] = x;
        length++;
    }

    void PushBack(T x) {
        if (length == max_capacity) {
            throw std::overflow_error("Deque overflow");
        }
        data[tail_index] = x;
        length++;
        if (tail_index == max_capacity - 1) {
            tail_index = 0;
        } else {
            tail_index++;
        }
    }

    T PopFront(void) {
        if (Empty()) {
            throw std::underflow_error("Deque underflow");
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

    T PopBack(void) {
        if (Empty()) {
            throw std::underflow_error("Deque underflow");
        }
        if (tail_index == 0) {
            tail_index = max_capacity - 1;
        } else {
            tail_index--;
        }
        length--;
        return data[tail_index];
    }
};

int main(void) {
    Deque<int, 6> deque;

    std::cout << "Testing mixed PushFront and PushBack" << std::endl;
    deque.PushBack(10);
    deque.PushFront(20);
    deque.PushBack(30);
    deque.PushFront(40);

    std::cout << "Popping from both ends" << std::endl;
    std::cout << "PopFront: " << deque.PopFront() << std::endl;
    std::cout << "PopBack: " << deque.PopBack() << std::endl;

    std::cout << "Testing wrap-around at capacity" << std::endl;
    deque.PushBack(50);
    deque.PushBack(60);
    deque.PushBack(70);
    deque.PushBack(80);

    try {
        deque.PushFront(90);
    } catch (const std::overflow_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "Emptying from the back" << std::endl;
    while (!deque.Empty()) {
        std::cout << "PopBack: " << deque.PopBack() << std::endl;
    }

    try {
        deque.PopFront();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "Testing with std::string" << std::endl;
    Deque<std::string, 3> string_deque;
    string_deque.PushBack("Tail");
    string_deque.PushFront("Head");
    string_deque.PushBack("End");

    std::cout << "PopFront: " << string_deque.PopFront() << std::endl;
    std::cout << "PopBack: " << string_deque.PopBack() << std::endl;
    std::cout << "PopFront: " << string_deque.PopFront() << std::endl;

    return 0;
}
