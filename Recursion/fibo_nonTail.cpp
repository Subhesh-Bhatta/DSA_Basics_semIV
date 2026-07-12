#include <iostream>
#include <chrono>

long long int iterativeFibonacci(long long int);
long long int recursiveFibonacci(long long int);


int main(){

    long long int input;

    std::cout << "To what number to get the fibonacci series of?";
    std::cin >> input;

    auto startIterative = std::chrono::steady_clock::now();
    auto resultIterative = iterativeFibonacci(input);
    auto endIterative = std::chrono::steady_clock::now();
    auto diffIterative = endIterative-startIterative;

    std::cout << "Iterative approach says the" << input << "th term in the fibonacci sequence is " << resultIterative << '\n'; 
    std::cout << "Time taken for iterative approach is " << std::chrono::duration<double, std::milli>(diffIterative).count() << " ms" << '\n' ;
    std::cout << "\n";

    
    auto startRecursive = std::chrono::steady_clock::now();
    auto resultRecursive = recursiveFibonacci(input);
    auto endRecursive = std::chrono::steady_clock::now();
    auto diffRecursive = endRecursive - startRecursive;
    
    std::cout << "Recursive approach says the" << input << "th term in the fibonacci sequence is " << resultRecursive << '\n'; 
    std::cout << "Time taken for recursive approach is " << std::chrono::duration<double, std::milli>(diffRecursive).count() << " ms" << '\n' ;


    return 0;
}


long long int iterativeFibonacci(long long int n){
    long long int a=0,b=1,temp;
    for(int i = 1; i<=n; i++){
        if (i==n){
            return b;
        }
        temp = b;
        b+=a;
        a = temp;
    }
    return b; // just adding this so we don't get
    //fibo_nonTail.cpp:49:1: warning: control reaches end of non-void function [-Wreturn-type] 
}

long long int recursiveFibonacci(long long int n){
    if (n==1 || n==2){
        return 1;
    }
    else if (n<=0)
    {
        return 0;
    }
    
    return recursiveFibonacci(n-1)+recursiveFibonacci(n-2);
} 