//
// Created by Kenny on 11/15/2019.
//

#include "Song.h"

Song::Song(std::string artistIn, std::string titleIn, int durationIn){
    artist = artistIn;
    title = titleIn;
    duration = durationIn;
    playCount = 0;
}

Song::Song(const std::string& songString){
    std::stringstream splitter (songString);
    std::string durationString, playedString;

    // Removes any whitespace from the front of an attribute
    while(splitter.peek() == ' '){
        splitter.get();
    }
    getline(splitter, artist, ',');

    // Removes any whitespace from the front of an attribute
    while(splitter.peek() == ' '){
        splitter.get();
    }
    getline(splitter, title, ',');

    // Removes any whitespace from the front of an attribute
    while(splitter.peek() == ' '){
        splitter.get();
    }
    getline(splitter, durationString, ',');
    duration = std::stoi(durationString);

    // Removes any whitespace from the front of an attribute
    while(splitter.peek() == ' '){
        splitter.get();
    }
    getline(splitter, playedString, ',');
    playCount = std::stoi(playedString);
}

std::string Song::getArtist() {
    return artist;
}

std::string Song::getTitle() {
    return title;
}

int Song::getDuration() {
    return duration;
}

int Song::getPlayCount() {
    return playCount;
}

std::string Song::toString() {
    std::string output;
    output += artist;
    output += ", ";
    output += title;
    output += ", ";
    output += std::to_string(duration);
    output += ", ";
    output += std::to_string(playCount);
    output += "\n";
    return output;
}

void Song::incrementPlayCount() {
    playCount++;
}

bool Song::operator==(Song& s){
    if(artist == s.artist && title == s.title)
        return true;
    else return false;
}

bool Song::operator!=(Song& s){
    return !(*this == s);
}

bool Song::operator>(Song& s){
    if(artist > s.artist)
        return true;
    else if(artist == s.artist && title > s.title)
        return true;
    else return false;
}

bool Song::operator<(Song& s){
    if(artist < s.artist)
        return true;
    else if(artist == s.artist && title < s.title)
        return true;
    else return false;
}

bool Song::operator>=(Song& s){
    if(artist > s.artist)
        return true;
    else if(artist == s.artist && title >= s.title)
        return true;
    else return false;
}

bool Song::operator<=(Song& s){
    if(artist < s.artist)
        return true;
    else if(artist == s.artist && title <= s.title)
        return true;
    else return false;
}