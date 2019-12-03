cmake_minimum_required(VERSION 3.15)
project(TermProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(TermProject Song.cpp Song.h Queue.h Playlist.cpp Playlist.h SongNode.cpp SongNode.h SortedVector.h Vector.h PlaylistList.cpp PlaylistList.h Library.cpp Library.h UserInterface.cpp)