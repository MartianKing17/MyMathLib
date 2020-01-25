//
// Created by maxim on 31.10.19.
//

#include "Matrix.h"
#include "math.h"

namespace mylib
{

    template <typename T>
    Matrix<T>::Matrix(size_t n, T value)
    {
        this->size = n;

        this->array = new T[this->size];

        for (int i = 0; i < this->size; i++)
        {
            this->array[i] = new T[this->size];
        }

        for (std::size_t i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
            {
                this->array[i][j] = value;
            }
        }

    }

    template <typename T>
    T& Matrix<T>::operator[](const std::size_t i)
    {
        return this->array[i];
    }

    template <typename T>

    void Matrix<T>::free_arr(T *arr, const std::size_t len)
    {
        for (int i = 0; i < len; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }

    template <typename T>
    T ** Matrix<T>::rewriteArray(std::size_t i_ignore, std::size_t j_ignore, const T *arr, const std::size_t len_arr)
    {
        const std::size_t len_mas = len_arr + 1;

        T ** mas = new T[len_mas];

        for(size_t i = 0; i<len_mas; i++)
        {
            mas[i] = new T[len_mas];
        }

        for (int i = 0; i < len_arr; i++)
        {

            if(i == i_ignore)
            {
                continue;
            }

            for (int j = 0; j < len_arr; j++)
            {
                if(j == j_ignore)
                {
                    continue;
                }

                mas[i][j] = arr[i][j];
            }
        }

        return mas;
    }

    template <typename T>
    T Matrix<T>::det(T **deter, std::size_t len)
    {
        T ** arr;

        long long sum = 0;

        if(len == 2)
        {
            return deter[0][0]*deter[1][1] - deter[1][0]*deter[0][1];
        }

        for (int j = 0; j < len; j++)
        {
            arr = rewriteArray(0, j, deter, len);
            sum += mylib::pow(-1, j)*deter[0][j] * det(arr, len-1);
            free_arr(arr, len - 1);
        }

        return sum;

    }


    template <typename T>
    T * & Matrix<T>::operator+(const Matrix<T> &other)
    {
        T * arr = new T[this->size];
        const std::size_t len = this->size;

        for (int i = 0; i < len; ++i)
        {
            arr[i] = this->array[i] + other.array[i];
        }

        return arr;
    }

    template <typename T>
    Matrix<T> & Matrix<T>::operator+(Matrix<T> && other)
    {

    }

    template <typename T>
    Matrix<T> & Matrix<T>::operator-(const Matrix<T> &other)
    {

    }

    template <typename T>
    Matrix<T> & Matrix<T>::operator-(Matrix<T> && other)
    {

    }

    template <typename T>
    Matrix<T> & Matrix<T>::operator*(const Matrix<T> &other)
    {

    }

    template <typename T>
    Matrix<T> & Matrix<T>::operator*(Matrix<T> && other)
    {

    }

    template <typename T>
    Matrix<T> & Matrix<T>::operator*(T value)
    {

    }

    template <typename T>
    Matrix<T> & Matrix<T>::operator/(T value)
    {

    }

    template <typename T>
    T Matrix<T>::operator~() const
    {
        return det(this->array,this->size);
    }

    template <typename T>
    Matrix<T>::~Matrix()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] array[i];
            array[i] = nullptr;
        }

       delete[] array;
       this->array = nullptr;
    }
}