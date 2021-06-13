//
// Created by maxim on 23.03.20.
//

#include "AVL_Tree.h"

template <typename T>
void AVL_Tree<T>::insert(T data)
{
    const Node * current = root;
    Node * insert = new Node();
    insert->data = data;

    while(true)
    {
        if(current->data > insert->data && current->right != nullptr)
        {
            current = current->right;
        }
        else if(current->data > insert->data && current->right == nullptr)
        {
            current->right = insert;
            insert = nullptr;
            break;
        }
        else if(current->data < insert->data && current->left != nullptr)
        {
            current = current->left;
        }
        else if(current->data > insert->data && current->left == nullptr)
        {
            current->left = insert;
            insert = nullptr;
            break;
        }
    }

    balance();
}

template <typename T>
T AVL_Tree<T>::max()
{
    if(root == nullptr)
        return 0;

    const Node * find_max = root;
    T data;

    while(find_max->right != nullptr)
    {
        data = find_max->data;
        find_max = find_max->right;
    }

    return data;
}

template <typename T>
T AVL_Tree<T>::min()
{
    if(root == nullptr)
        return 0;

    const Node * find_min = root;
    T data;

    while(find_min->left != nullptr)
    {
        data = find_min->data;
        find_min = find_min->left;
    }

    return data;
}

template <typename T>
void AVL_Tree<T>::remove(T data)
{
    if(root == nullptr)
        return;

    const Node * current = root;

    while(true)
    {
        if(current->data == data)
        {
            if (current->right != nullptr)
            {
                Node * remove = current;
                root = current->right;
                current = root;
                delete remove;
                remove = nullptr;
                break;
            }
            else if (current->left != nullptr)
            {
                Node * remove = current;
                root = current->left;
                current = root;
                delete remove;
                remove = nullptr;
                break;
            }
            else
            {
                delete current;
                current = nullptr;
                root = current;
                break;
            }
        }

        else if (current->left != nullptr)
        {
            if (current->left->data < data)
            {
                current = current->right;
                continue;
            }
            else if (current->left->data > data)
            {
                current = current->left;
                continue;
            }
            else if (current->data == data && (current->left == nullptr && current->right == nullptr))

            {

            }
        }
        else if (current->right != nullptr)
        {

        }


    }
}