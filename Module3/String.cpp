//
//  String.cpp
//  Assignment2
//
//  Created by Jesper Hansen on 2015-11-20.
//  Copyright © 2015 Jesper Hansen. All rights reserved.

#define del(x) if(x){delete x;x = nullptr;}
//

#include "String.hpp"

/*
 *  Default constructor
 */
String::String()
{
    size = 1;
    strLength = 0;
    pString = new char[size];
    pString[0] = '\0';
}

/*
 *  Destructor
 */
String::~String()
{
    del(pString);
}

/*
 *  Copy constructor copies the reference to a new String object
 */
String::String(const String& rhs)
{
    size = rhs.size;
    strLength = rhs.strLength;
    
    pString = new char[size];
    
    strcpy(pString, rhs.pString);
}

/*
 *  Move constructor moves the reference to a new String object
 */
String::String(String&& rhs)
{
    size = rhs.size;
    strLength = rhs.strLength;
    pString = rhs.pString;
    
    // Reset the rhs reference
    rhs.pString=nullptr;
    rhs.size = 0;
    rhs.strLength = 0;
}

/*
 *  Constructor takes an char pointer and creates a new String object
 */
String::String(const char* cstr)
{
    strLength = strlen(cstr);       // Return the String length
    size = strLength + 1;           // Return the Size of the Array
    
    pString = new char[size];
    
    strcpy(pString, cstr);
}

/*
 *  Copy a String object to a another String object, return the object after copy
 */
String& String::operator=(const String &rhs)
{
    if (this == &rhs) {
        return *this;
    } else {
        // If current objects size is bigger or equal than rhs size we don't have to create a new object
        if (size >= rhs.size) {
            size = rhs.size;
            strLength = rhs.strLength;
            strcpy(pString, rhs.pString);
        } else {
            size = rhs.size;
            strLength = rhs.strLength;
            
            char *newArray = new char[size];
            strcpy(newArray, rhs.pString);
            
            delete [] pString;
            
            pString = newArray;
        }
        return *this;
    }
}

/*
 *  Moves the rhs object to a new current object, so the rhs object resets at the
 *  end of the move assignment
 */
String& String::operator=(String &&rhs)
{
    if (this == &rhs) {
        return *this;
    } else {
        // Delete the object pString points first
        delete [] pString;
        size = 0;
        strLength = 0;
        
        size = rhs.size;
        strLength = rhs.strLength;
        pString = rhs.pString;
        
        // Reset rhs
        rhs.size = 0;
        rhs.strLength = 0;
        rhs.pString = nullptr;
        
        return *this;
    }
}

/*
 *  Equal operator that delete the current array and creates a new one with the pointer cstr String
 */
String& String::operator=(const char *cstr)
{
    // If current objects size is bigger or equal than rhs size we don't have to create a new object
    if (size > (strlen(cstr) + 1)) {
        size = strlen(cstr) + 1;
        strLength = strlen(cstr);
        
        strcpy(pString, cstr);
    } else {
        size = strlen(cstr) + 1;        // Return the Size of the Array
        strLength = strlen(cstr);       // Return the String length
        
        char *newArray = new char[size];
        strcpy(newArray, cstr);
        delete [] pString;
        
        pString = newArray;
    }
    
    return *this;
}

/*
 *  Equal operator that delete the current String and creates a new String with only ch as the character
 */
String& String::operator=(char ch)
{
    // If current objects size is bigger or equal than rhs size we don't have to create a new object
    if (size > 1) {
        strLength = 1;
        size = strLength + 1;
        
        pString[0] = ch;
        pString[strLength] = '\0';
    } else {
        strLength = 1;
        size = strLength + 1;
        
        char *newArray = new char[size];
        newArray[0] = ch;
        newArray[1] = '\0';
        
        delete [] pString;
        
        pString = newArray;
    }
    
    return *this;
}

/*
 *  Function concatenates the rhs String object to the current String
 */
String& String::operator+=(const String &rhs)
{
    // If current objects size is bigger or equal than rhs size we don't have to create a new object
    if (size > (strLength + rhs.strLength + 1)) {
        int newLength = strLength + rhs.strLength;
        
        strcat(pString, rhs.pString, strLength, newLength);
        
        strLength = newLength;
    } else {
        size += rhs.size;
        int newLength = strLength + rhs.strLength;
        
        char *newArray = new char[size];
        
        strcat(newArray, pString, 0, strLength);
        
        strcat(newArray, rhs.pString, strLength, newLength);
        
        delete [] pString;
        
        strLength = newLength;
        pString = newArray;
    }
    
    return *this;
}

