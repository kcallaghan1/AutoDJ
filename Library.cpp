//
// Created by LordOfConstructs on 12/2/2019.
//

#include "Library.h"

Library::Library(){
    srand(time(NULL));
    this->currentSize = 0;
    this->maxSize = 2;
    this->songArray = new Song*[2];
}

Library::~Library(){
    for(int i = 0; i < currentSize; i++){
        delete songArray[i];
    }
    delete this->songArray;
}

void Library::doubleSize() {
    this->maxSize *= 2;
    Song** newSongArray = new Song*[this->maxSize];
    for(int i = 0; i < this->currentSize; i++){
        newSongArray[i] = this->songArray[i];
    }
    for(int i = this->currentSize; i < maxSize; i++){
        newSongArray[i] = nullptr;
    }
    delete[] this->songArray;
    this->songArray = newSongArray;
}

int Library::_find(std::string artist, std::string title, int start, int end){
    if(end <= start){
        if(this->songArray[start] != nullptr && this->songArray[start]->getArtist() == artist && this->songArray[start]->getTitle() == title){
            return start;
        }
        else {
            return -1;
        }
    }
    int midpoint = (end - start) / 2 + start;
    std::string artistAt = this->songArray[midpoint]->getArtist();
    std::string titleAt = this->songArray[midpoint]->getTitle();
    if(artistAt == artist && titleAt == title){
        return midpoint;
    }
    else if(artist < artistAt){
        return this->_find(artist, title, start,  midpoint - 1);
    }
    else if(artist > artistAt){
        return this->_find(artist, title, midpoint + 1, end);
    }
    else if(title < titleAt){
        return this->_find(artist, title, start, midpoint - 1);
    }
    else if(title > titleAt){
        return this->_find(artist, title, midpoint + 1, end);
    }
}

bool Library::add(Song& songToAdd){
    int loc = 0;
    while(loc < this->currentSize && songToAdd.getArtist() > this->songArray[loc]->getArtist()){
        loc++;
    }
    while(loc < this->currentSize &&
    songToAdd.getArtist() == this->songArray[loc]->getArtist() &&
    songToAdd.getTitle() > this->songArray[loc]->getTitle()){
        loc++;
    }
    if(this->currentSize >= this->maxSize){
        this->doubleSize();
    }
    if(this->songArray[loc] == nullptr){
        this->songArray[loc] = &songToAdd;
        currentSize++;
        return true;
    }
    else if(this->songArray[loc]->getArtist() != songToAdd.getArtist() || this->songArray[loc]->getTitle() != songToAdd.getTitle()) {
        for (int i = currentSize; i > loc; i--) {
            this->songArray[i] = this->songArray[i - 1];
        }
        this->songArray[loc] = &songToAdd;
        currentSize++;
        return true;
    }
    else{
        std::cout << "Duplicate song detected:  " << songToAdd.toString() << std::endl;
        return false;
    }
}

bool Library::remove(std::string artist, std::string title){
    int loc = _find(artist, title, 0, currentSize - 1);
    if(loc >= 0) {
        this->currentSize--;
        for (int i = loc; i < this->currentSize; i++) {
            this->songArray[i] = this->songArray[i + 1];
        }
        return true;
    }
    else return false;
}

bool Library::remove(Song& songToRemove){
    return remove(songToRemove.getArtist(), songToRemove.getTitle());
}

Song* Library::find(std::string artist, std::string title){
    int loc = _find(artist, title, 0, this->currentSize - 1);
    if(loc >= 0) {
        return this->songArray[loc];
    }
    else return nullptr;
}

Song* Library::find(Song& songToFind){
    return find(songToFind.getArtist(), songToFind.getTitle());
}

std::string Library::toString(){
    std::string returnString = "";
    for(int i = 0; i < this->currentSize; i++){
        returnString += this->songArray[i]->toString() + "\n";
    }
    return returnString;
}

std::string Library::toString(std::string artist){
    std::string returnString = "";
    for(int i = 0; i < this->currentSize; i++){
        if(songArray[i]->getArtist() == artist) {
            returnString += this->songArray[i]->toString() + "\n";
        }
    }
    return returnString;
}

Song* Library::randSong() {
    int loc = rand() % this->currentSize;
    return songArray[loc];
}

void Library::popAllRandOrder(Playlist* pl){
    Song** shuffledSongArr = new Song*[currentSize];
    for(int i = 0; i < currentSize; i++){
        shuffledSongArr[i] = songArray[i];
    }

    for(int i = 0; i < currentSize * 5; i++){
        Song* temp;
        int loc1 = rand() % currentSize, loc2 = rand() % currentSize;
        temp = shuffledSongArr[loc1];
        shuffledSongArr[loc1] = shuffledSongArr[loc2];
        shuffledSongArr[loc2] = temp;
    }

    for(int i = 0; i < currentSize; i++){
        pl->addSong(shuffledSongArr[i]);
    }
    delete[] shuffledSongArr;
}