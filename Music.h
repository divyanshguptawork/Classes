#ifndef MUSIC_H
#define MUSIC_H
#include "Media.h"

class Music: public Media {
 public:
  Music(const char*title, const char*artist, int year, float duration, const char* publisher);
  ~Music();

  void print() const override;
  const char* getArtist() const;
  float getDuration() const;
  const char* getPublisher() const;

 private:
  char artist[100];
  float duration;
  char publisher[100];
};

#endif
