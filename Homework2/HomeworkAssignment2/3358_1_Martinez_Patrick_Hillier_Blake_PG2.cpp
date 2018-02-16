// Authors: Patrick Martinez Serial: 24
//          Blake Hillier Serial: 20
// Due Date : Monday, February 19, 2018
// Programming Assignment Number 2
// Spring 2018 - CS 3358 - 1
//
// Instructor: Husain Gholoom.
//
// This program's purpose is to assist students in estimating their current
// course grade in CS 3358. It allows the user to create and populate a vector
// array with any amount of assignment grades and two test grades. It also
// allows the user to display either assignment grades, test grades or overall
// grades in the course. It also has an option to delete grades.

// Libraries
#include <iostream> // Provides cout, cin and other io stream operations
#include <vector>   // Provides vector type to hold grades
#include <iomanip>  // Provides setw and

using namespace std;

// Classes
/**********************************************
myGrades class
    This class is meant to hold program and test grades to perform calculations.
    The public methods will allow manipulation of data and presentation of data.

-vector<int> programGrades  - Holds program grades
-vector<int> testGrades     - Holds test grades
***********************************************/
class myGrades {

    private:    // Homework 2 pdf states grades should be stored in vector
                // even though only integers could be entered
        vector<double> programGrades;  // Vector to hold program grades
        vector<double> testGrades;     // Vector to hold test grades

    public:

        // Displays prompt and adds a program grade
        void setProgramGrade();
        // Displays prompt and adds a test grade
        void setTestGrade();
        // Shows programming assignment grades and average of these grades
        void const showProgramGrades();
        // Shows test grades and average of these grades
        void const showTestGrades();
        // Shows all grades and overall total
        void const showOverallGrade();
        // Displays prompt to remove a program grade equal to input=
        void deleteProgramGrade();
        // Displays prompt to remove a test grade equal to input
        void deleteTestGrade();
};

int main() {
    cout << "Welcome to Patrick and Blake's grades program.\n" << endl;

    // Sets constants for menu options
    enum menuOptions {
           SET_ASSIGNMENT_GRADE = 1,
           SET_TEST_GRADE,
           SHOW_ASSIGNMENT_GRADES,
           SHOW_TEST_GRADES,
           SHOW_OVERALL_GRADES,
           DELETE_ASSIGNMENT_GRADE,
           DELETE_TEST_GRADE,
           EXIT = 9
    };
    // Creates new myGrades object
    myGrades Grades;
    // If true, tells loop to run again
    bool runProgram = true;
    // Stores number identifying which function to run
    int userChoice;

    // Allows user to interact with the Grades object
    do {
        cout << "1. Set a Programming Assignment Grade" << endl;
        cout << "2. Set A Test Grade" << endl;
        cout << "3. Show All Programming Assignment Grades" << endl;
        cout << "4. Show All Test Grades" << endl;
        cout << "5. Show Overall Grades" << endl;
        cout << "6. Delete A Programming Assignment Grade" << endl;
        cout << "7. Delete A Test Grade" << endl;
        cout << "9. Exit The Program" << endl;
        cout << endl;

        try {
            cout << "Enter your choice ---> ";
            if(!(cin >> userChoice)) // If insertion to int fails, throw except.
                throw "Invalid input";
            // If int value is not valid, throw exception with int.
            else if (userChoice < 1 || userChoice > 9 || userChoice == 8)
                throw userChoice;
            // This is done to clear the input stream in case decimals are
            // entered. This was done since decimal handling was talked
            // about in class, and we were expected to truncate decimals.
            cin.clear();
            cin.ignore(256,'\n');
            // Program will only get to this point if input is valid.
            // Calls various functions on Grades based on the user's choice
            switch (userChoice) {

                case SET_ASSIGNMENT_GRADE:
                    Grades.setProgramGrade();
                        break;
                case SET_TEST_GRADE:
                    Grades.setTestGrade();
                        break;
                case SHOW_ASSIGNMENT_GRADES:
                    cout << "\nShow programming grades and average." << endl;
                    Grades.showProgramGrades();
                        break;
                case SHOW_TEST_GRADES:
                    cout << "\nShow test grades and average." << endl;
                    Grades.showTestGrades();
                        break;
                case SHOW_OVERALL_GRADES:
                    cout << "\nShow all grades." << endl;
                    Grades.showOverallGrade();
                        break;
                case DELETE_ASSIGNMENT_GRADE:
                    Grades.deleteProgramGrade();
                        break;
                case DELETE_TEST_GRADE:
                    Grades.deleteTestGrade();
                        break;
                case EXIT: runProgram = false;
                        break;
            }// End Switch
        }
        catch (int x) { // Catch invalid numbers
            cout << "\nError *** " << x << " is an invalid choice.\n" << endl;
        }
        catch (char const*) { // Catch all other invalid inputs
            cout << "\nError *** Incorrect input - You entered a character!\n"
            << endl;
            cin.clear();
            cin.ignore(256,'\n');
        }
    } while (runProgram);

    cout << "Implemented by Patrick Martinez and Blake Hillier. February 2018"
    << endl;

    return 0;
}

