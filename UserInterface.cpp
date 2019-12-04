//
// Created by Orion on 12/2/2019.
//

#import <iostream>
#import "Library.h"
#import "PlaylistList.h"
#import "FileManager.h"

void help(){
    std::cout <<
    "help\t\t\t\t\t\t\tBring up this menu again" << std::endl <<
    "library\t\t\t\t\t\t\tDisplay all songs in alphabetical order by artist (within artist alphabetical by song)" << std::endl <<
    "artist <artist>\t\t\t\t\tDisplay all songs for the given artist" << std::endl <<
    "song <artist, title>\t\t\tDisplay all information for the given song" << std::endl <<
    "import <filename>\t\t\t\tNOT IMPLEMENTED  Add all songs from the given file to the library. Print message to the user of any songs that already existed (do not add duplicates)" << std::endl <<
    "discontinue <filename>\t\t\tNOT IMPLEMENTED  Remove all songs from the given file from the library. Also remove these songs from any playlist in which they occur. Print message to the user of any songs that were not present (couldn't be removed)" << std::endl <<
    "playlists\t\t\t\t\t\tdisplay the names of all playlists and their durations" << std::endl <<
    "playlist <name>\t\t\t\t\tdisplay all songs left in the given playlist, and the duration (time it will take to play the remaining songs)" << std::endl <<
    "new <name>\t\t\t\t\t\tMake a new empty playlist with the given name" << std::endl <<
    "add <name, artist, title>\t\tAdd the given song to the end of the given playlist" << std::endl <<
    "remove <name, artist, title>\tremove the given song from the playlist" << std::endl <<
    "playnext <name>\t\t\t\t\tPrint all information about the next song to be played from the given playlist to the screen. Remove that song from the given playlist. Add to the playcount for that song in the library. If the playlist is now empty, it should be removed." << std::endl <<
    "newrandom <name, duration>\t\tNOT IMPLEMENTED  Make a new playlist with the given name, and populate it with a random group of songs that do not repeat (within this playlist) and are in some shuffled order.  the playlist will have as many songs as can fit without going over the the given duration" << std::endl <<
    "quit\t\t\t\t\t\t\t(SAVING NOT IMPLEMENTED) Save the library and all playlists and terminate execution" << std::endl;
}

void library(Library& lib){
    std::cout << lib.toString();
}

void artist(std::string artist, Library& lib){
    std::cout << lib.toString(artist);
}

void song(std::string artist, std::string title, Library& lib){
    Song* song = lib.find(artist, title);
    if(song != nullptr) {
        std::cout << song->toString() << std::endl;
    }
    else{
        std::cout << "Could not find song" << std::endl;
    }
}

void import(std::string fileName, Library& lib){
    FileManager* fm = new FileManager();
    fm->importToLibrary(fileName, lib);
}

void discontinue(){
    std::cout << "Not yet implemented!" << std::endl;
}

void playlists(PlaylistList& pll){
    std::cout << pll.toString();
}

void playlist(std::string name, PlaylistList& pll){
    Playlist* pl = pll.find(name);
    std::cout << pl->toString();
    std::cout << "Remaining Duration:  " << pl->getDuration() << std::endl;
}

void newPlaylist(std::string name, PlaylistList& pll) {
    Playlist *newPL = new Playlist(name);
    pll.add(*newPL);
    std::cout << "Added a new playlist with the name:  " << name << std::endl;
}

void add(std::string name, std::string artist, std::string title, PlaylistList& pll, Library& lib){
    Song* song = lib.find(artist, title);
    Playlist* pl = pll.find(name);
    if(song != nullptr && pl != nullptr){
        pl->addSong(song);
        std::cout << "Added song to playlist!" << std::endl;
    }
    else if(song == nullptr){
        std::cout << "Could not find song" << std::endl;
    }
    if(pl == nullptr){
        std::cout << "Could not find playlist" << std::endl;
    }
}

void remove(std::string name, std::string artist, std::string title, PlaylistList& pll, Library& lib){
    Playlist* pl = pll.find(name);
    if(pl != nullptr && pl->removeSong(artist, title)){
        std::cout << "Removed song from playlist!" << std::endl;
    }
    else if(pl == nullptr){
        std::cout << "Could not find playlist" << std::endl;
    }
    else{
        std::cout << "Could not find song:  " << artist << ", " << title << std::endl;
    }
}

