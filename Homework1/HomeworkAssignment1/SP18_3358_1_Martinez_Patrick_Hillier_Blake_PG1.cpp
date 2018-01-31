//  Roster Numbers: 24, 20 
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

#include <iostream> // Provides cout, cin and endl
#include <iomanip>  // Provides setw for setting output width
#include <cstdlib>  // Provides srand and rand
#include <ctime>     // provides time(for random seed)


using namespace std;

// Prototypes

// Populates an array with random numbers
void populateArray(int array1[][3]);

// Displays array on screen
void displayArray(int array1[][3], string title);

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
    srand(time(NULL)); // Seed random generator

    int array1[3][3]; // First 3 x 3 array
    int array2[3][3]; // Second 3 x 3 array
    int array3[3][3]; // Third 3 x 3 array

    // Tells program whether it should repeat the loop or end the program
    bool runProgram = true;
    // Stores user input to determine whether to continue program or not
    char userAnswer;

    do {
        populateArray(array1); // Populates array with random numbers
        populateArray(array2); // Populates array with random numbers

        displayArray(array1, "Array 1"); // Displays array1 on the screen
        displayArray(array2, "Array 2"); // Displays array2 on the screen

        // Adds both arrays and stores the results in array3
        addArrays(array1, array2, array3);

        // Displays array3 onto the screen
        displayArray(array3, "Sum of Array 1 and Array 2");

        // Multiplies array1 and array2 and stores the results in array3
        multiplyArrays(array1, array2, array3);

        // Displays array3 onto the screen
        displayArray(array3, "Product of Array 1 and Array 2");

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

    cout << "Program Terminated" << endl;

    return 0;
}

// Functions
/*******************************************************************
 populateArray
 Input: array1 (int [][3]) a 3 x 3 array
 Returns: nothing
 Inserts a random number from 1 - 12 into each slot for an array.
 *******************************************************************/
void populateArray(int array1[][3])
{

    int randNums[9]; // A 1D array to hold random numbers generated
    int numbersAdded = 0; // A counter to determine how many numbers
                          // have successfully been added


    // Add a random integer between 1-12 to randNums[0]
    randNums[numbersAdded] = rand()%12 + 1;
    numbersAdded++; // increment numbersAdded

    while (numbersAdded < 9) {
        bool alreadyInList = false; // Boolean to catch duplicate random number
        int randNum = rand()%12 + 1;// Int to temporarily store random number

        // Check if number is already in array
        for (int i = 0; i < numbersAdded; i++) {
            if (randNum == randNums[i])
                alreadyInList = true;
        }

        // Only add randNum if it is not in list
        if (!alreadyInList) {
            randNums[numbersAdded] = randNum;
            numbersAdded++; // increment numbersAdded ONLY if it's a new
                            // distinct number
        }
    }

    // Add the numbers in the randNums array to array1
    int index = 0; // Used to iterate through randNums array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            array1[i][j] = randNums[index];
            index++;
        }
    }
}

/***************************************************************
 displayArray
 Input: array1 (int [][3]) a 3 x 3 array
        string title - The title for the table
 Returns: nothing
 Prints the title of the table over the
 contents of the array on the screen in a 3 x 3 grid.
 ***************************************************************/
void displayArray(int array1[][3], string title)
{
    const int TABLE_WIDTH = 3; // Set the distance between table cells

    // Print 2 empty lines, then title:
    cout << endl << endl;
    cout << title << ": " << endl << endl;

    // Print each element in a table of 3 by 3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(TABLE_WIDTH) << array1[i][j];
        }
        cout << endl << endl;
    }
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
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            resultingArray[r][c] = array1[r][c] + array2[r][c];
        }
    }
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
 Input: array (int [][3]) as a 3 x 3 array1
 Returns: nothing
 Prints the result of flipping the rows into columns.
 ****************************************************/
void displayTransposedArray(int array1[][3])
{

}

/********************************************************************
 displayDeterminant
 Input: array1 (int [][3]) as a 3 x 3 array1
 Returns: nothing
 Calculates the determinant of the array1 and prints it on the screen.
 ********************************************************************/
void displayDeterminant(int array1[][3])
{
    double determinant = array1[0][0] * (array1[1][1] * array1[2][2] - array1[1][2] 
                         * array1[2][1]) - array1[0][1] * (array1[1][0] * 
                         array1[2][2] - array1[1][2] * array1[2][0]) + array1[0][2]
                         * (array1[1][0] * array1[2][1] - array1[1][1] * 
                         array1[2][0]);

    cout << "Determinant of Array 1 = " << determinant << endl;
}

/*************************************************************************
 sumArrayRows
 Input: array1 (int [][3]) as a 3 x 3 array1
 Returns: nothing
 Adds each element in a row and prints the sum on the screen for each row.
 **************************************************************************/
void sumArrayRows(int array1[][3])
{
    int row1 = 0;
    int row2 = 0;
    int row3 = 0; 

    for (int i = 0; i < 3; i++)
    {
        row1 += array1[0][i];
    }

    for (int i = 0; i < 3; i++)
    {
        row2 += array1[1][i];
    }


    for (int i = 0; i < 3; i++)
    {
        row3 += array1[2][i];
    }

    cout << "Sum of numbers in Row # 1 in Array 1 = " << row1 << endl;
    cout << "Sum of numbers in Row # 2 in Array 1 = " << row2 << endl;
    cout << "Sum of numbers in Row # 3 in Array 1 = " << row3 << endl;
}

/******************************************************************************
 sumArrayColumns
 Input: array1 (int [][3]) as a 3 x 3 array1
 Returns: nothing
 Adds each element in a column and prints the sum on the screen for each column
 *****************************************************************************/
void sumArrayColumns(int array1[][3])
{
    int column1 = 0;
    int column2 = 0;
    int column3 = 0; 

    for (int i = 0; i < 3; i++)
    {
        column1 += array1[i][0];
    }

    for (int i = 0; i < 3; i++)
    {
        column2 += array1[i][1];
    }


    for (int i = 0; i < 3; i++)
    {
        column3 += array1[i][2];
    }

    cout << "Sum of numbers in Column # 1 in Array 1 = " << column1 << endl;
    cout << "Sum of numbers in Column # 2 in Array 1 = " << column2 << endl;
    cout << "Sum of numbers in Column # 3 in Array 1 = " << column3 << endl;
}

/*************************************************************************
 sumArrayDiagonals
 Input: array1 (int [][3]) as a 3 x 3 array1
 Returns: nothing
 Adds each element in a diagonal and prints the sum on the screen for each
 diagonal.
 *************************************************************************/
void sumArrayDiagonals(int array1[][3])
{

}

/*********************************************************************
isSpecialArray
Input: array1(int [][3] as a 3 x 3 array1
Returns: true or false
Returns true if array1 is a Special Array and false otherwise.
**********************************************************************/
void isSpecialArray(int array11[][3])
{

}
