//
//  loan.h
//  Homework 4
//  Katriel Hadel

#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <time.h>
using namespace std;

class loan{
    private:
    int LibraryItemID;
    int PatronID;
    long DueDateTime;
    string CurrentStatus;
    
    public:
    loan();
    loan(int, int, long, string);
    void setLibraryItemID(int);
    int getLibraryItemID();
    void setPatronID(int);
    int getPatronID();
    void setDueDateTime(long);
    long getDueDateTime();
    void setCurrentStatus(string);
    string getCurrentStatus();
};

#endif /* loan_h */
