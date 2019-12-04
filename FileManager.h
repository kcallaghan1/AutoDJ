//
// Created by LordOfConstructs on 12/3/2019.
//

#ifndef TERMPROJECT_FILEMANAGER_H
#define TERMPROJECT_FILEMANAGER_H

#include <fstream>
#include "PlaylistList.h"
#include "Library.h"

class FileManager {
public:
    PlaylistList* importPlaylistList(std::string fileName);
    void exportPlaylistList(PlaylistList& pll, std::string fileName);

    void importToLibrary(std::string fileName, Library& lib);
    void exportLibrary(Library& lib, std::string fileName);
};


#endif //TERMPROJECT_FILEMANAGER_H
