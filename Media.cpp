#include "Media.h"

Media::Media(const char*t, int y) {
  stmcpy(title, t, 99);
  title[99] = '\0';
  year = y;
}
Media::~Media() {
  // Virtual destructor for cleanup
}

const char*Media::getTitle() const {
  return title;
}

int Media::getYear() const {
  return year;
}

