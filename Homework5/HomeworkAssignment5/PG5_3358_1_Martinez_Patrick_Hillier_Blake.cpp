/*******************************************************************************
 Roster Numbers: 20 24

 Authors: Blake Hillier and Patrick Martinez
 Due Date: April 9, 2018
 Programming Assignment Number 5

 Spring 2018 - CS 3358 - 261

 Instructor: Husain Gholoom

 //TODO: Description
 ******************************************************************************/

 #include <iostream>

 using namespace std;

 int main() {

     bool again = true;
     int arraySize = -1;
     char choice;

     cout << "Thinking Recursively\n"
          << "\n"
          << "The function of this program is to\n"
          << "use recursion in order to perform the following operations   :-\n"
          << "\n"
          << "    1. Display squares of integers in ascending order from 1 to\n"
          << "         the last element in the array\n"
          << "    2. Raise the first number to a power of 2\n"
          << "    3. Find the array's max value.\n"
          << "    4. Sort the array in descending order\n"
          << "    5. Calculate the sum of digits\n"
          << "    6. Determine if a number is prime (Processes all array\n"
          << "         values)\n";

    while(again) {
        cout << "\n\n"
             << "Select from the following menu\n"
             << "A.   Enter Array Size that is >=10 and <= 100 >.\n"
             << "X.   Terminate The Program.     ";

        cin >> choice;              //Get input
        cin.ignore(INT_MAX, '\n');  //Ignore any additional text

        if (choice == 'a' || choice == 'A') {
            bool validArray = false;
            cout << "\n\n Enter Array Size: ";

            while (!validArray) {
                if (!(cin >> arraySize)) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "\n\n***  Invalid Array Size Value  ***\n"
                         << "Enter an integer not a char: ";
                }
                else if ((arraySize < 10) || (arraySize > 1000)){
                    cout << "\n\n***  Invalid Array Size Value  ***\n"
                         << "Enter Array Size That is >= 10 and <= 1000: ";
                }
                else {
                    validArray = true;
                }
            }
        }
        else if (choice == 'x' || choice == 'X') {
            again = false;
        }
        else {
            cout << "\n***  Invalid Option  ***\n";
        }

    }

    cout << "\n\nPatrick Martinez & Blake Hillier - Tweak Programming Developer"
         << "\nApril 2018\n\n";
 }
