/*
TODO: Write desc of program
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;

void addition(float one, float two);
void multiply(float one, float two);
void divide(float one, float two);
void subtraction(float one, float two);
void remainders(float one, float two);
void powers(float one, float two);
void squareRoot(float one, float two);

int main() {
    float numA;
    float numB;

    cout << "Please input 2 numbers" << endl;
    cin >> numA >> numB;
    cout << endl;
    
    addition(numA, numB);
    multiply(numA, numB);
    divide(numA, numB);
    subtraction(numA, numB);
    remainders(numA, numB);
    powers(numA, numB);
    squareRoot(numA, numB);
 
    /*    
    
    TODO: 9 Write func. to test each previous function with 2 different test cases. 
        Include sc of test results.

    TODO: 10 opt. Write func. to find the larger of two numbers. Use the same numbers as inputted previously.
    */
   return 0;
}


void addition(float one, float two) {
    float sum = one+two;
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The sum of your numbers is ";
    cout << sum << endl;
}

void multiply(float one, float two) {
    float mult = one*two;
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The product of your numbers is ";
    cout << mult << endl;
}

void divide(float one, float two) {
    float div = one/two;
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The quotient of your numbers is ";
    cout << div << endl;
}

void subtraction(float one, float two) {
    float sub = one-two;
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The difference of your numbers is ";
    cout << sub << endl;
}

void remainders(float one, float two) {
    float remain = fmod(one, two);
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The remainder of your numbers is ";
    cout << remain << endl;
}

void powers(float one, float two) {
    float power = pow(one, two);
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The remainder of your numbers is ";
    cout << power << endl;
}

void squareRoot(float one, float two) {
    float root1 = sqrt(one);
    float root2 = sqrt(two);
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The square root of your first number is ";
    cout << root1 << endl;
    cout << "The square root of your second number is ";
    cout << root2 << endl;
}