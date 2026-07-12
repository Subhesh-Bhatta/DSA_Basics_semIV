#include <iostream>
#include <stdexcept>
#include <cassert>

template <typename T>
class CircularDeque {
private:
    int frontIndex = -1;
    int rearIndex = -1;
    int size;
    T* arr;

public:
    CircularDeque(int n) {
        size = n;
        arr = new T[size];
    }

    bool isEmpty() const {
        return frontIndex == -1 && rearIndex == -1;
    }

    bool isFull() const {
        //in circular queue or circular deque, the next index for the rear is (rearIndex + 1) % size
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

    void insertRear(T element) {
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
    
    void insertFront(T element) {
        if (isFull()) {
            throw std::overflow_error("Queue overflow");
        }

        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        }
        else {
            // adding in front means moving backwards, so we do frontIndex - 1,
            //  then we add size to it, since C++ can't evaluate (0-1) % 8 as 7, instead it gives -1, unlike the mathematical modulo operator
            frontIndex = (frontIndex - 1 + size) % size;
        }

        arr[frontIndex] = element;
    }
    

    void deleteFront() {
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
    
    void deleteRear() {
        if (isEmpty()) {
            throw std::underflow_error("Queue underflow");
        }

        if (frontIndex == rearIndex) {
            frontIndex = -1;
            rearIndex = -1;
        }
        else {
            rearIndex = (rearIndex - 1 + size) % size;
        }
    }

    ~CircularDeque() {
        delete[] arr;
    }
};


//chatgpt generated shit testcases, couldn't be bothered to write one myself, maybe some other day
int main() {

    return 0;
}