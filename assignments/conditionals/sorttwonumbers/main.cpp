#include <iostream>
#include <cassert>

using namespace std;

void test();
int orderer(int a, int b);

int main(int args, char* vect[]) {
    //Checking if test is passed to main.
    if(args > 1 && string(vect[1]) == "test") {
        test();
        return 0;
    }

    int a, b;
    //Gathering nums and calling orderer.
    cin >> a >> b;
    cout << endl;
    orderer(a,b);

}

//Function outputs the correct order and returns the first in the correct order
int orderer(int a, int b) {
    if(a < b) {
        cout << a << " " << b << endl;
        return a;
    } else if (a > b) {
        cout << b << " " << a << endl;
        return b;
    } else if (a == b) {
        cout << a << " " << b << endl;
        return a;
    }
    return 0;
} 

//Tests to see that the correct number is returned first.
void test() {
    int a1 = 5;
    int b1 = 5;
    int a2 = -10;
    int b2 = -5;
    int a3 = -7;
    int b3 = 3;
    int a4 = 1000000;
    int b4 = 2000000;

    assert(orderer(a1,b1) == 5);    
    assert(orderer(a2,b2) == -10);
    assert(orderer(a3,b3) == -7);
    assert(orderer(a4,b4) == 1000000);
}