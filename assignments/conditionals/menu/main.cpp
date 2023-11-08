/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\
| CLI that computes max, min, & odditty       |
| of any 5 given numbers. Written by June W   |
\*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

float max(float nums[5]);
float min(float nums[5]);
int oddity(float nums[5]);
void test();

int main(int args, char* vect[]) {

    //Checking if test is passed to main.
    if(args > 1 && string(vect[1]) == "test") {
        test();
        return 0;
    }

    string name;
    float numbers [5];
    int selection = 0;
    bool restart = true;
    int R = 0;
    
    //Intro for inputting name.
    cout << "Hello, please enter your name: "; 
    cin >> name;
    //While loop to keep program running and ask if wanted to restart. Respons with name and gathers numbers. Takes ints or floats.
    while (restart) {
        cout << endl << "Welcome, " << name << "." << endl << "Please enter 5 numbers: ";
        cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3] >> numbers[4];
        cout << endl << "Please enter a number, 1-3, to calculate max, min, and oddity of your numbers respectively: ";
        cin >> selection;
        cout << endl;
        switch(selection) {
            case 1: 
                max(numbers);
                break;
            case 2:
                min(numbers);
                break;
            case 3:
                oddity(numbers);
                break;
            default:
                cout << "That number is not on the range of 1-3. Try again: ";
                cin >> selection;
                continue;
        }
        cout << "Would you like to continue (enter 0) or end? (enter 1): ";
        cin >> R;
        if(R == 0) {
            restart = true;
        } else {
            restart = false;
            break;
        }
    }
    return 0;  
}

//Use for loop to find largest num and print results then return it
float max(float nums[5]) {
    float max = nums[0];
    for(int i = 1; i < 5; i++) {
        if(nums[i] > max) {
            max = nums[i];
        } else {
            continue;
        }
    }
    cout << "The maximum of your 5 numbers is " << max << "." << endl;
    return max;
}

//Use for loop to find smallest num and print results then return it
float min(float nums[5]) {
    float min = nums[0];
    for(int i = 1; i < 5; i++) {
        if(nums[i] < min) {
            min = nums[i];
        } else {
            continue;
        }
    }
    cout << "The minimum of your 5 numbers is " << min << "." << endl;
    return min;
}


//If remainder is 1 num is odd so return 1, if remainder is 0 num is even return 0, if num is 0 return -1. All cases print results
int oddity(float nums[5]) {
    int num = (nums[0] + nums[1] + nums[2] + nums[3] + nums[4]);
    int oddity = num%2;
    if(num == 0) {
        cout << "The floor of the sum of your numbers is 0." << endl;
        return -1;
    } else if(oddity == 1) {
        cout << "The floor of the sum of your numbers is odd." << endl;
        return 1;
    } else if (oddity == 0){
        cout << "The floor of the sum of your numbers is even." << endl;
        return 0;
    } else {
        return 2;
    }
}

//Tests 3 arrays of numbers only if test is passed to main.
void test() {
    float array1[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
    float array2[5] = {-3.5, 2.0, -1.25, 0.5, 4.75};
    float array3[5] = {10001.0, 20001.0, 30001.0, 40001.0, 50001.0};   

    assert(min(array1) == 0.0);
    assert(min(array2) == -3.5);
    assert(min(array3) == 10001.0);

    assert(max(array1) == 0.0);
    assert(max(array2) == 4.75);
    assert(max(array3) == 50001.0);

    assert(oddity(array1) == -1);
    assert(oddity(array2) == 0);
    assert(oddity(array3) == 1);
}