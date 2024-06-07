#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class HangmanGame {
    private:
        int maxGuesses;
        int currentGuesses;
        string wordToGuess;
        string hint;
        vector<char> guessedLetters;

        bool contains(char c) {
            return find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end();
        }

        string getHiddenWord() {
            string hiddenWord;
            for (char c : wordToGuess) {
                if (contains(c)) {
                    hiddenWord += c;
                } else {
                    hiddenWord += '-';
                }
            }
            return hiddenWord;
        }

        void printStatus() {
            cout << "Guesses left: " << maxGuesses - currentGuesses << endl;
            cout << "Guessed letters: ";
            for (char c : guessedLetters) {
                cout << c << " ";
            }
            cout << endl;
            cout << "Hint: " << hint << endl;
            cout << "Word to guess: " << getHiddenWord() << endl;
        }

    public:
        HangmanGame(int maxGuesses, string wordToGuess, string hint) {
            this->maxGuesses = maxGuesses;
            this->currentGuesses = 0;
            this->wordToGuess = wordToGuess;
            this->hint = hint;
        }

        void play() {
            while (currentGuesses < maxGuesses) {
                printStatus();
                cout << "Enter a letter: ";
                char c;
                cin >> c;
                if (contains(c)) {
                    cout << "You already guessed that letter." << endl;
                } else {
                    guessedLetters.push_back(c);
                    if (wordToGuess.find(c) != string::npos) {
                        cout << "Correct guess!" << endl;
                    } else {
                        cout << "Incorrect guess." << endl;
                        currentGuesses++;
                    }
                }
                if (getHiddenWord() == wordToGuess) {
                    cout << "Congratulations, you guessed the word!" << endl;
                    return;
                }
            }
            cout << "You ran out of guesses. The word was " << wordToGuess << "." << endl;
        }
};

int main() {
    srand(time(nullptr));
    vector<string> words = {"apple", "banana", "cherry", "orange", "pear"};
    string wordToGuess = words[rand() % words.size()];
    string hint = "A type of fruit";
    HangmanGame game(6, wordToGuess, hint);
    game.play();
    return 0;
}
