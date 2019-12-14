//
// Created by LordOfConstructs on 12/2/2019.
//

#include "Library.h"

Library::Library(){
    songList = new SortedArrayList<Song>();
}

Library::~Library(){
    delete songList;
}

bool Library::add(Song& songToAdd){
    return songList->add(songToAdd);
}

bool Library::remove(std::string artist, std::string title){
    Song* temp = new Song(artist, title, 0);
    bool result = songList->remove(*temp);
    delete temp;
    return result;
}

Song* Library::find(std::string artist, std::string title){
    Song* temp = new Song(artist, title, 0);
    Song* result = songList->find(*temp);
    delete temp;
    return result;
}

std::string Library::toString(){
    std::string returnString = "";
    for(int i = 0; i < songList->getSize(); i++){
        returnString += songList->get(i)->toString();
    }
    return returnString;
}

std::string Library::toString(std::string artist){
    std::string returnString = "";
    for(int i = 0; i < songList->getSize(); i++){
        if(songList->get(i)->getArtist() == artist) {
            returnString += songList->get(i)->toString();
        }
    }
    return returnString;
}

Song* Library::randSong() {
    int loc = rand() % songList->getSize();
    return songList->get(loc);
}

void Library::popAllRandOrder(Playlist* pl){
    Song** shuffledSongArr = new Song*[songList->getSize()];
    for(int i = 0; i < songList->getSize(); i++){
        shuffledSongArr[i] = songList->get(i);
    }

    for(int i = 0; i < songList->getSize() * 5; i++){
        Song* temp;
        int loc1 = rand() % songList->getSize(), loc2 = rand() % songList->getSize();
        temp = shuffledSongArr[loc1];
        shuffledSongArr[loc1] = shuffledSongArr[loc2];
        shuffledSongArr[loc2] = temp;
    }

    for(int i = 0; i < songList->getSize(); i++){
        pl->addSong(shuffledSongArr[i]);
    }
    delete[] shuffledSongArr;
}