//
// Created by Kenny on 11/15/2019.
//

#ifndef TERMPROJECT_QUEUE_H
#define TERMPROJECT_QUEUE_H

#include <stdexcept>
#include "Song.h"

class Queue{
private:
    // Abstract, should not be directly implemented.
    Queue(const Queue& queueToCopy);
    Queue& operator=(const Queue& queueToCopy);


    // adds new Song to a queue, appending to the end of the queue.
    virtual void enqueue(Song* songToAdd)=0;

    // removes a song from the front of the queue, returns the song.
    // throw an exception if the Queue is empty.
    virtual Song* dequeue() = 0;

public:
    // constructor
    Queue() {}

    // destructor
    virtual ~Queue() {}

    virtual bool isEmpty() = 0;
};

#endif //TERMPROJECT_QUEUE_H
