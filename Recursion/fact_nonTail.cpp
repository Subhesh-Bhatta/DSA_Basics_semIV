#include <iostream>
#include <chrono>

long long int iterativeFactorial(long long int);
long long int recursiveFactorial(long long int);

int main(){

    long long int input;

    std::cout << "What number to get the factorial of?";
    std::cin >> input;

    
    auto startIterative = std::chrono::steady_clock::now();
    auto resultIterative = iterativeFactorial(input);
    auto endIterative = std::chrono::steady_clock::now();
    auto diffIterative = endIterative-startIterative;
    
    std::cout << "Iterative approach says factorial of " << input << " is " << resultIterative << '\n'; 
    std::cout << "Time taken for iterative approach is " << std::chrono::duration<double, std::milli>(diffIterative).count() << " ms" << '\n' ;
    std::cout << "\n";


    auto startRecursive = std::chrono::steady_clock::now();
    auto resultRecursive = recursiveFactorial(input);
    auto endRecursive = std::chrono::steady_clock::now();
    auto diffRecursive = endRecursive - startRecursive;
    
    std::cout << "Recursive approach says factorial of " << input << " is " << resultRecursive << '\n'; 
    std::cout << "Time taken for recursive approach is " << std::chrono::duration<double, std::milli>(diffRecursive).count() << " ms" << '\n' ;

    
    return 0;
}


long long int iterativeFactorial(long long int n){
    long long int factorial = 1;
    for(long long int i=n; i>1 ; i--){
        factorial*=i;
    }
    return factorial;
};

long long int recursiveFactorial(long long int n){
    if (n==1){
        return 1;
    }
    else{
        return n*recursiveFactorial(n-1);
    }
};