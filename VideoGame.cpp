#include "VideoGame.h"
#include <iostream>
#include <iomanip>
using namespace std;

VideoGame::VideoGame(const char*t, int y, const char* pub, float r)
  :Media(t,y){
  strncpy(publisher, pub, 99);
  publisher[99]='\0';
  rating = r;
}

VideoGame::~VideoGame() {}

void VideoGame::print() const {
  cout << "[Video Game]" << title << "," << year
       <<", Publisher: " << publisher
       << ", Rating:" << fixed << setprecision(1) << rating << endl;
}
const char* VideoGame::getPublisher() const {
  return publisher;
}

float VideoGame::getRating() const {
  return rating;
}
