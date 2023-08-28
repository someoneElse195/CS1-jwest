/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\
| CLI that computes sum, product, max, min,   |
| average, & odditty of any 5 given numbers.  |
| Written by amwest.                          |
\*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>
#include <string>

using namespace std;

void max(float nums[5]);
void min(float nums[5]);
void average(float nums[5]);
void oddity(float nums[5]);


int main() {
    string name;
    float numbers [5];

    cout << "Hello, please enter your name: " << endl; 
    cin >> name;
    cout << endl << "Welcome, " << name << "." << endl << "Please enter 5 numbers: ";
    cin >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3] >> numbers[4];
    cout << endl;
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
    cout << max << endl;

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
    cout << min << endl;

}

void average(float nums[5]) {
    float avg = (nums[0] + nums[1] + nums[2] + nums[3] + nums[4])/5.00;

    cout << avg << endl;
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