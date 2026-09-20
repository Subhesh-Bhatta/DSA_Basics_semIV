#pragma once
#include <vector>

void bubbleSort(std::vector<int>& arr, bool asc = true);

void selectionSort(std::vector<int>& arr, bool asc = true);

void insertionSort(std::vector<int>& arr, bool asc = true);

 //also called partition-exchange sort
void quickSort(std::vector<int>& arr, int min=0, int max = -1, bool asc = true);

void shellSort(int arr[], int n);

void heapSort(int arr[], int n);

void mergeSort(int arr[], int n);

void radixSort(int arr[], int n);
