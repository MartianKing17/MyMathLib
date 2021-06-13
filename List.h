//
// Created by maxim on 23.03.20.
//

#ifndef MYMATHLIB_LIST_H
#define MYMATHLIB_LIST_H

#include <iostream>
#include <exception>

template <typename T>
class List
{
    struct Node
    {
        T data;
        Node * next;
        Node * prev;
    };

    Node * head;
    Node * tail;
    std::size_t len;

public:

    class iterator
    {
        explicit iterator(Node * node);
        Node * node;
    public:
        iterator &operator = (const iterator & other);
        iterator &operator = (iterator && other);
        iterator &operator++();
        iterator &operator--();
        iterator &operator++(int);
        iterator &operator--(int);
        T &operator*();
        ~iterator();
    };

    List();
    List(const List<T> & other);
    List(List<T> && other) noexcept;
    List & operator =(const List<T> & other);
    List & operator =(List<T> && other) noexcept;
    bool empty();
    T front();
    T back();
    iterator begin();
    iterator end();
    size_t size();
    void clear() noexcept;
    void push_front(const T & data);
    void push_back(const T & data);
    void pop_front();
    void pop_back();
    void reverse() noexcept;
    void merge(List<T> && other);
    void sort();
    ~List();
};


#endif //MYMATHLIB_LIST_H
