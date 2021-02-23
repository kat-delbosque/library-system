//
//  patron.h
//  Homework 4
//  Katriel Hadel

#ifndef PATRON_H
#define PATRON_H

#include <string>
using namespace std;

class patron{
    private:
    string Name;
    int ID;
    float FineBalance;
    int NumItems;
    
    public:
    patron();
    patron(string, int, float, int);
    void setName(string);
    string getName();
    void setID(int);
    int getID();
    void setFineBalance(float);
    float getFineBalance();
    void setNumItems(int);
    int getNumItems();
};

#endif /* patron_hpp */
