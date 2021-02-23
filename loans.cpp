//
//  loans.cpp
//  Homework 4
//  Katriel Hadel

#include <time.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "loans.h"
#include "LibraryItems.h"
#include "loan.h"


void loans::checkOutLibraryItem(int patronID, int itemID){
    time_t currentTime = time(0);
    LibraryItems Item;
    long dueTime = currentTime + Item.returnLoanPeriod(itemID);
    string status = "normal";

        LoanVec.push_back(loan(itemID, patronID, dueTime, status));
}

void loans::checkInLibraryItem(int patronID, int libraryID){
    for(unsigned int i = 0; i < LoanVec.size(); i++){
        if(LoanVec[i].getLibraryItemID() == libraryID){LoanVec.erase(LoanVec.begin() + i);}
    }
}

float loans::findDaysOverdue(int libraryID){
    time_t currentTime = time(0);
    long secondsOverdue;
    float daysOverdue = 0;
    for(unsigned int i = 0; i < LoanVec.size(); i++){
        if(currentTime > LoanVec[i].getDueDateTime() && libraryID == LoanVec[i].getLibraryItemID()){
            secondsOverdue = currentTime - LoanVec[i].getDueDateTime();
            daysOverdue = secondsOverdue/86400;
        }
    }
    return daysOverdue;
}

void loans::listAllOverdue(){
    for(unsigned int i = 0; i < LoanVec.size(); i++){
        if(LoanVec[i].getCurrentStatus() == "overdue"){
            cout <<  "LibraryItem: " << LoanVec[i].getLibraryItemID() << "  Status: OVERDUE" << endl;
        }
    }
}

void loans::listLibraryItemsForPatron(){
    int patronID;
    cout << "Enter the ID for the patron's Item list you want: ";
    cin >> patronID;
    cin.ignore();
    cout << "Patron " << patronID << " item list." << endl;
    for(unsigned int i = 0; i < LoanVec.size(); i++){
        if(LoanVec[i].getPatronID() == patronID){
            cout << "Item ID: " << LoanVec[i].getLibraryItemID() << endl;
        }
    }
}

void loans::recheckLibraryItem(){
    long newDueDateTime;
    int LibraryItemID;
    unsigned int i = 0;
    unsigned int index = 0;
    bool IDFound = false;
    cout << "Enter the library ID for the item you would like to re-check: ";
    cin >> LibraryItemID;
    cin.ignore();
    
        for(i =0; i < LoanVec.size(); i++){
            if(LoanVec[i].getLibraryItemID() == LibraryItemID){
                index = i;
                IDFound = true;
            }
        }
        if(IDFound == true){
            newDueDateTime = LoanVec[index].getDueDateTime();
            newDueDateTime +=864000;
            LoanVec[index].setDueDateTime(newDueDateTime);
        }
        else{cout << "Loan not found in system." << endl;}
}

void loans::storeLoans(){
    ofstream fout;
    fout.open("/Users/katriel/Documents/Computer Science II/Homework 1040/Homework 4/loans.txt");
    fout << LoanVec.size() << endl;
    for(unsigned int i = 0; i < LoanVec.size(); i++){
    fout << LoanVec[i].getLibraryItemID() << " " << LoanVec[i].getPatronID() << " "  << LoanVec[i].getDueDateTime() << " " << LoanVec[i].getCurrentStatus() << endl;
    }
    fout.close();
}

void loans::loadLoans(){
    string Loan;
    long numLoans;
    ifstream fin;
    int LibraryItemID;
    int PatronID;
    long DueDateTime;
    string CurrentStatus;
    fin.open("/Users/katriel/Documents/Computer Science II/Homework 1040/Homework 4/loans.txt");
    fin >> numLoans;
    fin.ignore();
    while(getline(fin, Loan)){
        stringstream ss(Loan);
        ss >> LibraryItemID;
        ss.ignore();
        ss >> PatronID;
        ss.ignore();
        ss >> DueDateTime;
        ss.ignore();
        ss >> CurrentStatus;
        ss.ignore();
        LoanVec.push_back(loan(LibraryItemID, PatronID, DueDateTime, CurrentStatus));
    }
    
    fin.close();
    
}

void loans::updateLoanStatus(){
    time_t currentTime = time(0);
    for(unsigned int i = 0; i < LoanVec.size(); i++){
        if(currentTime > LoanVec[i].getDueDateTime()){
            LoanVec[i].setCurrentStatus("overdue");
        }
    }
}

string loans::checkLoanStatus(int patronID){
    string status = "normal";
    for(unsigned int i = 0; i < LoanVec.size(); i++){
        if(patronID == LoanVec.at(i).getPatronID() && LoanVec.at(i).getCurrentStatus() == "overdue"){
            status = LoanVec.at(i).getCurrentStatus();
        }
    }
    return status;
}
