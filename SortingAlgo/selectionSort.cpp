#include "sortingAlgo.h"
#include <vector>

void selectionSort(std::vector<int>& arr, bool asc = true){
    
    std::size_t n = arr.size();

    for(std::size_t i = 0; i < n-1; i++){
        int current_index = i;
        for(std::size_t j = i+1; j<n; j++){

            if(asc){
                if(arr[j] < arr[current_index]){
                    current_index = j;
                }
            }
            else{
                if(arr[j] > arr[current_index]){
                    current_index = j;
                }
            }


        }
        if(current_index!=i){
            std::swap(arr[current_index], arr[i]);
        }
    }

}