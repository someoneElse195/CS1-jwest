/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=*\
| Program to output ascii art. |
\*-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

#include <iostream>

using namespace std;

void printASCII();
void extraASCII();

int main() {
    string name;
    cout << "Hello, please enter your name: ";
    cin >> name;
    cout << "\nNice meeting you, " << name;
    cout << "\nHope you like my Tom & Jerry ASCII art...\n\n";
    printASCII();
    extraASCII();

    
    cout << "\nGood bye... hit enter to exit the program: " << '\n';
    cin.ignore(100, '\n');
    cin.get();
    cout << "See ya\n\n";

    return 0;
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

void extraASCII() {
    string L1 = "                             _______      _______";
    string L2 = "                          /*********\\   /*********\\";
    string L3 = "                         /***********\\ /***********\\";
    string L4 = "                        /***************************\\";
    string L5 = "                        |***************************|";
    string L6 = "                        |***************************|";
    string L7 = "                         \\*************************/";
    string L8 = "                           \\*********************/";
    string L9 = "                             \\*****************/";
    string L10= "                               \\*************/";
    string L11= "                                 \\*********/";
    string L12= "                                   \\*****/";
    string L13= "                                     \\*/";
    cout << L1 << endl << L2 << endl << L3 << endl << L4 << endl << L5 << endl << L6 << endl << L7 << endl << L8 << endl << L9 << endl << L10 << endl << L11 << endl << L12 << endl << L13 << endl;
}


/*
              ******       ******
            **********   **********
          ************* *************
         *****************************
         *****************************
         *****************************
          ***************************
            ***********************
              *******************
                ***************
                  ***********
                    *******
                      ***


   |\_/|            *****************************    	    (\_/)
 /  @  @ \      	*         ASCII Lab         *  	       (='.'=)
( >  0  < )         *        <Your Name>        * 	     ( " )_( " )
   >>x<<        	*      <Semester Year>      *
  /  O  \       	*         CSCI 111          *
		            *****************************
*/