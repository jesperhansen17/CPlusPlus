//
//  main.cpp
//  Assignment2
//
//  Created by Jesper Hansen on 2015-11-20.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#include <iostream>
#include "String.hpp"
#include <string>

String foo()
{
    String s1("Anders");
    return s1;
}

int main() {
    String s1("Jesper");
    String s2("Johan");
    String s3;
    String s4("Zlatan");
    
    s3 = foo();
    
    s1 = s2;
    
    std::cout << s1 << std::endl;
    
    s3 = s1 + s4;
    
    std::cout << s3 << std::endl;
    
    s4 = "Ibra";
    
    std::cout << s4 << std::endl;
    
    s3 = 'A';
    
    std::cout << s3 << std::endl;
    
    s4[0] = 'A';
    
    std::cout << s4 << std::endl;

    const char *p = s4.data();
    std::cout << p << std::endl;
    
    std::cout << s4.length() << " and " << s4.capacity() << std::endl;
    s4.push_back('A');
    std::cout << s4.length() << " and " << s4.capacity() << std::endl;
    s4.shrink_to_fit();
    std::cout << s4.length() << " and " << s4.capacity() << std::endl;

    if (s1 == "Johan") {
        std::cout << "Is the same" << std::endl;
    } else {
        std::cout << "Is not the same" << std::endl;
    }
    
    std::cout << s1.at(2) << std::endl;
    
    s1.reserve(20);
    s1.resize(10);
    std::cout << s1.length() << " and " << s1.capacity() <<  " and the value is " << s1 << std::endl;
    s1 += s3;
    
    std::cout << s1 << std::endl;
    
    for (int i = 0; i < 100; i++) {
        s1.push_back('A');
    }
    
    //while (1);
    return 0;
}
