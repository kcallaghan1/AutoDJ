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
        if(songCount == 1){
            first->setNext(newNode);
        }
        last->setNext(newNode);
        last = newNode;
    }
    songCount++;
}

Song* Playlist::dequeue(){
    Song* output = first->getSong();
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

int Playlist::getDuration() {
    if(getSongCount() == 0){
        return 0;
    }
    int duration = 0;
    SongNode* temp = first;
    for(int i = 0; i < songCount; i++){
        duration += temp->getSong()->getDuration();
        temp = temp->getNext();
    }
    return duration;
}

bool Playlist::removeSong(std::string artistIn, std::string titleIn) {
    if(songCount == 0){
        return false;
    }
    SongNode* temp = first;
    if(first->getSong()->getTitle() == titleIn && first->getSong()->getArtist() == artistIn){
        first = temp->getNext();
        delete temp;
        songCount--;
        return true;
    }
    else{
        while(temp->getNext() != nullptr) {
            SongNode *temp2 = temp->getNext();
            if (temp2->getSong()->getTitle() == titleIn && temp2->getSong()->getArtist() == artistIn) {
                temp->setNext(temp2->getNext());
                delete temp2;
                songCount--;
                return true;
            }
            temp = temp->getNext();
        }
    }
    return false;
}

void Playlist::popRand(Library& lib, int maxDuration) {
    lib.popAllRandOrder(this);
    while(this->getDuration() > maxDuration){
        this->dequeue();
    }
}

std::string Playlist::toString(){
    std::string returnString = name + "\n" + std::to_string(songCount) + "\n";
    SongNode* temp = first;
    while(temp != nullptr){
        returnString += temp->getSong()->toString() + "\n";
        temp = temp->getNext();
    }
    return returnString;
}