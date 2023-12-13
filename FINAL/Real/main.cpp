
        //=========================================================================================================================================================//
        //                                                                    TIC TAC TOE                                                                          //
        //=========================================================================================================================================================//

        /*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\
        |    Originally this project was going to include far more. I have a basic GUI app built to play tic tac toe in, but I ended up in a bit over my head...    |
        |         While I wish I could have finished that version of it (and I likely will over break), this is the version that I made for class.                  |
        |      I did this without looking at my previous version I made in Java for my classes at OU to be able to compare how different these two were.            |
        |                             All in all, this one is far better than my last version but it could still use A LOT of work.                                 |
        |                                   From system calls to just weird algorithms I have a lot of work to improve this.                                        |
        |                                            Hope you enjoyed the program whoever may be reading this! ^-^                                                  |
        |                                Written by June West for the final in Jeremy Bergen's CS1 class at Colorado Mesa University.                               |
        \*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Grid.h"

using namespace std;

#ifdef _WIN32
#define clearScreen() system ("cls") // not secure!
#else
#define clearScreen() system ("clear") // not secure!
#endif


string welcome();
void game(bool&, int&, int&, int&);
void printBoard(Grid);
void aiChoose(Grid&, int&, int&, int, int);
void aiChooseRandom(Grid&, int&, int&);
int choosePlayer();
void printStats(string, int, int, int);

int main() {

    bool player = 0;
    int playerW = 0;
    int aiW = 0;
    int draw = 0;

    string playerName = welcome();

    game(player, playerW, aiW, draw);

    printf("Hope you enjoyed %s, you played %i times...\n", playerName.c_str(), (playerW+aiW+draw));

    printf("You won %i time(s), the AI won %i time(s), and drew %i time(s).\nThis will all be saved to stats.txt in the folder you ran this executable!\n", playerW, aiW, draw);

    printStats(playerName, playerW, aiW, draw);

}


string welcome() {
    string name;
    cout << "Welcome to Tic-Tac-Toe! Please enter your name: ";
    cin >> name;
    return name;
}

void game(bool &player, int &xWin, int &oWin, int &draw) {
    clearScreen();
    int gameEnd = -1;
    while(gameEnd == -1) {
        Grid gameGrid;
        char play = 'y';
        bool gameActive = true;
        int player = 0;
        int x;
        int y;
        int userPlayer = -1;

        do {
            userPlayer = choosePlayer();
        } while(userPlayer == -1);

        while(gameActive) {
            bool selecting = true;
            
            clearScreen();
            printBoard(gameGrid); 


                while (selecting) {
                    
                    if(player == userPlayer) {
                        printf("\nIt is your turn.\nPlease choose a space to play by entering the coordinates of the space in the format 'x y': ");
                        cin >> x >> y;
                        cout << endl;
                        if(gameGrid.getCell(x,y) == -1) {
                            gameGrid.setCell(x,y, player);
                            selecting = false;
    
                        } else {
                            cout << "That square is already filled... \n\n";
                        }
                    } else {
                        cout << "DEBUG: INSIDE SELECTING LOOP AI SELECTION" << endl;
                        aiChoose(gameGrid, x, y, player, userPlayer);
                        gameGrid.setCell(x,y,player);
                        selecting = false;
                    }




                }

                if(gameGrid.checkWin()) {
                    clearScreen();
                    gameActive = false;
                    printf("Player %i wins!\n\n", player+1);
                    if (player == 0) {
                        xWin++;
                    } else {
                        oWin++;
                    }
                    cout << "Game end board: \n";
                    printBoard(gameGrid);

                } else if(gameGrid.checkDraw()) {
                    clearScreen();
                    gameActive = false;
                    cout << "The game resulted in a draw.\n";
                    draw++;
                    cout << "Game end board: \n";
                    printBoard(gameGrid);
                }else {
                    if(player == 0) {
                        player = 1;
                        } else {
                            player = 0;
                    }
                }



        }
        

        cout << "\nWould you like to continue? y to continue, anything else to quit. ";
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


void printBoard(Grid gameGrid) {
    cout << "\n     #     #     \n";
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 3; i++) {
            if (gameGrid.getCell(i,j) == -1) {
                cout << "     ";
            } else if (gameGrid.getCell(i,j) == 0) {
                cout << "  X  ";
            } else {
                cout << "  O  ";
            } 
            if (i!=2) {
                cout << "#";
            }
        } 
        if(j!=2) {
            cout << "\n     #     #     \n#################\n     #     #     \n";
        } else {
            cout << "\n     #     #     \n";
        }
    }   
}

void aiChoose(Grid &gameGrid, int &x, int &y, int player, int userPlayer) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (gameGrid.getCell(i, j) == -1) {
                gameGrid.setCell(i, j, player); 
                if (gameGrid.checkWin()) {
                    x = i;
                    y = j;
                    return;
                }
                gameGrid.setCell(i, j, -1); 
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (gameGrid.getCell(i, j) == -1) {
                gameGrid.setCell(i, j, userPlayer); 
                if (gameGrid.checkWin()) {
                    x = i;
                    y = j;
                    return;
                }
                gameGrid.setCell(i, j, -1);  
            }
        }
    }

    aiChooseRandom(gameGrid, x, y);
    
}

void aiChooseRandom(Grid& gameGrid, int &x, int &y) {
    srand(time(nullptr));

    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (gameGrid.getCell(x, y) != -1); 
}

int choosePlayer() {
    int selection = 0;
    cout << "If you would like to play as X enter 0, otherwise enter 1 to play as O: ";
    cin >> selection;
    if(selection != 0 && selection != 1) {
        cout << "\nThat is not a valid selection. Try again\n";
        return -1;
    }
    return selection;
}


void printStats(string playerName, int playerW, int aiW, int draws) {
    
    ofstream oFile("stats.txt");

    int timesPlayed = (playerW + aiW + draws);
    oFile << "===========================================\n";
    oFile << "Player name:\n\t" << playerName << "\n";
    oFile << "===========================================\n";
    oFile << "number of player wins:\n\t" << playerW << "\n";
    oFile << "===========================================\n";
    oFile << "Number of AI wins:\n\t" << aiW << "\n";
    oFile << "===========================================\n";
    oFile << "Number of draws:\n\t" << draws << "\n";
    oFile << "===========================================\n";
    oFile << "Total games played:\n\t" << timesPlayed << "\n";
    oFile << "===========================================\n";

    if(aiW > playerW) {
        oFile << "\nJeez you really suck huh?\n You lost to the AI " << aiW << " times????\n";
    }
}