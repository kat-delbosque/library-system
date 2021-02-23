//
//  loans.h
//  Homework 4
//  Katriel Hadel

#ifndef LOANS_H
#define LOANS_H

#include "loan.h"
#include <vector>
using namespace std;

class loans{
    private:
    vector<loan> LoanVec; //collection of loans
    
    public:
    void checkOutLibraryItem(int, int); //adds loan to LoanVec based on the LibraryItem/patron id given
    void checkInLibraryItem(int, int);//deletes laon based on LibraryItem/patron id given
    void listAllOverdue();//list all loans with status = overdue
    void listLibraryItemsForPatron();//prints all the LibraryItem ids for a particular patron
    float findDaysOverdue(int);//calculate how many days a LibraryItem is overdue (using seconds) and returns the result
    void recheckLibraryItem();
    void storeLoans();//prints loans in LoanVec into loans.txt
    void loadLoans();//reads loans.txt into LoanVec
    void updateLoanStatus();//checks if loan is overdue and updates status
    string checkLoanStatus(int);//uses LibraryItem id to return loan status
};

#endif /* loans_h */
