//
// Created by Kenny on 11/19/2019.
//

#ifndef TERMPROJECT_SONGNODE_H
#define TERMPROJECT_SONGNODE_H

#include "Song.h"

class SongNode {
private:
    // Points to a song, for use in a playlist
    Song* songPtr;

    // Points to the next song in a playlist.
    SongNode* nextSong;

public:
    // creates a new SongNode from the given song.
    SongNode(Song& songIn);
    SongNode(Song* songIn);

    // copy constructor for SongNode, "nextSong" is set to null.
    SongNode(const SongNode& songNodeIn);

    // destructor for SongNode.
    ~SongNode();

    // returns the Song pointed to by songPtr.
    Song* getSong();

    // returns the song pointed to by nextSong;
    SongNode* getNext();

    // sets the Song in songPtr to the user-defined song.
    void setSong(Song* songIn);

    // sets the Song in nextSong to the user-defined song.
    void setNext(SongNode* songNodeIn);
};


#endif //TERMPROJECT_SONGNODE_H
