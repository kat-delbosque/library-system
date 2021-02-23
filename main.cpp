//
//  main.cpp
//  Homework 4
//  Katriel Hadel

#include "patron.h"
#include "book.h"
#include "loan.h"
#include "patrons.h"
#include "LibraryItems.h"
#include "loans.h"

#include <iostream>
using namespace std;

void topMenu();
void patronMenu();
void LibraryItemMenu();
void loanMenu();

int main(){
    
    patrons PATRON;
    LibraryItems ITEM;
    loans LOANS;
    
    PATRON.loadPatrons();
    ITEM.loadLibraryItems();
    LOANS.loadLoans();
    
    char Choice = 'A';
    int choice = -1;
    
    while(Choice != 'q'){
        topMenu();
        cin >> Choice;
        cin.ignore();
    switch(Choice){
        case 'p':{ //to enter patron menu
            patronMenu();
            cin >> choice;
            cin.ignore();
            while(choice > 0 && choice < 7){
            switch(choice){//PATRON MENU START
                case 1: { //add patron
                    
                    PATRON.addPatron();
                   
                    patronMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                }
                case 2:{ //edit patron
                    
                    PATRON.editPatron();
                   
                    patronMenu();
                    cin >> choice;
                    cin.ignore();
            
                        break;
                }
                case 3:{ //print patrons
                    
                    PATRON.printPatrons();
                    
                    patronMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                    }
                case 4:{ //print specific patron
                    int id;
                    cout << "Enter ID of patron to print: ";
                    cin >> id;
                    cin.ignore();
                    PATRON.printPatron(id);
                        
                    patronMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                }
                case 5:{ //pay fines
                    
                    PATRON.payFines();
                    
                    patronMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                }
                case 6:{ //delete patron
                    
                    PATRON.deletePatron();
                    
                    patronMenu();
                    cin >> choice;
                    cin.ignore();
                    break;
                }
                case 0:{ //return to main menu
                    break;
               }
            }
            }
            break;
        }
        case 'i':{ //to enter Library Item menu
            LibraryItemMenu();
            cin >> choice;
            cin.ignore();
            while(choice > 0 && choice < 6){
            switch(choice){//ITEM MENU START
                case 1:{ //add item
                      
                       ITEM.addLibraryItem();
                    
                       LibraryItemMenu();
                       cin >> choice;
                       cin.ignore();
                           break;
                       }
                case 2:{ //edit item
                      
                       ITEM.editLibraryItem();
                    
                       LibraryItemMenu();
                       cin >> choice;
                       cin.ignore();
                           break;
                       }
                case 3:{ //print items
                       ITEM.printLibraryItems();
                        
                       LibraryItemMenu();
                       cin >> choice;
                       cin.ignore();
                           break;
                       }
                case 4:{ //print a particular item
                       ITEM.printLibraryItem();
                    
                       LibraryItemMenu();
                       cin >> choice;
                       cin.ignore();
                           break;
                       }
                case 5:{//delete item
                    
                    ITEM.deleteLibraryItem();
                    
                    LibraryItemMenu();
                    cin >> choice;
                    cin.ignore();
                    break;
                }
                case 0:{
                    break;
                }
            }
            }
            break;
    }
        case 'l':{ //to enter loan menu
            loanMenu();
            cin >> choice;
            cin.ignore();
            while(choice > 0 && choice < 7){
            switch(choice){//LOAN MENU START
                case 1:{ //check out LibraryItem
                    string itemStatus;
                    string loanStatus;
                    int numLibraryItems;
                    int patronID;
                    int libraryID;
                   
                    cout << "Enter patron ID: ";
                    cin >> patronID;
                    cin.ignore();
                    cout << "Enter the LibraryItem's library ID: ";
                    cin >> libraryID;
                    cin.ignore();
                    
                    itemStatus = ITEM.checkStatus(libraryID);
                    loanStatus = LOANS.checkLoanStatus(patronID);
                    numLibraryItems = PATRON.checkNumLibraryItems(patronID);
                    
                    if(numLibraryItems >= 5){
                        cout << "This patron may not check out another LibraryItem." << endl;
                    }
                    else if(loanStatus == "overdue"){
                        cout << "This patron may not check out another LibraryItem because of overdue LibraryItem(s)." << endl;
                    }
                    else if(itemStatus == "out"){
                        cout << "This LibraryItem is currently checked out." << endl;
                    }
                    else if(itemStatus == "lost"){
                        cout << "This LibraryItem is lost." << endl;
                    }
                    else if(ITEM.findLibraryItem(libraryID) == nullptr){
                        cout << "Invalid library ID." << endl;
                    }
                    else if(PATRON.findPatron(patronID) == -1){
                        cout << "Invalid patron ID." << endl;}
                    else{
                        LOANS.checkOutLibraryItem(patronID, libraryID);
                        PATRON.updateNumItems(patronID);
                        ITEM.updateStatusOut(libraryID);
                    }
                    loanMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                }
                case 2:{ //check in LibraryItem
                    float fineAmount = 0.0;
                    int patronID, libraryID;
                    
                    cout << "Enter patron ID: ";
                    cin >> patronID;
                    cin.ignore();
                    cout << "Enter the LibraryItem's library ID: ";
                    cin >> libraryID;
                    cin.ignore();
                    
                    fineAmount = ((LOANS.findDaysOverdue(libraryID) * 0.25) + PATRON.patronBalance(patronID));
                    PATRON.setNewBalance(fineAmount, patronID);
                    
                    LOANS.checkInLibraryItem(patronID, libraryID);
                    ITEM.updateStatusIn(libraryID);
                    PATRON.decNumItems(patronID);
                    
                    loanMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                }
                case 3:{ //list overdue
                    
                    LOANS.listAllOverdue();
                    
                    loanMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                }
                case 4:{ //list LibraryItems for a particular patron
                    LOANS.listLibraryItemsForPatron();
                    loanMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                }
                case 5:{ //recheck LibraryItem
                    
                    LOANS.recheckLibraryItem();
                   
                    loanMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                }
                case 6:{ //report lost
                    float newBalance;
                    int patronID;
                    int libraryID;
                    cout << "Enter library ID for the item that is lost: ";
                    cin >> libraryID;
                    cin.ignore();
                    cout << "Enter patron ID of person who lost the item: ";
                    cin >> patronID;
                    cin.ignore();
                    ITEM.reportLost(libraryID);
                    newBalance = ITEM.getCost(libraryID) + PATRON.patronBalance(patronID);
                    PATRON.setNewBalance(newBalance, patronID);
                    loanMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                }
                case 7:{ //update loan status
                    LOANS.updateLoanStatus();
                    loanMenu();
                    cin >> choice;
                    cin.ignore();
                        break;
                }
                case 0:{
                    break;
                }
            }
            }
        break;
    }
        case 'q':{ //to quit
        break;
        }
    }
    }
    
    PATRON.storePatrons();
    ITEM.storeLibraryItems();
    LOANS.storeLoans();
    ITEM.clearVec();
    
    return 0;
}

