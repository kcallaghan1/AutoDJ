//
// Created by LordOfConstructs on 12/14/2019.
//

#ifndef TERMPROJECT_SORTEDARRAYLIST_H
#define TERMPROJECT_SORTEDARRAYLIST_H

#include <iostream>
#import "ArrayList.h"

template <typename T>class SortedArrayList : public ArrayList<T> {
protected:
    virtual int _find(T& thingToFind){
        return _find(thingToFind, 0, this->currentSize);
    }

    virtual int _find(T& thingToFind, int start, int end){
        if(end <= start){
            if(this->array[start] != nullptr && *(this->array[start]) == thingToFind){
                return start;
            }
            else {
                return -1;
            }
        }
        int midpoint = (end - start) / 2 + start;
        if(*(this->array[midpoint]) == thingToFind){
            return midpoint;
        }
        else if(thingToFind < *(this->array[midpoint])){
            return this->_find(thingToFind, start,  midpoint - 1);
        }
        else {
            return this->_find(thingToFind, midpoint + 1, end);
        }
    }

public:
    virtual bool add(T& thingToAdd){
        int loc = 0;
        while(loc < this->currentSize && thingToAdd > *(this->array[loc])) {
            loc++;
        }
        if(this->currentSize >= this->maxSize){
            this->doubleSize();
        }
        if(this->array[loc] == nullptr){
            this->array[loc] = &thingToAdd;
            this->currentSize++;
            return true;
        }
        else if(*(this->array[loc]) != thingToAdd) {
            for (int i = this->currentSize; i > loc; i--) {
                this->array[i] = this->array[i - 1];
            }
            this->array[loc] = &thingToAdd;
            this->currentSize++;
            return true;
        }
        else{
            std::cout << "Duplicate song detected:  " << thingToAdd.toString() << std::endl;
            return false;
        }
    }

};


#endif //TERMPROJECT_SORTEDARRAYLIST_H
