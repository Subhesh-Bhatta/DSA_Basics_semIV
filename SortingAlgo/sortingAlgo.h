#pragma once
#include <vector>
#include <cmath>

void bubbleSort(std::vector<int>& arr, bool asc = true);

void selectionSort(std::vector<int>& arr, bool asc = true);

void insertionSort(std::vector<int>& arr, bool asc = true);

//also called partition-exchange sort
//TODO: this is currently only Lorunto partioning scheme, make one for Hoare as well later
void quickSort(std::vector<int>& arr, int min=0, int max = -1, bool asc = true);

//generalizaton and a better version of insertion Sort
// also caleld diminishing increment sort
void shellSort(std::vector<int>& arr, bool asc = true);

void mergeSort(std::vector<int>& arr, int left = 0, int right = -1, bool asc = true);

void radixSort(std::vector<int>& arr, bool asc = true);

void heapSort(int arr[], int n);
