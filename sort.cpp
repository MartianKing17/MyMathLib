//
// Created by maxim on 16.01.20.
//

#include "sort.h"

template <typename T>
void swap(T * first, T * second)
{
    T swap = *second;
    *second = *first;
    *first = swap;
}

template <typename T>
void swap(T * array, std::size_t first_elem, std::size_t second_elem)
{
    T swap = array[second_elem];
    array[second_elem] = array[first_elem];
    array[first_elem] = swap;
}


template <typename T>
T * bubble_sort(T * data, std::size_t len)
{
    for (std::size_t i = 0; i < len-1; ++i)
    {
        for (std::size_t j = 0; j < len-1; ++j)
        {
            if(i == j)
                continue;

            if(data[i] > data[j])
            {
                swap(data, i, j);
            }
        }
    }

    return data;
}

template <typename T>
T * insert(T * arr, std::size_t j, std::size_t i, std::size_t len)
{
    const std::size_t index = i;
    T * new_arr = new T[len];

    for (int k = 0; k <= j; ++k)
    {
        if(arr[k] > arr[i])
        {
            new_arr[k] =  arr[i];
            continue;
        }

        new_arr[k] = arr[k];
    }

    for (int l = ++j; l < len; ++l)
    {
        if(index == l)
        {
            continue;
        }

        new_arr[l] = arr[l];
    }

    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    return arr;
}


template <typename T>
T * insertion_sort(T * data, std::size_t len)
{
    std::size_t j = 0;

    for(std::size_t i = 0; i < len; i++)
    {
        if(data[i] > data[i+1])
        {
           data=insert(data, j, i, len);
        }

        ++j;
    }

    return data;
}

template <typename T>
std::size_t find_index_of_smallest_form_index(T * arr, std::size_t len, std::size_t index_of_smallest_value = 0)
{
    for (std::size_t i = 0; i < len; ++i)
    {
        if(arr[index_of_smallest_value] > arr[i])
            index_of_smallest_value = i;
    }

    return index_of_smallest_value;
}

template <typename T>
T * swap_data(T * arr, std::size_t min_value_index, std::size_t current_index,std::size_t len)
{
    T * new_arr = new T[len];

    for (std::size_t i = 0; i < current_index; ++i)
    {
        new_arr[i] = arr[i];
    }

    new_arr[++current_index] = arr[min_value_index];

    for (int j = ++(++current_index); j < len; ++j)
    {
        if(j == min_value_index)
        {
            continue;
        }

        new_arr[j] = arr[j];
    }


}


template <typename T>
T * sort_by_selection(T * data, std::size_t len)
{
    std::size_t index_of_smallest_value = find_index_of_smallest_form_index(data, len);

    for (std::size_t current_index = 0; current_index < len; ++current_index)
    {
        data = swap_data(data, index_of_smallest_value, current_index, len);
        index_of_smallest_value = find_index_of_smallest_form_index(data, len, index_of_smallest_value);
    }

    return data;
}

template <typename T>
void copy_arr(T * to_copy, T * from_copy, std::size_t start_index, std::size_t end_index)
{
    for (size_t i = 0, j =start_index; j < end_index; i++,j++)
    {
        to_copy[i] = from_copy[j];
    }
}

template<typename T>
void min_max(T & num_1, T & num_2) //return num_1 - min, num_2 - max
{
    if (num_1 > num_2)
    {
        swap(num_1, num_2);
    }
}

template<typename T>
void merge_array(T * left, T * right, std::size_t len_left, std::size_t len_right)
{
    T * merge_arr = new T[len_left + len_right];

    if(right[len_right - 1] < left[len_left - 1])
    {
        size_t i = 0;

        for (size_t j = 0; j < len_right; ++j,++i)
        {
            merge_arr[i] = right[j];
        }

        for (size_t j = 0; j < len_left; ++j, ++i)
        {
            merge_arr[i] = left[j];
        }
    }
    else if(left[len_left - 1] < right[len_right - 1]) {
        size_t i = 0;

        for (size_t j = 0; j < len_left; ++j, ++i) {
            merge_arr[i] = left[j];
        }

        for (size_t j = 0; j < len_right; ++j, ++i) {
            merge_arr[i] = right[j];
        }
    }
    else
    {
        std::size_t left_index = 0;
        std::size_t right_index = 0;

        for (size_t j = 0; j < len_left + len_right; ++j)
        {
            if (left[left_index] > right[right_index]  && right_index != len_right)
            {
                merge_arr[j] = right[right_index];
                ++right_index;
            }
            else if (left[left_index] <= right[right_index] && left_index != len_left)
            {
                merge_arr[j] = left[left_index];
                ++left_index;
            }
            else if (left[left_index] > right[right_index]  && right_index == len_right)
            {
                merge_arr[j] = left[left_index];
                ++left_index;
            }
            else if (left[left_index] <= right[right_index] && left_index == len_left)
            {
                merge_arr[j] = right[right_index];
                ++right_index;
            }
        }
    }

    return merge_arr;
}

template<typename T>
T * merge_sort(T * data, std::size_t len)
{
    if(len <= 2)
    {
        min_max(data[0] , data[1]);
    }

    const std::size_t split_arr_len = len/2;
    T * left = new T[split_arr_len];
    T * right = new T[split_arr_len];
    copy_arr(left, data, 0, split_arr_len);
    copy_arr(right, data, split_arr_len, len);
    merge_sort(left, split_arr_len);
    merge_sort(right, split_arr_len);
    merge_array(left, right, data);
}
