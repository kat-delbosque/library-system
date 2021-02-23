//
//  patron.cpp
//  Homework 4
//  Katriel Hadel

#include "patron.h"

patron::patron(){
    Name = "none";
    ID = -1;
    FineBalance = -1.0;
    NumItems = -1;
}

patron::patron(string name, int id, float fineBalance, int numItems){
    Name = name;
    ID = id;
    FineBalance = fineBalance;
    NumItems = numItems;
}

void patron::setName(string name){
    Name = name;
}

string patron::getName(){
    return Name;
}

void patron::setID(int id){
    ID = id;
}

int patron::getID(){
    return ID;
}

void patron::setFineBalance(float fineBalance){
    FineBalance = fineBalance;
}

float patron::getFineBalance(){
    return FineBalance;
}

void patron::setNumItems(int numItems){
    NumItems = numItems;
}

int patron::getNumItems(){
    return NumItems;
}

    
