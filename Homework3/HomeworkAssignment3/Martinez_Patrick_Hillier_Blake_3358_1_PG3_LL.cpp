/*******************************************
 Roster Numbers: 20 24

 Authors: Blake Hillier and Patrick Martinez

 Programming Assignment Number 3

 Spring 2018 - CS 3358 - 251

 Due Date: March 5, 2018

 Instructor: Husain Gholoom

 This program is a demonstration of a linked list. It will
 a) Build 2 linked lists of 15 random integers from 1-19
 b) Create a new list that contains all elements of list 1 and list 2 then
    display
 c) It will display the number of occurrences of the first element in list 3
 d) Create a new list by removing all duplicates in list 3 and display this list
 e) Display number of elements in list 4
 f) Display list 4 backwards
 g) Move the last element of list4 and place it after the 3rd element in the
    same list, then display
 h) Sort list 4 in ascending order, and display.

 *******************************************/

#include <cstdlib>  // Provides srand and rand
#include <ctime>    // Provides time for random seed
#include <iomanip>  // Provides setw and precision
#include <iostream> // Provides cin, cout and endl
#include <string>

using namespace std;

class NumberList {
    // Contains item in list and pointers to the items in front of and behind it
    struct ListNode {
        ListNode *prv;
        int num;
        ListNode *nxt;
    };

    // Beginning of list
    ListNode *head;

    public:
        // Creates list with 15 #'s between 1-19
        NumberList();
        // Creates lists based on list1 and then list2
        NumberList(NumberList const &list1, NumberList const &list2);
        // Creates list based on list1 with no duplicate numbers
        NumberList(NumberList const& list1);
        // Function to create a node at the end of the list
        void createNode(int val);
        // Function to return the value at index position
        int getValueAt(int index);
        // Deletes all structures in list and points head to null
        void clearList();
        // Displays items in list
        void display(string listName);
        // Finds number of Occurrences for the number at position index
        void numOccurrence(int index, string listName);
        // Finds length of list
        int findLength();
        // Displays the list backwards
        void displayBackwards();
        // Move the last element behind the element at destinationIndex
        void moveElement(int destinationIndex);
        // Sorts the list in increasing number
        void sortList();
};

int main() {
    bool run = true;
    char userChoice;
    srand(time(NULL)); // Seed Random Generator

    do {
        // Creates 2 lists and fills them with 15 #'s 1-19
        NumberList list_1;
        NumberList list_2;

        // Displays lists on screen
        list_1.display("list_1");
        list_2.display("list_2");

        // Creates list from numbers in list_1 and
        //  then list_2 and displays it on screen
        NumberList list_3(list_1, list_2);
        list_3.display("list_3");

        // Displays number of times 1st number appears in list
        list_3.numOccurrence(0, "list_3");

        // Creates list based off of list_3 with no duplicate
        // numbers and displays it on screen
        NumberList list_4(list_3);
        list_4.display("list_4");

        // Displays number of items in list
        cout << "Length of list 4: " << list_4.findLength() << endl;

        // Displays list backwards on screen
        list_4.displayBackwards();

        // Moves the last element and places it after the 3rd
        // one and displays it on screen
        list_4.moveElement(3);
        list_4.display("list_4 after moving last element to the 4th position");

        // Sorts list in increasing order and displays it on screen
        list_4.sortList();
        list_4.display("list_4 sorted");

        // Deletes the list
        list_1.clearList();
        list_2.clearList();
        list_3.clearList();
        list_4.clearList();

        cout << "Would you like to run this again? (Y/y = yes or N/n = no)"
            << endl;
        cin >> userChoice;

        // Checks user's input to see whether to run program again or not
        if (userChoice == 'y' || userChoice == 'Y')
            run = true;
        else if (userChoice == 'n' || userChoice == 'N')
            run = false;
        else {
            cout << "Input not recognized./nTerminating program." << endl;
            run = false;
        }

    } while (run);

    cout << "This LL Program is Implemented by:\nBlake Hillier and Patrick";
    cout << "Martinez - March 5th, 2018" << endl;

    return 0;
}

// Functions

/*******************************************************************
 NumberList default constructor
 Creates a list with 15 numbers between 1-19
 *******************************************************************/
NumberList::NumberList() {
    const int INIT_LENGTH = 15;

    // Creates first node
    ListNode * newNode = new ListNode;
    newNode -> prv = NULL;
    newNode -> num = rand()%19 + 1;

    // Points head to the first node
    head = newNode;
    // Creates variable prvNode and points it at the first node stored in head
    ListNode * prvNode = new ListNode;
    prvNode = head;

    /************************************************************
     For each list item: creates a new node
                         points the previous node to the new node
                         points the new node to the previous node
                         creates a number for the new node
                         points the new node also to null
                         assigns the new node to prvNode
     ************************************************************/
    for (int i = 1; i < INIT_LENGTH; i++) {
        ListNode * newNode = new ListNode;
        prvNode -> nxt = newNode;
        newNode -> prv = prvNode;
        newNode -> num = rand()%19 + 1;
        newNode -> nxt = NULL;
        prvNode = newNode;
    }
}

