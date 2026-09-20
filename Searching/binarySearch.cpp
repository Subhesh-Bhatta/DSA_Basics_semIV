#include <vector>
#include <stdexcept>

//return the index of the item in the array if found, else throws an exception
//best for a sorted array
template<typename T>
int binarySearch(const std::vector<T>& arr, T data, bool isAsc = true)
{
    int first = 0;
    int last = arr.size() - 1;

    while (first <= last)
    {
        int mid = first + (last - first) / 2;

        if (arr[mid] == data)
            return mid;

        if (isAsc)
        {
            if (data < arr[mid])
                last = mid - 1;
            else
                first = mid + 1;
        }
        else
        {
            if (data < arr[mid])
                first = mid + 1;
            else
                last = mid - 1;
        }
    }

    throw std::out_of_range("Data not found");
}