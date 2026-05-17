#ifndef GAME_H
#define GAME_H

#include <string>
using namespace std;

// Base class provided by instructor (CSC-213 Project)
class Game {
protected:
    string name;
    int score;

public:
    Game(string gameName) : name(gameName), score(0) {}
    virtual ~Game() {}

    // Pure virtual function - every derived game must implement this
    virtual void play() = 0;

    string getName() const { return name; }
    int getScore() const { return score; }

    virtual void displayScore() const {
        cout << "[" << name << "] Your score: " << score << endl;
    }
};

#endif
