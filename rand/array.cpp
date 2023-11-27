#include <iostream>

using namespace std;

void sort(int [], int);

int main() { 
    int test[] = {9, 2, 6, 7, 1, 4, 3};
    int length = 7;
    sort(test, length);
    cout << test[0] << test[1] << test[2] << test[3] << test[4] << test[5] << test[6] << endl;
}

void sort(int nums[], int len) {
    int i, j, temp;
    bool sorted = false;
    while(!sorted) {
        for(i = 0; i < len; i++) {
            sorted = true;
            for(j = 0; j < len-i-1; j++) {
                if (nums[i] >= nums[i+1]) {
                    temp = nums[i+1];
                    nums[i+1] = nums[i];
                    nums[i] = temp;
                    sorted = false;
                }
            }
            if(sorted) break;
        }
    }
}