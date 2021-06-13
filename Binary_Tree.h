//
// Created by maxim on 23.03.20.
//

#ifndef MYMATHLIB_BINARY_TREE_H
#define MYMATHLIB_BINARY_TREE_H

/*
    Source:
        https://ru.wikipedia.org/wiki/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D0%BE%D0%B5_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE_%D0%BF%D0%BE%D0%B8%D1%81%D0%BA%D0%B0
*/


template <typename T>
class Binary_Tree
{
    struct Node
    {
        int key;
        T data;
        Node * left;
        Node * right;
    };

public:
    void insert(int key, T data);
    T max();
    T min();
    void remove(int key);
};


#endif //MYMATHLIB_BINARY_TREE_H
