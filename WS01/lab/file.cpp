#define _CRT_SECURE_NO_WARNINGS
#include "file.h"
#include <cstdio>  // For file operations

namespace seneca {

    FILE* fptr = nullptr;  // Initialize the global file pointer

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != nullptr;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool readTitle(char title[]) {
        return fscanf(fptr, "%[^(](", title) == 1;
    }

    bool readYear(int* year) {
        return fscanf(fptr, "%d)", year) == 1;
    }

    bool readMovieRating(char rating[]) {
        return fscanf(fptr, " %[^|]|", rating) == 1;
    }

    bool readDuration(int* duration) {
        return fscanf(fptr, "%d|", duration) == 1;
    }

    bool readGenres(char genre[][11]) {
        char genres[256];
        int gi = 0; // Genres index
        int i = 0;  // genre[i] index
        int j = 0;  // genre[i][j] index
        bool res = fscanf(fptr, " %[^|]|", genres);
        if (res) {  // Spreading CSV to an array of strings
            res = false;
            while (genres[gi]) {
                if (genres[gi] != ',') {
                    genre[i][j++] = genres[gi++];
                    res = true;
                }
                else {
                    genre[i][j] = '\0';
                    i++;
                    gi++;
                    j = 0;
                }
            }
        }
        genre[i++][j] = '\0';
        genre[i][0] = '\0';  // NULL terminating the array of strings
        return res;
    }

    bool readConsumerRating(float* rating) {
        return fscanf(fptr, "%f\n", rating) == 1;
    }

}
