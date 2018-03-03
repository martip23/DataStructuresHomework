/*******************************************
 Roster Numbers: 20 24
 
 Authors: Blake Hillier and Patrick Martinez

 Programming Assignment Number 3

 Spring 2018 - CS 3358 - 251?

 Due Date: March 5, 2018

 Instructor: Husain Gholoom

 Description here
 *******************************************/
 
#include <cstdlib> // Provides srand and rand
#include <ctime> // Provides time for random seed
#include <iomanip> // Provides setw and precision 
#include <iostream> // Provides cin, cout and endl

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
    // End of list
    ListNode *tail;

    public:
        // Creates list with 15 #'s between 1-19
        NumberList();
        // Creates lists based on list1 and then list2
        NumberList(NumberList const &list1, NumberList const &list2);
        // Creates list based on list1 with no duplicate numbers
        NumberList(NumberList const& list1);
        // Deletes all structures in list and points head/tail to null
        void clearList();
        // Displays items in list
        void display();
        // Finds number of Occurances for the number at position index
        void numOccurance(int index);
        // Finds length of list
        void findLength();
        // Displays the list backwards
        void displayBackwards();
        // Move the last element behind the element at destinationIndex
        void moveElement(int destinationIndex);
        // Sorts the list in increasing number
        void sort();
}; 
        
int main() {
    bool run = true;
    char userChoice;

    do {
        // Creates 2 lists and fills them with 15 #'s 1-19
        NumberList list_1;
        NumberList list_2;

        // Displays lists on screen
        list_1.display();
        list_2.display();
  
        // Creates list from numbers in list_1 and then list_2 and displays it on screen
        NumberList list_3(list_1, list_2);
        list_3.display();

        // Displays number of times 1st number appears in list
        list_3.numOccurance(1);

        // Creates list based off of list_3 with no duplicate numbers and displays it on screen
        NumberList list_4(list_3);
        list_4.display();

        // Displays number of items in list
        list_4.findLength();

        // Displays list backwards on screen
        list_4.displayBackwards();
 
        // Moves the last element and places it after the 3rd one and displays it on screen
        list_4.moveElement(3);
        list_4.display();

        // Sorts list in increasing order and displays it on screen 
        list_4.sort();
        list_4.display();

        // Deletes the list
        list_1.clearList();
        list_2.clearList();
        list_3.clearList();
        list_4.clearList();

        cout << "Would you like to run this again? (Y/y = yes or N/n = no)" << endl;
        cin >> userChoice;

        // Checks user's input to see wether to run program again or not
        if (userChoice == 'y' || userChoice == 'Y')
            run = true;
        else if (userChoice == 'n' || userChoice == 'N')
            run = false;
        else
            cout << "Input not recognized./nTerminating program." << endl;

    } while (run);
 
    cout << "This LL Program is Implimented by:/nBlake Hillier and Patrick";
    cout << "Martinez - March 5th, 2018" << endl;
}

// Functions

// Creates list with 15 #'s between 1-19
NumberList::NumberList() {
    const int INIT_LENGTH = 15;
    srand(time(NULL)); // Seed Random Generator

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
    // Points the last node to the tail
    tail = prvNode;
}

// Creates lists based on list1 and then list2
NumberList::NumberList(NumberList const &list1, NumberList const &list2) {
}

// Creates list based on list1 with no duplicate numbers
NumberList::NumberList(NumberList const &list1) {
}

// Deletes all structures in list and points head/tail to null
void NumberList::clearList() {
}

// Displays items in list
void NumberList::display() {
}

// Finds number of Occurances for the number at position index
void NumberList::numOccurance(int index) {
}

// Finds length of list
void NumberList::findLength() {
}

// Displays the list backwards
void NumberList::displayBackwards() {
}

// Move the last element behind the element at destinationIndex
void NumberList::moveElement(int destinationIndex) {
}

// Sorts the list in increasing number
void NumberList::sort() {
}
