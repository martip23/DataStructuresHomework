//      Roster Numbers: 24 20
//
//      Authors: Patrick Martinez, Blake Hillier
//      Due Date: 3/28/2018
//      Programming Assignment Number: 4
//
//      Spring 2018 - CS 3358 - 251
//
//      Instructor: Husain Gholoom
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
class CharStack {
    char * stackArray;
    int stackSize;
    int numItems;
    int top;

    public:
    
    // Creates the dynamic array of size 'size'.
    CharStack(int size);

    // Deletes stackArray.
    ~CharStack();

    // Inserts c at the top of the stack.
    void push(char c);

    // Removes and returns the top element from the stack.
    char pop();

    /**********************
     getSize
     Input: none
     Returns size of stack.
     **********************/
    int getSize() { return stackSize; };
};

/************
A queue implementation meant to use any type. Utilizes a linked list.
************/
template <class ItemType>
class Queue {

    struct Node {
        ItemType data;  // Data held in queue
        Node* next; // Link to next node
        Node* prev;
    };

    Node* front;    // Link to front of queue
    Node* back;     // Link to tail of queue

    public:
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

    /**************
    Destroys linked list
    *************/
    ~Queue();
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
            if(!(cin >> userChoice)) {// If insertion to int fails, throw except
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
                    cout << "\nEnter Stack Values: ";
                    cin >> stackValues;

                    // Stores the number of characters in stackValues
                    int count = stackValues.length();
                    // Stores the location of the pound symbol
                    int poundIndex = -1;
                    // Finds index of pound symbol in stackValues
                    for (int i = 0; i < count; i++) {
                        if (stackValues[i] == '#')
                            poundIndex = i;
                    }
                    if (poundIndex == -1)
                        throw -1;

                    // Creates a stack to fit characters up to the pound symbol
                    CharStack * stack1 = new CharStack(poundIndex);
                    // Creates a stack to fit characters after the pound symbol
                    CharStack * stack2 = new CharStack(count - poundIndex - 1);

                    // Populate Stack1 with characters up to the pound symbol
                    for (int i = 0; i < poundIndex; i++) {
                        stack1->push(stackValues[i]);
                    }

                    // Populate Stack2 with characters after the pound symbol
                    for (int i = poundIndex + 1; i < count; i++) {
                        stack2->push(stackValues[i]);
                    }

                    // Checks if stacks are same size
                    // If true, compare each element
                    // If false, strings aren't identical
                    bool isSameString = true;
                    if (stack1->getSize() != stack2->getSize())
                        isSameString = false;
                    else {
                        for (int i = 0; i < stack1->getSize(); i++) {
                            if (stack1->pop() != stack2->pop())
                                // If elements don't match, strings aren't equal
                                isSameString = false;
                        }
                    }

                    if (isSameString)
                        cout << "\nStrings are Identical" << endl << endl;
                    else
                        cout << "\nStrings are not Identical" << endl << endl;

                    delete stack1;
                    delete stack2;
                    break;
                }
                case 2: {
                    // Use queue
                    Queue<char> queue;
                    Queue<char> queue2;
                    bool secondSequence = false;

                    string queueValues;
                    cout << "Enter Queue Values:\t";
                    cin >> queueValues;
                    // Stores the number of characters in queueValues
                    int count = queueValues.length();
                    // Stores the location of the pound symbol
                    int poundIndex = -1;
                    // Finds index of pound symbol in queueValues
                    for (int i = 0; i < count; i++) {
                        if (queueValues[i] == '#')
                            poundIndex = i;
                    }
                     if (poundIndex == -1)
                        throw -1;

                    for (int i = 0; i < poundIndex; i++) {
                        queue.enqueue(queueValues[i]);
                    }

                    for (int i = count - 1; i > poundIndex; i--) {
                        queue2.enqueue(queueValues[i]);
                    }

                    bool areReverse = true;
                    while (!queue.isEmpty() && !queue2.isEmpty() && areReverse){
                        if (queue.dequeue() != queue2.dequeue()) {
                            areReverse = false;
                        }
                    }
                    if (queue.isEmpty() && queue2.isEmpty())
                        areReverse = true;
                    else areReverse = false;

                    if (areReverse) {
                        cout << "String2 is reverse of String1" << endl << endl;
                    }
                    else
                        cout << "String 2 is not reverse of string1" << endl
                        << endl;
                }
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

/********************
Creates a queue recursively for reverse comparison with queue
********************/
void recursiveQueue (string toReverse) {


}

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
        nextNode->prev = NULL;
        front = nextNode;
        back = nextNode;
    } else {
        nextNode->prev = back;
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
    if (isEmpty()) {
        cout << "\nERROR: NO ITEMS TO DEQUE" << endl;
        throw -1;
    }
    ItemType returnVal = front->data;
    Node* temp = front;
    if (front->next == NULL) {
        front = NULL;
    }
    else {
        front = front->next;
        front->prev = NULL;
    }
    delete temp;
    return returnVal;
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

template <class ItemType>
Queue<ItemType>::~Queue() {
    while(!isEmpty()) {
        dequeue();
    }
    delete front;
    delete back;
}

// CharStack Functions

/*****************************************
 Constructor
 Input: size (int) as size of the array
 Creates the dynamic array of size 'size'.
 *****************************************/
CharStack::CharStack(int size) {
    stackArray = new char[size];
    top = -1;
    numItems = 0;
    stackSize = size;
}

/*******************
 Destructor
 Input: none
 Deletes stackArray.
 *******************/
CharStack::~CharStack() {
    delete stackArray;
}

/*****************************************************************
 push
 Input: c (char) as the character inserted at the top of the stack
 Inserts c at the top of the stack.
 *****************************************************************/
void CharStack::push(char c) {
    stackArray[++top] = c;
    numItems++;
}

/***************************************************
 pop
 Input: none
 Removes and returns the top element from the stack.
 ***************************************************/
char CharStack::pop() {
    numItems--;
    return stackArray[top--];
}
