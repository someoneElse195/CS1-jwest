/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*\
| Simple input output program,   |
| prints out 7 stages of hangman.|
| Written by amwest              |
\*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>
#include <string>

using namespace std;

void stageOne();
void stageTwo();
void stageThree();
void stageFour();
void stageFive();
void stageSix();
void stageSeven();

int main() {
    string name = "";
    cout << "Please input your name: ";
    cin >> name;
    cout << endl << "Welcome, " << name << "." << endl;

    stageOne(); 
    stageTwo();
    stageThree();
    stageFour();
    stageFive();
    stageSix();
    stageSeven();  

    return 0;
}

void stageOne() {
    string l1 = "  +---+";
    string l2 = "  |   |";
    string l3 = "      |";
    string l4 = "      |";
    string l5 = "      |";
    string l6 = "      |";
    string l7 = "=======";

    cout << "Stage 1: " << endl << l1 << endl << l2 << endl << l3 << endl << l4 << endl << l5 << endl << l6 << endl << l7 << endl << endl;
}

void stageTwo() {
    string l1 = "  +---+";
    string l2 = "  |   |";
    string l3 = "  0   |";
    string l4 = "      |";
    string l5 = "      |";
    string l6 = "      |";
    string l7 = "=======";

    cout << "Stage 2: " << endl << l1 << endl << l2 << endl << l3 << endl << l4 << endl << l5 << endl << l6 << endl << l7 << endl << endl;
}

void stageThree() {
    string l1 = "  +---+";
    string l2 = "  |   |";
    string l3 = "  0   |";
    string l4 = "  |   |";
    string l5 = "      |";
    string l6 = "      |";
    string l7 = "=======";

    cout << "Stage 3: " << endl << l1 << endl << l2 << endl << l3 << endl << l4 << endl << l5 << endl << l6 << endl << l7 << endl << endl;
}

void stageFour() {
    string l1 = "  +---+";
    string l2 = "  |   |";
    string l3 = "  0   |";
    string l4 = "  |\\  |";
    string l5 = "      |";
    string l6 = "      |";
    string l7 = "=======";

    cout << "Stage 4: " << endl << l1 << endl << l2 << endl << l3 << endl << l4 << endl << l5 << endl << l6 << endl << l7 << endl << endl;
}

void stageFive() {
    string l1 = "  +---+";
    string l2 = "  |   |";
    string l3 = "  0   |";
    string l4 = " /|\\  |";
    string l5 = "      |";
    string l6 = "      |";
    string l7 = "=======";

    cout << "Stage 5: " << endl << l1 << endl << l2 << endl << l3 << endl << l4 << endl << l5 << endl << l6 << endl << l7 << endl << endl;
}

void stageSix() {
    string l1 = "  +---+";
    string l2 = "  |   |";
    string l3 = "  0   |";
    string l4 = " /|\\  |";
    string l5 = " /    |";
    string l6 = "      |";
    string l7 = "=======";

    cout << "Stage 6: " << endl << l1 << endl << l2 << endl << l3 << endl << l4 << endl << l5 << endl << l6 << endl << l7 << endl << endl;
}

void stageSeven() {
    string l1 = "  +---+";
    string l2 = "  |   |";
    string l3 = "  0   |";
    string l4 = " /|\\  |";
    string l5 = " / \\  |";
    string l6 = "      |";
    string l7 = "=======";

    cout << "Stage 7: " << endl << l1 << endl << l2 << endl << l3 << endl << l4 << endl << l5 << endl << l6 << endl << l7 << endl << endl;
}