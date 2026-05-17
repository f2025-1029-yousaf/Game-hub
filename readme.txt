================================================================
  PuzzleChallenge — OOP Game Hub
  Course: CSC-213 Object Oriented Programming
  Project Part 1
================================================================

FILES IN THIS REPOSITORY
--------------------------
Game.h            — Base class provided by instructor (abstract, pure virtual play())
Hangman.h         — Derived game: classic letter-guessing game
MathChallenge.h   — Derived game: random arithmetic questions with difficulty levels
Anagram.h         — Derived game: unscramble the letters to find the hidden word
main.cpp          — Entry point; uses polymorphism to randomly select and run games
words.txt         — Word list for Hangman (one word per line, uppercase)
anagram_words.txt — Word list for Anagram (format: WORD|hint, one per line)
readme.txt        — This file

HOW TO COMPILE & RUN
----------------------
Using g++ (any standard C++11 or later compiler):

    g++ main.cpp -o PuzzleChallenge
    ./PuzzleChallenge          (Linux/Mac)
    PuzzleChallenge.exe        (Windows)

Or with explicit standard flag:
    g++ -std=c++11 main.cpp -o PuzzleChallenge

GAME DESCRIPTIONS
------------------
1. HANGMAN
   - A word is randomly picked from words.txt
   - Player guesses one letter at a time
   - 6 wrong guesses allowed before game over
   - ASCII art draws the hangman as guesses go wrong
   - Score = number of words solved

2. MATH CHALLENGE
   - Choose difficulty: Easy (1-10), Medium (1-50), Hard (1-100)
   - Random arithmetic questions: +, -, *, /
   - Division always produces whole-number answers
   - Streak bonus: 3 correct in a row = +3 points instead of +1
   - Score accumulates across questions

3. ANAGRAM
   - A word from anagram_words.txt is scrambled randomly
   - Player types the unscrambled word
   - Type 'hint' to reveal a clue (-1 point penalty)
   - Type 'skip' to pass (no penalty)
   - Correct without hint = +2 points; with hint = +1 point

OOP CONCEPTS DEMONSTRATED
---------------------------
- Inheritance:     Hangman, MathChallenge, Anagram all extend Game
- Polymorphism:    main.cpp uses Game* array; play() dispatched at runtime
- Abstraction:     Game class is abstract (pure virtual play())
- Encapsulation:   Each game manages its own state privately
- Composition:     MathChallenge uses DifficultySettings struct
                   Anagram uses WordEntry struct
- File Handling:   Words loaded from external .txt files at runtime

AI DISCLOSURE
--------------
Code structure and logic were developed with assistance from Claude (Anthropic AI).
All generated code was reviewed, understood, and verified by the submitting student.
Students are able to explain and defend all code choices as required by the project rubric.
================================================================
