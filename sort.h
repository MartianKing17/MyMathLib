//
// Created by maxim on 16.01.20.
//

#ifndef MYMATHLIB_SORT_H
#define MYMATHLIB_SORT_H

#include <iostream>

template <typename T>
void swap(T * first, T * second);

template <typename T>
void swap(T * array, std::size_t first_elem, std::size_t second_elem);

template <typename T>
T * bubble_sort(T * data, std::size_t len);

template <typename T>
T * insertion_sort(T * data, std::size_t len);

template <typename T>
T * sort_by_selection(T * data, std::size_t len);

#endif //MYMATHLIB_SORT_H
