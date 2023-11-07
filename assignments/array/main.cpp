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
void chooseNum(int nums[], int playerNums[], int, int);
void trackNumsLeft(int nums[], int, int);
void outputNums(int numsAlice[], int numsBob[]);

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
    
    int numsAlice[sizeAlice];
    int numsBob[sizeBob];
    
    for(int i = 0; i < arraySize; i++) {
        cout << nums[i];
    }
    bool activePlayer = true;
    while(numsLeft>0) {
        if(activePlayer) {
            chooseNum(nums, numsAlice, arraySize, numsLeft);
        } else {
            chooseNum(nums, numsBob, arraySize, numsLeft);
        }
        
        activePlayer = !activePlayer;
    }
    
}

void inputNums(int nums[], int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        cin >> nums[i];
    }
}

void chooseNum(int nums[], int playerNums[], int arraySize, int numsLeft) {
    int largestNum = nums[0];
    int remIndex = 0;
    
    for(int i = 1;i < arraySize; ++i) {
        if(largestNum < nums[i]) {
            largestNum = nums[i];
            remIndex = i;
        }
    }
    trackNumsLeft(nums, remIndex, numsLeft);
    
    for(int i = sizeof(playerNums) / sizeof(int); i > 0 ; i--) {
        playerNums[i] = playerNums[i-1];
    }
    playerNums[0] = largestNum;
}

void trackNumsLeft(int nums[], int indexRemoved, int numsLeft) {
    nums[indexRemoved] = 0;
    numsLeft--;
}

void outputNums(int numsAlice[], int numsBob[]) {
    for(int i = 0; i <  sizeof(numsAlice) / sizeof(int); i++) {
        cout << numsAlice[i];
    }
    for(int i = 0; i <  sizeof(numsBob) / sizeof(int); i++) {
        cout << numsBob[i];
    }
}


