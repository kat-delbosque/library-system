//  Katriel Hadel
//  LibraryItem.h
//  Homework 4
//


#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

class LibraryItem{
    private:
    int LibraryID;
    float Cost;
    string CurrentStatus;
    long LoanPeriod;
    
    public:
    LibraryItem();
    LibraryItem(int, float, string, long);
    void setLibraryID(int);
    int getLibraryID();
    void setCost(float);
    float getCost();
    void setCurrentStatus(string);
    string getCurrentStatus();
    void setLoanPeriod(long);
    long getLoanPeriod();
    virtual void print();
    virtual ~LibraryItem() { }
    friend ostream& operator<<(ostream& st, LibraryItem& it);
};

#endif /* LibraryItem_h */
