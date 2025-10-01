
ic.h"
#include <iostream>
#include <iomanip>
using namespace std;

Music::Music(const char* t, const char* a, int y, float d, const char* pub)
  : Media(t, y) {
  strncpy(artist, a, 99);
  artist[99] = '\0';
  duration = d;
  strncpy(publisher, pub, 99);
  publisher[99] = '\0';
}

Music::~Music() {}

void Music::print() const {
  cout << "[Music] " << title << ", " << year
       << ", Artist: " << artist
       << ", Duration: " << fixed << setprecision(2) << duration << " mins"
       << ", Publisher: " << publisher << endl;
}

const char* Music::getArtist() const {
  return artist;
}

float Music::getDuration() const {
  return duration;
}

const char* Music::getPublisher() const {
  return publisher;
}
