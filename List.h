//
// Created by Orion on 12/2/2019.
//

#ifndef TERMPROJECT_LIST_H
#define TERMPROJECT_LIST_H


//The vector is an array with an expandable storage space
template <typename T>class List {
public:
    //Adds a new value to the list at the end
    virtual bool add(T& thingToAdd) = 0;

    //Finds and removes the given value from the list
    virtual bool remove(T& thingToRemove) = 0;

    //Finds the given value from the list
    virtual T* find(T& thingToFind) = 0;

    virtual int getSize() = 0;

    virtual T* get(int index) = 0;
};


#endif //TERMPROJECT_LIST_H
