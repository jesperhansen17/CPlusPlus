//
//  main.cpp
//  Assignment3
//
//  Created by Jesper Hansen on 2015-11-25.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#include <string>
#include <iostream>
#include <assert.h>
#include "String.hpp"
#include "Iterator.hpp"

String foo()
{
    String s1("Anders");
    return s1;
}

void TestForGodkantItt() {
    
    //-	typdefs fˆr iterator, const_iterator,  reverse_iterator och const_revers_iterator
    String::iterator Str;
    String::reverse_iterator rStr;
    
    //-	funktionerna begin, end, cbegin, cend, rbegin, rend, crbegin och crend.
    
    //-	default constructor, copy constructor och tilldelning (=)
    String s("foobar");
    Str=s.begin();
    rStr=s.rbegin();
    *Str='a';
    *(rStr+2)='c';
    assert(s=="aoocar");
    
    String s5("foobar");
    for (auto i = s5.rbegin(); i != s5.rend(); i++) {
        std::cout << *i;
    }
    std::cout << std::endl;
    
    String s2("Washington");
    for (auto j = s2.begin(); j != s2.end(); j++) {
        std::cout << *j;
    }
    std::cout << std::endl;
    
    String s3("hej");
    for (auto x = s3.rbegin(); x != s3.rend(); x++) {
        std::cout << *x;
    }
    std::cout << std::endl;
    
    String s4("Malmö");
    for (auto y = s4.begin(); y != s4.end(); y++) {
        std::cout << *y;
    }
    std::cout << std::endl;
    
    String::iterator iter = s4.begin();
    *iter = 'a';
    std::cout << s4 << std::endl;
    *(iter+2) = 'b';
    std::cout << s4 << std::endl;
    
    String s1="foobara";
    auto it = s1.begin();
    assert(*it=='f');
    assert(*(it++)=='f' && *it == 'o');
    ++it;
    assert(*++it=='b');
    assert(*(it+1)=='a');
    assert(it[2]=='a');
    
    String reverse = "araboof";
    auto rit = reverse.rbegin();
    assert(*rit == 'f');
    assert(*(rit++)=='f');
    assert(*rit == 'o');
    ++rit;
    assert(*++rit=='b');
    assert(*(rit+1)=='a');
    assert(rit[2]=='a');
    
    String s1reverse="foobara";
    auto iter2 = s1.rbegin();
    assert(*iter2=='a');
    assert(*(iter2++)=='a' && *iter2 == 'r');
    ++iter2;
    assert(*++iter2=='b');
    assert(*(iter2+1)=='o');
    assert(iter2[2]=='f');
}


int main() {
    TestForGodkantItt();
    
//    String s1("Jesper");
//    String s2("Hansen");
//    String s3;
//    String s4("Zlatan");
//    
//    s3 = s1 + s2;
//    std::cout << s3 << std::endl;
//
//    s3 = foo();
//    
//    s1 = s2;
//    
//    std::cout << s1 << std::endl;
//    
//    s3 = s1 + s4;
//    
//    std::cout << s3 << std::endl;
//    
//    s4 = "Ibra";
//    
//    std::cout << s4 << std::endl;
//    
//    s3 = 'A';
//    
//    std::cout << s3 << std::endl;
//    
//    s4[0] = 'A';
//    
//    std::cout << s4 << std::endl;
//    
//    const char *p = s4.data();
//    std::cout << p << std::endl;
//    
//    std::cout << s4.length() << " and " << s4.capacity() << std::endl;
//    s4.push_back('A');
//    std::cout << s4.length() << " and " << s4.capacity() << std::endl;
//    s4.shrink_to_fit();
//    std::cout << s4.length() << " and " << s4.capacity() << std::endl;
//    
//    if (s1 == "Johan") {
//        std::cout << "Is the same" << std::endl;
//    } else {
//        std::cout << "Is not the same" << std::endl;
//    }
//    
//    //s1.at(2) = 'A';
//    std::cout << s1.at(2) << std::endl;
//    
//    s1.reserve(20);
//    s1.resize(10);
//    std::cout << s1.length() << " and " << s1.capacity() <<  " and the value is " << s1 << std::endl;
//    s1 += s3;
//    
//    std::cout << s1 << std::endl;
//    
//    for (int i = 0; i < 100; i++) {
//        s1.push_back('A');
//    }
//    
    
    //while(1);
    return 0;
}
