#include <vector>
#include <stdexcept>

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