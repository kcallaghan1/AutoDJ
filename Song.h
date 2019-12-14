//
// Created by Kenny on 11/15/2019.
//

#ifndef TERMPROJECT_SONG_H
#define TERMPROJECT_SONG_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Song {
private:
    // Holds the artist who made the song.
    std::string artist;
    // Holds the title of the song.
    std::string title;
    // Holds the duration of the song in seconds.
    int duration;
    // Holds the number of times the song has been played.
    int playCount;


public:
    // Constructor: makes a new song based on user-input.
    Song(std::string artistIn, std::string titleIn, int durationIn);

    // Alternate constructor: creates a new song from string input:
    // String format: "Artist, Title, Duration (seconds)"
    Song(const std::string& songString);
/* Won't be necessary, as a Song object does not need any dynamic memory.
    // Copy-constructor:
    Song(const Song& songToCopy);

    // Overload assignment operator:
    Song& operator=(const Song& songToCopy);

    // Destructor:
    ~Song();
*/
    // Returns song's artist.
    std::string getArtist();

    // Returns song's title.
    std::string getTitle();

    // Returns song duration in seconds.
    int getDuration();

    // Returns the number of times the song has been played.
    int getPlayCount();

    // Returns song as string "Artist, Title, Duration (seconds), Playcount"
    std::string toString();

    // increase playCount by 1
    void incrementPlayCount();
};


#endif //TERMPROJECT_SONG_H
