//
//  Shared_Ptr.hpp
//  Assignment4
//
//  Created by Jesper Hansen on 2015-12-01.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#ifndef Shared_Ptr_hpp
#define Shared_Ptr_hpp

#include <stdio.h>
#include <iostream>
#include "ReferenceCounter.hpp"

template <typename T>
class Shared_Ptr {
    
private:
    T *pointer;
    ReferenceCounter *refPtr;
    
public:
    // Constructors
    Shared_Ptr();
    Shared_Ptr(T *ptr);
    Shared_Ptr(std::nullptr_t);
    Shared_Ptr(Shared_Ptr<T> &rhs);
    ~Shared_Ptr();
    
    // Assignment
    Shared_Ptr& operator=(const Shared_Ptr<T>& rhs);
    
    // Equal comparison between two Shared_Ptr
    friend bool operator==(const Shared_Ptr<T>& lhs, const Shared_Ptr<T>& rhs)
    {
        return lhs.pointer == rhs.pointer;
    }
    
    // Equal comparison between a Shared_Ptr and a Pointer (nullptr)
    friend bool operator==(const Shared_Ptr& lhs, std::nullptr_t rhs)
    {
        return lhs.pointer == rhs;
    }
    
    // Smaller than comparison between two Shared_Ptr
    friend bool operator<(const Shared_Ptr<T>& lhs, const Shared_Ptr<T>& rhs)
    {
        return lhs.pointer < rhs.pointer;
    }
    
    friend bool operator<(const Shared_Ptr& lhs, std::nullptr_t rhs)
    {
        return lhs.pointer < rhs;
    }
    
    // Bigger than comparison between two Shared_Ptr
    friend bool operator>(const Shared_Ptr<T>& lhs, const Shared_Ptr<T>& rhs)
    {
        return lhs.pointer > rhs.pointer;
    }
    
    friend bool operator>(const Shared_Ptr& lhs, std::nullptr_t rhs)
    {
        return lhs.pointer > rhs;
    }
    
    
    // Operators overload
    T& operator*() const;
    T* operator->() const;
    operator bool();
    
    // Member functions
    void reset(T* = nullptr);
    T* get() const;                             // To get the resource associated with the shared_ptr.
    bool unique();                              // To know whether the resource is managed by only this shared_ptr instance.
    
    friend std::ostream& operator<<(std::ostream& os, const Shared_Ptr& str);
};
#endif /* Shared_Ptr_hpp */
