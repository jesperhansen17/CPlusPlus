//
//  Iterator.cpp
//  Assignment3
//
//  Created by Jesper Hansen on 2015-11-25.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#include "Iterator.hpp"

/*
 *  Destructor
 */
Iterator::~Iterator()
{
    myString = nullptr;
}

/*
 *	Increment prefix
 */
Iterator Iterator::operator++()
{
    myString++;
    return *this;
}

/*
 *	Increment postfix
 */
Iterator Iterator::operator++(int)
{
    // Save the old value
    Iterator temp = *this;
    myString++;
    return temp;
}

/*
 *  Pointer value at right hand side sets to the local myString pointer
 */
Iterator& Iterator::operator=(const Iterator& rhs)
{
    if (this == &rhs) {
        return *this;
    } else {
        myString = rhs.myString;
        return *this;
    }
}

/*
 *  Function which checks if the left and the right object is equal.
 *  If equal returns true otherwise false
 */
bool operator==(const Iterator& lhs, const Iterator& rhs)
{
    return lhs.myString == rhs.myString;
}

/*
 *	Function which checks if the left and the right object are not equal
 *	If not equal return true otherwise false
 */
bool operator!=(const Iterator& lhs, const Iterator& rhs)
{
    return lhs.myString != rhs.myString;
}

/*
 *	Return the pointer value
 */
char& Iterator::operator*()
{
    return *myString;
}

/*
 *  Increment myString pointer with the number of i
 */
Iterator Iterator::operator+(int i)
{
    myString = myString + i;
    return Iterator(myString);
}

/*
 *  Retreive the char at position i from myString pointer
 */
char& Iterator::operator[](int i) const
{
    return myString[i];
}

//#########ReverseIterator##############################

/*
 *  Destructor
 */
ReverseIterator::~ReverseIterator()
{
    myString = nullptr;
}

/*
 *  Pointer value at right hand side sets to the local myString pointer
 */
ReverseIterator& ReverseIterator::operator=(const ReverseIterator &rhs)
{
    if (this == &rhs) {
        return *this;
    } else {
        myString = rhs.myString;
        return *this;
    }
}

/*
 *  Increment prefix
 */
ReverseIterator ReverseIterator::operator++()
{
    --myString;
    return *this;
}

/*
 *  Incremnet postfix
 */
ReverseIterator ReverseIterator::operator++(int)
{
    // Save the old value
    ReverseIterator temp = *this;
    --myString;
    return temp;
}

/*
 *  Function which checks if the left and the right object is equal.
 *  If equal returns true otherwise false
 */
bool operator==(const ReverseIterator& lhs, const ReverseIterator& rhs)
{
    return lhs.myString == rhs.myString;
}

/*
 *  Function which checks if the left and the right object are not equal.
 *  If not equal returns true otherwise false
 */
bool operator!=(const ReverseIterator& lhs, const ReverseIterator& rhs)
{
    return lhs.myString != rhs.myString;
}

/*
 *	Return the pointer value
 */
char& ReverseIterator::operator*()
{
    return *myString;
}

/*
 *  Retreive the char at position i from myString pointer
 */
ReverseIterator ReverseIterator::operator+(int i)
{
    myString = myString - i;
    return ReverseIterator(myString);
}

/*
 *  Retreive the char at position i from myString pointer
 */
char& ReverseIterator::operator[](int i) const
{
    return myString[-i];
}

/*
 *  Prints out the String by adding my String to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Iterator& str)
{
    os << str.myString;
    return os;
}

