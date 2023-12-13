#include <iostream>
#include <iomanip>
#include "grid.h"

using namespace std;

#ifdef _WIN32
#define clearScreen() system ("cls") // not secure!
#else
#define clearScreen() system ("clear") // not secure!
#endif

void game(bool&, int&, int&);

int main() {

    bool player = 0;
    int xWin = 0;
    int oWin = 0;

    game(player, xWin, oWin);

}


void game(bool &player, int &xWin, int &oWin) {
    clearScreen();
    int gameEnd = -1;
    while(gameEnd == -1) {
        char play = 'y';
        bool gameActive = true;

        while(gameActive) {
            Grid gameGrid;

            for (int z = 0; z < 3; z++) {
                for(int j = 0; j < 3; j++) {
                    for(int i = 0; i < 3; i++) {
                        if (gameGrid.getCell(i,j) == -1) {
                            cout << "   ";
                        } else if (gameGrid.getCell(i,j) == 0) {
                            cout << " O ";
                        } else {
                            cout << " X ";
                        } 
                        if (i!=2) {
                            cout << "#";
                        }
                    } 
                    cout << endl;
                }
                if (z!=2) {
                    cout << "###########\n";
                }
            }

            gameActive = false;

        }
        

        cout << "Would you like to continue? y to continue, anything else to quit. ";
        cin >> play;

        switch (play) {
            case 'y':
                clearScreen();
                continue;
            default:
                clearScreen();
                gameEnd = 0;
                break;
        }
    }
}

