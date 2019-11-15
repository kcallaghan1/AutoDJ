#include <iostream>
#include "Song.h"

int main() {
    Song* mySong = new Song("Distance Overtime", "That Way", 260);
    std::cout << mySong->toString() << std::endl;
    return 0;
}