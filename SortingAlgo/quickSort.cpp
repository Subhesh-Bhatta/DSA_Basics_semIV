#include <sortingAlgo.h>

// using int for indexes instead of size_t since I didn't 
// want to deal with the logic correction of making i = min -1
// as size_t can't be negative
// better not to use it while learning

void quickSort(std::vector<int>& arr, int min, int max, bool asc){
    
    if(arr.empty()){
        return;
    }

    // max defaults to -1, which we use as the last array index
    if(max == -1){
        max = arr.size() - 1;
    }
    
    if(min >= max){
        return;
    }

    int pivot = arr[max];
    int i = min-1;
    int j = min;
    for(; j < max; j++){
        if(asc){
            if(arr[j] < pivot){
                std::swap(arr[++i],arr[j]);
            }
        }
        else{
            if(arr[j] > pivot){
                std::swap(arr[++i],arr[j]);
            }

        }
    }
    std::swap(arr[++i], arr[max]);

    quickSort(arr, min, i-1, asc);
    quickSort(arr, i+1, max, asc);


}
