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

using namespace std;

class NumberList {
    // Contains item in list and pointers to the items in front of and behind it
    struct ListNode {
        int num;
        ListNode *nxt;
    };

    // Beginning of list
    ListNode *head;

    public:
        // Sets head to null
        NumberList();
        // Creates lists based on list1 and then list2
        NumberList(NumberList const &list1, NumberList const &list2);
        // Creates list based on list1 with no duplicate numbers
        NumberList(NumberList const& list1);
        // Populates linked list with 15 numbers between 1-19 (Created since an empty list
        // was useful for displayBackwards)
        void populateList(int numbers);
        // Function to create a node at the end of the list
        void createNode(int val);
        // Deletes node with the value passed
        void deleteNode(int value);
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
        // Space each run of the program
        cout << endl;

        // Creates 2 lists and fills them with 15 #'s 1-19
        NumberList list_1;
		list_1.populateList(15);
        NumberList list_2;
		list_2.populateList(15);

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
        cout << "Length of list 4: " << list_4.findLength() << endl << endl;

        // Displays list backwards on screen
        list_4.displayBackwards();

        // Moves the last element, places it after the 3rd
        // element, and displays it on screen
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

        bool validChoice;  // Sentinel value to check valid input
        do {
            cout << "Would you like to run this again? (Y/y = yes or N/n = no)"
                << endl;
            cin >> userChoice;

            // Checks user's input to see whether to run program again or not

            if (userChoice == 'y' || userChoice == 'Y') {
                run = true;
                validChoice = true;
            } else if (userChoice == 'n' || userChoice == 'N') {
                run = false;
                validChoice = true;
            } else {
                cout << "\nError*** Incorrect input. Type Y/y for yes, N/n "
                    << "for no." << endl;
                run = false;
                validChoice = false;
            }
        } while (!validChoice);// Repeat menu options until valid choice
                        // Similar to previous homework problems although
    } while (run);      // not an explicit requirement here.


    cout << "\nThis LL Program is Implemented by:\nBlake Hillier and Patrick";
    cout << "Martinez - March 5th, 2018" << endl << endl;

    return 0;
}

// Functions

/*******************************************************************
 NumberList default constructor
 Sets head to null
 *******************************************************************/
NumberList::NumberList() {
    head = NULL;
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
 Numberlist Single Parameter constructor
 Input: 1 numberList
 Output: None
 Creates list based on list1 with no duplicate values.
 *******************************************************************/
NumberList::NumberList(NumberList const &list1) {
    head = NULL;

    ListNode *temp = new ListNode;

    if (list1.head) {
        temp = list1.head;
        createNode(temp -> num);

        for (int i = 1; temp->nxt; i++) {
            temp = temp -> nxt;

            bool foundDuplicate = false;
            for (int j = 0; j < i; j++) {
	        if (temp->num == getValueAt(j)) {
                    foundDuplicate = true;
                    i--;
                }
            }
            if (!foundDuplicate)
                createNode(temp->num);
        }
    }
}

/*******************************************************************
 populateList
 Input: Integers to populate
 Output: None
 Populates a new Linked List with random integers from 1-19
 *******************************************************************/
 void NumberList::populateList(int numbers) {

    int listLength = numbers;

    // Creates first node
    ListNode *prvNode = new ListNode;
    prvNode -> num = rand()%19 + 1;

    // Points head to the first node
    head = prvNode;

    /************************************************************
     For each list item: creates a new node
                         points the previous node to the new node
                         creates a number for the new node
                         points the new node also to null
                         assigns the new node to prvNode
     ************************************************************/
    for (int i = 1; i < listLength; i++) {
        ListNode * newNode = new ListNode;
        prvNode -> nxt = newNode;
        newNode -> num = rand()%19 + 1;
        newNode -> nxt = NULL;
        prvNode = newNode;
    }
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
 deleteNode
 Input: value to delete
 Output: None
 Deletes node with the value passed.
 *******************************************************************/
void NumberList::deleteNode(int value){
    if (!head)
        return;

    ListNode *temp;

    if (head->num == value) {
        temp = head;
        head = temp->nxt;
        delete temp;
    }
    else {
        ListNode *previousNode = new ListNode;
        temp = head;

        while(temp && temp->num != value){
            previousNode = temp;
            temp = temp -> nxt;
        }

        if (temp) {
            previousNode -> nxt = temp -> nxt;
            delete temp;
        }
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
        return -1;
    }
    else {
        ListNode *temp;
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
    cout << endl << endl;
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
    cout << "The number " << item << " appears " << numOccurrences << " times in " << listName
        << "." << endl << endl;
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
    if(!head)
        return;

    // Create temporary empty list.
    NumberList tempList;

    // Add the last element and iterate backwards.
    for (int i = 1; i <= findLength(); i++) {
        tempList.createNode(getValueAt(findLength() - i));
    }
    tempList.display("List 4 backwards");
}

/*******************************************************************
 moveElement
 Input: destinationIndex
 Returns: none
 Moves the last element behind the element at destinationIndex
 *******************************************************************/
void NumberList::moveElement(int destinationIndex) {
    ListNode * lastPtr = head;
    ListNode * prvPtr;

    while ( lastPtr -> nxt) {
        prvPtr = lastPtr;
        lastPtr = lastPtr -> nxt;
    }

    prvPtr -> nxt = NULL;
    ListNode * tmpPtr = head;

    for (int i = 1; i < destinationIndex; i++) {
       tmpPtr = tmpPtr -> nxt;
    }

    lastPtr -> nxt = tmpPtr -> nxt;
    tmpPtr -> nxt = lastPtr;
}

/*******************************************************************
 sortList
 Input: none
 Returns: none
 Sorts the list in ascending order
 *******************************************************************/
void NumberList::sortList() {
    ListNode * currentPtr = head;
    ListNode * minNumPtr = head;
    ListNode * tmpPtr = head;
    int length = this -> findLength();

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            tmpPtr = tmpPtr -> nxt;
            if (tmpPtr -> num < minNumPtr -> num)
                minNumPtr = tmpPtr;
        }
        if (minNumPtr != currentPtr) {
            int temp = minNumPtr -> num;
            minNumPtr -> num = currentPtr -> num;
            currentPtr -> num = temp;
        }

        if (currentPtr -> nxt) {
            currentPtr = currentPtr -> nxt;
            tmpPtr = currentPtr;
            minNumPtr = currentPtr;
	}
    }
}
