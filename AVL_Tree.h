//
// Created by maxim on 23.03.20.
//

#ifndef MYMATHLIB_AVL_TREE_H
#define MYMATHLIB_AVL_TREE_H

/*
    Source:
        https://habr.com/ru/post/150732/
*/

#include <utility>
#include <cstddef>


template <typename T>
class AVL_Tree
{
    struct Node
    {
        T data;
        unsigned char height;
        Node * left;
        Node * right;
    };

    Node * balance();
    Node *root;

public:
    void insert(T data);
    T max();
    T min();
    void remove(T data);



};


#endif //MYMATHLIB_AVL_TREE_H
