//
// Created by Kenny on 12/9/2019.
//

#include "Playlist.h"

int main(){
    std::ofstream writeFile;
    writeFile.open("writeExample.txt");
    writeFile << "Writing this to a file.\n";
    writeFile.close();

    std::ifstream readFile;
    std::string line;
    readFile.open("readExample.txt");
    while(getline(readFile, line)){
        std::cout << line << '\n';
    }
    readFile.close();

    return 0;
}
