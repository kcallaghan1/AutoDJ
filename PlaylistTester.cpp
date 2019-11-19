//
// Created by Kenny on 11/19/2019.
//

#include "Playlist.h"

int main(){
    Song* song1 = new Song("Distance Overtime", "That Way", 280);
    Song* song2 = new Song("The Beatles", "Here Comes The Sun", 189);

    Playlist* myPlaylist = new Playlist("playlist1");
    std::cout << myPlaylist->getName() << std::endl; // Expected "playlist1"
    std::cout << myPlaylist->isEmpty() << std::endl; // Expected 1

    myPlaylist->addSong(song1);
    std::cout << myPlaylist->isEmpty() << std::endl; // Expected 0
    std::cout << myPlaylist->getSongCount() << std::endl; // Expected 1

    myPlaylist->addSong(song2);
    std::cout << myPlaylist->getSongCount() << std::endl; // Expected 2
    Song* returnedSong1 = myPlaylist->playNextSong();
    std::cout << returnedSong1->toString() << std::endl; // Expect song1.toString()
    std::cout << myPlaylist->playNextSong()->toString() << std::endl; // Expect song2.toString()
    std::cout << myPlaylist->isEmpty() << std:: endl; // Expected 1

    return 0;
}