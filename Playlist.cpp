//
// Created by Kenny on 11/19/2019.
//

#include "Playlist.h"

Playlist::Playlist(std::string nameIn){
    name = nameIn;
    first = nullptr;
    last = nullptr;
    songCount = 0;
}

Playlist::~Playlist() {
    while(!isEmpty()){
        dequeue();
    }
}

void Playlist::enqueue(Song* songToAdd){
    SongNode* newNode = new SongNode(songToAdd);
    if(isEmpty()){
        first = newNode;
        last = newNode;
    }
    else{
        last->setNext(newNode);
        last = newNode;
    }
    songCount++;
}

Song* Playlist::dequeue(){
    Song* output = new Song(first->getSong()->toString());
    SongNode* temp = first;
    first = first->getNext();
    delete temp;
    songCount--;
    return output;
}

bool Playlist::isEmpty() {
    if(songCount == 0){
        return true;
    }
    return false;
}

void Playlist::addSong(Song* songToAdd) {
    enqueue(songToAdd);
}

Song* Playlist::playNextSong() {
    if(isEmpty()){
        throw std::out_of_range("The playlist is empty.");
    }
    else{
        Song* output = dequeue();
        output->incrementPlayCount();
        return output;
    }
}

std::string Playlist::getName() {
    return name;
}

int Playlist::getSongCount() {
    return songCount;
}