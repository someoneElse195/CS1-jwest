/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*\
| Solving Kattis Faktor problem.  |
| Written by amwest               |
\*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/

#include <iostream>

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
    int bribesNeeded = I*A;

    return bribesNeeded;
}