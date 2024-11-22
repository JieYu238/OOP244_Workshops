#ifndef FILE_H
#define FILE_H

#include <cstdio>  // For FILE operations

namespace seneca {

    extern FILE* fptr;  // Global file pointer

    bool openFile(const char filename[]);
    void closeFile();
    bool readTitle(char title[]);
    bool readYear(int* year);
    bool readMovieRating(char rating[]);
    bool readDuration(int* duration);
    bool readGenres(char genres[][11]);
    bool readConsumerRating(float* rating);

}

#endif  // FILE_H
