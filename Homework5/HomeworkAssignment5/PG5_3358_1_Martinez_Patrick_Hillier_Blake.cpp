/*******************************************************************************
Roster Numbers: 20 24

Authors: Blake Hillier and Patrick Martinez
Due Date: April 9, 2018
Programming Assignment Number 5

Spring 2018 - CS 3358 - 261

Instructor: Husain Gholoom

This program demonstrates functions done on an array which employ recursion and
other programming techniques. The program will begin by populating an array of
user-defined size with random integers from 10-1000. It then raises the first
element to a power of 2, gets the array's max value, sort's the array in
descending order, calculates the sum of digits and determines if all numbers
in the array are prime.
******************************************************************************/

#include <iostream> // For cin/cout statements
#include <ctime>    // For srand, time
#include <cstdlib>  // For rand
#include <cassert>  // For debugging

using namespace std;

/*******************************************************************************
OurArray: This class is like a wrapper for a dynamic array. It makes getting
the size easier. A at method has been implemented to allow easy access to
memory index data. This class abstracts the dynamic array creation allowing the
user to only worry about how big they want their data to be.
*******************************************************************************/
class OurArray {
private:
    int* intArray; // Pointer to array
    int  size;   // Holds size of array to make writing other functions easier

    // A private utility for the descending quick sort.
    void decQuickSort(int arr[], int left, int right);

    // Private utility to get exponent
    int getExponent(int base, int power);

    // Private utility to get squares
    void findSquares(int num);

    // Private utility to get max number
    int findMaxNum(int i);

    // Private utility to find the sum of a number's digits
    int sumDigits(int num);

    // Private utility to find if a number is prime
    bool isPrime(int num, int mod);

public:
    // The constructor requires an int for array size. It will be populated
    // with random integers between 10 - 100
    OurArray(int size);

    // Gets the data at position index
    int at(int index);

    // Returns size of array
    int getSize();

    // Displays first ten items in the array.
    void displayFirstTen();

    // Displays the square of all numbers from 1 to the last number in the array
    void displaySquares(int index);

    // Displays the result of raising a base to an exponent
    void displayExponent(int base, int power);

    // Displays the highest element in this array
    void displayMaxElement();

    // Runs a descending sort on this machine and displays data
    void displayAndSort();

    // Displays the sum of the digits of the first number in the array
    void displaySumOfDigits();

    // Displays whether each number in the array is a prime or not.
    void displayPrimes();

    // Frees memory reserved for dynamic array
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
                    ourArray.displaySquares(ourArray.getSize() - 1);
                    ourArray.displayExponent(ourArray.at(0), 2);
                    ourArray.displayMaxElement();
                    ourArray.displayAndSort();
                    ourArray.displaySumOfDigits();
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

     return 0;
}

//Function definitions
/******************************************************************************
decQuickSort: A private utility that performs quick sort on an array to sort
items in decreasing order.
Inputs: arr[]   The array to sort
        left    The left index of the array section to sort
        right   The rightmost index to sort
Output: None
******************************************************************************/
void OurArray::decQuickSort(int arr[], int left, int right) {
    int i = left;   // Left index to check
    int j = right;  // Right index to check
    int pivot = arr[right]; // Choose last element for pivot
    int temp;       // To hold int for swaps

    // While indexes have not passed each other
    while(i <= j) {
            // If left index is > pivot, continue
        while (arr[i] > pivot)
            i++;
            // If right index is < pivot, continue
        while (arr[j] < pivot)
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

        // If there are items from beginning to pivot, sort them
        if (left < j)
            decQuickSort(arr, left, j);

        // If there are items from end to pivot, sort them too
        if (right > i)
            decQuickSort(arr, i, right);
    }
}

/******************************************************************************
OurArray: Constructor for OurArray. Takes a int size and creates an array of
that size randomly populated by integers >9 and <1001
Input:      Size    The size to make the array
Outputs:    None
******************************************************************************/
OurArray::OurArray(int size) {
    this->size = size;
    intArray = new int[size];
    for (int i = 0; i < size; i++)
        intArray[i] = (rand() % 991 + 10);
}

/******************************************************************************
at:     Function to get the item at position index.
Input:  Index   The index to get data from
Output: Int     The integer at index index
******************************************************************************/
int OurArray::at(int index) {
    return intArray[index];
}

/******************************************************************************
getSize:    Function to return size of array.
Input:      None
Output:     Int     Size of the array.
******************************************************************************/
int OurArray::getSize() {
    return size;
}

/******************************************************************************
displayFirstTen(): Displays the first 10 items in the array.
Input:  None
Output: None
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
 displaySquares: displays the sauare of each item in intArray from 1 to the
                   last number in the array
 Input: Index as the last item to square for the function
 Output: none
******************************************************************************/
void OurArray::displaySquares(int index) {
    cout << "\nTable of square values 1 - " << intArray[index] << endl;
    cout << endl << "N     N Squared" << endl;

    findSquares(intArray[index]);
}

