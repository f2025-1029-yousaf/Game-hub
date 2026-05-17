#ifndef ANAGRAM_H
#define ANAGRAM_H

/*
 * Anagram.h — Derived Game class for the Anagram game
 * Course: CSC-213 (Object Oriented Programming)
 * Description: Scrambles a word and asks the player to unscramble it.
 *              Word list is loaded from "anagram_words.txt" (file handling).
 *              Uses composition: WordEntry struct stores word + optional hint.
 *              Supports hints at the cost of points.
 *
 * AI Disclosure: Code structure and logic written with assistance from Claude (Anthropic).
 *                All code has been reviewed and understood by the submitting student.
 */

#include "Game.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// Composition: word paired with its hint
struct WordEntry {
    string word;
    string hint;
    WordEntry(string w, string h) : word(w), hint(h) {}
};

class Anagram : public Game {
private:
    vector<WordEntry> wordList;

    void loadWords() {
        ifstream file("anagram_words.txt");
        if (file.is_open()) {
            string word, hint;
            // Format: WORD|hint per line
            string line;
            while (getline(file, line)) {
                size_t sep = line.find('|');
                if (sep != string::npos) {
                    word = line.substr(0, sep);
                    hint = line.substr(sep + 1);
                    transform(word.begin(), word.end(), word.begin(), ::toupper);
                    wordList.push_back(WordEntry(word, hint));
                }
            }
            file.close();
        }
        // Fallback words with hints
        if (wordList.empty()) {
            wordList = {
                WordEntry("LISTEN",    "To pay attention with your ears"),
                WordEntry("SILENT",    "Making no sound"),
                WordEntry("TRIANGLE",  "A 3-sided polygon"),
                WordEntry("INTEGRAL",  "A calculus concept"),
                WordEntry("CINEMA",    "A place to watch movies"),
                WordEntry("ICEMAN",    "A character made of ice"),
                WordEntry("DUSTY",     "Covered in fine particles"),
                WordEntry("STUDY",     "To learn from books"),
                WordEntry("EARTH",     "Our home planet"),
                WordEntry("HEART",     "Pumps blood in your body"),
                WordEntry("STARE",     "To look fixedly"),
                WordEntry("TEARS",     "Drops from crying"),
                WordEntry("MASTER",    "An expert or owner"),
                WordEntry("STREAM",    "A small flowing body of water"),
                WordEntry("BINARY",    "Base-2 number system"),
            };
        }
    }

    string scramble(const string& word) const {
        string scrambled = word;
        // Keep shuffling until the scrambled version differs from original
        do {
            for (int i = (int)scrambled.size() - 1; i > 0; i--) {
                int j = rand() % (i + 1);
                swap(scrambled[i], scrambled[j]);
            }
        } while (scrambled == word && word.size() > 1);
        return scrambled;
    }

public:
    Anagram() : Game("Anagram") {
        srand((unsigned)time(nullptr));
        loadWords();
    }

    void play() override {
        cout << "\n========== ANAGRAM ==========\n";
        cout << "Unscramble the letters to form a valid word!\n";
        cout << "Type 'hint' to reveal the hint (-1 point).\n";
        cout << "Type 'skip' to skip the word (no penalty).\n\n";

        bool keepPlaying = true;

        while (keepPlaying) {
            // Pick a random word
            const WordEntry& entry = wordList[rand() % wordList.size()];
            string scrambled = scramble(entry.word);

            cout << "Scrambled: " << scrambled << "\n";
            cout << "Letters  : " << entry.word.size() << " letters\n";

            bool solved = false;
            bool hintUsed = false;

            while (!solved) {
                cout << "Your answer: ";
                string answer;
                cin >> answer;
                transform(answer.begin(), answer.end(), answer.begin(), ::toupper);

                if (answer == "HINT") {
                    if (!hintUsed) {
                        cout << "Hint: " << entry.hint << "\n";
                        hintUsed = true;
                        score = max(0, score - 1);
                        cout << "(Score -1 for using hint)\n";
                    } else {
                        cout << "Hint already used for this word.\n";
                    }
                } else if (answer == "SKIP") {
                    cout << "Skipped! The word was: " << entry.word << "\n";
                    break;
                } else if (answer == entry.word) {
                    int points = hintUsed ? 1 : 2;
                    score += points;
                    cout << "*** Correct! +" << points << " point(s) ***\n";
                    solved = true;
                } else {
                    cout << "Not quite. Try again (or type 'hint'/'skip').\n";
                }
            }

            displayScore();

            cout << "Next word? (y/n): ";
            char choice;
            cin >> choice;
            keepPlaying = (tolower(choice) == 'y');
        }
    }
};

#endif
