//
// Created by LordOfConstructs on 12/3/2019.
//

#include "FileManager.h"

PlaylistList* FileManager::importPlaylistList(std::string fileName){
    std::ifstream* inputStream = new std::ifstream(fileName, std::ios::in);
    std::string parse;
    getline(*inputStream, parse, '\n');
    PlaylistList* pll = new PlaylistList();
    while(parse != "") {
        Playlist* pl = new Playlist(parse);
        int len;
        *inputStream >> len;
        std::string songInput;
        for(int i = 0; i < len; i++){
            getline(*inputStream, songInput, '\n');
            pl->addSong(new Song(songInput));
        }
        getline(*inputStream, parse, '\n');
    }
}

void FileManager::importToLibrary(std::string fileName, Library& lib) {
    std::ifstream* inputStream = new std::ifstream(fileName, std::ios::in);
    if(inputStream) {
        std::string parse;
        getline(*inputStream, parse, ',');
        while (parse != "") {
            lib.add(*(new Song(parse)));
        }
        inputStream->close();
    }
}

void FileManager::exportPlaylistList(PlaylistList &pll, std::string fileName){

}

void FileManager::exportLibrary(Library &lib, std::string fileName) {

}