// Authors: Patrick Martinez
//          Blake Hillier Serial: 20 
// Due Date : Monday, February 19, 2018
// Programming Assignment Number 2
// Spring 2018 - CS 3358 - 1 
//
// Instructor: Husain Gholoom. 
//
// <Brief description of the purpose of the program>

// Libraries
#include <iostream>
#include <vector>
using namespace std;

// Classes
class myGrades {
    vector<int> programGrades;
    vector<int> testGrades;
 
    public:
       void setProgramGrade();
       void setTestGrade();
       void const showProgramGrades();
       void const showTestGrades();
       void const showOverallGrade();
       void deleteProgramGrade();
       void deleteTestGrade(); 
};

int main() {
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
void myGrades::setProgramGrade() {

}

void myGrades::setTestGrade() {

}

void const myGrades::showProgramGrades() {

}

void const myGrades::showTestGrades() {

}

void const myGrades::showOverallGrade() {

}

void myGrades::deleteProgramGrade() {

}

void myGrades::deleteTestGrade() {

}