/*******************************************************************************
 findSquares: finds all numbers from num to 0 and displays them in reverse order
 Input: num as the number to square
 Output: none
*******************************************************************************/
void OurArray::findSquares(int num) {
    if (num > 0)
        findSquares(num - 1);

    cout << num << "     " << num * num << endl;
}

/******************************************************************************
getExponent: Gets the result of raising a base to an exponent.
Input:  base    The base number to raise
        power   The power to raise to
Output: None
******************************************************************************/
int OurArray::getExponent(int base, int power) {
    if (power == 1 || power == 0)
        return base;
    return base * getExponent(base, power-1);
}

/******************************************************************************
displayExponent: Displays the result of raising a base to an exponent.
Input:  base    The base number to raise
        power   The power to raise to
Output: None
******************************************************************************/
void OurArray::displayExponent(int base, int power) {
    cout << "\n\n"
         << "Power Function:"
         << "\n\n"
         << base << " raised to the " << power << "nd power is: "
         << getExponent(base, power) << "\n";
}

/******************************************************************************
 displayMaxElement: Displays the largest number in the array
 Input: none
 Output: none
******************************************************************************/
void OurArray::displayMaxElement() {
    cout << "Max Number of (";
    for (int i = 0; i < 10; i++) {
        cout << intArray[i] << ", ";
    }
    cout  << ") is : ";
    cout << findMaxNum(0);
}

/*******************************************************************************
 findMaxNum: finds maximum number in the array
 Input: i as the index in the array
 Output: the max number being compared
*******************************************************************************/
int OurArray::findMaxNum(int i) {
    int maxNum = 0;
    if (i == this->getSize() - 1)
        return intArray[i];
    else
        maxNum = findMaxNum(i + 1);

    if (maxNum > intArray[i])
        return maxNum;
    else
        return intArray[i];
}

/******************************************************************************
displayAndSort(): Sorts the array in descending order, displays final list, and
    displays time information between steps.
Input:  None
Output: None
******************************************************************************/
void OurArray::displayAndSort(){

    cout << "\n\n"
         << "Sorted array"
         << "\n\n";

    time_t begin = time(NULL);
    struct tm *beginStructure = localtime(&begin);
    char beginTime [12];
    strftime(beginTime, 12, "%HH:%MM:%SS", beginStructure);

    decQuickSort(intArray, 0, size - 1);

    time_t end = time(NULL);
    struct tm *endStructure   = localtime(&end);
    char endTime [12];
    strftime(endTime, 12, "%HH:%MM:%SS", endStructure);

    for (int i = 0; i < size; i++) {
        cout << intArray[i] << "  ";
    }
    cout << "\n\n"
         << "Start Time             :" << beginTime << endl
         << "End Time               :" << endTime   << endl
         << "Actual CPU Clock time  :" << difftime(end, begin) << endl;
}

/******************************************************************************
 displaySumOfDigits: displays the sum of the digits of the first number in the
                     array
 Input: none
 Output: none
******************************************************************************/
void OurArray::displaySumOfDigits() {
    int num = intArray[0];

    cout << "\nSum of digits for the number " << num << " is "
         << sumDigits(num);
    cout << endl;
}

/*******************************************************************************
 sumDigits: finds the sum of the digits of num
 Input: num as the number you want to sum the digits of
 Output: the sum of the digits of num
*******************************************************************************/
int OurArray::sumDigits(int num) {
    if (num > 10)
        return sumDigits(num/10) + (num % 10);
    else
        return num;
}

/******************************************************************************
 displayPrimes: displays whether each number in the array is a prime number
 Input: none
 Output: none
******************************************************************************/
void OurArray::displayPrimes() {
    cout << "\n\nIs it prime: " << endl;
    for (int i = 0; i < this->getSize(); i++) {
        cout << i << " " <<  intArray[i];
        if (isPrime(intArray[i], 2))
            cout << " is Prime" << endl;
        else
            cout << " is Not Prime" << endl;
    }
}

/******************************************************************************
 isPrime: Checks if num is a prime number
 Input: num as the number being checked if prime
        mod as the current divisor for num
 Output: true if num is prime
         false if num is not prime
******************************************************************************/
bool OurArray::isPrime(int num, int mod) {
    if (num == mod)
        return true;
    else if (num % mod == 0)
        return false;
    else
        return isPrime(num, ++mod);
}
/******************************************************************************
~OurArray: Destroys the dynamically allocated memory for numArray
Input:  None
Output: None
******************************************************************************/
OurArray::~OurArray() {
    delete[] intArray;
}
