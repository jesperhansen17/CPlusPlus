//
//  Shared_Ptr.cpp
//  Assignment4
//
//  Created by Jesper Hansen on 2015-12-01.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#include "Shared_Ptr.hpp"
#include "ReferenceCounter.hpp"

/*
 *  Constructor with no arguments
 */
template <typename T>
Shared_Ptr<T>::Shared_Ptr() : pointer(nullptr), refPtr(nullptr) {}

/*
 *  Constructor with a pointer as argument and create an new ReferenceCounter
 */
template <typename T>
Shared_Ptr<T>::Shared_Ptr(T *ptr) : pointer(ptr)
{
    refPtr = new ReferenceCounter();
}

/*
 *  Constructor that takes a nullptr as parameter
 */
template <typename T>
Shared_Ptr<T>::Shared_Ptr(std::nullptr_t ptr) : pointer(ptr), refPtr(nullptr) {}

/*
 *  Copy constructor
 */
template <typename T>
Shared_Ptr<T>::Shared_Ptr(Shared_Ptr<T>& rhs) {
    pointer = rhs.pointer;
    refPtr = rhs.refPtr;
    if (pointer) {
        refPtr->incRefCount();
    }
}

/*
 *  Destructor
 *  If Shared_Ptr holds more than 0 references just decrement. 
 *  When Shared_Ptr has no more references delete and point the pointer and refCtr to a nullptr
 */
template <typename T>
Shared_Ptr<T>::~Shared_Ptr()
{
    if (pointer && refPtr->decRefCount() == 0) {
        delete pointer;
        delete refPtr;
        pointer = nullptr;
        refPtr = nullptr;
    }
}

/*
 *  Assign operator copies rhs to lhs
 */
template <typename T>
Shared_Ptr<T>& Shared_Ptr<T>::operator=(const Shared_Ptr<T>& rhs)
{
    if (pointer == rhs.pointer) {
        return *this;
    } else {
        pointer = rhs.pointer;
        refPtr = rhs.refPtr;
        refPtr->incRefCount();
        return *this;
    }
}

/*
 *  Return the reference of the pointer
 */
template <typename T>
T& Shared_Ptr<T>::operator*() const
{
    return *pointer;
}

/*
 *  Returns a pointer to the object pointed by the stored pointer in order to access one of its members.
 */
template <typename T>
T* Shared_Ptr<T>::operator->() const
{
    return pointer;
}

/*
 *  Function checks if the pointer is a null pointer or not
 */
template <typename T>
Shared_Ptr<T>::operator bool()
{
    return pointer != 0;
}

/*
 *  Returns the stored pointer.
 */
template <typename T>
T* Shared_Ptr<T>::get() const
{
    return pointer;
}

/*
 *  Checks if the Shared_Ptr only holds one reference
 */
template <typename T>
bool Shared_Ptr<T>::unique()
{
    if (pointer == nullptr) {
        return false;
    } else {
        if (refPtr->getRecCount() == 1) {
            return true;
        } else {
            return false;
        }
    }
}

/*
 *  Shared_Ptr becomes empty if no parameter is added,
 *  in all other cases the new pointer takes ownership over the Shared_Ptr
 */
template <typename T>
void Shared_Ptr<T>::reset(T* ptr)
{
    // If Shared_Ptr and the parameter is both empty, do nothing
    if (pointer == nullptr && ptr == nullptr) {
        return;
    } else if (ptr == nullptr) {            // If parameter is a nullptr, decrement and if count is 0 delete object.
        if (pointer && refPtr->decRefCount() == 0) {
            delete pointer;
            delete refPtr;
        }
        refPtr = nullptr;
    } else {                                // If ptr contains a pointer, first decrement and the change reference and pointer
        refPtr->decRefCount();
        refPtr = new ReferenceCounter();
    }
    pointer = ptr;
}

/*
 *  Prints out the String by adding my String to the output stream
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const Shared_Ptr<T> sPtr) {
    os << sPtr.pointer;
    return os;
}
