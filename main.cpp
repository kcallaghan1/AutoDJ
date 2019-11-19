#include "SongNode.h"

int main() {
    Song* mySong = new Song("Distance Overtime", "That Way", 280);
    std::cout << mySong->toString() << std::endl;

    SongNode* node1 = new SongNode(mySong);
    std::cout << node1->getSong()->toString() << std::endl;


    std::cout << node1->getNext() << std::endl;

    Song* song2 = new Song("The Beatles", "Here Comes The Sun", 189);
    SongNode* node2 = new SongNode(song2);
    node1->setNext(node2);
    std::cout << node1->getNext()->getSong()->toString() << std::endl;
    return 0;
}