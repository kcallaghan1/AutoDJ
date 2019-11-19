//
// Created by Kenny on 11/15/2019.
//

#ifndef TERMPROJECT_QUEUE_H
#define TERMPROJECT_QUEUE_H

#include "Song.h"

class Queue{
private:
    // Abstract, should not be directly implemented.
    Queue(const Queue& queueToCopy);
    Queue& operator=(const Queue& queueToCopy);


    // adds new Song to a queue, appending to the end of the queue.
    virtual void enqueue(Song& songToAdd)=0;

    // removes a song from the front of the queue, returns the song.
    virtual Song* dequeue() = 0;

public:
    // constructor
    Queue() {}

    // destructor
    virtual ~Queue() {}
};

#endif //TERMPROJECT_QUEUE_H
