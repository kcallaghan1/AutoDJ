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
    std::string durationString;

    getline(splitter, artist, ',');
    splitter.get(); // Used to get rid of space in front of artist.Only reasonable when "Artist, Title". If it is
    // written like "Artist,Title" without space, then it will break.
    getline(splitter, title, ',');
    getline(splitter, durationString, ',');
    duration = std::stoi(durationString);
    playCount = 0;
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
/*    output += ", ";
    output += std::to_string(playCount); */
    return output;
}

void Song::incrementPlayCount() {
    playCount++;
}