/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*\
|                                                  |
|   Code to solve kattis problem "Falling Apart"   |
|   https://open.kattis.com/problems/fallingapart  |
|               Written by June West               |
|                                                  |
\*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/

#include <iostream>

using namespace std;

/*
    
take input of 2 lines,
    line1: number of pieces 1-15 inclusive
    line2: values of pieces space-separated. 1-100 inclusive
choose number of highest value to return to current player.
alternate between players until no numbers remain.
combine values of each players gathered integers. print out in single line separated by a space.

alice goes first
*/

void inputNums(int nums[], int);
void chooseNum(int nums[], int playerNums[], int, int &, int);
void trackNumsLeft(int nums[], int, int &);
void outputNums(int numsAlice[], int numsBob[], int, int);

int main() {
    int arraySize = 0;
    
    cin >> arraySize;
    
    int numsLeft = arraySize;
    
    int sizeAlice = 0;
    int sizeBob = 0;
    
    int nums[arraySize];
    inputNums(nums, arraySize);
    
    sizeAlice = arraySize/2 + (arraySize % 2 != 0);
    sizeBob = arraySize - sizeAlice;

    // cout << "DEBUG: SIZE ALICE: " << sizeAlice << endl;
    // cout << "DEBUG: SIZE BOB: " << sizeBob << endl;
    
    int numsAlice[sizeAlice];
    int numsBob[sizeBob];
    
    for(int i = 0; i < sizeAlice; i++) {
        numsAlice[i] = 0;
        // cout << numsAlice[i] << endl;
    }
    for(int i = 0; i < sizeBob; i++) {
         numsBob[i] = 0;
        //cout << numsBob[i] << endl;
    }

    bool activePlayer = true;
    while(numsLeft>0) {
        //cout << "DEBUG: IN WHILE LOOP" << endl;
        if(activePlayer) {
            chooseNum(nums, numsAlice, arraySize, numsLeft, sizeAlice);
            //cout << "DEBUG: alice turn" << endl;
        } else {
            chooseNum(nums, numsBob, arraySize, numsLeft, sizeBob);
            //cout << "DEBUG: bob turn" << endl;
        }
        
        activePlayer = !activePlayer;
    }

    outputNums(numsAlice, numsBob, sizeAlice, sizeBob);
    
}

void inputNums(int nums[], int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        cin >> nums[i];
    }
}

void chooseNum(int nums[], int playerNums[], int arraySize, int &numsLeft, int pNumSize) {
    int largestNum = nums[0];
    int remIndex = 0;
    
    for(int i = 1;i < arraySize; ++i) {
        if(largestNum < nums[i] && nums[i] != 0) {
            largestNum = nums[i];
            remIndex = i;
        }
    }
    // cout << "largestNum: " << largestNum << endl;
    trackNumsLeft(nums, remIndex, numsLeft);
    
    for(int i = pNumSize-1; i > 0 ; i--) {
        // cout << "playerNums[" << i << "]: " << playerNums[i] << endl;
        // cout << "playerNums[" << i-1 << "]: " << playerNums[i-1] << endl;
        playerNums[i] = playerNums[i-1];
        // cout << "playerNums[" << i << "]: " << playerNums[i] << endl;
        // cout << "playerNums[" << i << "-1]: " << playerNums[i-1] << endl;
    }
    playerNums[0] = largestNum;
    // cout << "playernums[0]: " << playerNums[0] << endl;
}

void trackNumsLeft(int nums[], int indexRemoved, int &numsLeft) {
    nums[indexRemoved] = 0;
    numsLeft--;
}

void outputNums(int numsAlice[], int numsBob[], int sizeAlice, int sizeBob) {
    // cout << endl << "numsAlice:" << endl << endl;
    int totalA = 0;
    int totalB = 0;
    for(int i = 0; i <  sizeAlice; i++) {
        totalA+=numsAlice[i];
    }
    // cout << endl << "numsBob:" << endl << endl;
    for(int i = 0; i <  sizeBob; i++) {
        totalB+=numsBob[i];
    }
    cout << totalA << " " << totalB << endl;
}


