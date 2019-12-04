//
// Created by Kenny on 11/19/2019.
//

#ifndef TERMPROJECT_PLAYLIST_H
#define TERMPROJECT_PLAYLIST_H

#include "Queue.h"
#include "SongNode.h"

class Playlist : public Queue{
private:
    // Holds the name of the playlist.
    std::string name;

    // Holds the number of songs in the playlist.
    int songCount;

    // Points to the first song in the playlist.
    SongNode* first;

    // Points to the last song in the playlist.
    SongNode* last;

    // Adds new song at the end of the playlist.
    void enqueue(Song* songToAdd);

    // Removes a song from the front of the playlist.
    Song* dequeue();

public:
    // Constructor
    Playlist(std::string nameIn);

    // Destructor
    ~Playlist();

    // Adds song to a playlist
    void addSong(Song* songToAdd);

    // Removes a song from a playlist and increments song's playCount
    // Throws exception if the playlist is empty.
    Song* playNextSong();

    // Returns the name of the playlist.
    std::string getName();

    // Returns the number of songs in the playlist.
    int getSongCount();

    // True if songCount == 0.
    bool isEmpty();

    // Returns the duration of a playlist
    int getDuration();

    // Removes song given specified artist and title.
    void removeSong(std::string artistIn, std::string titleIn);
};


#endif //TERMPROJECT_PLAYLIST_H
