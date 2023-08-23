/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
= This program is a simple calculator that takes -
- in two numbers and outputs various computations=
= using them. Written by amwest                  -
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


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
void largerOf(float one, float two);
void test();

int main() {
    float numA;
    float numB;

    cout << "Please input 2 numbers, to do a test run input -1 for both numbers." << endl;
    cin >> numA >> numB;
    cout << endl;

    if(numA == -1 && numB == -1) {
        cout << "Running tests: " << endl;
        test();
    } else {    
        addition(numA, numB);
        multiply(numA, numB);
        divide(numA, numB);
        subtraction(numA, numB);
        remainders(numA, numB);
        powers(numA, numB);
        squareRoot(numA, numB);
        largerOf(numA, numB);
    }
    
    cout << endl << "Note: With large numbers the output may appear inf, especially with power." << endl << "This is due to the precision limits of the float data type." << endl;
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
    cout << "The remainder of your numbers is ";
    cout << remain << endl;
}

void powers(float one, float two) {
    float power = pow(one, two);
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The power of your numbers is ";
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

void largerOf(float one, float two) {
    if(one > two) {
        cout << "The larger of your two numbers is: " << one << endl;
    } else if(two > one) {
        cout << "The larger of your two numbers is: " << two << endl;
    } else {
        cout << "Your two numbers are equal" << endl;
    }
}

void test() {
    int min = 1;
    int max = 200;

    float numA = min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
    float numB = min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
    float numC = min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
    float numD = min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));

    cout << "The two random number sets are: (" << numA << ", " << numB << "), and (" << numC << ", " << numD << ")." << endl;

    cout << endl << "Test one:" << endl;
    addition(numA, numB);
    multiply(numA, numB);
    divide(numA, numB);
    subtraction(numA, numB);
    remainders(numA, numB);
    powers(numA, numB);
    squareRoot(numA, numB);
    largerOf(numA, numB);

    cout << endl << "Test two: " << endl;

    addition(numC, numD);
    multiply(numC, numD);
    divide(numC, numD);
    subtraction(numC, numD);
    remainders(numC, numD);
    powers(numC, numD);
    squareRoot(numC, numD);
    largerOf(numC, numD);
}