/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\
| The program requests a radius of a circle to then   |
| calculate the area and circumference of said circle |
| Written by amwest                                   |
\*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
 
int main() {
	const double pi = 3.14159;

	double radius=0, area=0, circumference=0;

	string name = "Anonymous";
	cout << "Hi there, what's your full name? ";
	getline(cin, name);

	cout << "Nice meeting you, " << name << "!" << endl;

	// display some information about this program to the user
	cout << "\nProgram finds area and circumference of a circle with the given radius.\n";
	cout << string(75, '=') << endl << endl;

	// prompt user telling what to do
	cout << name << ", please enter radius of a circle: ";
	cin >> radius; //read the entered value and store it into radius variable

	area = pi * pow(radius, 2);
    circumference = pi * radius * 2;

	cout << "Your circle has radius: " << fixed << setprecision(6) << radius << endl;
	cout << "Area of the circle is:\t" << area << '\n';
	cout << "Circumference of the circle is:\t" << circumference << '\n';

	// the following code may be required to make your console pause...
	cout << "Good bye...\nHit enter to exit the program!" << '\n';
	cin.ignore(1000, '\n'); //ignore 1000 chars or until \n whichever comes first
	// make the console wait for user input
	cin.get();

	return 0;
}