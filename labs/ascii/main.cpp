/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\
| Program to output ascii art. |
\*-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>

using namespace std;

void printASCII();

int main() {
    
    printASCII();

}


void printASCII() {
    string L1 = "   |\\_/|                *****************************           (\\_/)";
    string L2 = " /  @ @  \\      	*         ASCII Lab         *  	       (='.'=)";
    string L3 = "( >  0  < )             *          amwest           * 	     ( \" )_( \" )";
    string L4 = "   >>x<<        	*           2023            *";
    string L5 = "  /  O  \\       	*         CSCI 111          *";
    string L6 = "		        *****************************";

    cout << L1 << endl << L2 << endl << L3 << endl << L4 << endl << L5 << endl << L6 << endl;
}







/*
   |\_/|            *****************************    	    (\_/)
 /  @  @ \      	*         ASCII Lab         *  	       (='.'=)
( >  0  < )         *        <Your Name>        * 	     ( " )_( " )
   >>x<<        	*      <Semester Year>      *
  /  O  \       	*         CSCI 111          *
		            *****************************
*/