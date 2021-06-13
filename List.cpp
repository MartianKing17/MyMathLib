//
// Created by maxim on 23.03.20.
//

#include "List.h"

template <typename T>
List<T>::List()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->len = 0;
}

template <typename T>
List<T>::List(const List<T> &other)
{
    if(this->head != nullptr)
    {
        clear();
    }

    this->head = other.head;
    this->tail = other.tail;
    this->len  = other.len;
}

template <typename T>
List<T>::List(List<T> &&other) noexcept
{
    if(this->head != nullptr)
    {
        clear();
    }

    this->head = other.head;
    this->tail = other.tail;
    this->len  = other.len;
    other.head = nullptr;
    other.tail = nullptr;
    other.len  = 0;
}

template <typename T>
List<T> & List<T>::operator =(const List<T> & other)
{
    if(this->head != nullptr)
    {
        clear();
    }

    this->head = other.head;
    this->tail = other.tail;
    this->len  = other.len;

    return *this;
}


template <typename T>
List<T> & List<T>::operator =(List<T> && other) noexcept
{
    if(this->head != nullptr)
    {
        clear();
    }

    this->head = other.head;
    this->tail = other.tail;
    this->len  = other.len;
    other.head = nullptr;
    other.tail = nullptr;
    other.len  = 0;

    return *this;
}

template <typename T>
bool List<T>::empty()
{
    if(this->head == nullptr)
    {
        return false;
    }

    return true;
}


template <typename T>
T List<T>::front()
{
    return head->data;
}


template <typename T>
T List<T>::back()
{
    return tail->prev->data;
}


template <typename T>
size_t List<T>::size()
{
    return size;
}

template <typename T>
typename  List<T>::iterator List<T>::begin()
{
    iterator it(this->head);
    return it;
}

template <typename T>
typename  List<T>::iterator List<T>::end()
{
    iterator it(this->tail);
    return it;
}

template <typename T>
void List<T>::clear() noexcept
{
    Node * current = head;
    Node * next    = head->next;
    head = nullptr;

    while(current != tail)
    {
        delete current;
        current = next;
        next = next->next;
    }
}


template <typename T>
void List<T>::push_front(const T & data)
{
    Node * new_node = new Node;
    new_node->data = data;
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    ++this->len;
}


template <typename T>
void List<T>::push_back(const T & data)
{
    Node * new_node = new Node;
    new_node->data = data;
    tail->prev->next = new_node;
    tail->prev = new_node;
    ++this->len;
}


template <typename T>
void List<T>::pop_front()
{
    Node * del = head;
    head->next->prev = nullptr;
    head = head->next;
    delete del;
    del = nullptr;
    --this->len;
}


template <typename T>
void List<T>::pop_back()
{
    Node * del = tail->prev;
    tail->prev = tail->prev->prev;
    tail->prev->next = nullptr;
    delete del;
    del = nullptr;
    --this->len;
}


template <typename T>
void List<T>::reverse() noexcept
{
    Node *prev, *next, *currect;
    prev = tail->prev->next;
    next = tail->prev->prev;
    currect = tail->prev;
    head = currect;

    while (currect != nullptr)
    {
        currect->next = next;
        currect->prev = prev;
        next = currect->next->prev;
        prev = currect->next->next;
        currect = currect->next;
    }
}


template <typename T>
void List<T>::merge(List<T> && other)
{

}


template <typename T>
void List<T>::sort()
{

}

template <typename T>
List<T>::~List()
{
    clear();
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
List<T>::iterator::iterator(Node * node)
{
    this->node = node;
    return *this;
}


template <typename T>
typename List<T>::iterator & List<T>::iterator::operator=(const iterator &other)
{
    this->node = other.node;
    return *this;
}


template <typename T>
typename List<T>::iterator & List<T>::iterator::operator=(iterator && other)
{
    this->node = other.node;
    other.node = nullptr;
    return *this;
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator++()
{
    if(node->next == nullptr)
    {
        std::exception_ptr e;
        throw e;
    }

    node = node->next;
    return *this;
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator--()
{
    if(node->prev == nullptr)
    {
        std::exception_ptr e;
        throw e;
    }

    node = node->prev;
    return *this;
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator++(int)
{
    List<T>::iterator temp = node;
    ++(*this);
    return temp;
}


template <typename T>
typename List<T>::iterator & List<T>::iterator::operator--(int)
{
    List<T>::iterator temp = node;
    --(*this);
    return temp;
}

template <typename T>
T & List<T>::iterator::operator*()
{
    return this->node->data;
}


template <typename T>
List<T>::iterator::~iterator()
{
    this->node = nullptr;
}