//  Roster Numbers: 20 24
//
//  Authors: Patrick Martinez & Blake Hillier
//  Due Date: 4/25/2018
//  Programming Assignment Number 6
//
//  Spring 2018 - CS 3358 - 001
//
//  Instructor: Husain Gholoom.
//
//  This program will create a BST class with the following functions
//  1. A function that builds a BST by inserting nodes and display the tree.
//  2. A function that traverses and displays the tree in pre-order form.
//  3. A function that traverses and displays the tree in post-order form.
//  4. A function that displays all the right sub roots of that tree.
//  5. A function that displays all the left sub roots of the tree.
//  6. A function that counts and displays all the leaves of the tree.
//  7. A function that displays only the leaves of the tree.
//

#include <iostream> // For cout
using namespace std;

/*******************************************************************************
Class: Binary Search Tree
A class to store an array based BST data structure.
*******************************************************************************/
class BinarySearchTree {
private:
    // Doubles the size of the BST (Effectively adds a new row). This will be
    // necessary since most applications will NOT be the best case scenario
    // where the size of the array == the data items in the array.
    // Consider the worst case scenario when inserting 1 - 5 in order. You would
    // need 32 array spots to implement this in an array. This is useful for
    // insertNode applications.
    void extendSize();

public:
    int size;   //Refers to the size of the array, not data elements in array.
    int* array; //Dynamic array of size size.

    // Creates an array implementation of size, initializes to NULL.
    BinarySearchTree(int size);

    // Inserts a new node at its appropriate location. Rejects numbers already
    // in list.
    void insertNode(int val);

    // Traverses and displays tree in pre-order form with root index.
    void const preOrder(int index);

    // Traverses and displays the tree in post-order form with root index.
    void const postOrder(int index);

    // Displays all of the right sub roots of the tree.
    void const displayRSR(int index);

    // Line comment
    void const displayLSR();

    // Returns number of leaves in BST.
    int const treeLeavesCount();

    // Line comment
    void const displayLeafValues();

    // Deallocates dynamic memory
    ~BinarySearchTree();
};

int main () {
    BinarySearchTree tree(13);

    cout << "Binary Search Tree By Patrick Martinez & Blake Hillier\n\n";
    cout << "Inserting nodes.\n\n";
    tree.insertNode(70);
    tree.insertNode(50);
    tree.insertNode(100);
    tree.insertNode(30);
    tree.insertNode(60);
    tree.insertNode(80);
    tree.insertNode(110);
    tree.insertNode(20);
    tree.insertNode(68);
    tree.insertNode(90);
    tree.insertNode(120);
    tree.insertNode(25);
    tree.insertNode(62);

    cout << "Building BST is completed.\n\n";

    /********** FOR TESTING, REMOVE ON FINAL ASSIGNMENT***********/
    for (int i = 0; i < tree.size; i++) {
        cout << i << ":" << tree.array[i] << ", ";
    }
    cout << "\n\n";
    /********** FOR TESTING, REMOVE ON FINAL ASSIGNMENT***********/

    cout << "Values of the Binary Search tree.\n\n";



    // Pre-Order Traversal
    cout << "Pre-Order Traversal of the BST :\n\n";
    tree.preOrder(1);
    cout << "\n\n";     // Added extra newlines to improve output

    // Post-Order Traversal
    cout << "Post-Order Traversal of the BST :\n\n";
    tree.postOrder(1);
    cout << "\n\n";     // Added extra newlines to improve output

    // All right sub root values
    cout << "Here are all the right sub root values for the BST :\n\n";
    tree.displayRSR(1);

    // All left sub root values
    cout << "Here are all the right sub root values for the BST :\n\n";
    tree.displayLSR();

    // Counting Number of Leaves
    cout << "\n\nNumber of Leaves =     " << tree.treeLeavesCount();

    // Display the leaf values
    cout << "\n\nHere are the leaf values in the BST:\n\n";
    tree.displayLeafValues();

    cout << "\n\nApril 25, 2018\n\n"
         << "Written by Patrick Martinez & Blake Hillier\n\n";

    return 0;
}

/** IMPLEMENTATIONS **/

/*******************************************************************************
Creates an array implementation of size, initializes to NULL.
Inputs: None
Outputs: None
*******************************************************************************/
BinarySearchTree::BinarySearchTree(int size){
    this->size = size + 1;
    array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = NULL;
}

