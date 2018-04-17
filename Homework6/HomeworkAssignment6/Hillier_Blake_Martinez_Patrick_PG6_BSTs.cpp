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
class BinarySearchTree() {
public:
    int size;
    int* array;

    // Creates
    BinarySearchTree(int x);

    // Line comment
    void insertNode(int x);

    // Line comment
    void const preOrder();

    // Line comment
    void const postOrder();

    // Line comment
    void const displayRSR();

    // Line comment
    void const displayLSR();

    // Line comment
    void const treeLeavesCount();

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

BIG COMMENT

*******************************************************************************/
void BinarySearchTree::insertNode(int x){

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
void const BinarySearchTree::treeLeavesCount(){

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
