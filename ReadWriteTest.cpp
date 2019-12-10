//
// Created by Kenny on 12/9/2019.
//

#include "Playlist.h"

int main(){
    std::ofstream writeFile;
    writeFile.open("C:/Users/Kenny/CLionProjects/AutoDJ-master/writeExample.txt"); // Replace this with the path that is unique to your system.
    writeFile << "Writing this to a file.\n";
    writeFile.close();

    std::ifstream readFile;
    std::string line;
    readFile.open("C:/Users/Kenny/CLionProjects/AutoDJ-master/readExample.txt"); // Replace this with the path that is unique to your system.
    while(getline(readFile, line)){
        std::cout << line << '\n';
    }
    readFile.close();

    return 0;
}
