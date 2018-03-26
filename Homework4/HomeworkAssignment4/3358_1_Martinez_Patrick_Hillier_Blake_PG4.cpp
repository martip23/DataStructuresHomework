/*******************************************************************************
 Roster Numbers: 24 20

 Authors: Patrick Martinez and Blake Hillier
 Due Date: 28 March 2018
 Program Assignment Number 4

 Spring 2018 - CS 3358 - 261

 Instructor: Hussain Gholoom.

 TODO: Description
 *******************************************************************************/

#include <iostream>

using namespace std;

class Stack {

};

class Queue {
};

int main() {
    cout << "*** Welcome to Our Stack / Queue Program ***" << endl << endl;
    cout << "The function of this program is to:" << endl;
    cout << "    1. Use stack to determine wether or not two strings are the same." << endl << endl;
    cout << "    2. Use queue to determine wether or not STRING2 is a reverse of STRING1." << endl << endl;

    bool run = true;
    do { 
        cout << "Select from the following menu" << endl;
        cout << "    1. Enter Stack Values." << endl;
        cout << "    2. Enter Queue Values." << endl;
        cout << "    9. Terminate the program. ";
    
        try {
            int userChoice;
            if(!(cin >> userChoice)) // If insertion to int fails, throw except.
                throw -1;
            // If int value is not valid, throw exception with int.
            else if (userChoice != 1 && userChoice != 2 && userChoice != 9)
                throw -1;
            // This is done to clear the input stream in case decimals are
            // entered. This was done since decimal handling was talked
            // about in class, and we were expected to truncate decimals.
            cin.clear();
            cin.ignore(256,'\n'); 
            switch (userChoice) {
                case 1:
                    // Use Stack
                    cout << "\nSTACK" << endl;
                    break;
                case 2:
                    // Use Queue
                    cout << "\nQUEUE" << endl;
                    break;
		case 9:
		    run = false;
		    break;
		default:
                    throw -1;
		    break;
	    } // End Switch
        }
        catch (...) {
            cout << "Invalid Option" << endl << endl;
        }

    } while (run);

    cout << "\n*** End of the Program. ***" << endl;
    cout << "*** Written by Patrick Martinez and Blake Hillier ***" << endl;
    cout << "*** March 28 - 2018 ***" << endl << endl;
}
