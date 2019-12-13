//
// Created by Orion on 12/2/2019.
//

#ifndef TERMPROJECT_PLAYLISTLIST_H
#define TERMPROJECT_PLAYLISTLIST_H

#import "Vector.h"
#import "Playlist.h"

class PlaylistList : public Vector<Playlist>{
private:
    //Keeps track of the amount of playlists the array currently holds, and how many it can hold at maximum
    int currentSize, maxSize;
    //Holds the pointer to the main array of playlists
    Playlist** playlistArray;
    //Finds a playlist's index based on the name and returns it
    int _find(std::string playListToFind);
    //Doubles the max capacity of the array and moves contents over
    void doubleSize();
public:
    //Constructor and Destructor
    PlaylistList();
    ~PlaylistList();

    //Adds a playlist to the end of the list of playlists
    bool add(Playlist& playlistToAdd);
    //Finds and removes the playlist from the list of playlists
    bool remove(std::string playlistToRemove);
    //Finds and returns the playlist from the list of playlists
    Playlist* find(std::string playlistToFind);
    //Returns a string with the names of all the playlists, one per line
    std::string toString();
    //Returns a string with the following info for each playlist:  Name, Size, each song's toString
    std::string store();

    //Adding these remove and find functions to keep the incrastructure happy
    bool remove(Playlist& playlistToRemove);
    Playlist* find(Playlist& playlistToFind);
};


#endif //TERMPROJECT_PLAYLISTLIST_H
