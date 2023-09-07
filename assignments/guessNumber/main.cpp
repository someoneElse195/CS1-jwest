/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\
| Guess the number game. Tracks statistics                |
| of times played, amount won, and amount lost.           |
| The game will continue until the user chooses to end.   |
| Written by amwest.                                      |
\*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


/* 
    1: Ask for users name and greet them. ##DONE##
    2: Define int randomNumber() that will return a random number from 1-20. ##DONE##
    3: Define int readNumber() that will prompt user to enter num and return guess. ##DONE##
        Check if number is between 1-20 ##DONE##
    4: Define int checkGuess(int user, int rand) that will compare user's guess to rand number and 
        return 0 if equal, -1 if first is less than second, and 2 otherwise ##DONE##
    5: Define game() to implement logic of the game
        a. Call randomNumber() ##DONE##
        b. Until game is over, ask player to guess using readNumber() ##DONE##
        c. Call checkGuess() to check the players guess. ##DONE##
        d. If player guesses within 6 tries the game is over and player wins. ##DONE##
        e. If player cannot guess within 6 tries, game ends and player loses. ##DONE##
        f. For every wrong guess inform the player if guess is too high or too low. ##DONE##
    6: When game ends, inform player if lost or won, and reveal random number if lost. ##DONE##
    7: Game will continue until player wants to quit. (Check when game ends) ##DONE##
    8: When game ends provide following stats to player: ##DONE##
        a. Number of times played 
        b. percent won
        c. percent lost
*/

#include <iostream>
#include <cmath>

using namespace std;

int randomNumber();
int readNumber();
int checkGuess(int userNum, int randNum);
bool game();
void win();
void lose();
void statistics(bool win);
bool restart();
void unittest();


int randNum;
int timesPlayed = 0;
int wins = 0;
int losses = 0;

int main() {
    string name = "Null";
    bool win = false;
    float percentWon;
    float percentLost;
   
    cout << "Hello, welcome to Guess the Number, please enter your name: ";
    cin >> name;
    cout << "\nWelcome " << name << "!\n\n";

    while(true) {
        win = game();
        statistics(win);
        if(restart()) {
            continue;
        } else {
            break;
        }
    }
    percentWon = 1.0* wins/timesPlayed * 100;
    percentLost = 1.0* losses/timesPlayed * 100;

    printf("\nYou played %d times, won %.2f%% of the games, and lost %.2f%% of the games. Thanks for playing!\n\n", timesPlayed, percentWon, percentLost);

    return 0;
}


int randomNumber() {
    srand((unsigned) time(NULL));
    int min = 1;
    int max = 20;
    int randNum = min + rand() % max;
    return randNum;
}

int readNumber() {
    int guess;
    while(true) {
        cout << "Guess the number from 1-20: ";
        cin >> guess;
        cout << "\n\n";
        if (guess <= 20 && guess >= 1) {
            break;
        } else {
            cout << "That number is not in the range 1-20.\n";
            continue;
        }
    }
    return guess;
}

int checkGuess(int userNum, int randNum) {
    if (userNum == randNum) {
        return 0;
    } else if (userNum < randNum) {
        return -1;
    } else {
        return 2;
    }
}

bool game() {
    int tries = 0;
    randNum = randomNumber(); 
    while(true) {
        if(tries == 6) {
            lose();
            return false;
        }
        int guess = readNumber();
        int check = checkGuess(guess, randNum);
        tries+=1;
        switch(check) {
            case 0:
                win();
                return true;
            case -1:
                cout << "Your guess is lower than the number.\n";
                continue;
            case 2:
                cout << "Your guess is higher than the number\n";
                continue;
        }
        
    }
}

void win() {
    cout << "You won! Congratulations you win a brand new car!!!!\n\n";
}

void lose() {
    cout << "You guessed 6 times, game over. The number was " << randNum << ". Try again!\n\n";
}

bool restart() {
    char YNCont;
    cout << "Would you like to continue the game? Y/N: ";
    cin >> YNCont;  
    if(tolower(YNCont) == 'y') {   
        return true;
    } else {
        return false;
    }
}

void statistics(bool win) {
    if(win) {
        wins+=1;
    } else {
        losses+=1;
    }
    timesPlayed+=1;
}

void unittest() {

}


