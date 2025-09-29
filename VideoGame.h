#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Media.h"

class VideoGame: public Media {
 public:
  VideoGame(const char* title, int year, const char* publisher, float rating);
  ~VideoGame();

  void print() const override;
  const char* getPublisher() const;
  float getRating() const;

 private:
  char publisher[100];
  float rating;
};

#endif
