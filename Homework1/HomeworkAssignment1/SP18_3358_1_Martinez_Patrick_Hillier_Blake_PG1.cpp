//  Roster Numbers: 24, ??
//
//  Authors: Patrick Martinez, Blake Hillier
//  Due Date: Monday 2/5/2018
//  Programming Assignment Number 1
//  Spring 2018 - CS 3358 - 261
//
//  Instructor: Hussain Gholoom
//
//  This program fulfills the homework requirements for assignment one.
//  This program will create 2 arrays of size 3x3, populate them with distinct
//  numbers, add and multiply these arrays, and display results. It will then
//  display the transpose and determinate of array1. Then the sum of each
//  column, row and major diagonals and finally determine whether or not it is
//  a special array.

#include <iostream>

using namespace std;

// Prototypes

// Populates the arrays with random numbers
void populateArrays(int array1[][3], int array2[][3]);

// Displays array on screen
void displayArray(int array1[][3]);

// Adds array1 and array2 and stores sum in resultArray
void addArrays(int array1[][3], int array2[][3], int resultArray[][3]);

// Multiplies array1 and array2 and stores in resultArray
void multiplyArrays( int array1[][3], int array2[][3], int resultArray[][3]);

// Transposes and displays array1
void displayTransposedArray(int array1[][3]);

// Calculates and displays determinant of array1
void displayDeterminant(int array1[][3]);

// Sums up every row in array1 and displays results
void sumArrayRows(int array1[][3]);

// Sums all columns in array1 and displays results
void sumArrayColumns(int array1[][3]);

// Sums all major diagonals in an array and displays results
void sumArrayDiagonals(int array1[][3]);

// Determines if array is a special result and displays result
void isSpecialArray(int array1[][3]);

int main()
{
    int array1[3][3]; // First 3 x 3 array
    int array2[3][3]; // Second 3 x 3 array
    int array3[3][3]; // Third 3 x 3 array

    // Tells program whether it should repeat the loop or end the program
    bool runProgram = true;
    // Stores user input to determine whether to continue program or not
    char userAnswer;

    do {
        populateArrays(array1, array2); // Populates arrays with random numbers

        displayArray(array1); // Displays array1 on the screen
        displayArray(array2); // Displays array2 on the screen

        // Adds both arrays and stores the results in array3
        addArrays(array1, array2, array3);

        // Displays array3 onto the screen
        displayArray(array3);

        // Multiplies array1 and array2 and stores the results in array3
        multiplyArrays(array1, array2, array3);

        // Displays array3 onto the screen
        displayArray(array3);

        // Transposes array1 and displays the result on the screen
        displayTransposedArray(array1);

        // Calculates and displays determinant of array1
        displayDeterminant(array1);

        // Sums up every row in array1 and displays each row results
        sumArrayRows(array1);

        // Sums all columns in array1 and displays each column results
        sumArrayColumns(array1);

        // Sums all major diagonals in an array and displays results
        sumArrayDiagonals(array1);

        // Determines if array is a special result and displays result
        isSpecialArray(array1);

        cout << "Do you want to run again? (y/n): ";
        cin >> userAnswer;

        // If user answered 'n', then the loop will end
        if (userAnswer == 'n')
           runProgram = false;

    } while (runProgram);

    cout << "Program Terminated";

    return 0;
}

// Functions
/*******************************************************************
 populateArrays
 Input: array1 (int [][3]) a 3 x 3 array
        array2 (int [][3]) a 3 x 3 array
 Returns: nothing
 Inserts a random number from 1 - 12 into each slot for both arrays.
 *******************************************************************/
void populateArrays(int array1[][3], int array2[][3])
{

}
/***************************************************************
 displayArray
 Input: array (int [][3]) a 3 x 3 array
 Returns: nothing
 Prints the contents of the array on the screen in a 3 x 3 grid.
 ***************************************************************/
void displayArray(int array1[][3])
{

}
/******************************************************************
 addArrays
 Input: array1 (int [][3]) as a 3 x 3 array
        array2 (int [][3]) as a 3 x 3 array
        resultingArray (int [][3]) as a 3 x 3 array
 Returns: nothing
 Adds the two arrays together and stores it in the resulting array.
 Prints the resultingArray onto the screen.
 ******************************************************************/
void addArrays(int array1[][3], int array2[][3], int resultingArray[][3])
{

}
/****************************************************************************
 multiplyArrays
 Input: array1 (int [][3]) as a 3 x 3 array
        array2 (int [][3]) as a 3 x 3 array
        resultingArray (int [][3]) as a 3 x 3 array
 Returns: nothing
 Multiplies the arrays together and stores the result in the resulting Array.
 Prints the resultingArray on the screen.
 ****************************************************************************/
void multiplyArrays(int array1[][3], int array2[][3], int resultingArray[][3])
{

}
/****************************************************
 displayTransposedArray
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Prints the result of flipping the rows into columns.
 ****************************************************/
void displayTransposedArray(int array1[][3])
{

}
/********************************************************************
 displayDeterminant
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Calculates the determinant of the array and prints it on the screen.
 ********************************************************************/
void displayDeterminant(int array1[][3])
{

}
/*************************************************************************
 sumArrayRows
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Adds each element in a row and prints the sum on the screen for each row.
 **************************************************************************/
void sumArrayRows(int array1[][3])
{

}
/******************************************************************************
 sumArrayColumns
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Adds each element in a column and prints the sum on the screen for each column
 *****************************************************************************/
void sumArrayColumns(int array1[][3])
{

}
/*************************************************************************
 sumArrayDiagonals
 Input: array (int [][3]) as a 3 x 3 array
 Returns: nothing
 Adds each element in a diagonal and prints the sum on the screen for each
 diagonal.
 *************************************************************************/
void sumArrayDiagonals(int array1[][3])
{

}
/*********************************************************************
isSpecialArray
Input: array(int [][3] as a 3 x 3 array
Returns: true or false
Returns true if array is a Special Array and false otherwise.
**********************************************************************/
void isSpecialArray(int array1[][3])
{

}
