#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"

class Movie : public Media {
public:
    Movie(const char* title, const char* director, int year, float duration, float rating);
    ~Movie();

    void print() const override;
    const char* getDirector() const;
    float getDuration() const;
    float getRating() const;

private:
    char director[100];
    float duration;
    float rating;
};

#endif
