/*********************
* Author: Caleb Drake, Alexander Katrompas
* Class: COSC 2436 Data Structures
* Program: Hash Table
* Purpose: This program creates a hashtable object that efficiently and effectively stores data structs using an array of linkedlists.
*          This is the "main.cpp" file, which thoroughly tests the hashtable code randomly each time it is run.
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    HashTable hashTable;
    cout << "----- Created hashTable -----" << endl;
    
    // show it is empty by calling getCount and printTable
    cout << "Nodes in hash table: " << hashTable.getCount() << endl;
    hashTable.printTable();
    
    // try and put ALL the test data into the table and show what happens
    cout << endl << "----- Adding test data -----" << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << "  " << strs[i] << ":  " << hashTable.insertEntry(ids[i], &strs[i]) << endl;
    }
    cout << endl << "Nodes in hash table: " << hashTable.getCount() << endl;
    hashTable.printTable();

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.


    // Test: Adding multiple of the same id to the hashtable
    //       This should fail each time a duplicate id is added.
    cout << endl << "----- Testing multiple duplicate insertions -----" << endl;
    for (int i = 0; i < SIZE * 2.5; i++) {
        int fakeID = 122;
        string fakeData = "repeated input: first time inserts";

        cout << "Rep " << i + 1 << ": " << hashTable.insertEntry(fakeID, &fakeData) << " | ";

        if (i+1 % 10 == 0) {      // This statement is to organize the output better and make it easier to read
            cout << endl;
        }
    }
    
    // Test: Removing a node from the hashtable. Multiple times.
    //       This should succeed the first time, then fail the rest due to the node being gone.
    cout << endl << "\n----- Testing multiple duplicate removals -----" << endl;
    int removalID = ids[testdatasize - 2];

    for (int i = 0; i < SIZE * 2.5; i++) {
        cout << "Rep " << i + 1 << ": " << hashTable.removeEntry(removalID) << " | ";

        if (i + 1 % 10 == 0) {      // This statement is to organize the output better and make it easier to read
            cout << endl;
        }
    }

    // Test: Remove an invalid node
    //       This should fail.
    cout << endl << "\n----- Testing invalid id removal -----" << endl;
    cout << "Trying -1 (negative id): " << hashTable.removeEntry(ids[testdatasize - 1]) << endl;
    cout << "Trying 123456 (nonexisting id): " << hashTable.removeEntry(123456) << endl;

    // Test: Try and get data from a valid node (multiple times) and invalid nodes, including a negative id node and a nonexistent node.
    //       This should succeed every time for each valid node and return "" for every invalid node.
    string* gottenData = new string;

    cout << endl << "----- Testing getting valid and invalid nodes' data -----" << endl;
    gottenData = hashTable.getData(ids[1]);
    cout << "Valid id get 1: " << ids[1] << " - " << *gottenData << endl;
    gottenData = hashTable.getData(ids[1]);
    cout << "Valid id get 2: " << ids[1] << " - " << *gottenData << endl;
    gottenData = hashTable.getData(ids[1]);
    cout << "Valid id get 3: " << ids[1] << " - " << *gottenData << endl;

    gottenData = hashTable.getData(ids[testdatasize - 1]);
    cout << "Invalid id: " << ids[testdatasize - 1] << " - " << *gottenData << endl;
    gottenData = hashTable.getData(123456);
    cout << "Invalid id: " << "123456" << " - " << *gottenData << endl;

    // Test: Insert and remove a bunch of data from the hash table.
    //       This is to make sure it can handle frequent data movement.
    string spamInput = "Zerg";

    cout << endl << "----- Testing rapid insertion and removal of data -----" << endl;
    for (int i = 0; i < SIZE * 3; i++) {
        cout << "insertion " << i << ": " << hashTable.insertEntry(i + 1, &spamInput) << " - ";
        cout << "removal " << i << ": " << hashTable.removeEntry(i + 1) << "    ";
        if (i + 1 % 5 == 0) {
            cout << endl;
        }
    }

    cout << endl << endl << "----- Final count and list of hashtable -----" << endl;
    cout << "Count: " << hashTable.getCount() << endl;
    hashTable.printTable();
    
    
    return 0;
}
