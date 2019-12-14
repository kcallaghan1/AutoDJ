//
// Created by LordOfConstructs on 12/3/2019.
//

#include "FileManager.h"

FileManager::FileManager(){
    this->path = "../SavedFiles/";
}

void FileManager::importPlaylistList(PlaylistList** pll, std::string fileName){  //Edit the line below this to be the correct folder
    std::ifstream* inputStream;
    *pll = new PlaylistList();
    try {
        inputStream= new std::ifstream(this->path + fileName);
    }
    catch(std::exception e){
        std::cout << "Error importing given file:  "  << e.what() << std::endl;
    }
    if(inputStream) {
        std::string parse;
        while(getline(*inputStream, parse) && parse != "") {
            Playlist *pl = new Playlist(parse);
            (*pll)->add(*pl);
            int len;
            *inputStream >> len;
            getline(*inputStream, parse);
            std::string songInput;
            for (int i = 0; i < len; i++) {
                getline(*inputStream, songInput);
                pl->addSong(new Song(songInput));
            }
        }
    }
}

void FileManager::importToLibrary(Library& lib, std::string fileName) {
    int count = 0;
    std::ifstream *inputStream = nullptr;
    try {
         inputStream = new std::ifstream(
                 this->path + fileName);
    }
    catch(std::exception e){
        std::cout << "Error importing given file:  "  << e.what() << std::endl;
    }
    if(inputStream) {
        std::string parse;
        while (getline(*inputStream, parse)) {
            if(lib.add(*(new Song(parse)))){
                count++;
            }
        }
        inputStream->close();
        std::cout << "Imported " << count << " songs!" << std::endl;
    }
}

void FileManager::discontinueFromLibrary(Library& lib, std::string fileName) {
    int count = 0;
    std::ifstream *inputStream = nullptr;
    try {
        inputStream = new std::ifstream(
                this->path + fileName);
    }
    catch(std::exception e){
        std::cout << "Error importing given file:  "  << e.what() << std::endl;
    }
    if(inputStream) {
        std::string parse;
        while (getline(*inputStream, parse)) {
            if(lib.remove(*(new Song(parse)))){
                count++;
            }
        }
        inputStream->close();
        std::cout << "Removed " << count << " songs!" << std::endl;
    }
}

void FileManager::exportPlaylistList(PlaylistList &pll, std::string fileName){
    std::ofstream *outputStream = nullptr;
    try {
        outputStream = new std::ofstream(
                this->path + fileName);
    }
    catch(std::exception e){
        std::cout << "Error importing given file:  "  << e.what() << std::endl;
    }
    if(outputStream){
        *outputStream << pll.store();
        outputStream->close();
    }
}

void FileManager::exportLibrary(Library &lib, std::string fileName) {
    std::ofstream *outputStream = nullptr;
    try {
        outputStream = new std::ofstream(
                this->path + fileName);
    }
    catch(std::exception e){
        std::cout << "Error importing given file:  "  << e.what() << std::endl;
    }
    if(outputStream){
        *outputStream << lib.toString();
        outputStream->close();
    }
}