//  Katriel Hadel
//  LibraryItem.cpp
//  Homework 4
//

#include <string>
#include <iostream>
using namespace std;
#include "LibraryItem.h"

LibraryItem::LibraryItem(){
    LibraryID = 0;
    Cost = 0.0;
    CurrentStatus = "in";
    LoanPeriod = 0;

}

LibraryItem::LibraryItem(int libraryID, float cost, string currentStatus, long loanPeriod){
    LibraryID = libraryID;
    Cost = cost;
    CurrentStatus = currentStatus;
    LoanPeriod = loanPeriod;
}

void LibraryItem::setLibraryID(int libraryID){
    LibraryID = libraryID;
}

int LibraryItem::getLibraryID(){
    return LibraryID;
}

void LibraryItem::setCost(float cost){
    Cost = cost;
}

float LibraryItem::getCost(){
    return Cost;
}

void LibraryItem::setCurrentStatus(string currentstatus){
    CurrentStatus = currentstatus;
}

string LibraryItem::getCurrentStatus(){
    return CurrentStatus;
}

void LibraryItem::setLoanPeriod(long loanPeriod){
    LoanPeriod = loanPeriod;
}

long LibraryItem::getLoanPeriod(){
    return LoanPeriod;
}

void LibraryItem::print(){
    cout << "Library ID: " << LibraryID << endl;
    cout << "Cost: $" << Cost << endl;
    cout << "Current Status: " << CurrentStatus << endl;
    cout << "Loan Period: " << LoanPeriod << endl;
}

ostream& operator<<(ostream& st, LibraryItem& it){
    it.print();
    return st;
}
