//
// Created by LordOfConstructs on 12/14/2019.
//

#ifndef TERMPROJECT_ARRAYLIST_H
#define TERMPROJECT_ARRAYLIST_H

#include <string>
#import "List.h"

template <typename T>class ArrayList : public List<T>{
protected:
    //Keeps track of the amount of playlists the array currently holds, and how many it can hold at maximum
    int currentSize, maxSize;

    //Holds the pointer to the main array of playlists
    T** array;

    //Finds a playlist's index based on the name and returns it
    virtual int _find(T& thingToFind){
        for(int i = 0; i < currentSize; i++){
            if(thingToFind == *(array[i])) {
                return i;
            }
        }
        return -1;
    }

    //Doubles the max capacity of the array and moves contents over
    void doubleSize(){
        this->maxSize *= 2;
        T** newArray = new T*[this->maxSize];
        for(int i = 0; i < currentSize; i++){
            newArray[i] = array[i];
        }
        for(int i = currentSize; i < maxSize; i++){
            newArray[i] = nullptr;
        }
        delete[] array;
        this->array = newArray;
    }

public:
    //Constructor and Destructor:
    ArrayList(){
        this->currentSize = 0;
        this->maxSize = 1;
        this->array = new T*[1];
    }
    ~ArrayList(){
        for(int i = 0; i < currentSize; i++){
            delete array[i];
        }
        delete[] array;
    }

    //Adds a new value to the ArrayList at the end
    virtual bool add(T& thingToAdd){
        if(this->currentSize >= this->maxSize){
            this->doubleSize();
        }
        array[currentSize++] = &thingToAdd;
        return true;
    }

    //Finds and removes the given value from the ArrayList
    virtual bool remove(T& thingToRemove){
        int loc = _find(thingToRemove);
        if(loc >= 0) {
            this->currentSize--;
            delete array[loc];
            for (int i = loc; i < this->currentSize; i++) {
                array[i] = array[i + 1];
            }
            return true;
        }
        else return false;
    }

    //Finds the given value from the vector
    virtual T* find(T& thingToFind){
        int loc = _find(thingToFind);
        if(loc >= 0 && loc < currentSize)
            return array[loc];
        else return nullptr;
    }

    //Returns the current size of the ArrayList
    int getSize(){
        return currentSize;
    }

    //Returns a pointer to the object at the given index so long as it's valid
    virtual T* get(int index){
        if(index >= 0 && index < currentSize){
            return array[index];
        }
        else return nullptr;
    }
};


#endif //TERMPROJECT_ARRAYLIST_H
