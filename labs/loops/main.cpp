/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*\
|                                 Loops Lab (5)                                |
|                           Updated By: June West                              |
|                                  CSCI 111                                    |
|                               Date: 9/11/23                                  |
|                                                                              | 
|      Program prints geometric shapes of given height with * using loops      |
\*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printTriangle(int height) {
    //Function takes height as an argument to print the triangle
    //of that height with *
    int row = 1;
    // row
    while (row <= height) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row += 1;
        cout << endl;
    }
    cout << endl;
}


void printFlippedTriangle(int height) {
    /* 
    Implement the function that takes height as an argument
    and prints a triangle with * of given height.
    Triangle of height 5, e.g., should look like the following.
    * * * * *
    * * * *
    * * *
    * *
    *
    
    */
    // FIXME3 ... ##FIXED##
    
    while (height >= 0) {
        // column
        for(int col = 1; col<=height; col++)
            cout << "* ";
        height -= 1;
        cout << endl;
    }
    cout << endl;

}

void printSquare(int height) {
    /*  
    FIXME4 ##FIXED##
    Design and implement a function that takes an integer as height and
    prints square of the given height with *.
    Square of height 5, e.g., would look like the following.

    *  *  *  *  *  
    *  *  *  *  *   
    *  *  *  *  *   
    *  *  *  *  *   
    *  *  *  *  *   

    */
    for(int i = 0; i < height; i ++) {
        for(int e = 0; e < height; e++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;

}

// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main(int argc, char* argv[]) {
    // FIXME5 add a loop to make the program to continue to run until the user wants to quit ##FIXED##
    // FIXME6 call clearScreen function to clear the screen for each round of the loop ##FIXED##
    char end = 'y';

    while(true) {
        clearScreen();
        int height;
        cout << "Program prints geometric shapes of given height with *\n";
        cout << "Please enter the height of the shape: ";
        cin >> height;
        // call printTriangle function passing user entered height
        printTriangle(height);

        // FIXME7 ##FIXED
        // Call printFlippedTriangle passing proper argument
        // Manually test the function
        printFlippedTriangle(height);

        // FIXME6 ##FIXED
        // Call the function defined in FIXME4 passing proper argument
        // Manually test the function
        printSquare(height);

        cout << "Continue? y/Y to continue. Anything else to quit: ";
        // FIXME9 ##FIXED##
        // prompt user to enter y/Y to continue anything else to quit 
        cin >> end;

        // FIXME10 ##FIXED##
        // Use conditional statements to break the loop or continue the loop
        if (end == 'y' || end == 'Y') {
            continue;
        } else {
            break;
        }
    }

    return 0;

}