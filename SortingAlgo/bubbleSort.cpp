#include "sortingAlgo.h"
#include <vector>

void bubbleSort(std::vector<int>& arr, bool asc){

    std::size_t n = arr.size();
    bool swapped;

    for(std::size_t i = 0; i < n-1; i++){
        swapped = false;
        // you can loop til n-1 technically, but its pointless
        // since every outer (i) loop, you sort an element in the last index, then 
        // second last, and so on
        for(std::size_t j = 0; j < n - i - 1; j++){

            if(asc){
                if(arr[j] > arr[j+1]){
                    std::swap(arr[j],arr[j+1]);
                    swapped = true;
                }
            }
            // for descending, we just swap the smallest element down to last position
            else{
                if(arr[j+1] > arr[j]){
                    std::swap(arr[j+1],arr[j]);
                    swapped = true;
                }
            }

        }

        if(!swapped){
            break;
        }


    }
}
