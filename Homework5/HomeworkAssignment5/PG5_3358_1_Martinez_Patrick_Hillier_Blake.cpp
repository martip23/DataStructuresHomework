/*******************************************************************************
Roster Numbers: 20 24

Authors: Blake Hillier and Patrick Martinez
Due Date: April 9, 2018
Programming Assignment Number 5

Spring 2018 - CS 3358 - 261

Instructor: Husain Gholoom

//TODO: Description
******************************************************************************/

#include <iostream> // For cin/cout statements
#include <vector>   // For vectors
#include <ctime>    // For srand, time
#include <cstdlib>  // For rand
#include <cassert>  // For debugging

using namespace std;

// Function prototypes


void populateArray(vector<int> &origArray, int arraySize);

void displayFirstTen(vector<int> const &dispArray);

void displaySquaresToLastNumber(vector<int> const &origArray);

void displayRaiseToPower(int base, int power);

void displayMaxElement(vector<int> const &origArray);

void displayAndStoreQuickSort(vector<int> const &origArray,
                              vector<int> &sortedArray);

void displaySumOfDigits(int num);

void displayPrimes(vector<int> const &sortedArray);

int main() {

    srand(time(NULL)); // Seed random number generator
    bool again = true; // Whether to continue program, or exit
    int arraySize = -1;// The size of the array to be created
    char choice;       // User input choice
    vector<int> origArray;  // Holds unsorted array
    vector<int> sortedArray;// Holds sorted array

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
            bool validArray = false;    // Whether the array input is valid
            cout << "\n\nEnter Array Size: ";

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
                    populateArray(origArray, arraySize);
                    displayFirstTen(origArray);
                    displaySquaresToLastNumber(origArray);
                    displayRaiseToPower(origArray[0], 2);
                    displayMaxElement(origArray);
                    displayAndStoreQuickSort(origArray, sortedArray);
                    displaySumOfDigits(sortedArray[0]);
                    displayPrimes(sortedArray);
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

//Function definitions


void populateArray(vector<int> &origArray, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        origArray.push_back(rand() % 991 + 10);
    }
    assert(origArray.size() == arraySize);
};

void displayFirstTen(vector<int> const &dispArray) {

};

void displaySquaresToLastNumber(vector<int> const &origArray) {

};

void displayRaiseToPower(int base, int power) {

};

void displayMaxElement(vector<int> const &origArray) {

};

void displayAndStoreQuickSort(vector<int> origArray, vector<int> sortedArray) {
    sortedArray.push_back(-1); // Temporary to allow build
};

void displaySumOfDigits(int num) {

};

void displayPrimes(vector<int> sortedArray) {

};
