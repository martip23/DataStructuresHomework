//  Authors: Patrick Martinez, Blake Hillier
//  Due Date: ??
//  Programming Assignment Number 1
//  Spring 2018 - CS 3358 - 261
//
//  Instructor: Hussain Gholoom
//
//  <INSERT DESCRIPTION>

#include <iostream>

using namespace std;

// Prototypes
/*******************************************************************
 populateArrays
 Input: array1 (int [][3]) a 3 x 3 array
        array2 (int [][3]) a 3 x 3 array
 Returns: nothing
 Inserts a random number from 1 - 12 into each slot for both arrays.
 *******************************************************************/
void populateArrays(int array1[][3], int array2[][3]);

/***************************************************************
 displayArray
 Input: array (int [][3]) a 3 x 3 array
 Returns: nothing
 Prints the contents of the array on the screen in a 3 x 3 grid.
 ***************************************************************/
void displayArray(int array[][3]);

/******************************************************************
 addArrays
 Input: array1 (int [][3]) as a 3 x 3 array
        array2 (int [][3]) as a 3 x 3 array
        resultingArray (int [][3]) as a 3 x 3 array
 Returns: nothing
 Adds the two arrays together and stores it in the resulting array.
 Prints the resultingArray onto the screen.
 ******************************************************************/
void addArrays(int array1[][3], int array2[][3], int resultingArray[][3]);

/****************************************************************************
 multiplyArrays
 Input: array1 (int [][3]) as a 3 x 3 array
        array2 (int [][3]) as a 3 x 3 array
        resultingArray (int [][3]) as a 3 x 3 array
 Returns: nothing
 Multiplies the arrays together and stores the result in the resulting Array.
 Prints the resultingArray on the screen.
 ****************************************************************************/
void multiplyArrays( int array1[][3], int array2[][3], int resultingArray[][3]);

/****************************************************
 displayTransposedArray
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Prints the result of flipping the rows into columns.
 ****************************************************/
void displayTransposedArray(int array[][3]);

/********************************************************************
 displayDeterminant
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Calculates the determinant of the array and prints it on the screen.
 ********************************************************************/
void displayDeterminant(int array[][3]);

/*************************************************************************
 sumArrayRows
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Adds each element in a row and prints the sum on the screen for each row.
 **************************************************************************/
void sumArrayRows(int array[][3]);

/*******************************************************************************
 sumArrayColumns
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Adds each element in a column and prints the sum on the screen for each column.
 *******************************************************************************/
void sumArrayColumns(int array[][3]);

/*************************************************************************
 sumArrayDiagonals
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Adds each element in a diagonal and prints the sum on the screen for each
 diagonal.
 *************************************************************************/
void sumArrayDiagonals(int array[][3]);

/***************************************************************************
 isSpecialArray
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Checks to see is the array has nine distinct numbers and prints the result.
 ***************************************************************************/ 
void isSpecialArray(int array[][3]);

int main()
{
    int array1[3][3]; // First 3 x 3 array
    int array2[3][3]; // Second 3 x 3 array
    int array3[3][3]; // Third 3 x 3 array
    // Tells program wether it should repeat the loop or end the program
    bool runProgram = true;
    // Stores the users answer to determine if the program should continue running
    char userAnswer; 

    do {
        populateArrays(array1, array2); // Populates the arrays with random numbers

        displayArray(array1); // Displays array1 on the screen
        displayArray(array2); // Displays array2 on the screen
 
        // Adds both arrays and stores the results in array3
        addArrays(array1, array2, array3);

        // Displays array3 onto the screen
        displayArray(array3);

        // Multiplies array1 and array2 together and stores the results in array3
        multiplyArrays(array1, array2, array3);

        // Displays array3 onto the screen
        displayArray(array3);

        // Transposes array1 and displays the result on the screen
        displayTransposedArray(array1);

        // Calculates the determinant of array1 and displays the result on the screen
        displayDeterminant(array1);

        // Adds each element in a row for all rows in array1 and displays the result on the screen
        sumArrayRows(array1);

        // Adds each element in a column for all columns in array1 and displays the result on the screen
        sumArrayColumns(array1);

        // Adds each diagonal element for both diagonals in array1 and displays the result on the screen
        sumArrayDiagonals(array1);

        // Determins if array1 is a special array and displays the result on the screen
        isSpecialArray(array1);

        cout << "Do you want to run again? (y/n): ";
        cin >> userAnswer;

        // If user answered 'n', then the loop will end
        if (userAnswer == 'n')
           runProgram = false;

    } while (runProgram);

    cout << "Program Terminated";
}

// Functions
