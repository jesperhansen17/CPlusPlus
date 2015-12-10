//
//  main.cpp
//  Assignment4
//
//  Created by Jesper Hansen on 2015-12-01.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#include "Shared_Ptr.hpp"
#include "Shared_Ptr.cpp"
#include <iostream>
#include <string>
#include <assert.h>

struct C {
    float value;
    C(float value) :value(value){};
};

void TestG() {
    //-	Konstruktor som tar:
    //	o	inget	G
    //	o	En SharedPtr	G
    //	o	En pekare	G
    
    
    Shared_Ptr<C> p11;
    assert(!p11);
    Shared_Ptr<C> p15(nullptr);
    assert(!p15);
    Shared_Ptr<C> p12(new C(12));
    assert(p12);
    Shared_Ptr<C> p13(p11);
    assert(!p13);
    
    assert(p12.unique());
    Shared_Ptr<C> p14(p12);
    assert(p14);
    assert(!p12.unique());
    
    Shared_Ptr<C> p16(nullptr);
    assert(!p16.unique());
    
    
    //-	Destruktor	G
    //It will test itself
    //-	Tilldelning från en
    //	o	En SharedPtr	G
    p14 = p12;
    assert(p14);
    
    p14 = p14;
    assert(p14);
    
    //-	Jämförelse med (== och <)
    Shared_Ptr<C> p31(new C(31));
    //	o	En SharedPtr	G
    assert(p11 == nullptr);
    assert(p11 < p12);
    assert(!(p12 < p11));
    assert(p14 == p12);
    assert(!(p14 == p31));
    assert((p14 < p31) || (p31 < p14));
    
    //get, * och ->
    
    Shared_Ptr<C> p41(new C(41));
    Shared_Ptr<C> p42(new C(42));
    assert((p41->value) == (p41.get()->value));
    assert((p41->value) != (p42.get()->value));
    assert(&(*p41) == (p41.get()));
    
    int *i = new int(30);
    Shared_Ptr<int> sp(i);
    Shared_Ptr<int> dp(sp);
    Shared_Ptr<int> kp(sp);
    sp.reset(new int);
    *sp = 10;
    std::cout << *sp << std::endl;
    
    dp.reset();                 // deletes managed object, acquires new pointer
    assert(!dp);
    
    kp.reset();                 // deletes managed object
    assert(!kp);
    
    p41.reset();
    assert(!p41);
}

int main() {
    TestG();
    while (1);
    return 0;
}
