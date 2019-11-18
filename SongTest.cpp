//
// Created by Kenny on 11/18/2019.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Song.h"

Song createSongFromString(const std::string& songString){
    std::stringstream splitter (songString);
    std::string artist, title, duration;

    getline(splitter, artist, ',');
    splitter.get(); // Used to get rid of space in front of artist.Only reasonable when "Artist, Title". If it is
    // written like "Artist,Title" without space, then it will break.
    getline(splitter, title, ',');
    getline(splitter, duration, ',');

    std::cout << artist << std::endl;
    std::cout << title << std::endl;
    std::cout << std::stoi(duration) << std::endl;

    return Song(artist, title, std::stoi(duration));

}

int main() {
    Song song1("The Beatles", "Here Comes The Sun", 189);
    std::cout << song1.toString().compare("The Beatles, Here Comes The Sun, 189") << std::endl;
    Song song2 = createSongFromString("The Beatles, Here Comes The Sun, 189");
    std::cout << song1.toString() << std::endl;
    std::cout << song2.toString() << std::endl;
    std::cout << song1.toString().compare(song2.toString()) << std::endl;
}