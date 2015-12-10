//
//  DDList.cpp
//  Assignment1
//
//  Created by Jesper Hansen on 2015-11-15.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include "DDList.h"

template <class T>
List<T>::~List()
{
    while (first) {
        Pop_Front();
    }
}

/*
 *  Add the data to a new Node and push it last in the list
 *  by sending the data and the size of the list to the Push function
 */
template <class T>
Node<T> * List<T>::Push_Back(const T& data)
{
    Node<T> *pNode = new Node<T>();
    
    // If the list is empty, create a new Node that is both the first and the last Node
    if (last == nullptr) {
        pNode->data = data;
        pNode->prev = nullptr;
        pNode->next = nullptr;
        
        first = last = pNode;
    } else {
        // Otherwise create a new Node and put it at last position
        last->next = pNode;
        
        pNode->data = data;
        pNode->prev = last;
        pNode->next = NULL;
        
        last = pNode;
    }
    
    return pNode;
}

/*
 *  Add the data to a new Node and push it first in the list
 *  by sending the data and the position 0 to the Push function
 */
template <class T>
Node<T> * List<T>::Push_Front(const T& data)
{
    Node<T> *pNode = new Node<T>();
    
    // If list is empty create an new Node that is both the first and the last node
    if (first == nullptr) {
        pNode->data = data;
        pNode->next = nullptr;
        pNode->prev = nullptr;
        
        first = last = pNode;
    } else {
        // Otherwise create a new Node an put it at the first position
        first->prev = pNode;
        
        pNode->data = data;
        pNode->prev = nullptr;
        pNode->next = first;
        
        first = pNode;
    }
    
    return pNode;
}

/*
 *  Retrives the data from the Node at the end of the list and returns the data.
 *  Also removes the node from the list
 */
template <class T>
T List<T>::Pop_Back()
{
    // Retrives the last Node in the list
    if (last == nullptr) {
        throw std::invalid_argument("Can't Pop, List is empty");
    } else {
        T lastData = last->data;
        
        if (last->prev != nullptr) {
            last = last->prev;
            delete last->next;
            last->next = nullptr;
        } else {
            // If the removed Node was the last in the list
            delete last;
            first = nullptr;
            last = nullptr;
        }
        
        return lastData;
    }
}

/*
 *  Retrives the data from the Node at the beginning of the list and returns the data.
 *  Also removes the node from the list
 */
template <class T>
T List<T>::Pop_Front()
{
    if (first == nullptr) {
        throw std::invalid_argument("Can't Pop, List is empty");
    } else {
        T firstData = first->data;
        
        if (first->next != nullptr) {
            first = first->next;
            delete first->prev;
            first->prev = nullptr;
        } else {
            // Removes the last Node in the list
            delete first;
            first = nullptr;
            last = nullptr;
        }
        
        return firstData;
    }
}

/*
 *  Returns the first Node in the list
 */
template <class T>
Node<T> * List<T>::First()
{
    return first;
}

/*
 *  Returns the last Node in the list
 */
template <class T>
Node<T> * List<T>::Last()
{
    return last;
}

template <class T>
Node<T> * List<T>::InsertAfter(Node<T> *currentNode, const T& data)
{
    Node<T> *pNode = new Node<T>();
    pNode->data = data;
    pNode->prev = currentNode;
    
    if (currentNode->next == nullptr) {
        pNode->next = nullptr;
        last = pNode;
    } else {
        pNode->next = currentNode->next;
        currentNode->next->prev = pNode;
    }
    
    currentNode->next = pNode;
    
    return pNode;
}

template <class T>
Node<T> * List<T>::InsertBefore(Node<T> *currentNode, const T& data)
{
    Node<T> *pNode = new Node<T>();
    pNode->data = data;
    pNode->next = currentNode;
    
    if (currentNode->prev == nullptr) {
        pNode->prev = nullptr;
        first = pNode;
    } else {
        pNode->prev = currentNode->prev;
        currentNode->prev->next = pNode;
    }
    
    currentNode->prev = pNode;

    return pNode;
}

template <class T>
bool List<T>::Check(int count)
{
    // Count defines how many nodes that the user expects it to be in the List
    // Return true means that everything is ok
    
    //######################################
    //# ^ (XOR) 0^0=0, 1^0=1, 0^1=1, 1^1=0 #
    //######################################
    if ((count == 0) ^ (first == nullptr)) {
        return false;   // When empty list is first==null and the otherway around
    }
    
    if (first == nullptr) {
        return (last == nullptr && count == 0);
    }
    
    //######################################
    //# || (OR) 0|0=0, 1|0=1, 0|1=1, 1|1=1 #
    //######################################
    if (count == 0 || last == nullptr) {
        return false;
    }
    
    // Now is first & last != null and count != 0
    Node<T> * node = first;
    Node<T> * lastNode = nullptr;
    
    while (node != nullptr && count > 0) {
        if (lastNode != node->prev) {
            return false;
        }
        count--;
        lastNode = node;
        node = node->next;
    }
    return (lastNode == last) && (count == 0);
}

template <class T>
void List<T>::PrintList()
{
    Node<T> *temp;
    temp = first;
    
    while (temp != nullptr) {
        std::cout << temp->data << ", ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Returns a pointer to the previous Node
template <class T>
Node<T> * Node<T>::Prev()
{
    return prev;
}

// Returns a pointer to the next Node
template <class T>
Node<T> * Node<T>::Next()
{
    return next;
}

