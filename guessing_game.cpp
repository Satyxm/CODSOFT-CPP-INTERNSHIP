#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
    int userGuess, secretNumber, attempts = 0;

    cout << "Welcome to the Number Guessing Game! Guess a number between 0 and 100." << endl;

    // Seed for random number generation
    srand(time(0));
    secretNumber = rand() % 101; // Generates a random number between 0 and 100

    while(true) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if(userGuess == secretNumber) {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
            break;
        } else if(userGuess > secretNumber) {
            cout << "Too high! Try a lower number." << endl;
        } else {
            cout << "Too low! Try a higher number." << endl;
        }
    }

    return 0;
}
