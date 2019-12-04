//
// Created by Kenny on 11/19/2019.
//

#include "Playlist.h"

int main(){
    Song* song1 = new Song("Distance Overtime", "That Way", 280);
    Song* song2 = new Song("The Beatles", "Here Comes The Sun", 189);
    Song* song3 = new Song("Phish", "Reba", 840);

    Playlist* myPlaylist = new Playlist("playlist1");
    std::cout << myPlaylist->getName() << std::endl; // Expected "playlist1"
    std::cout << myPlaylist->isEmpty() << std::endl; // Expected 1
    std::cout << myPlaylist->getDuration() << std::endl; // Expected 0

    myPlaylist->addSong(song1);
    std::cout << myPlaylist->isEmpty() << std::endl; // Expected 0
    std::cout << myPlaylist->getSongCount() << std::endl; // Expected 1
    std::cout << myPlaylist->getDuration() << std::endl; // Expected 280

    myPlaylist->addSong(song2);
    std::cout << myPlaylist->getSongCount() << std::endl; // Expected 2
    std::cout << myPlaylist->getDuration() << std::endl; // Expected 469
    Song* returnedSong1 = myPlaylist->playNextSong();
    std::cout << returnedSong1->toString() << std::endl; // Expect song1.toString()
    std::cout << returnedSong1->getPlayCount() << std::endl; // Expected 1
    std::cout << myPlaylist->playNextSong()->toString() << std::endl; // Expect song2.toString()
    std::cout << myPlaylist->isEmpty() << std:: endl; // Expected 1

    myPlaylist->addSong(song1);
    myPlaylist->addSong(song2);
    std::cout << myPlaylist->getDuration() << std::endl; // Expected 469
    std::cout << myPlaylist->getSongCount() << std::endl; // Expected 2
    myPlaylist->removeSong("The Beatles", "Here Comes The Sun");
    std::cout << myPlaylist->getSongCount() << std::endl; // Expected 1
    std::cout << myPlaylist->getDuration() << std::endl; // Expected 189
    myPlaylist->addSong(song2);
    myPlaylist->addSong(song3);
    std::cout << myPlaylist->getDuration() << std::endl; // Expected 1309
    myPlaylist->removeSong("The Beatles", "Here Comes The Sun");
    std::cout << myPlaylist->getDuration() << std::endl; // Expected 1120
    myPlaylist->removeSong("Phish", "Reba");
    std::cout << myPlaylist->getDuration() << std::endl; // Expected 280
    myPlaylist->removeSong("Distance Overtime", "That Way");
    std::cout << myPlaylist->getDuration() << std::endl; // Expected 0

    return 0;
}