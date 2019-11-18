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