//
//  Iterator.hpp
//  Assignment3
//
//  Created by Jesper Hansen on 2015-11-25.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#ifndef Iterator_hpp
#define Iterator_hpp

#include <iostream>
#include <stdio.h>

class Iterator {
public:
	typedef char value_type;

	Iterator() : myString(nullptr) {}
	~Iterator();
	Iterator(value_type *str) : myString(str) {}
	Iterator(const Iterator& rhs) : myString(rhs.myString) {}

	Iterator& operator=(const Iterator& rhs);
	Iterator operator++();                                                     // Preincrement
	Iterator operator++(int);                                                  // Posticrement
	friend bool operator==(const Iterator& lhs, const Iterator& rhs);
	friend bool operator!=(const Iterator& lhs, const Iterator& rhs);
	value_type& operator*();
	Iterator operator+(int i);
	value_type& operator[](int i) const;                                              // DONE

	value_type* getPtr() const{ return myString; }
	friend std::ostream& operator<<(std::ostream& os, const Iterator& str);     // DONE

private:
	value_type* myString;
};

class ReverseIterator {
public:
	typedef char value_type;

	ReverseIterator() : myString(nullptr) {}
	~ReverseIterator();
	ReverseIterator(value_type *str) : myString(str) {}
	ReverseIterator(const Iterator& rhs) : myString(rhs.getPtr()) {}
	ReverseIterator(const ReverseIterator& rhs) = default;

	ReverseIterator& operator=(const ReverseIterator& rhs);
	ReverseIterator operator++();                              					// Preincrement
	ReverseIterator operator++(int);												// Posticrement
	friend bool operator==(const ReverseIterator& lhs, const ReverseIterator& rhs);
	friend bool operator!=(const ReverseIterator& lhs, const ReverseIterator& rhs);
	value_type& operator*();
	ReverseIterator operator+(int i);
	value_type& operator[](int i) const;                      // DONE

	friend std::ostream& operator<<(std::ostream& os, const Iterator& str);   // DONE

private:
	value_type* myString;
};


#endif /* Iterator_hpp */
