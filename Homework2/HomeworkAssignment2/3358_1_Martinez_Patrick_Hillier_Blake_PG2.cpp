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

    private:
    vector<int> programGrades;  // Vector to hold program grades
    vector<int> testGrades;     // Vector to hold test grades

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

    // Creates new myGrades object
    myGrades Grades;
    // If true, tells loop to run again
    bool runProgram = true;
    // Stores number identifying which function to run
    int userChoice;

    // Allows user to interact with the Grades object
    do {
        cout << "1. Set a Programming Assingment Grade" << endl;
        cout << "2. Set A Test Grade" << endl;
        cout << "3. Show All Programming Assingment Grades" << endl;
        cout << "4. Show All Test Grades" << endl;
        cout << "5. Show Overall Grades" << endl;
        cout << "6. Delete A Programming Assingment Grade" << endl;
        cout << "7. Delete A Test Grade" << endl;
        cout << "9. Exit The Program" << endl;
        cout << endl;
        cout << "Enter your choice ---> ";
        cin >> userChoice;

        try {
            // Checks if userChoice contains an integer 1-7 or 9
            if (false) {
                cout << "ERROR: Invalid Choice\n Input needs to be an integer";
                cout << endl;
            } else
                cout << "ERROR: Invalid Choice" << endl;

            // Calls various functions on Grades based on the user's choice
            switch (userChoice) {
                case 1: Grades.setProgramGrade();
                        break;
                case 2: Grades.setTestGrade();
                        break;
                case 3: Grades.showProgramGrades();
                        break;
                case 4: Grades.showTestGrades();
                        break;
                case 5: Grades.showOverallGrade();
                        break;
                case 6: Grades.deleteProgramGrade();
                        break;
                case 7: Grades.deleteTestGrade();
                        break;
                case 9: runProgram = false;
                        break;
                default: cout << "ERROR: Invalid Choice\n Input needs to be from 1-7";
                         cout << " or 9" << endl;
            }// End Switch
        }
        catch (...) {
         // we might have to work on the structure of our try-catchs
        }

    } while (runProgram);

    cout << "Implemented by Patrick Martinez and Blake Hillier" << endl;
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

}
/*******************************************************************
 setTestGrade
 Input: none
 Returns: none
 Displays a prompt for an int from 1-25 and passes it to the test grades array
 *******************************************************************/
void myGrades::setTestGrade() {

}
/*******************************************************************
 showProgramGrades
 Input: none
 Returns: none
 Shows program grades and program grades average out of 10.
 *******************************************************************/
void const myGrades::showProgramGrades() {

}
/*******************************************************************
 showTestGrades
 Input: none
 Returns: none
 Shows test grades and test grades average out of 20.
 *******************************************************************/
void const myGrades::showTestGrades() {

}
/*******************************************************************
 showOverallGrade
 Input: none
 Returns: none
 Shows all grades, average for each, and an overall total.
 *******************************************************************/
void const myGrades::showOverallGrade() {

}
/*******************************************************************
 deleteProgramGrade
 Input: none
 Returns: none
 Prompts for a grade to delete. Deletes grade equal to input.
 *******************************************************************/
void myGrades::deleteProgramGrade() {

}
/*******************************************************************
 deleteTestGrade
 Input: none
 Returns: none
 Prompts for a grade to delete. Deletes grade equal to input.
 *******************************************************************/
void myGrades::deleteTestGrade() {

}
