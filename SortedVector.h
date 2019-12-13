//
// Created by Orion on 12/2/2019.
//

#ifndef TERMPROJECT_SORTEDVECTOR_H
#define TERMPROJECT_SORTEDVECTOR_H

#import "Vector.h"

//The sorted vector is a vector that is always sorted
template <typename T> class SortedVector : public Vector<T>{
private:
    //Abstract do not directly implement
    SortedVector(const SortedVector& queueToCopy);
    SortedVector& operator=(const SortedVector& queueToCopy);

    //Adds a new value to the vector at the appropriate location
    virtual bool add(T& thingToAdd) = 0;

    //Finds and removes the given value from the vector
    virtual bool remove(T& thingToRemove) = 0;

    //Finds the given value from the vector
    virtual T* find(T& thingToFind) = 0;

    virtual void doubleSize() = 0;

public:
    //Constructor
    SortedVector() {}

    //Destructor
    virtual ~SortedVector() {}

};


#endif //TERMPROJECT_SORTEDVECTOR_H