/*******************************************************************
 NumberList 2 parameter constructor
 Input: two Number List objects
 Output: None
 Creates new list based on list1 and list2
 *******************************************************************/
NumberList::NumberList(NumberList const &list1, NumberList const &list2) {
    head = NULL;

    ListNode *temp = new ListNode;

    if (list1.head) {
        temp = list1.head;
        createNode(temp -> num);

        while (temp->nxt) {
            temp = temp -> nxt;
            createNode(temp -> num);
        }
    }
    if (list2.head) {
        temp = list2.head;
        if (!head) {
            head = list2.head;
        } else {
            createNode(temp -> num);
        }
        while (temp->nxt) {
            temp = temp -> nxt;
            createNode(temp -> num);
        }
    }
}

/*******************************************************************
 Numberlist Single Paramter constructor
 Input: 1 numberList
 Output: None
 Creates list based on list1 with no duplicate values.
 *******************************************************************/
NumberList::NumberList(NumberList const &list1) {
    head = NULL;
}

/*******************************************************************
 createNode
 Input: value to insert
 Output: None
 Adds a value to the end of the list, very valuable for the copy constructors
 *******************************************************************/
void NumberList::createNode(int val) {
    ListNode *newNode = new ListNode;
    newNode -> num = val;
    newNode -> nxt = NULL;

    // If first element, it will be head
    if (head == NULL) {
        head = newNode;
    } else {
        ListNode *tempPtr = new ListNode;
        tempPtr = head;

        while (tempPtr->nxt) {
            tempPtr = tempPtr -> nxt;
        }
        tempPtr -> nxt = newNode;
    }
}

/*******************************************************************
 getValueAt (index)
 Input: Index - The index to get the value from
 Output: Integer at this index
 Gets the value at whatever index is passed in. Valuable for copy functions.
 **STARTS AT 0**
 *******************************************************************/
int NumberList::getValueAt(int index) {
    if (index >= findLength()) {
        cout << "\n***ERROR***Index out of range!\n" << endl;
    }
    else {
        ListNode *temp = new ListNode;
        temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp -> nxt;
        }

        return temp -> num;
    }
}
/*******************************************************************
 clearList
 Input: None
 Output: None
 Clears the list.
 *******************************************************************/
void NumberList::clearList() {
    if (!head) { // TODO: Delete if statement once all constructors have been implemented
        ListNode * rptr = head;
        head = NULL;
        ListNode * nxtptr;

        while (rptr -> nxt) {
            nxtptr = rptr -> nxt;
            delete rptr;
            rptr = nxtptr;
        }

        delete rptr;
        rptr = NULL;
    }
}

/*******************************************************************
 Display
 Input: none
 Returns: none
 Displays all items in list.
 *******************************************************************/
void NumberList::display(string listName) {
    if (!head) { // TODO: Delete if statement once all constructors have been implemented
        ListNode *newNode = new ListNode;
        newNode -> num = -1;
        newNode -> nxt = NULL;
        newNode -> prv = NULL;
        head = newNode;
    }

    // Create tptr, point it to head, and print it's number
    ListNode *tptr = head;
    cout << listName << ": " << tptr -> num;

    // If tptr points to another node,
    // assing tptr to that node and print its number
    while (tptr -> nxt) {
        tptr = tptr -> nxt;
        cout << " " << tptr -> num;
    }
    cout << endl;
}

/*******************************************************************
 numOccurrence
 Input: index
 Returns: none
 Displays the number of occurrences of for the item at index position.
 *******************************************************************/
void NumberList::numOccurrence(int index, string listName) {
    int item = getValueAt(index);
    int numOccurrences = 1;
    ListNode *temp = new ListNode;
    temp = head;

    while (temp->nxt) {
        if (item == temp->nxt->num)
            numOccurrences++;
        temp = temp->nxt;
    }
    cout << item << " appears " << numOccurrences << " times in " << listName
        << "." << endl;
}

/*******************************************************************
 findLength
 Input: none
 Returns: none
 Displays the length of the list.
 *******************************************************************/
int NumberList::findLength() {
    int counter = 0;

    if (head) {
        counter++;
        ListNode *temp = new ListNode;
        temp = head;

        // If there is a new node to traverse, add 1 and GO
        while (temp->nxt) {
            counter++;
            temp = temp->nxt;
        }
    }
    return counter;
}

/*******************************************************************
 displayBackwards
 Input: none
 Returns: none
 Displays the list backwards.
 *******************************************************************/
void NumberList::displayBackwards() {
    // IDEA: Push onto stack array, then pop to display.
}

/*******************************************************************
 moveElement
 Input: destinationIndex
 Returns: none
 Moves the last element behind the element at destinationIndex
 *******************************************************************/
void NumberList::moveElement(int destinationIndex) {
}

/*******************************************************************
 sort
 Input: none
 Returns: none
 Sorts the list in ascending order
 *******************************************************************/
void NumberList::sortList() {
}
