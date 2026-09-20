#include "sortingAlgo.h"

void merge(std::vector<int>& arr, int left, int mid, int right, bool asc){
    
    std::vector<int> temp;

    int i = left;
    int j = mid+1;
    
    while(i<=mid && j<=right){
        if(asc?arr[i] <= arr[j] : arr[i] >= arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    while (j <= right) {
        temp.push_back(arr[j++]);
    }

    for(int k = 0; k < temp.size(); k++){
        arr[left+k] = temp[k];
    }


}

void mergeSort(std::vector<int>& arr, int left, int right, bool asc){
    
    if (right == -1){
        right = arr.size()-1;
    }

    if(left>=right){
        return;
    }


    int mid = (left + right)/2;

    mergeSort(arr, left, mid, asc);
    mergeSort(arr, mid + 1, right, asc);

    merge(arr, left, mid, right, asc);

}