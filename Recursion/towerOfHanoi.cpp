#include <iostream>
#include <exception>

void printMoves(int diskNo, int start, int end){
    char startChar = 'A' + start - 1; // if start = 1, startChar = A + 0 = A; if start = 2, startChar = A + 1 = B; this works due to ASCII value addition
    char endChar = 'A' + end - 1; 
    std::cout <<"Move disk "<< diskNo << " from " << startChar << " to " << endChar << ".\n";
}

void TowerOfHanoi (int disks, int startingRod, int destinationRod){
    
    // let us say {1,2,3} is the set of possible values for rod numbering. 
    // We will also know two numbers in this set, with one being missing. 
    // So, we need to create just one equation which relates all three of these values, and solving that equation will always give us the missing value.
    // Note that the equation must relate these values, using a constant value
    // e.g sum = 1 + 2 + 3 = 6. So, using equation sum = missing + known_x + known_y => missing = sum - (known_x + known_y), we can always solve for 'missing'.
    // We can't just make an equation out of only known_x, known_y, and missing, since the elements might not have any relation without introducing a new variable.
    // Similarly, we can also use product = missing*known_x*known_y to make intermediateRod = (3*2*1)/(startingRod * destinationRod)
    // Expanding on this, for set {1,2,3,4} from which we need to figure out two missing values given two values, we can make two equations,
    // one being product = 24 = missing_x * missing_y * known_x * known_y, and another being sum = 10 = missing_x + missing_y + known_x + known_y
    int intermediateRod = 6 - (startingRod + destinationRod);
    
    if(disks == 1){
        printMoves(1, startingRod, destinationRod);
        return;
    }
    TowerOfHanoi(disks-1, startingRod, intermediateRod);

    printMoves(disks, startingRod, destinationRod);

    TowerOfHanoi(disks - 1, intermediateRod, destinationRod);

}


int main (){

    int inputDisks, startingRod, destinationRod;
    
    std::cout << "How many disks do you want to solve the Tower of Hanoi problem for?" << '\n';
    std::cin >> inputDisks;

    std::cout << "What do you want the starting rod to be? (1/2/3)" << '\n';
    std::cin >> startingRod;
    std::cout << "What do you want the destination rod to be? (1/2/3), (Don't make this the same as starting rod)" << '\n';
    std::cin >> destinationRod;

    TowerOfHanoi(inputDisks, startingRod, destinationRod);


    return 0;
}