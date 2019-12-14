//
// Created by LordOfConstructs on 12/2/2019.
//

#ifndef TERMPROJECT_LIBRARY_H
#define TERMPROJECT_LIBRARY_H

#import "Playlist.h"
#import "Song.h"
#import "SortedArrayList.h"

class Playlist;

class Library{
private:
    List<Song>* songList;
public:
    //Constructor and Destructor
    Library();
    ~Library();

    //Adds a song to the appropriate location in the library
    bool add(Song& songToAdd);
    //Finds and removes the playlist from the list of playlists, returns true if removed, false otherwise
    bool remove(std::string artist, std::string title);
    //Finds and returns the playlist from the list of playlists
    Song* find(std::string artist, std::string title);
    //Returns a string with all the songs in the library one to a line
    std::string toString();
    //Same as toString but only for a specific artist
    std::string toString(std::string artist);
    //Returns a random song from the library
    Song* randSong();
    //Populates the playlist passed with all the songs in the library in a random order.
    void popAllRandOrder(Playlist* pl);
};


#endif //TERMPROJECT_LIBRARY_H
