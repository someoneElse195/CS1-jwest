#include <iostream>

using namespace std;


void sumNums(int, int, int&);
int loopFunc(int);



int main() {
    int count = -2;

    cout << loopFunc(count) << endl;

    return 0;
}

void sumNums(int n1, int n2, int& sum) {
    sum = n2 + sum;
}

int loopFunc(int count) {
    int sum = 0;
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < 5; j++) {
            sumNums(i,j,sum);
        }
        if(sum>=20) {
            return sum;
        }
        
    }
    return sum;
}