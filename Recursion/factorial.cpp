#include <iostream>
#include <chrono>

long long int iterativeFactorial(long long int);
long long int nonTailRecursiveFactorial(long long int);
long long int TailRecursiveFactorial(long long int, long long int);

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
    
    
    auto startNonTailRecursive = std::chrono::steady_clock::now();
    auto resultNonTailRecursive = nonTailRecursiveFactorial(input);
    auto endNonTailRecursive = std::chrono::steady_clock::now();
    auto diffNonTailRecursive = endNonTailRecursive - startNonTailRecursive;
    
    std::cout << "Non tail recursive approach says factorial of " << input << " is " << resultNonTailRecursive << '\n'; 
    std::cout << "Time taken for non tail recursive approach is " << std::chrono::duration<double, std::milli>(diffNonTailRecursive).count() << " ms" << '\n' ;
    std::cout << "\n";
    
    auto startTailRecursive = std::chrono::steady_clock::now();
    auto resultTailRecursive = TailRecursiveFactorial(input, 1);
    auto endTailRecursive = std::chrono::steady_clock::now();
    auto diffTailRecursive = endTailRecursive - startTailRecursive;
    
    std::cout << "Tail recursive approach says factorial of " << input << " is " << resultTailRecursive << '\n'; 
    std::cout << "Time taken for tail recursive approach is " << std::chrono::duration<double, std::milli>(diffTailRecursive).count() << " ms" << '\n' ;
    std::cout << "\n";
    
    
    return 0;
}


long long int iterativeFactorial(long long int n){
    long long int factorial = 1;
    for(long long int i=n; i>1 ; i--){
        factorial*=i;
    }
    return factorial;
};

// non tail recursion is the type of recursion where no further operation are left to be done after recursive call except for returning
// here multiplying by n in n*recursiveCall is left to be done, making this non tail recursion 
long long int nonTailRecursiveFactorial(long long int n){
    if (n==1){
        return 1;
    }
    else{
        return n*nonTailRecursiveFactorial(n-1);
    }
};

// tail recursion is the type of recursion where recursive call is the last operation in the function before returning
// here the multiplication is done inside the recursive call, making it so that no operations need to be done after recursively call except for returning
long long int TailRecursiveFactorial(long long int currentNo,long long int previousMultiplication){
    if(currentNo <= 1){
        return previousMultiplication;
    }
    return TailRecursiveFactorial(currentNo-1,currentNo*previousMultiplication);
}