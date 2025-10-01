#include <iostream>
#include <vector>
#include <cstring>
#include "Media.h"
#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"
using namespace std;

void addMedia(vector<Media*>& db);
void searchMedia(const vector<Media*>& db);
void deleteMedia(vector<Media*>& db);

int main() {
    vector<Media*> database;
    char command[20];

    cout << "Commands: ADD, SEARCH, DELETE, QUIT" << endl;

    while (true) {
        cout << "\nEnter command: ";
        cin >> command;

        if (strcmp(command, "ADD") == 0) {
            addMedia(database);
        } else if (strcmp(command, "SEARCH") == 0) {
            searchMedia(database);
        } else if (strcmp(command, "DELETE") == 0) {
            deleteMedia(database);
        } else if (strcmp(command, "QUIT") == 0) {
            for (Media* m : database) delete m;
            database.clear();
            break;
        } else {
            cout << "Invalid command." << endl;
        }
    }
    return 0;
}

void addMedia(vector<Media*>& db) {
    char type[20];
    cout << "Enter type (VIDEOGAME, MUSIC, MOVIE): ";
    cin >> type;

    if (strcmp(type, "VIDEOGAME") == 0) {
        char title[100], publisher[100];
        int year;
        float rating;
        cout << "Title: "; cin.ignore(); cin.getline(title, 100);
        cout << "Year: "; cin >> year;
        cout << "Publisher: "; cin.ignore(); cin.getline(publisher, 100);
        cout << "Rating: "; cin >> rating;
        db.push_back(new VideoGame(title, year, publisher, rating));
    }
    else if (strcmp(type, "MUSIC") == 0) {
        char title[100], artist[100], publisher[100];
        int year;
        float duration;
        cout << "Title: "; cin.ignore(); cin.getline(title, 100);
        cout << "Artist: "; cin.getline(artist, 100);
        cout << "Year: "; cin >> year;
        cout << "Duration (minutes): "; cin >> duration;
        cout << "Publisher: "; cin.ignore(); cin.getline(publisher, 100);
        db.push_back(new Music(title, artist, year, duration, publisher));
    }
    else if (strcmp(type, "MOVIE") == 0) {
        char title[100], director[100];
        int year;
        float duration, rating;
        cout << "Title: "; cin.ignore(); cin.getline(title, 100);
        cout << "Director: "; cin.getline(director, 100);
        cout << "Year: "; cin >> year;
        cout << "Duration (minutes): "; cin >> duration;
        cout << "Rating: "; cin >> rating;
        db.push_back(new Movie(title, director, year, duration, rating));
    }
    else {
        cout << "Unknown media type." << endl;
    }
}

void searchMedia(const vector<Media*>& db) {
    char criteria[20];
    cout << "Search by TITLE or YEAR? ";
    cin >> criteria;

    if (strcmp(criteria, "TITLE") == 0) {
        char title[100];
        cout << "Enter title: "; cin.ignore(); cin.getline(title, 100);
        for (Media* m : db) {
            if (strcmp(m->getTitle(), title) == 0) {
                m->print();
            }
        }
    }
    else if (strcmp(criteria, "YEAR") == 0) {
        int year;
        cout << "Enter year: "; cin >> year;
        for (Media* m : db) {
            if (m->getYear() == year) {
                m->print();
            }
        }
    }
}

void deleteMedia(vector<Media*>& db) {
    char criteria[20];
    cout << "Delete by TITLE or YEAR? ";
    cin >> criteria;

    if (strcmp(criteria, "TITLE") == 0) {
        char title[100];
        cout << "Enter title: "; cin.ignore(); cin.getline(title, 100);

        for (auto it = db.begin(); it != db.end();) {
            if (strcmp((*it)->getTitle(), title) == 0) {
                (*it)->print();
                cout << "Delete this? (y/n): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y') {
                    delete *it;
                    it = db.erase(it);
                    cout << "Deleted." << endl;
                } else {
                    ++it;
                }
            } else {
                ++it;
            }
        }
    }
    else if (strcmp(criteria, "YEAR") == 0) {
        int year;
        cout << "Enter year: "; cin >> year;

        for (auto it = db.begin(); it != db.end();) {
            if ((*it)->getYear() == year) {
                (*it)->print();
                cout << "Delete this? (y/n): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y') {
                    delete *it;
                    it = db.erase(it);
                    cout << "Deleted." << endl;
                } else {
                    ++it;
                }
            } else {
                ++it;
            }
        }
    }
}
