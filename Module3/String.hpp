//
//  String.hpp
//  Assignment2
//
//  Created by Jesper Hansen on 2015-11-20.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#ifndef String_hpp
#define String_hpp

#include <stdio.h>
#include <iostream>
#include "Iterator.hpp"

class Iterator;

class String {
private:
    char* pString;
    int size;
    int strLength;
    
public:
    typedef Iterator iterator;
    typedef ReverseIterator reverse_iterator;
    
    //###########Assignment2###################################
    ~String();                                          // DONE
    String();                                           // DONE
    String(const String& rhs);                          // DONE
    String(String&& rhs);                               // DONE
    String(const char* cstr);                           // DONE
    String& operator=(const String& rhs);               // DONE
    String& operator=(String&& rhs);                    // DONE
    String& operator=(const char* cstr);                // DONE
    String& operator=(char ch);                         // DONE
    String operator+(const String& cstr);               // DONE
    String& operator+=(const String& rhs);              // DONE
    String& operator+=(char* cstr);                     // DONE
    
    friend bool operator==(const String& lhs, const String& rhs);
    friend bool operator!=(const String& lhs, const String& rhs);
    
    const char& at(int i) const;                        // DONE
    char& operator[](int i) const;                      // DONE
    const char* data() const;                           // DONE
    int length() const;                                 // DONE
    void reserve(int n);                                // DONE
    int capacity() const;                               // DONE
    void shrink_to_fit();                               // DONE
    void push_back(char c);                             // DONE
    void resize(int n);                                 // DONE
    char strlen(const char* str) const;                 // DONE
    void strcpy(char *destination, const char *source); // DONE
    void strcat(char *destination, const char *source, int start, int end); // DONE
    friend std::ostream& operator<<(std::ostream& os, const String& str);   // DONE
    
    //##########Assignment3###################################
    Iterator begin();
    Iterator end();
    ReverseIterator rbegin();
    ReverseIterator rend();
};


#endif /* String_hpp */
