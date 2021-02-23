//
//  LibraryItems.h
//  Homework 4
//  Katriel Hadel

#ifndef LIBRARYITEMS_H
#define LIBRARYITEMS_H

#include <vector>
#include "LibraryItem.h"

class LibraryItems{
    private:
    vector<LibraryItem*> LibraryItemVec; //collection of LibraryItems
    
    public:
    void clearVec(); //cleaing up
    LibraryItem* findLibraryItem(int libraryID); //return index of LibraryItem based on id
    void addLibraryItem(); //add new LibraryItem by creating a new object LibraryItem the using .push_back
    void editLibraryItem(); //use findLibraryItem to find person to edit based on title
    void deleteLibraryItem(); //use findLibraryItem to find book to delete based on title
    void printLibraryItems(); // print all LibraryItems in collection
    ostream& printLibraryItem(); //use findLibraryItem to find LibraryItem based on title then print that LibraryItem
    void storeLibraryItems(); //prints LibraryItems in vector into LibraryItems.txt
    void loadLibraryItems(); //reads LibraryItems from LibraryItems.txt into LibraryItemVec
    void updateStatusOut(int); //changes book status to out based on id
    void updateStatusIn(int); //changes book status to in based on id
    float getCost(int); //returns the cost of a book based on id
    string checkStatus(int); //returns status of book based on id
    void reportLost(int); //sets book's status to lost
    long returnLoanPeriod(int); //returns loan period for item id entered
};

#endif /* libraryitems_h */
