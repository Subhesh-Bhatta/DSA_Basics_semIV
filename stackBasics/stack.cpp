#include <iostream>

class Stack{
    private:
        int top=-1; //Index of top element of stck
        int size; //Capacity of array
        char* arr; //first element of a dynamically allocated array

    public:
        // Constructor for stack
        Stack(int n){
            this->size = n;
            arr = new char[size]; //Allocating char size memory for array of size 'size'
        }

        // copy constructor (deep copy)
        Stack(const Stack& other){
            this->size = other.size;

            this->arr = new char[this->size];

            for(int i=0; i<=other.top; i++){
                this->arr[i] = other.arr[i];
            }

            this->top = other.top;
        }
        
        //helper function to resize stack
        void resize(int newSize){

            if (newSize < size){

                std::cout << "Resizing stack to a smaller size than original\n";
                std::cout << "The original stack is this size:\n" << size;
                std::cout << "Current stack holds " << (top + 1)
                        << " elements and newSize given was " << newSize << "\n";

                std::cout << "Are you sure? (1/0)\n";

                int YorN;
                std::cin >> YorN;

                if (!YorN){
                    return;
                }
            }

            char* newArr = new char[newSize];

            int limit = (top < newSize - 1) ? top : newSize - 1;

            for(int i = 0; i <= limit; i++){
                newArr[i] = arr[i];
            }

            delete[] arr;

            arr = newArr;
            size = newSize;
            top = limit;
        }


        bool isEmpty(){
            return top == -1;
            //same as return top==-1?true:false
        }

        bool isFull(){
            return top == size-1;
        }

        void push(char x){
            if (isFull()){ // or if (this->isFull())
                std::cout << "Stack overflow\n";
                std::cout << "Do you want to increase the size of stack?(1/0)\n";
                
                int YorN;

                std::cin >> YorN;

                if (!YorN) return;
                
                std::cout<<"Increasing size of stack by 10\n";
                resize(size+10);

            }
            // arr[top]=x;
            // top+=1;
            arr[++top]=x;
            
        }


        void pop(){
            if (isEmpty()){
                std::cout << "Stack underflow\n";
                // throw std::underflow_error("Stack underflow");
            }
            else{
                top-=1;
            }
        }

        char peek(){
            if (isEmpty()){
                std::cout << "Stack underflow\n";
                return '\0';
                // throw std::underflow_error("Stack underflow");
            }
            else{
                
                return arr[top];
            }
        }


        // Destructor for stack
        ~Stack(){
            delete[] arr;
        }

};



// The tests are written by Claude, don't know how good they are
int main() {
    std::cout << "=== Stack Test Suite ===\n\n";

    // 1. Constructor & basic state
    std::cout << "--- Test 1: Constructor ---\n";
    Stack s(5);
    std::cout << "isEmpty: " << (s.isEmpty() ? "true" : "false") << " (expected: true)\n";
    std::cout << "isFull:  " << (s.isFull()  ? "true" : "false") << " (expected: false)\n\n";

    // 2. Push & peek
    std::cout << "--- Test 2: Push & Peek ---\n";
    s.push('A'); s.push('B'); s.push('C');
    std::cout << "peek: '" << s.peek() << "' (expected: 'C')\n";
    std::cout << "isEmpty: " << (s.isEmpty() ? "true" : "false") << " (expected: false)\n\n";

    // 3. Pop
    std::cout << "--- Test 3: Pop ---\n";
    s.pop();
    std::cout << "peek after pop: '" << s.peek() << "' (expected: 'B')\n";
    s.pop();
    std::cout << "peek after two pops: '" << s.peek() << "' (expected: 'A')\n\n";

    // 4. isFull
    std::cout << "--- Test 4: isFull ---\n";
    s.push('D'); s.push('E'); s.push('F'); s.push('G'); // A + 4 = 5
    std::cout << "isFull: " << (s.isFull() ? "true" : "false") << " (expected: true)\n\n";

    // 5. Underflow
    std::cout << "--- Test 5: Pop / Peek on empty stack ---\n";
    Stack small(2);
    small.pop(); // prints "Stack underflow"
    char u2 = small.peek(); // prints "Stack underflow", returns '\0'
    std::cout << "peek on empty returned: '" << u2 << "' (expected: '\\0')\n\n";

    // 6. Copy constructor
    std::cout << "--- Test 6: Copy constructor (deep copy) ---\n";
    Stack original(3);
    original.push('X'); original.push('Y'); original.push('Z');
    Stack copy(original);
    std::cout << "copy.peek: '" << copy.peek() << "' (expected: 'Z')\n";
    copy.pop();
    std::cout << "original.peek after mutating copy: '"
              << original.peek() << "' (expected: 'Z')\n\n";

    // 7. Resize (grow)
    std::cout << "--- Test 7: resize() grow ---\n";
    Stack rs(3);
    rs.push('1'); rs.push('2'); rs.push('3');
    rs.resize(6);
    rs.push('4'); rs.push('5'); rs.push('6');
    std::cout << "isFull: " << (rs.isFull() ? "true" : "false") << " (expected: true)\n";
    std::cout << "peek: '" << rs.peek() << "' (expected: '6')\n\n";

    // 8. Destructor (implicit, via scope)
    std::cout << "--- Test 8: Destructor ---\n";
    {
        Stack temp(4);
        temp.push('T');
    }
    std::cout << "Stack destructor ran without crash\n\n";

    std::cout << "=== All tests complete ===\n";
    return 0;
}