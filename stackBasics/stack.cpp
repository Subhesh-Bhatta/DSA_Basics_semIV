#include <iostream>
#include <stdexcept> //for underflow and overflow errors

template <typename T>
class Stack{
    private:
        int top=-1; //Index of top element of stck
        int size; //Capacity of array
        T* arr; //first element of a dynamically allocated array, and the element if of type T

    public:
        // Constructor for stack
        Stack(int n){
            this->size = n;
            //Allocating T (can be char, int or anything) sized memory for array of size 'size'
            // arr = new T[size];
            this->arr = new T[size]; //same as above, just to keep style consistent 
        }

        // copy constructor (deep copy)
        Stack(const Stack& other){
            this->size = other.size;

            this->arr = new T[this->size];

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

            T* newArr = new T[newSize];

            int limit = (top < newSize - 1) ? top : newSize - 1;

            for(int i = 0; i <= limit; i++){
                newArr[i] = arr[i];
            }

            delete[] arr;

            arr = newArr;
            size = newSize;
            top = limit;
        }


        bool isEmpty() const{
            return top == -1;
            //same as return top==-1?true:false
        }

        bool isFull() const{
            return top == size-1;
        }

        void push(T x){
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
                // std::cout << "Stack underflow\n";
                throw std::underflow_error("Stack underflow");
            }
            else{
                top-=1;
            }
        }

        T peek() const{
            if (isEmpty()){
                std::cout << "Stack underflow\n";
                // return '\0'; 
                // since I am using a template instead of a specific type, making it so that it returns garbage value of multiple types is unfeasible,
                // so, throwing an exception is better
                // or we can just do 
                // return T{}
                throw std::underflow_error("Stack underflow");
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
    std::cout << "========== Stack Test Suite ==========\n\n";

    // 1. Constructor & initial state
    std::cout << "[Test 1] Constructor\n";
    Stack<int> s(5);
    std::cout << "isEmpty(): " << (s.isEmpty() ? "PASS" : "FAIL") << '\n';
    std::cout << "isFull():  " << (!s.isFull() ? "PASS" : "FAIL") << "\n\n";



    // 2. Push & Peek
    std::cout << "[Test 2] Push & Peek\n";
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element = " << s.peek()
              << " (Expected: 30)\n\n";



    // 3. Pop
    std::cout << "[Test 3] Pop\n";

    s.pop();

    std::cout << "Top after pop = " << s.peek()
              << " (Expected: 20)\n";

    s.pop();

    std::cout << "Top after second pop = " << s.peek()
              << " (Expected: 10)\n\n";



    // 4. isFull
    std::cout << "[Test 4] isFull\n";

    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    std::cout << "isFull(): "
              << (s.isFull() ? "PASS" : "FAIL")
              << "\n\n";



    // 5. Underflow
    std::cout << "[Test 5] Underflow Exceptions\n";

    Stack<char> small(2);

    try {
        small.pop();
        std::cout << "FAIL : pop() should have thrown.\n";
    }
    catch(const std::underflow_error& e){
        std::cout << "PASS : " << e.what() << '\n';
    }

    try{
        small.peek();
        std::cout << "FAIL : peek() should have thrown.\n";
    }
    catch(const std::underflow_error& e){
        std::cout << "PASS : " << e.what() << '\n';
    }

    std::cout << '\n';



    // 6. Copy Constructor
    std::cout << "[Test 6] Copy Constructor (Deep Copy)\n";

    Stack<char> original(3);

    original.push('X');
    original.push('Y');
    original.push('Z');

    Stack<char> copy(original);

    std::cout << "Copy top = "
              << copy.peek()
              << " (Expected: Z)\n";

    copy.pop();

    std::cout << "Original top after modifying copy = "
              << original.peek()
              << " (Expected: Z)\n";

    std::cout << "Copy top after pop = "
              << copy.peek()
              << " (Expected: Y)\n\n";



    // 7. Resize Grow
    std::cout << "[Test 7] Resize (Grow)\n";

    Stack<int> rs(3);

    rs.push(1);
    rs.push(2);
    rs.push(3);

    rs.resize(6);

    rs.push(4);
    rs.push(5);
    rs.push(6);

    std::cout << "isFull(): "
              << (rs.isFull() ? "PASS" : "FAIL")
              << '\n';

    std::cout << "Top = "
              << rs.peek()
              << " (Expected: 6)\n\n";



    // 8. Resize Shrink
    std::cout << "[Test 8] Resize (Shrink)\n";

    rs.resize(2);

    std::cout << "Top after shrink = "
              << rs.peek()
              << " (Expected: 2)\n";

    std::cout << "isFull(): "
              << (rs.isFull() ? "PASS" : "FAIL")
              << "\n\n";



    // 9. Destructor
    std::cout << "[Test 9] Destructor\n";

    {
        Stack<double> temp(5);

        temp.push(1.1);
        temp.push(2.2);
    }

    std::cout << "PASS : Destructor executed without crash.\n\n";



    std::cout << "========== All Tests Finished ==========\n";

    return 0;
}