/*
TODO: Write desc of program
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

float addition(float one, float two);

int main() {
    float numA;
    float numB;

    cout << "Please input 2 numbers" << endl;
    cin >> numA >> numB;
    
    float sum = addition(numA, numB);
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "The sum of your numbers is ";
    cout << sum << endl;
    
    /*
    TODO: 2 Write func. that takes 2 numbers, multiplies them, and returns the result.
        Function must accept floats & integers.

    TODO: 3 Write func. that takes 2 numbers, divides first by second, returns result.
        Function must accept floats & integers.

    TODO: 4 Write func. that takes 2 numbers, subtracts second from first.
        Function must accept floats & integers.

    TODO: 5 Same as 3 however returns remainder.

    TODO: 6 Write func. that finds the first to the power of the second and returns result.
        Function must accept floats & integers.
    
    TODO: 7 Write func. that takes num and returns square root.
        Function must accept floats & integers.

    TODO: 8 Prompt user to provide 2 numbers. Call all previous functions, and print out results of each 
        with proper descriptions.
    
    TODO: 9 Write func. to test each previous function with 2 different test cases. 
        Include sc of test results.

    TODO: 10 opt. Write func. to find the larger of two numbers. Use the same numbers as inputted previously.
    */
   return 0;
}


float addition(float one, float two) {
    float sum = one;
    sum+=two;
    return sum;
}