/*
 *  Function concatenates the cstr String to the current String
 */
String& String::operator+=(char *cstr)
{
    String temp(cstr);
    return *this += temp;
}

/*
 *  Creates a temporary String and concatenates this String with the cstr array
 */
String String::operator+(const String &cstr)
{
    return String(*this) += cstr;
}

/*
 *  Function which checks if the left and the right object is equal.
 *  If equal returns true otherwise false
 */
bool operator==(const String& lhs, const String& rhs)
{
    if (lhs.size == rhs.size && lhs.strLength == rhs.strLength) {
        int i = 0;
        while (i < lhs.strLength) {
            if (lhs.pString[i] != rhs.pString[i]) {
                return false;
            }
            i++;
        }
        return true;
    }
    return false;
}

/*
 *	Function which checks if the left and the right object are not equal
 *	If not equal return true otherwise false
 */
bool operator!=(const String& lhs, const String& rhs)
{
    if (lhs.size == rhs.size || lhs.strLength == rhs.strLength) {
        int i = 0;
        while (i < lhs.strLength) {
            if (lhs.pString[i] != rhs.pString[i]) {
                return true;
            }
            i++;
        }
        return false;
    }
    return true;
}

/*
 *  Returns the char at position i
 *  Function should not be able to change any member variable,
 *  but the user can use this function for change the return value
 */
char& String::operator[](int i) const
{
    return pString[i];
}

/*
 *  Returns the character at position i, exception is thrown if i is greater then the number of character in the String
 *  Both the return and the function is const, this is because the function should not be able to change any member variable
 *  and the return value should not be able to be changed
 */
const char& String::at(int i) const
{
    if (i > size) {
        throw std::out_of_range("IndexOutOfBounds");
    } else {
        return pString[i];
    }
}

/*
 *  Returns a pointer to the internal array holding the String
 */
const char* String::data() const
{
    char *pointer;
    pointer = pString;
    return pointer;
}

/*
 *  Returns the lenght of a String, in terms of bytes
 */
int String::length() const
{
    return strLength;
}

/*
 * Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
 * If n is greater than the current string capacity, the function causes the container to increase its capacity to n characters (or greater).
 */
void String::reserve(int n)
{
    if (n > size) {
        size = n;
        char *newArray = new char[size];
        strcpy(newArray, pString);
        delete [] pString;
        pString = newArray;
    }
}

/*
 *  Returns the size of the storage space currently allocated for the String, expressed in terms of bytes
 */
int String::capacity() const
{
    return size;
}

/*
 *  Requests the string to reduce its capacity to fit its size.
 */
void String::shrink_to_fit()
{
    size = strLength + 1;
    char *newArray = new char[size];
    strcpy(newArray, pString);
    delete [] pString;
    pString = newArray;
}

/*
 *  Add a character at the end of the array
 */
void String::push_back(char c)
{
    if (strLength < size - 1) {
        pString[strLength++] = c;
        pString[strLength] = '\0';
    } else {
        reserve(size * 3);
        pString[strLength++] = c;
        pString[strLength] = '\0';
    }
}

/*
 *  Function resizes the String of n length, if n is bigger then length().
 *  Fill the rest of the String with null terminator ('\0')
 */
void String::resize(int n)
{
    if ((n > size) && (n > strLength)) {
        reserve(n);
    } else if ((n < size) && (n > strLength)) {
        for (int i = strLength + 1; i < n; i++) {
            pString[i] = '\0';
        }
    } else {
        strLength = n;
        size = n + 1;
        pString[n] = '\0';
    }
}

/*
 *  Prints out the String by adding my String to the output stream
 */
std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.pString;
    return os;
}

/*
 *  Function returning the number of character in a String
 */
char String::strlen(const char *str) const
{
    char i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

/*
 *  Copies the source array to the destination array
 */
void String::strcpy(char *destination, const char* source)
{
    for (int i = 0; *source != '\0'; source++, i++) {
        destination[i] = *source;
    }
    destination[strLength] = '\0';
}

/*
 *  Appends a copy of the source string to the destination string.
 */
void String::strcat(char *destination, const char *source, int start, int end)
{
    for (int i = start; *source != '\0'; source++, i++) {
        destination[i] = *source;
    }
    destination[end] = '\0';
}

//###########Assignment3####################
Iterator String::begin()
{
    return Iterator(pString);
}

Iterator String::end()
{
    return Iterator(pString + strLength);
}

ReverseIterator String::rbegin()
{
    return ReverseIterator(pString + strLength - 1);
}

ReverseIterator String::rend()
{
    return ReverseIterator(pString - 1);
}

