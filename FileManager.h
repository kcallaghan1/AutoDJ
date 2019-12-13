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
    void importPlaylistList(PlaylistList** pll, std::string fileName);
    void exportPlaylistList(PlaylistList& pll, std::string fileName);

    void importToLibrary(Library& lib, std::string fileName);
    void discontinueFromLibrary(Library& lib, std::string fileName);
    void exportLibrary(Library& lib, std::string fileName);
};


#endif //TERMPROJECT_FILEMANAGER_H
