#include "sortingAlgo.h"

int getMax(const std::vector<int>& arr)
{
    int mx = arr[0];

    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];

    return mx;
}

void countSort(std::vector<int>& arr, int exp, bool asc)
{
    int n = arr.size();
    std::vector<int> buckets[10];

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        buckets[digit].push_back(arr[i]);
    }

    int index = 0;

    if (asc)
    {
        for (int bucket = 0; bucket < 10; bucket++)
        {
            for (int value : buckets[bucket])
            {
                arr[index] = value;
                index++;
            }
        }
    }
    else
    {
        for (int bucket = 9; bucket >= 0; bucket--)
        {
            for (int value : buckets[bucket])
            {
                arr[index] = value;
                index++;
            }
        }
    }
}

void radixSort(std::vector<int>& arr, bool asc)
{
    if (arr.empty())
        return;

    int max = getMax(arr);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, exp, asc);
}