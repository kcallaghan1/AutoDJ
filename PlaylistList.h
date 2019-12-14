//
// Created by Orion on 12/2/2019.
//

#ifndef TERMPROJECT_PLAYLISTLIST_H
#define TERMPROJECT_PLAYLISTLIST_H

#import "ArrayList.h"
#import "Playlist.h"

class PlaylistList{
private:
    List<Playlist>* playlistList;
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
};


#endif //TERMPROJECT_PLAYLISTLIST_H
