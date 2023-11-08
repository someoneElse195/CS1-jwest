/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\
| Guess the number game. Tracks statistics                |
| of times played, amount won, and amount lost.           |
| The game will continue until the user chooses to end.   |
| Written by June West.                                   |
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
#include <cassert>

using namespace std;

//Declaring functions.
int randomNumber();
int readNumber();
int checkGuess(int userNum, int randNum);
bool game();
bool restart();
void unittest();

int main(int args, char* argv[]) {

    if(args > 1 && string(argv[1]) == "test") {
        unittest();
        return 0;
    }

    string name = "Null";
    bool win = false;
    int timesPlayed = 0;
    int timesWon = 0;
    int timesLost = 0;
    float percentWon;
    float percentLost;
   
    cout << "Hello, welcome to Guess the Number, please enter your name: ";
    cin >> name;
    cout << "\nWelcome " << name << "!\n\n";

    //Loop to keep track of wins, update statistics, check if restarting, and most importantly call the game function.
    while(true) {
        win = game();
        if(win) {
            timesWon+=1;
        } else {
            timesLost+=1;
        }
        timesPlayed+=1;
        if(restart()) {
            continue;
        } else {
            break;
        }
    }
    //Calculate and output times won and times lost. 
    percentWon = 1.0* timesWon/timesPlayed * 100;
    percentLost = 1.0* timesLost/timesPlayed * 100;

    printf("\nYou played %d times, won %.2f%% of the games, and lost %.2f%% of the games. Thanks for playing!\n\n", timesPlayed, percentWon, percentLost);

    return 0;
}

//Function to generate a random number between min (1) and max (20).
int randomNumber() {
    srand((unsigned) time(NULL));
    int min = 1;
    int max = 20;
    int randNum = min + rand() % max;
    return randNum;
}

//Function to take in a number from the user and return it. If number is not 1-20 it will ask agai until it recieves one.
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

//Compares the user's guess to the random number. Returns 0 if equal, -1 if less than, and 2 otherwise.
int checkGuess(int userNum, int randNum) {
    if (userNum == randNum) {
        return 0;
    } else if (userNum < randNum) {
        return -1;
    } else {
        return 2;
    }
}

//The function to actually play the game.
bool game() {
    int tries = 0;
    int randNum = randomNumber(); 
    //Loop to keep the game going until either won or guesses = 6. 
    while(true) {
        if(tries == 6) {
            cout << "You guessed 6 times, game over. The number was " << randNum << ". Try again!\n\n";
            return false;
        }
        int guess = readNumber();
        int check = checkGuess(guess, randNum);
        //Increment the amount of tries each time a guess is made.
        tries+=1;
        //Switch to check if number is =, <, or > using checkGuess.
        switch(check) {
            case 0:
                cout << "You won! Congratulations you win a brand new car!!!!\n\n";
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

//Function to check if user wants to continue playing the game.
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

//Function to test the checkGuess function.
void unittest() {
    assert(checkGuess(5, 5) == 0);
    assert(checkGuess(5, 2) == 2);
    assert(checkGuess(5, 10) == -1);
    cout << "\nAll test cases passed\n\n";
}


