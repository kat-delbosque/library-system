//
//  loan.cpp
//  Homework 4
//  Katriel Hadel 

#include "loan.h"

loan::loan(){
    LibraryItemID = -1;
    PatronID = -1;
    DueDateTime = -1;
    CurrentStatus = "none";
}

loan::loan(int LibraryItemID, int patronID, long dueDateTime, string currentStatus){
    LibraryItemID = LibraryItemID;
    PatronID = patronID;
    DueDateTime = dueDateTime;
    CurrentStatus = currentStatus;
}

void loan::setLibraryItemID(int LibraryItemID){
    LibraryItemID = LibraryItemID;
}

int loan::getLibraryItemID(){
    return LibraryItemID;
}

void loan::setPatronID(int patronID){
    PatronID = patronID;
}

int loan::getPatronID(){
    return PatronID;
}

void loan::setDueDateTime(long dueDateTime){
    DueDateTime = dueDateTime;
}

long loan::getDueDateTime(){
    return DueDateTime;
}

void loan::setCurrentStatus(string currentStatus){
    CurrentStatus = currentStatus;
}

string loan::getCurrentStatus(){
    return CurrentStatus;
}
