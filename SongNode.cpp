//
// Created by Kenny on 11/19/2019.
//

#include "SongNode.h"

SongNode::SongNode(Song& songIn){
    songPtr = new Song(songIn.toString());
    nextSong = nullptr;
}

SongNode::SongNode(Song* songIn){
    songPtr = new Song(songIn->toString());
    nextSong = nullptr;
}

SongNode::SongNode(const SongNode& songIn){
    Song* songToEnter = new Song(songIn.songPtr->toString());
    songPtr = songToEnter;
    nextSong = nullptr;
}

SongNode::~SongNode(){
    delete songPtr;
}

Song* SongNode::getSong() {
    return songPtr;
}

SongNode* SongNode::getNext() {
    return nextSong;
}

void SongNode::setSong(Song* songIn) {
    songPtr = songIn;
}

void SongNode::setNext(SongNode* songNodeIn) {
    nextSong = songNodeIn;
}