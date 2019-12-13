//
// Created by Orion on 12/2/2019.
//

#ifndef TERMPROJECT_VECTOR_H
#define TERMPROJECT_VECTOR_H


//The vector is an array with an expandable storage space
template <typename T>class Vector {
private:
    //Abstract do not directly implement
    Vector(const Vector& queueToCopy);
    Vector& operator=(const Vector& queueToCopy);

    //Adds a new value to the vector at the end
    virtual bool add(T& thingToAdd) = 0;

    //Finds and removes the given value from the vector
    virtual bool remove(T& thingToRemove) = 0;

    //Finds the given value from the vector
    virtual T* find(T& thingToFind) = 0;

    virtual void doubleSize() = 0;

public:
    //Constructor
    Vector() {}

    //Destructor
    virtual ~Vector() {}
};


#endif //TERMPROJECT_VECTOR_H
