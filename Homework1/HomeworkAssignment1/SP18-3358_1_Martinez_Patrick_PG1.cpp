//  Authors: Patrick Martinez, Blake Hillier
//  Due Date: ??
//  Programming Assignment Number 1
//  Spring 2018 - CS 3358 - 261
//
//  Instructor: Hussain Gholoom
//
//  <INSERT DESCRIPTION>

using namespace std;

// Prototypes

int main()
{
    int array1[3][3]; // First 3 x 3 array
    int array2[3][3]; // Second 3 x 3 array
    // Tells program wether it should repeat the loop or end the program
    bool runProgram = true;

    do {
        populateArrays(array1, array2); // Populates the arrays with random numbers

        displayArray(array1); // Displays array1 on the screen
        displayArray(array2); // Displays array2 on the screen
    
        int array3[3][3]; // Third 3 x 3 array
 
        // Adds both arrays and stores the results in array3
        addArrays(array1, array2, array3);

        // Displays array3 onto the screen
        displayArray(array3);

        // Multiplies array1 and array2 together and stores the results in array3
        multiplyArrays(array1, array2, array3);

        // Displays array3 onto the screen
        displayArray(array3);

        // Transposes array1 and displays the result on the screen
        transposeArray(array1);

        // Calculates the determinant of array1 and displays the result on the screen
        findDeterminant(array1);

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

    } while (runProgram)

    cout << "Program Terminated";
}

// Functions
