/*-=-=-=-=-=-=-=-=-=-=-=-=-=-*\
| Solving Kattis R2 problem.  |
| Written by amwest           |
\*-=-=-=-=-=-=-=-=-=-=-=-=-=-*/

#include <iostream>

using namespace std;

//int randNum();
int findR2(int R1, int S); 

int main() {
    int S;
    int R1;
    int R2 = findR2(R1, S);

    cout << "Please input 2 numbers, average and R1: ";
    cin >> R1 >> S;
    cout << endl << "R2 = " << R2 << endl;

    return 0;
}

/*int randNum() {
    int max = 1000;
    int min = -1000;
	srand((unsigned) time(NULL));
	int random = -1000 + (rand() % 2001);
    return random;
}*/

int findR2(int R1, int S) {
    int R2 = (2*S-R1);
    return R2;
}
