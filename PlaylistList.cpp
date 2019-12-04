//
// Created by Orion on 12/2/2019.
//

#include "PlaylistList.h"

PlaylistList::PlaylistList(){
    this->currentSize = 0;
    this->maxSize = 1;
    this->playlistArray = new Playlist*[1];
}

PlaylistList::~PlaylistList() {
    for(int i = 0; i < currentSize; i++){
        delete playlistArray[i];
    }
    delete[] playlistArray;
}

void PlaylistList::add(Playlist& playlistToAdd){
    if(this->currentSize >= this->maxSize){
        this->doubleSize();
    }
    this->playlistArray[currentSize++] = &playlistToAdd;
}

bool PlaylistList::remove(std::string playlistToRemove){
    int loc = _find(playlistToRemove);
    if(loc >= 0) {
        this->currentSize--;
        for (int i = loc; i < this->currentSize; i++) {
            this->playlistArray[i] = this->playlistArray[i + 1];
        }
        return true;
    }
    else return false;
}

bool PlaylistList::remove(Playlist &playlistToRemove) {
    return this->remove(playlistToRemove.getName());
}

Playlist* PlaylistList::find(std::string playlistToFind){
    int loc = _find(playlistToFind);
    if(loc >= 0) {
        return this->playlistArray[loc];
    }
    else return nullptr;
}

Playlist* PlaylistList::find(Playlist &playlistToFind) {
    return this->find(playlistToFind.getName());
}

void PlaylistList::doubleSize() {
    this->maxSize *= 2;
    Playlist** newPlaylistArray = new Playlist*[this->maxSize];
    for(int i = 0; i < this->currentSize; i++){
        newPlaylistArray[i] = this->playlistArray[i];
    }
    delete[] this->playlistArray;
    this->playlistArray = newPlaylistArray;
}

int PlaylistList::_find(std::string playListTofind){
    for(int i = 0; i < currentSize; i++){
        if(this->playlistArray[i]->getName() == playListTofind) {
            return i;
        }
    }
    return -1;
}

std::string PlaylistList::toString(){
    std::string returnString = "";
    for(int i = 0; i < this->currentSize; i++){
        returnString += this->playlistArray[i]->getName() + "\t" + std::to_string(this->playlistArray[i]->getDuration()) + "\n";
    }
    return returnString;
}