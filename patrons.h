//
//  patrons.h
//  Homework 4
//  Katriel Hadel

#ifndef PATRONS_H
#define PATRONS_H

#include <vector>
using namespace std;

class patrons{
    private:
    vector<patron> patronVec; //collection of patrons
    
    public:
    unsigned int findPatron(int); //return index of patron based on their ID
    void addPatron(); //add new patron by creating a new object patron the using .push_back
    void editPatron(); //use findPatron to find person to edit based on ID
    void deletePatron(); //use findPatron to find person to delete based on ID
    void printPatrons(); // print all patrons in collection
    void printPatron(int); //use findPatron to find patron based on ID then print that patron
    void payFines(); //use findPatron to find patron based on ID -> pay amount input -> return new fine balance
    void storePatrons();//prints patrons in vector into patrons.txt
    void loadPatrons();//reads text from patrons.txt in patronVec
    int checkNumLibraryItems(int); //checks the number of books a patron has based on their id and returns their number of books
    void decNumItems(int); //decrements patron's numItems when book is returned
    float patronBalance(int); //finds patrons balance based on their id and returns their fine balance
    void updateNumItems(int);//finds patrons number of books based on their id and increments it
    void setNewBalance(float, int);//takes in new balance/patron id and updates that patrons balance to tbe balance given
};

#endif /* patrons_h */
