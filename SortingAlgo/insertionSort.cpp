#include "sortingAlgo.h"
#include <vector>

void insertionSort(std::vector<int>& arr, bool asc){

    std::size_t n = arr.size();
    for(std::size_t i = 1; i < n; i++){
        int temp = arr[i];
        std::size_t current_index = i;
        //we are chekcing if j>0 starting from j=i instead of
        //j>=0 starting from j=i-1 since size_t can't be negative
        // so j>=0 will always be true  
        for(std::size_t j = i; j > 0; j--){
            
            if(asc){
                if(arr[j-1] > temp){
                    arr[j] = arr[j-1];
                    current_index = j-1; 
                }
            }
            else{
                if(arr[j-1] < temp){
                    arr[j] = arr[j-1]; 
                    current_index = j-1; 

                }
            }
        
        }

        arr[current_index] = temp;

    }

}