void patronMenu(){
    cout << "1 - add patron" << endl;
    cout << "2 - edit patron" << endl;
    cout << "3 - print patrons" << endl;
    cout << "4 - print specific patron" << endl;
    cout << "5 - pay fines" << endl;
    cout << "6 - delete patron" << endl;
    cout << "0 - return to main menu" << endl << endl;
       cout << "Enter choice: ";
}

void LibraryItemMenu(){
    cout << "1 - add item" << endl;
    cout << "2 - edit item" << endl;
    cout << "3 - print items" << endl;
    cout << "4 - print specific item" << endl;
    cout << "5 - delete item" << endl;
    cout << "0 - return to main menu" << endl << endl;
    cout << "Enter choice: ";
}

void loanMenu(){
    cout << "1 - check out an item" << endl;
    cout << "2 - check in an item" << endl;
    cout << "3 - list all overdue" << endl;
    cout << "4 - list all items for a particular patron" << endl;
    cout << "5 - recheck an item" << endl;
    cout << "6 - report loast" << endl;
    cout << "7 - update loan status" << endl;
    cout << "0 - return to main menu" << endl << endl;
    cout << "Enter choice: ";
}

void topMenu(){
    cout << "p - Patron Menu" << endl;
    cout << "i - LibraryItem Menu" << endl;
    cout << "l - Loan Menu" << endl;
    cout << "q - QUIT" << endl << endl;
    cout << "Enter choice: ";
}
