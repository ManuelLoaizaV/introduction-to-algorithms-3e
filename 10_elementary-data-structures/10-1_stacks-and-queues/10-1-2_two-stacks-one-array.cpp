#include <array>
#include <iostream>
#include <stdexcept>

const int MAX_CAPACITY{32};

template<typename T, int max_capacity = MAX_CAPACITY>
struct TwoStacks {
    std::array<int, 2> top_indices{-1, max_capacity};
    T data[max_capacity];

    bool Empty(int id) {
        if (id == 0) {
            return top_indices[0] == -1;
        }
        return top_indices[1] == max_capacity;
    }

    void Push(int id, T x) {
        if (top_indices[0] + 1 == top_indices[1]) {
            throw std::overflow_error("Stacks capacity overflow");
        }
        if (id == 0) {
            top_indices[0]++;
        } else {
            top_indices[1]--;
        }
        data[top_indices[id]] = x;
    }

    T Pop(int id) {
        if (Empty(id)) {
            throw std::underflow_error("Stack underflow");
        }
        if (id == 0) {
            top_indices[0]--;
            return data[top_indices[0] + 1];
        }
        top_indices[1]++;
        return data[top_indices[1] - 1];
    }
};

int main(void) {
    TwoStacks<int, 6> stacks;

    std::cout << "Pushing elements to both stacks" << std::endl;;
    stacks.Push(0, 10);
    stacks.Push(0, 20);
    stacks.Push(1, 99);
    stacks.Push(1, 88);
    stacks.Push(0, 30);
    stacks.Push(1, 77);

    std::cout << "Attempting to push to a full buffer" << std::endl;
    try {
        stacks.Push(0, 40); 
    } catch (const std::overflow_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "Popping elements" << std::endl;
    std::cout << "Pop Stack 0: " << stacks.Pop(0) << std::endl;
    std::cout << "Pop Stack 1: " << stacks.Pop(1) << std::endl;

    std::cout << "Pushing to Stack 1 again" << std::endl;
    stacks.Push(1, 66);
    stacks.Push(0, 30);

    std::cout << "Emptying Stack 0" << std::endl;
    while (!stacks.Empty(0)) {
        std::cout << "Pop Stack 0: " << stacks.Pop(0) << std::endl;
    }

    std::cout << "Attempting to pop from empty Stack 0" << std::endl;
    try {
        stacks.Pop(0);
    } catch (const std::underflow_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "Testing with std::string and small capacity" << std::endl;
    TwoStacks<std::string, 2> string_stacks;
    string_stacks.Push(0, "hello");
    string_stacks.Push(1, "world");
    std::cout << "Pop Stack 1: " << string_stacks.Pop(1) << std::endl;
    std::cout << "Pop Stack 0: " << string_stacks.Pop(0) << std::endl;
    return 0;
}