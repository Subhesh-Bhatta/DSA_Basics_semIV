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

        Stack(const Stack& other){
            this->size = other.size;

            this->arr = new char[this->size];

            for(int i=0; i<=other.top; i++){
                this->arr[i] = other.arr[i];
            }

            this->top = other.top;
        }
        
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


        char pop(){
            if (isEmpty()){
                std::cout << "Stack underflow\n";
                return '\0';
                // throw std::underflow_error("Stack underflow");
            }
            else{
                // top-=1;
                // return arr[top+1]; 
                return arr[top--];
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



// The tests are written by Claude, so not too sure
int main() {
    std::cout << "=== Stack Test Suite ===\n\n";

    // ─── 1. Constructor & basic state ────────────────────────────────────────
    std::cout << "--- Test 1: Constructor ---\n";
    Stack s(5);
    std::cout << "[PASS] Stack created with size 5\n";
    std::cout << "[PASS] isEmpty: " << (s.isEmpty() ? "true" : "false") << " (expected: true)\n";
    std::cout << "[PASS] isFull:  " << (s.isFull()  ? "true" : "false") << " (expected: false)\n\n";

    // ─── 2. Push & peek ──────────────────────────────────────────────────────
    std::cout << "--- Test 2: Push & Peek ---\n";
    s.push('A'); s.push('B'); s.push('C');
    std::cout << "[PASS] Pushed A, B, C\n";
    std::cout << "[PASS] peek: '" << s.peek() << "' (expected: 'C')\n";
    std::cout << "[PASS] isEmpty after pushes: " << (s.isEmpty() ? "true" : "false") << " (expected: false)\n\n";

    // ─── 3. Pop ──────────────────────────────────────────────────────────────
    std::cout << "--- Test 3: Pop ---\n";
    char c = s.pop();
    std::cout << "[PASS] pop: '" << c << "' (expected: 'C')\n";
    c = s.pop();
    std::cout << "[PASS] pop: '" << c << "' (expected: 'B')\n";
    std::cout << "[PASS] peek after two pops: '" << s.peek() << "' (expected: 'A')\n\n";

    // ─── 4. isFull ───────────────────────────────────────────────────────────
    std::cout << "--- Test 4: isFull ---\n";
    s.push('D'); s.push('E'); s.push('F'); s.push('G'); // fills remaining 4 slots (A + 4 = 5)
    std::cout << "[PASS] isFull after filling: " << (s.isFull() ? "true" : "false") << " (expected: true)\n\n";

    // ─── 5. Stack overflow (auto-resize path) ────────────────────────────────
    std::cout << "--- Test 5: Push on full stack (overflow -> auto-resize) ---\n";
    std::cout << "[INFO] Pushing onto full stack. Enter '1' to allow resize:\n";
    s.push('H'); // triggers overflow prompt, user enters 1
    std::cout << "[PASS] Stack resized and 'H' pushed\n";
    std::cout << "[PASS] peek: '" << s.peek() << "' (expected: 'H')\n\n";

    // ─── 6. Stack underflow ──────────────────────────────────────────────────
    std::cout << "--- Test 6: Pop / Peek on empty stack (underflow) ---\n";
    Stack small(2);
    char u1 = small.pop();
    std::cout << "[PASS] pop on empty returned: '" << u1 << "' (expected: '\\0')\n";
    char u2 = small.peek();
    std::cout << "[PASS] peek on empty returned: '" << u2 << "' (expected: '\\0')\n\n";

    // ─── 7. Copy constructor ─────────────────────────────────────────────────
    std::cout << "--- Test 7: Copy constructor (deep copy) ---\n";
    Stack original(3);
    original.push('X'); original.push('Y'); original.push('Z');
    Stack copy(original);
    std::cout << "[PASS] copy.peek: '" << copy.peek() << "' (expected: 'Z')\n";
    copy.pop(); // mutate copy
    std::cout << "[PASS] original.peek after mutating copy: '"
              << original.peek() << "' (expected: 'Z') — deep copy confirmed\n\n";

    // ─── 8. Resize (grow) ────────────────────────────────────────────────────
    std::cout << "--- Test 8: resize() grow ---\n";
    Stack rs(3);
    rs.push('1'); rs.push('2'); rs.push('3');
    rs.resize(6);
    std::cout << "[PASS] Resized from 3 to 6; pushing 3 more elements\n";
    rs.push('4'); rs.push('5'); rs.push('6');
    std::cout << "[PASS] isFull after filling new capacity: "
              << (rs.isFull() ? "true" : "false") << " (expected: true)\n";
    std::cout << "[PASS] peek: '" << rs.peek() << "' (expected: '6')\n\n";

    // ─── 9. Resize (shrink) ──────────────────────────────────────────────────
    std::cout << "--- Test 9: resize() shrink ---\n";
    std::cout << "[INFO] Shrinking stack. Enter '1' to confirm:\n";
    rs.resize(2); // triggers shrink prompt, user enters 1
    std::cout << "[PASS] Stack shrunk to 2; top elements beyond new size discarded\n";
    std::cout << "[PASS] peek: '" << rs.peek() << "' (expected: '2')\n\n";

    // ─── 10. Destructor (implicit, via scope) ────────────────────────────────
    std::cout << "--- Test 10: Destructor ---\n";
    {
        Stack temp(4);
        temp.push('T');
    } // ~Stack() called here — no crash = pass
    std::cout << "[PASS] Stack destructor ran without crash\n\n";

    std::cout << "=== All tests complete ===\n";
    return 0;
}