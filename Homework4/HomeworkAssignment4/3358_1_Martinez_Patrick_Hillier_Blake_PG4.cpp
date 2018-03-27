//      Roster Numbers: 24 20
//
//      Authors: Patrick Martinez, Blake Hillier
//      Due Date: 3/28/2018
//      Programming Assignment Number: 4
//
//      Spring 2018 - CS 3358 - 251
//
//      Instructor: Husain Gholoom.
//
//      Description: For this assignment we will implement a stack and queue ADT
//      and use these ADTs to compare strings. We will use a stack to determine
//      whether two strings are the same and a queue to determine whether two
//      strings are the reverse of each other. The program will have a terminal
//      IO for input and output.

#include <iostream>

using namespace std;

/************
A stack implementation meant to use char types.
************/
class charStack { //Capitalized class name -Patrick 3.27.18
    char * stackArray;
    int stackSize;
    int numItems;
    int top;

    public:
    /*****************************************
     Constructor
     input: size (int) as size of the array
     Creates the dynamic array of size 'size'.
     *****************************************/
    charStack(int size);

    /*****************************************************************
     push
     Input: c (char) as the character inserted at the top of the stack
     Inserts c at the top of the stack.
     *****************************************************************/
    void push(char c);

    /***************************************************
     pop
     Input: none
     Removes and returns the top element from the stack.
     ***************************************************/
    char pop();
};

/************
A queue implementation meant to use any type. Utilizes a linked list.
************/
template <class ItemType>
class Queue {

    struct Node {
        ItemType data;  // Data held in queue
        Node* next; // Link to next node
    };

    Node* front;    // Link to front of queue
    Node* back;     // Link to tail of queue

    /****************
    Class Constructor.
    ****************/
    Queue();

    /****************
    Used to add a char to the back of the queue
    ****************/
    void enqueue(ItemType data);

    /****************
    Used to remove a char from the front of the queue
    ****************/
    ItemType dequeue(void);

    /****************
    Checks if queue is empty
    ****************/
    bool isEmpty(void);
};

int main() {
    cout << "*** Welcome to Our Stack / Queue Program ***" << endl << endl;
    cout << "The function of this program is to:" << endl;
    cout << "    1. Use stack to determine whether or not two strings"
        << " are the same." << endl;
    cout << "    2. Use queue to determine whether or not STRING2"
        << " is a reverse of STRING1." << endl << endl;

    bool run = true;
    do {
        cout << "Select from the following menu" << endl;
        cout << "    1. Enter Stack Values." << endl;
        cout << "    2. Enter Queue Values." << endl;
        cout << "    9. Terminate the program. ";

        try {
            int userChoice;
            if(!(cin >> userChoice)) {// If insertion to int fails, throw except.
                // Clear cin error state and recover.
                cin.clear();
                cin.ignore(256,'\n');
                throw -1;
            }
            // If int value is not valid, throw exception with int.
            else if (userChoice != 1 && userChoice != 2 && userChoice != 9)
                throw -1;

            switch (userChoice) {
                case 1: {
                    // Use Stack
                    string stackValues;
                    cout << "Enter Stack Values: ";
                    cin >> stackValues;

                    charStack * stack = new charStack(stackValues.length());
                    for (int i = 0; i < stackValues.length(); i++) {
                        stack->push(stackValues[i]);
                    } 
                    
                    break;
                }
                case 2:
                    // Use Queue
                    cout << "\nQUEUE" << endl;
                    break;
                case 9:
                    run = false;
                    break;
                default:
                    throw -1;
                    break;
            } // End Switch
        }
        catch (...) {
            cout << "Invalid Option" << endl << endl;
        }

    } while (run);

    cout << "\n*** End of the Program. ***" << endl;
    cout << "*** Written by Patrick Martinez and Blake Hillier ***" << endl;
    cout << "*** March 28 - 2018 ***" << endl << endl;
}

/***Function Implementation***/

/** Queue Implementations **/

/****************
Sets up linked list for initial use
****************/
template <class ItemType>
Queue<ItemType>::Queue(void) {
    front   = NULL;
    back    = NULL;
}


/****************
Used to add a char to the back of the queue
Input: ch (char) to be put at the back of the line.
****************/
template <class ItemType>
void Queue<ItemType>::enqueue(ItemType data) {
    Node *nextNode = new Node;
    nextNode->data = data;
    nextNode->next = NULL;

    if (isEmpty()) {
        front = nextNode;
        back = nextNode;
    } else {
        back->next = nextNode;
        back = nextNode;
    }
}

/****************
Used to remove a char from the front of the queue
Output: Letter that has been dequeued
****************/
template <class ItemType>
ItemType Queue<ItemType>::dequeue(void) {
    ItemType item;
    return item;
}

/****************
Checks if queue is empty
Output: True if empty, else false.
****************/
template <class ItemType>
bool Queue<ItemType>::isEmpty(void) {
    if (front == NULL) {
        return true;
    }
    else return false;
}

// charStack Functions

// Creates the dynamic array of size 'size'.
charStack::charStack(int size) {
    stackArray = new char[size];
    top = -1;
    numItems = 0;
    stackSize = size;
}

// Inserts c at the top of the stack.
void charStack::push(char c) {
    stackArray[++top] = c;
    numItems++;
}
