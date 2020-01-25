//
// Created by maxim on 31.10.19.
//

#ifndef MYMATHLIB_MATRIX_H
#define MYMATHLIB_MATRIX_H

#include <iostream>


namespace mylib
{
    template <typename T>
    class Matrix
    {
        std::size_t size;
        T ** array;

        void free_arr(T *arr, const std::size_t len);//-
        T ** rewriteArray(std::size_t i_ignore, std::size_t j_ignore, const T *arr, const size_t len_arr);// -
    public:
        explicit Matrix(size_t n = 2, T value = 0);//+
        T * &operator+(const Matrix<T> &other);
        Matrix<T> &operator+(Matrix<T> && other);
        Matrix<T> &operator-(const Matrix<T> &other);
        Matrix<T> &operator-(Matrix<T> && other);
        Matrix<T> &operator*(const Matrix<T> &other);
        Matrix<T> &operator*(Matrix<T> && other);
        Matrix<T> &operator*(T value);
        Matrix<T> &operator/(T value);
        Matrix<T> &operator[](std::size_t i);//+
        T operator~() const;//-
        ~Matrix();//+
    };
}




#endif //MYMATHLIB_MATRIX_H
