#include <vector>
#include <stdexcept>

//return the index of the item in the array if found, else throws an exception
//best for unsorted list/ a random one which we know nothing about
template<typename T>
std::size_t linearSearch(std::vector<T>& arr, T data)
{
    for (std::size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == data)
            return i;
    }

    throw std::out_of_range("Data not found");
}