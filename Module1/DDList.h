//
//  DDList.h
//  Assignment1
//
//  Created by Jesper Hansen on 2015-11-13.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#ifndef DDList_h
#define DDList_h

//######################################################################################
//# Forward declaration, declares a class without defining it. A class must be defined #
//# not just declared before we can use objects of that type.                          #
//######################################################################################
template <class T>
class List;


template <class T>
class Node {
    //#############################################################################
    //# A class can allow other another class or function to access its nonpublic #
    //# members by making that class or function a friend.                        #
    //#############################################################################
    friend class List<T>;
private:
    Node *prev, *next;
public:
    Node():prev(), next() {}
    T data;
    Node * Prev();
    Node * Next();
};

template <class T>
class List {
    //#############################################################################
    //# A class can allow other another class or function to access its nonpublic #
    //# members by making that class or function a friend.                        #
    //#############################################################################
    friend class Node<T>;
private:
    Node<T> *last, *first;
    Node<T> * Push(T data, int index);
    T Pop(int index);
public:
    List():first(),last() {}
    ~List();
    int Size();
    Node<T> * Push_Front(const T& data);
    Node<T> * Push_Back(const T& data);
    T Pop_Front();
    T Pop_Back();
    Node<T> * First();
    Node<T> * Last();
    //Node<T> * InsertAfter(int pos, const T& data);
    //Node<T> * InsertBefore(int pos, const T& data);
    Node<T> * InsertBefore(Node<T> *currentNode, const T& data);
    Node<T> * InsertAfter(Node<T> *currentNode, const T& data);
    bool Check(int count);
    void PrintList();
};


#endif /* DDList_h */
