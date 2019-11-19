//
// Created by Kenny on 11/18/2019.
//

#include "Song.h"


int main() {
    Song song1("The Beatles", "Here Comes The Sun", 189);
    std::cout << song1.toString().compare("The Beatles, Here Comes The Sun, 189") << std::endl;
    Song song2 = Song("The Beatles, Here Comes The Sun, 189");
    std::cout << song1.toString() << std::endl;
    std::cout << song2.toString() << std::endl;
    std::cout << song1.toString().compare(song2.toString()) << std::endl;
}