/*******************************************************************************
   Doubles the size of the BST (Effectively adds a new row). This will be
   necessary since most applications will NOT be the best case scenario
   where the size of the array == the data items in the array.
   Consider the worst case scenario when inserting 1 - 5 in order. You would
   need 32 array spots to implement this in an array. This is useful for
   insertNode applications.

   Inputs: None
   Outputs: None
*******************************************************************************/
void BinarySearchTree::extendSize(){
    // Create new array of double size
    int* tempArray = new int[size*2];
    int newSize = size * 2;

    // Copy into new array
    for (int i = 0; i < size; i++) {
        tempArray[i] = array[i];
    }
    // Set rest of array to NULL and duplicate size
    for (int i = size ; i < newSize; i++){
        tempArray[i] = NULL;
    }
    size = newSize;
    delete[] array;
    array = tempArray;
}

/*******************************************************************************
Inserts a new node at its appropriate location. Rejects numbers already in list.
Input: Val to insert, not already in list.
Output: None
*******************************************************************************/
void BinarySearchTree::insertNode(int val){
    int currentIndex = 1;

    while (true) {
        // Insert here if empty.
        if (array[currentIndex] == NULL) {
            array[currentIndex] = val;
            return;
        }
        // Go left if node greater than, cancel if equal
        else if (array[currentIndex] >= val) {
            if (array[currentIndex] == val) {
                cout << "ERROR!-- Repeating element" << endl;
                return;
            }
            currentIndex *= 2;
        } // Else, go right
        else
            currentIndex = ((currentIndex * 2) + 1);
        if (currentIndex > size)
            extendSize();
    }
}

/*******************************************************************************
Traverses and displays the tree in pre-order form.
Input: int index - The index to start pre-order at.
Output: None
*******************************************************************************/
void const BinarySearchTree::preOrder(int index){

    // Do nothing and return if node empty or out of array boundary.
    //
    // NOTE: Since array boundary does not == to due to initializing array size
    // to a passed value. The constructor could round up to nearest log2(x) as a
    // workaround to keep size consistent with traditional trees, but increasing
    // array size by two seems to work fine as long as we check that we do not
    // go out of the array bounds by checking (index > size). Generally, BSTs
    // are created in linked lists which would have provided a more elegant
    // solution.
    if (array[index] == NULL || index > size)
        return;

    // Standard pre-order structure
    cout << array[index] << ", ";
    preOrder(index * 2);
    preOrder((index * 2) + 1);
}

/*******************************************************************************
Traverses and displays the tree in post-order form.
Input: int index - The index to start the pre-order traversal at.
OutPut: none
*******************************************************************************/
void const BinarySearchTree::postOrder(int index){
    // Check if node is empty or if index is out of bounds of the array
    if (array[index] == NULL || index > size)
        return;

    postOrder((index * 2));
    postOrder((index * 2) + 1);
    cout << array[index] << " ";
}

/*******************************************************************************
Displays all of the right sub roots of the tree.
Input: Index to start
Output: None
*******************************************************************************/
void const BinarySearchTree::displayRSR(int index){
    int rightChild = ((index * 2) + 1);
    // If main root, don't print and pass child if within range and not null.
    if (index == 1) {
        if ((rightChild != NULL) && (rightChild < size))
            displayRSR(rightChild);
        cout << "\n\n";
    } else if ((rightChild != NULL) && (rightChild < size)) {
        cout << array[index] << ", ";
        displayRSR(rightChild);
    }
    return;
}

/*******************************************************************************

BIG COMMENT

*******************************************************************************/
void const BinarySearchTree::displayLSR(){

}

/*******************************************************************************
Counts the number of leaves in the BST.
*******************************************************************************/
int const BinarySearchTree::treeLeavesCount(){
    int count = 0;
    for (int i = 1; i < size; i++) {
        // If node not empty AND left child not there AND right child not there
        // increment count.
        if (((array[i * 2 + 1] == NULL) || ((i * 2 + 1) > size)) &&
            ((array[i*2] == NULL) || ((i * 2) > size)) && (array[i] != NULL))
            count++;
    }
    return count;
}

/*******************************************************************************

BIG COMMENT

*******************************************************************************/
void const BinarySearchTree::displayLeafValues(){

}

/*******************************************************************************
Deallocates dynamic memory
Inputs: None
Outputs: None
*******************************************************************************/
BinarySearchTree::~BinarySearchTree(){
    delete[] array;
}