// Functions
/*******************************************************************
 setProgramGrade
 Input: none
 Returns: none
 Displays a prompt for an int from 1-10 and pushes it to the assignment grades
 array.
 *******************************************************************/
void myGrades::setProgramGrade() {
    int input;
    cout << endl << "Enter a programming assignment grade: ";
    if (!(cin >> input)) {
        cout << "\nError *** Incorrect input - You entered a character!\n";
    }
    else if (input < 0 || input > 10)
        cout << "Error *** Invalid value - Enter a value between 0 and 10.\n";
    else
        programGrades.push_back(input);
        cin.clear();
        cin.ignore(256,'\n');

    cout << endl;

}
/*******************************************************************
 setTestGrade
 Input: none
 Returns: none
 Displays a prompt for an int from 1-25 and passes it to the test grades array
 *******************************************************************/
void myGrades::setTestGrade() {
    int input;

    if (testGrades.size() >= 2)
        cout << endl << "Error *** No more test grades can be added.";
    else {
        cout << endl << "Enter a test grade: ";
        if (!(cin >> input)) {
            cout << "\nError *** Incorrect input - You entered a character!\n";
            cin.clear();
            cin.ignore(256,'\n');
        }
        else if (input < 0 || input > 25)
            cout << "Error *** Invalid value - Enter a value between 0 and 25.";
        else
            testGrades.push_back(input);
            cin.clear();
            cin.ignore(256,'\n');
    }
    cout << endl;

}
/*******************************************************************
 showProgramGrades
 Input: none
 Returns: none
 Shows program grades and program grades average out of 10.
 *******************************************************************/
void const myGrades::showProgramGrades() {
    double average = 0;
    if (programGrades.empty())
        cout << "\nNo programming  grades are recorded.\n" << endl;
    else {
        cout << "\nProgramming assignment grades:" << endl;
        for (int i = 0; i < programGrades.size(); i++) {
            cout << setw(6) << setprecision(2) << fixed << programGrades[i];
            average += programGrades[i];
        }
        average = (average * 2 / programGrades.size());
        cout << "\nAverage programming assignment grades are "
        << setprecision(2) << fixed << average << " out of 20";
        cout << endl << endl;
    }
}
/*******************************************************************
 showTestGrades
 Input: none
 Returns: none
 Shows test grades and test grades average out of 20 or 45.
 *******************************************************************/
void const myGrades::showTestGrades() {
    double average = 0;
    if (testGrades.empty())
        cout << "\nNo test grades are recorded.\n" << endl;
    else {
        cout << "\nTest grades:" << endl;
        for (int i = 0; i < testGrades.size(); i++) {
            cout << setw(6) << setprecision(2) << fixed << testGrades[i];
            average += testGrades[i];
        };
        if (testGrades.size() == 1) {
            cout << "\nAverage test grades are "
            << setprecision(2) << fixed << average << " out of 20";
            cout << endl << endl;
        }
        else if (testGrades.size() == 2) {
            cout << "\nAverage test grades are "
            << setprecision(2) << fixed << average << " out of 45";
            cout << endl << endl;
        }
    }
}
/*******************************************************************
 showOverallGrade
 Input: none
 Returns: none
 Shows all grades, average for each, and an overall total.
 *******************************************************************/
void const myGrades::showOverallGrade() {
    cout << "\nOverall grades are as follows: \n" << endl;
    showProgramGrades();
    showTestGrades();
    cout << "Overall total -- >" << endl;
}
/*******************************************************************
 deleteProgramGrade
 Input: none
 Returns: none
 Prompts for a grade to delete. Deletes grade equal to input.
 *******************************************************************/
void myGrades::deleteProgramGrade() {
    cout << "\nDELETE PROGRAM CALLED\n" << endl;
}
/*******************************************************************
 deleteTestGrade
 Input: none
 Returns: none
 Prompts for a grade to delete. Deletes grade equal to input.
 *******************************************************************/
void myGrades::deleteTestGrade() {
    cout << "\nDELETE TEST CALLED\n" << endl;
}
