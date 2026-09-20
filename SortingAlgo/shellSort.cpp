#include "sortingAlgo.h"

void shellSort(std::vector<int>& arr, bool asc){

    int n = arr.size();

    for(int gap = n/2; gap > 0; gap/=2){
        for(int i = gap; i < n; i++){

            int j = i;
            if(asc){
                while(j >= gap && arr[j-gap] > arr[j]){
                    std::swap(arr[j],arr[j-gap]);
                    j-=gap;
                }
            }
            else{
                while(j >= gap && arr[j-gap] < arr[j]){
                    std::swap(arr[j],arr[j-gap]);
                    j-=gap;
                }
            }
        }
    }

}
