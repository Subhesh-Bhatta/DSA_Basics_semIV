#include <iostream>
#include <stdexcept>
#include <cassert>

template <typename T>
class Queue {
private:
    int frontIndex = -1;
    int rearIndex = -1;
    int size;
    T* arr;

public:
    Queue(int n) {
        size = n;
        arr = new T[size];
    }

    bool isEmpty() const {
        return frontIndex == -1 && rearIndex == -1;
    }

    bool isFull() const {
        return rearIndex == size - 1;
    }

    T front() const {
        if (isEmpty()) {
            std::cout << "Queue Empty\n";
            throw std::underflow_error("Queue underflow");
        }

        return arr[frontIndex];
    }

    T rear() const {
        if (isEmpty()) {
            std::cout << "Queue Empty\n";
            throw std::underflow_error("Queue underflow");
        }

        return arr[rearIndex];
    }

    void enqueue(T element) {
        if (isFull()) {
            throw std::overflow_error("Queue overflow");
        }

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        }
        else {
            rearIndex++;
        }

        arr[rearIndex] = element;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue underflow");
        }

        if (frontIndex == rearIndex) {
            frontIndex = -1;
            rearIndex = -1;
        }
        else {
            frontIndex++;
        }
    }

    ~Queue() {
        delete[] arr;
    }
};


//tests written by chatgpt, don't know how good it is
int main() {

    Queue<int> q(3);

    // -------------------------
    // Test 1: Newly created queue
    // -------------------------
    assert(q.isEmpty());
    assert(!q.isFull());

    // -------------------------
    // Test 2: Enqueue first element
    // -------------------------
    q.enqueue(10);

    assert(!q.isEmpty());
    assert(q.front() == 10);
    assert(q.rear() == 10);

    // -------------------------
    // Test 3: Enqueue second element
    // -------------------------
    q.enqueue(20);

    assert(q.front() == 10);
    assert(q.rear() == 20);

    // -------------------------
    // Test 4: Enqueue third element
    // -------------------------
    q.enqueue(30);

    assert(q.isFull());
    assert(q.front() == 10);
    assert(q.rear() == 30);

    // -------------------------
    // Test 5: Overflow
    // -------------------------
    try {
        q.enqueue(40);
        assert(false);
    }
    catch (const std::overflow_error&) {
        std::cout << "Overflow test passed.\n";
    }

    // -------------------------
    // Test 6: Dequeue once
    // -------------------------
    q.dequeue();

    assert(q.front() == 20);
    assert(q.rear() == 30);

    // -------------------------
    // Test 7: Dequeue twice
    // -------------------------
    q.dequeue();

    assert(q.front() == 30);
    assert(q.rear() == 30);

    // -------------------------
    // Test 8: Remove last element
    // -------------------------
    q.dequeue();

    assert(q.isEmpty());

    // -------------------------
    // Test 9: Underflow
    // -------------------------
    try {
        q.dequeue();
        assert(false);
    }
    catch (const std::underflow_error&) {
        std::cout << "Underflow test passed.\n";
    }

    // -------------------------
    // Test 10: front() on empty queue
    // -------------------------
    try {
        q.front();
        assert(false);
    }
    catch (const std::underflow_error&) {
        std::cout << "front() empty test passed.\n";
    }

    // -------------------------
    // Test 11: rear() on empty queue
    // -------------------------
    try {
        q.rear();
        assert(false);
    }
    catch (const std::underflow_error&) {
        std::cout << "rear() empty test passed.\n";
    }

    std::cout << "\nAll tests passed!\n";
}