void playNext(std::string name, PlaylistList& pll){
    Playlist* pl = pll.find(name);
    if(pl != nullptr && !pl->isEmpty()){
        Song* songToPlay =  pl->playNextSong();
        if(songToPlay != nullptr) {
            std::cout <<songToPlay->toString() << std::endl;
            if(pl->isEmpty()){
                std::cout << "Playlist is empty, deleting!" << std::endl;
                pll.remove(*pl);
            }
        }
    }
    else if(pl == nullptr){
        std::cout << "Could not find playlist" << std::endl;
    }
    else if(pl->isEmpty()){
        std::cout << "Playlist is empty, deleting!" << std::endl;
        pll.remove(*pl);
    }
}

void newRandom(){
    std::cout << "Not yet implemented!" << std::endl;
}

void save(){

}

bool parse(std::string input, Library& lib, PlaylistList& pll){
    std::stringstream ss(input);
    std::string func;
    getline(ss, func, ' ');
    if(func == "help"){
        help();
    }
    else if(func == "library"){
        library(lib);
    }
    else if(func == "artist"){
        std::string a;
        getline(ss, a, '\n');
        if(a != "") {
            artist(a, lib);
        }
        else{
            std::cout << "Please enter an artist!" << std::endl;
        }
    }
    else if(func == "song"){
        std::string a, t;

        // Removes any whitespace from the front of an attribute
        while(ss.peek() == ' '){
            ss.get();
        }
        getline(ss, a, ',');

        // Removes any whitespace from the front of an attribute
        while(ss.peek() == ' '){
            ss.get();
        }
        getline(ss, t, '\n');

        if(a != "" && t != ""){
            song(a, t, lib);
        }
        else{
            std::cout << "Please enter an artist and title!" << std::endl;
        }
    }
    else if(func == "import"){
        std::cout << "Not yet implemented!" << std::endl;
        /*std::string fn;
        while(ss.peek() == ' '){
            ss.get();
        }
        getline(ss, fn);
        import(fn, lib);*/
    }
    else if(func == "discontinue"){
        discontinue();
    }
    else if(func == "playlists"){
        playlists(pll);
    }
    else if(func == "playlist"){
        std::string n;
        getline(ss, n, '\n');
        if(n != "") {
            playlist(n, pll);
        }
        else{
            std::cout << "Please enter a playlist to view!" << std::endl;
        }
    }
    else if(func == "new"){
        std::string n;
        getline(ss, n, '\n');
        if(n != "") {
            newPlaylist(n, pll);
        }
        else{
            std::cout << "Please enter a name for the playlist!" << std::endl;
        }
    }
    else if(func == "add"){
        std::string n, a, t;

        // Removes any whitespace from the front of an attribute
        while(ss.peek() == ' '){
            ss.get();
        }
        getline(ss, n, ',');

        // Removes any whitespace from the front of an attribute
        while(ss.peek() == ' '){
            ss.get();
        }
        getline(ss, a, ',');

        // Removes any whitespace from the front of an attribute
        while(ss.peek() == ' '){
            ss.get();
        }
        getline(ss, t, '\n');

        if(n != "" && a != "" && t != "") {
            add(n, a, t, pll, lib);
        }
        else{
            std::cout << "Please enter a playlist name, artist, and title!" << std::endl;
        }
    }
    else if(func == "remove"){
        std::string n, a, t;

        // Removes any whitespace from the front of an attribute
        while(ss.peek() == ' '){
            ss.get();
        }
        getline(ss, n, ',');

        // Removes any whitespace from the front of an attribute
        while(ss.peek() == ' '){
            ss.get();
        }
        getline(ss, a, ',');

        // Removes any whitespace from the front of an attribute
        while(ss.peek() == ' '){
            ss.get();
        }
        getline(ss, t, '\n');

        if(n != "" && a != "" && t != "") {
            remove(n, a, t, pll, lib);
        }
        else {
            std::cout << "Please enter a playlist name, artist, and title!" << std::endl;
        }
    }
    else if(func == "playnext"){
        std::string n;
        getline(ss, n, '\n');
        if(n != "") {
            playNext(n, pll);
        }
        else{
            std::cout << "Please enter a name!" << std::endl;
        }
    }
    else if(func == "newrandom"){
        newRandom();
    }
    else if(func == "quit"){
        save();
        std::cout << "Quitting...";
        return false;
    }
    else{
        std::cout << "Didn't recognize that command...  Try again" << std::endl;
    }
    return true;
}

int main(){
    Library* lib = new Library();
    lib->add(*new Song("Usher", "Revenge", 100));
    lib->add(*new Song("Usher", "DJ Got Us Fallin' In Love", 87));
    lib->add(*new Song("Captain Sparkles", "Revenge", 104));
    PlaylistList* pll = new PlaylistList();
    std::cout << "Enter a command:  ";
    std::string input;
    getline(std::cin, input, '\n');
    while(parse(input, *lib, *pll)){
        std::cout << "Enter a command:  ";
        getline(std::cin, input, '\n');
    }
}