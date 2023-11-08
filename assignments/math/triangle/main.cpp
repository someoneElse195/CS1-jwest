/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\
| Program to compute area and perimeter of a triangle.            |
| The program will also output whether the sides form a triangle. |
| Written by June West                                            |
\*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>
#include <cmath>

using namespace std;

float area(float a, float b, float c);
float peri(float a, float b, float c);
bool isTri(float a, float b, float c);

int main() {

    float sideA;
    float sideB;
    float sideC;

    /* While statement to loop back around if sides are determined to not be a triangle.            *\
    \* If sides form a triangle it will output data to console and break loop to terminate program. */
    
    while(true) {

        cout << "Please input 3 sides for a triangle: ";
        cin >> sideA >> sideB >> sideC;
        cout << endl;
        if(isTri(sideA, sideB, sideC)) {
            float triArea = area(sideA, sideB, sideC);

            cout << "The area is: " << triArea << endl;
            break;
        } else {
            cout << "This is not a triangle. ";
        }

    }


}

//Computes area of triangle.

float area(float a, float b, float c) {
    float area =(.25 * sqrt((a + b + c) * (b - a + c) * (a - b + c) * (a + b - c)));
    return area;
}

//Computes perimeter of triangle.

float peri(float a, float b, float c) {
    float peri = a + b + c;
    return peri;
}

//Determines whether inputted numbers form a triangle.

bool isTri(float a, float b, float c) {
    if(a < (b+c) && b < (a+c) && c < (a+b)) {
        return true;
    } else {
        return false;
    }
}