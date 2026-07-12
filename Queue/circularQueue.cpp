#include <iostream>
#include <stdexcept>
#include <cassert>

template <typename T>
class CircularQueue {
private:
    int frontIndex = -1;
    int rearIndex = -1;
    int size;
    T* arr;

public:
    CircularQueue(int n) {
        size = n;
        arr = new T[size];
    }

    bool isEmpty() const {
        return frontIndex == -1 && rearIndex == -1;
    }

    bool isFull() const {
        //in circular queue, the next index for the rear is (rearIndex + 1) % size
        return (rearIndex + 1) % size==frontIndex;
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
            rearIndex = (rearIndex + 1) % size;
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
            frontIndex = (frontIndex + 1) % size;
        }
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

//tests written by chatgpt, don't know how good it is
int main() {

    CircularQueue<int> q(5);   // Can store 4 elements

    // ---------------------------------
    // Test 1: Newly created queue
    // ---------------------------------
    assert(q.isEmpty());
    assert(!q.isFull());

    // ---------------------------------
    // Test 2: Enqueue one element
    // ---------------------------------
    q.enqueue(10);

    assert(!q.isEmpty());
    assert(q.front() == 10);
    assert(q.rear() == 10);

    // ---------------------------------
    // Test 3: Enqueue more elements
    // ---------------------------------
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    assert(q.isFull());
    assert(q.front() == 10);
    assert(q.rear() == 40);

    // ---------------------------------
    // Test 4: Overflow
    // ---------------------------------
    try {
        q.enqueue(50);
        assert(false);     // Should never reach here
    }
    catch (const std::overflow_error&) {
        std::cout << "Overflow test passed.\n";
    }

    // ---------------------------------
    // Test 5: Dequeue once
    // ---------------------------------
    q.dequeue();

    assert(!q.isEmpty());
    assert(!q.isFull());
    assert(q.front() == 20);
    assert(q.rear() == 40);

    // ---------------------------------
    // Test 6: Wrap-around enqueue
    // rear should wrap to index 0
    // ---------------------------------
    q.enqueue(50);

    assert(q.isFull());
    assert(q.front() == 20);
    assert(q.rear() == 50);

    // ---------------------------------
    // Test 7: Remove all elements
    // ---------------------------------
    q.dequeue();   // removes 20
    assert(q.front() == 30);

    q.dequeue();   // removes 30
    assert(q.front() == 40);

    q.dequeue();   // removes 40
    assert(q.front() == 50);

    q.dequeue();   // removes 50

    assert(q.isEmpty());

    // ---------------------------------
    // Test 8: Underflow
    // ---------------------------------
    try {
        q.dequeue();
        assert(false);
    }
    catch (const std::underflow_error&) {
        std::cout << "Underflow test passed.\n";
    }

    // ---------------------------------
    // Test 9: front() on empty queue
    // ---------------------------------
    try {
        q.front();
        assert(false);
    }
    catch (const std::underflow_error&) {
        std::cout << "front() empty test passed.\n";
    }

    // ---------------------------------
    // Test 10: rear() on empty queue
    // ---------------------------------
    try {
        q.rear();
        assert(false);
    }
    catch (const std::underflow_error&) {
        std::cout << "rear() empty test passed.\n";
    }

    std::cout << "\nAll tests passed!\n";

    return 0;
}