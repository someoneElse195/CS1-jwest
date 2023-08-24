/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*\
| Solving Kattis Faktor problem.  |
| Written by amwest               |
\*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/

#include <iostream>
#include <cmath>

using namespace std;

int bribes(int I, int A);

int main() {
    int I;
    int A;
    int bribesNeeded;

    cin >> A >> I;

    bribesNeeded = bribes(I, A);

    cout << endl << bribesNeeded << endl;
}

int bribes(int I, int A) {
    float Ifloat = (float)I;

    Ifloat -=0.99;
    float IA = Ifloat*A;
    
    int bribesNeeded = ceil(IA);

    return bribesNeeded;
}