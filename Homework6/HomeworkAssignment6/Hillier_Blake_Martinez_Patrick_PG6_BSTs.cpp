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

    // Line comment
    void insertNode(int val);

    // Line comment
    void const preOrder();

    // Line comment
    void const postOrder();

    // Line comment
    void const displayRSR();

    // Line comment
    void const displayLSR();

    // Line comment
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
        cout << tree.array[i] << ", ";
    }
    /********** FOR TESTING, REMOVE ON FINAL ASSIGNMENT***********/

    cout << "Values of the Binary Search tree.\n\n";



    // Pre-Order Traversal
    cout << "Pre-Order Traversal of the BST :\n\n";
    tree.preOrder();


    // Post-Order Traversal
    cout << "Post-Order Traversal of the BST :\n\n";
    tree.postOrder();

    // All right sub root values
    cout << "Here are all the right sub root values for the BST :\n\n";
    tree.displayRSR();

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
   Outputs :None

*******************************************************************************/
void BinarySearchTree::extendSize(){
    // Create new array of double size
    int* tempArray = new int[size*2];

    // Copy into new array
    for (int i = 0; i < size; i++) {
        tempArray[i] = array[i];
    }
    // Set rest of array to NULL and duplicate size
    size*=2;
    for (int i = size; i < size; i++){
        tempArray[i] = NULL;
    }
    delete[] array;
    array = tempArray;
}

/*******************************************************************************

BIG COMMENT

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

BIG COMMENT

*******************************************************************************/
void const BinarySearchTree::preOrder(){

}

/*******************************************************************************

BIG COMMENT

*******************************************************************************/
void const BinarySearchTree::postOrder(){

}

/*******************************************************************************

BIG COMMENT

*******************************************************************************/
void const BinarySearchTree::displayRSR(){

}

/*******************************************************************************

BIG COMMENT

*******************************************************************************/
void const BinarySearchTree::displayLSR(){

}

/*******************************************************************************

BIG COMMENT

*******************************************************************************/
int const BinarySearchTree::treeLeavesCount(){

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
