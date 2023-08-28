/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\
| CLI that computes max, min, & odditty       |
| of any 5 given numbers. Written by amwest   |
\*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>
#include <string>

using namespace std;

void max(float nums[5]);
void min(float nums[5]);
void oddity(float nums[5]);


int main() {
    string name;
    float numbers [5];
    int selection = 0;
    bool restart = true;
    int R = 0;
    
    cout << "Hello, please enter your name: "; 
    cin >> name;
    cout << endl << "Welcome, " << name << "." << endl << "Please enter 5 numbers: ";
    cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3] >> numbers[4];
    while (restart) {
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
       
}

void max(float nums[5]) {
    float max = nums[0];
    for(int i = 1; i < 5; i++) {
        if(nums[i] > max) {
            max = nums[i];
        } else {
            continue;
        }
    }
    cout << "The maximum of your 5 numbers is " << max << "." << endl;

}

void min(float nums[5]) {
    float min = nums[0];
    for(int i = 1; i < 5; i++) {
        if(nums[i] < min) {
            min = nums[i];
        } else {
            continue;
        }
    }
    cout << "The minimum of your 5 numbers is " << min << "." << endl;

}

void oddity(float nums[5]) {
    int num = (nums[0] + nums[1] + nums[2] + nums[3] + nums[4]);
    if(num == 0) {
        cout << "The floor of the sum of your numbers is 0." << endl;
    } else if(num%2 == 1) {
        cout << "The floor of the sum of your numbers is odd." << endl;
    } else if (num%2 == 0){
        cout << "The floor of the sum of your numbers is even." << endl;
    }
    
}