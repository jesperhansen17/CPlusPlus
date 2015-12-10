//
//  Referenced.h
//  Assignment4
//
//  Created by Jesper Hansen on 2015-12-04.
//  Copyright © 2015 Jesper Hansen. All rights reserved.
//

#ifndef Referenced_h
#define Referenced_h

/*
 *  Class that holds an counter for the number of reference of the Shared_Ptr
 */
class ReferenceCounter
{
    int refCount;
public:
    ReferenceCounter() : refCount(1) {}
    
    void incRefCount() {
        refCount++;
    }
    
    int decRefCount() {
        return --refCount;
    }
    
    int getRecCount() {
        return refCount;
    }
};

#endif /* Referenced_h */
