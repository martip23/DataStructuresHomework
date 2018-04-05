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
#include <ctime>    // For srand, time
#include <cstdlib>  // For rand
#include <cassert>  // For debugging

using namespace std;

/*******************************************************************************
BIG COMMENT FOR CLASS
*******************************************************************************/
class OurArray {
private:
    int* intArray; // Pointer to array
    int  size;   // Holds size of array to make writing other functions easier

    void quickSort(int arr[], int left, int right);

public:
    // One liner comment
    OurArray(int size);

    // One liner comment
    int at(int index);

    // Returns size of array
    int getSize();

    // One liner comment
    void displayFirstTen();

    // One liner comment
    void displaySquaresTo(int index);

    // One liner comment
    void displayExponent(int base, int power);

    // One liner comment
    void displayMaxElement();

    // One liner comment
    void displayAndSort();

    // One liner comment
    void displaySumOfDigits(int num);

    // One liner comment
    void displayPrimes();

    ~OurArray();
};

int main() {

    srand(time(NULL)); // Seed random number generator
    bool again = true; // Whether to continue program, or exit
    int arraySize = -1;// The size of the array to be created
    char choice;       // User input choice

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
        cin.ignore(256, '\n');  //Ignore any additional text

        if (choice == 'a' || choice == 'A') {
            bool validArray = false;    // Whether the array input is valid
            cout << "\n\nEnter Array Size: ";

            while (!validArray) {
                if (!(cin >> arraySize)) {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "\n\n***  Invalid Array Size Value  ***\n"
                         << "Enter an integer not a char: ";
                }
                else if ((arraySize < 10) || (arraySize > 1000)){
                    cout << "\n\n***  Invalid Array Size Value  ***\n"
                         << "Enter Array Size That is >= 10 and <= 1000: ";
                }
                else {
                    validArray = true;
                    OurArray ourArray(arraySize);

                    ourArray.displayFirstTen();
                    ourArray.displaySquaresTo(ourArray.getSize() - 1);
                    ourArray.displayExponent(ourArray.at(0), 2);
                    ourArray.displayMaxElement();
                    ourArray.displayAndSort();
                    ourArray.displaySumOfDigits(ourArray.at(0));
                    ourArray.displayPrimes();
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
/******************************************************************************
BIG COMMENT
******************************************************************************/
void OurArray::quickSort(int arr[], int left, int right) {
    int i = left;   // Left index to check
    int j = right;  // Right index to check
    int pivot = arr[right]; // Choose last element for pivot
    int temp;       // To hold int for swaps

    // While indexes have not passed each other
    while(i <= j) {
            // If left index is < pivot, continue
        while (arr[i] < pivot)
            i++;
            // If right index is > pivot, continue
        while (arr[j] > pivot)
            j--;

        // Make sure indexes have not touched
        if (i <= j) {
            // Swap them bad boys
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }

        // If there are items in the left array, sort them
        if (left < j)
            quickSort(arr, left, j);

        // If there are items in the right array, sort them too
        if (right > i)
            quickSort(arr, i, right);
    }
}

/******************************************************************************
BIG COMMENT
******************************************************************************/
OurArray::OurArray(int size) {
    this->size = size;
    intArray = new int[size];
    for (int i = 0; i < size; i++)
        intArray[i] = (rand() % 991 + 10);
}

/******************************************************************************
BIG COMMENT
******************************************************************************/
int OurArray::at(int index) {
    return intArray[index];
}

/******************************************************************************
BIG COMMENT
******************************************************************************/
int OurArray::getSize() {
    return size;
}

/******************************************************************************
BIG COMMENT
******************************************************************************/
void OurArray::displayFirstTen() {

    cout << "\n\n"
         << "The first 10 elements are:"
         << "\n";

    for (int i = 0; i < 10; i++) {
        cout << intArray[i] << "  ";
    }
    cout << "\n";
}

/******************************************************************************
BIG COMMENT
******************************************************************************/
void OurArray::displaySquaresTo(int index) {

}

/******************************************************************************
BIG COMMENT
******************************************************************************/
void OurArray::displayExponent(int base, int power) {

}

/******************************************************************************
BIG COMMENT
******************************************************************************/
void OurArray::displayMaxElement() {

}

/******************************************************************************
BIG COMMENT
******************************************************************************/
void OurArray::displayAndSort(){

    cout << "\n\n"
         << "Sorting array..."
         << "\n\n";

    quickSort(intArray, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << intArray[i] << "  ";
    }
    cout << "\n";
}

/******************************************************************************
BIG COMMENT
******************************************************************************/
void OurArray::displaySumOfDigits(int num) {

}

/******************************************************************************
BIG COMMENT
******************************************************************************/
void OurArray::displayPrimes() {

}

OurArray::~OurArray() {

}
