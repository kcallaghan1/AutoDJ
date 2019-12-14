//
// Created by Orion on 12/2/2019.
//

#include "PlaylistList.h"

PlaylistList::PlaylistList(){
    playlistList = new ArrayList<Playlist>();
}

PlaylistList::~PlaylistList() {
    delete playlistList;
}

bool PlaylistList::add(Playlist& playlistToAdd){
    return playlistList->add(playlistToAdd);
}

bool PlaylistList::remove(std::string playlistToRemove){
    Playlist* pl = new Playlist(playlistToRemove);
    bool result = playlistList->remove(*pl);
    delete pl;
    return result;
}

Playlist* PlaylistList::find(std::string playlistToFind){
    Playlist* pl = new Playlist(playlistToFind);
    Playlist* returnPL = playlistList->find(*pl);
    delete pl;
    return returnPL;
}

std::string PlaylistList::toString(){
    std::string output = "";
    for(int i = 0; i < playlistList->getSize(); i++){
        Playlist* pl = playlistList->get(i);
        output += pl->getName() + ", " + std::to_string(pl->getDuration()) + "\n";
    }
    return output;
}

std::string PlaylistList::store(){
    std::string output = "";
    for(int i = 0; i < playlistList->getSize(); i++){
        output += playlistList->get(i)->toString();
    }
    return output;
}