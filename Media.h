#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

class Media {
 public:
  Media(const char* title, int year);
  virtual ~Media();

  virtual void print() const = 0; //pure virtual
  const char* getTitle() const;
  int getYear() const;

 protected:
  char title[100];
  int year;
};
#endif
