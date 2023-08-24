/*-=-=-=-=-=-=-=-=-=-=-=-=-=-*\
| Solving Kattis R2 problem.  |
| Written by amwest           |
\*-=-=-=-=-=-=-=-=-=-=-=-=-=-*/

#include <iostream>

using namespace std;

int findR2(int R1, int S); 

int main() {
    int S;
    int R1;
    
    cin >> R1 >> S;
    int R2 = findR2(R1, S);
    cout << endl << R2 << endl;

    return 0;
}

int findR2(int R1, int S) {
    int R2 = (2*S-R1);
    return R2;
}
