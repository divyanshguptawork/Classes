#include "Movie.h"
#include <iostream>
#include <iomanip>
using namespace std;

Movie::Movie(const char* t, const char* d, int y, float dur, float r)
    : Media(t, y) {
    strncpy(director, d, 99);
    director[99] = '\0';
    duration = dur;
    rating = r;
}

Movie::~Movie() {}

void Movie::print() const {
    cout << "[Movie] " << title << ", " << year
         << ", Director: " << director
         << ", Duration: " << fixed << setprecision(2) << duration << " mins"
         << ", Rating: " << fixed << setprecision(1) << rating << endl;
}

const char* Movie::getDirector() const {
    return director;
}

float Movie::getDuration() const {
    return duration;
}

float Movie::getRating() const {
    return rating;
}
