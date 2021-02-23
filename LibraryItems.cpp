//
//  LibraryItems.cpp
//  Homework 4
//  Katriel Hadel
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
using namespace std;
#include "LibraryItem.h"
#include "dvd.h"
#include "cd.h"
#include "book.h"
#include "LibraryItems.h"

LibraryItem* LibraryItems::findLibraryItem(int libraryID){
    LibraryItem* obj;
    for(unsigned int i = 0; i < LibraryItemVec.size(); i++){
        if(LibraryItemVec[i]->getLibraryID() == libraryID){
            obj = LibraryItemVec[i];
            return obj;
        }
    }
    return nullptr;
}

void LibraryItems::addLibraryItem(){
    int choice = -1;
    int LibraryID;
    float Cost;
    long LoanPeriod;
    string CurrentStatus = "in";
    cout << "Enter library ID: ";
    cin >> LibraryID;
    cin.ignore();
    cout << "Enter cost: $";
    cin >> Cost;
    cin.ignore();
    cout << "Enter loan period (#days): ";
    cin >> LoanPeriod;
    cin.ignore();
    LoanPeriod *= 86400;
    while(choice < 1 || choice > 3){
    cout <<"1 - Add DVD\n"
    "2 - Add CD\n"
    "3 - Add Book\n";
    cin >> choice;
    cin.ignore();
    }
    if(choice == 1){//add DVD
        int RunTime;
        string Title, Category, Studio, ReleaseDate;
        cout << "Enter title: ";
        getline(cin, Title);
        cout << "Enter category: ";
        getline(cin, Category);
        cout << "Enter run time: ";
        cin >> RunTime;
        cin.ignore();
        cout << "Enter studio: ";
        getline(cin, Studio);
        cout << "Enter release date (mm/dd/yyyy): ";
        getline(cin, ReleaseDate);
        LibraryItemVec.push_back(new DVD(LibraryID, Cost, CurrentStatus, LoanPeriod, Title, Category, RunTime, Studio, ReleaseDate));
    }
    else if(choice == 2){//add CD
        int NumTracks;
        string Artist, Title, ReleaseDate, Genre;
        cout << "Enter artist: ";
        getline(cin, Artist);
        cout << "Enter title: ";
        getline(cin, Title);
        cout << "Enter number of tracks: ";
        cin >> NumTracks;
        cin.ignore();
        cout << "Enter release date (mm/dd/yyyy): ";
        getline(cin, ReleaseDate);
        cout << "Enter genre: ";
        getline(cin, Genre);
        LibraryItemVec.push_back(new CD(LibraryID, Cost, CurrentStatus, LoanPeriod, Artist, Title, NumTracks, ReleaseDate, Genre));
    }
    else if(choice == 3){//add book
        string Author, Title, ISBN, Category;
        cout << "Enter author: " << Author;
        getline(cin, Author);
        cout << "Enter title: " << Title;
        getline(cin, Title);
        cout << "Enter ISBN: " << ISBN;
        getline(cin, ISBN);
        cout << "Enter category: " << Category;
        getline(cin, Category);
        LibraryItemVec.push_back(new book(LibraryID, Cost, CurrentStatus, LoanPeriod, Author, Title, ISBN, Category));
    }
    

}

void LibraryItems::editLibraryItem(){
    int choice;
    int libraryID;
    cout << "Enter ID of LibraryItem to edit:";
    cin >> libraryID;
    cin.ignore();
    for(auto it = LibraryItemVec.begin(); it != LibraryItemVec.end(); ++it){
        if((*it)->getLibraryID()== libraryID){
            cout << "What would you like to edit?" << endl;
            cout << "1 - Change cost" << endl;
            cout << "2 - Change current status" << endl;
            cout << "Enter any other key to quit." << endl;
            cin >> choice;
            cin.ignore();
            
            switch(choice){
                case 1: {
                    cout << "Enter new cost: $";
                    float cost;
                    cin >> cost;
                    cin.ignore();
                    (*it)->setCost(cost);
                    break;
                }
                case 2: {
                    cout << "Enter new current status: ";
                    string currentStatus;
                    getline(cin, currentStatus);
                    (*it)->setCurrentStatus(currentStatus);
                    break;
                }
                default: {break;}
            }
        }
    }
        
}

void LibraryItems::deleteLibraryItem(){
    int libraryID;
    cout << "Enter library ID of LibraryItem to delete: ";
    cin >> libraryID;
    cin.ignore();
    for(auto it = LibraryItemVec.begin(); it != LibraryItemVec.end(); ++it){
        if((*it)->getLibraryID()== libraryID){
        LibraryItemVec.erase(it);
        }
    }
   
}

void LibraryItems::printLibraryItems(){
    for(auto it = LibraryItemVec.begin(); it != LibraryItemVec.end(); ++it){
        (*it)->print();
        cout << endl;
    }
     
}

ostream& LibraryItems::printLibraryItem(){
    int libraryID;
    cout << "Enter library ID of LibraryItem to print: ";
    cin >> libraryID;
    cin.ignore();
    findLibraryItem(libraryID);
    for(int i = 0; i < LibraryItemVec.size(); i++){
    if(LibraryItemVec[i]->getLibraryID() == libraryID){
        return cout << *(LibraryItemVec[i]);
    }
    }
    return cout << "Item not found" << endl;
}

void LibraryItems::storeLibraryItems(){
    ofstream fout;
    fout.open("/Users/katriel/Documents/Computer Science II/Homework 1040/Homework 4/LibraryItems.txt");
    fout << LibraryItemVec.size() << endl;
    LibraryItem* temp;
    for (auto it = LibraryItemVec.begin(); it != LibraryItemVec.end(); ++it){
        temp = *it;
        fout << temp->getLibraryID() << " " <<  temp->getCost() << " " << temp->getCurrentStatus() << endl;
        fout << temp->getLoanPeriod() << endl;
        
        if(typeid(**it) == typeid(DVD)){
            DVD* DVDitem = dynamic_cast<DVD*>(*it);
            fout << "1 ";
            fout << DVDitem->getTitle() << endl;
            fout << DVDitem->getCategory() << endl;
            fout << DVDitem->getRunTime() << " " << DVDitem->getStudio() << endl;
            fout << DVDitem->getReleaseDate() << endl;
        }
        else if(typeid(**it) == typeid(CD)){
            CD* CDitem = dynamic_cast<CD*>(*it);
            fout << "2 ";
            fout << CDitem->getArtist() << endl;
            fout << CDitem->getTitle() << endl;
            fout << CDitem->getNumTracks() << " " << CDitem->getReleaseDate() << endl;
            fout << CDitem->getGenre() << endl;
        }
        else if(typeid(**it) == typeid(book)){
            book* bookitem = dynamic_cast<book*>(*it);
            fout << "3 ";
            fout << bookitem->getAuthor() << endl;
            fout << bookitem->getTitle() << endl;
            fout << bookitem->getISBN() << endl;
            fout << bookitem->getCategory() << endl;
            
        }
    }
    fout.close();
}

void LibraryItems::loadLibraryItems(){
    int ITEM;
    long numLibraryItems;
    ifstream fin;
    int LibraryID;
    float Cost;
    long LoanPeriod;
    string CurrentStatus;
    fin.open("/Users/katriel/Documents/Computer Science II/Homework 1040/Homework 4/LibraryItems.txt");
    fin >> numLibraryItems;
    fin.ignore();
    for(int i = 0; i < numLibraryItems; i++){
        fin >> LibraryID;
        fin.ignore();
        fin >> Cost;
        fin.ignore();
        getline(fin, CurrentStatus);
        fin >> LoanPeriod;
        fin.ignore();
        fin >> ITEM;
        fin.ignore();
        if(ITEM == 1){//read in DVD
            string Title, Category, Studio, ReleaseDate;
            int RunTime;
            getline(fin, Title);
            getline(fin, Category);
            fin >> RunTime;
            fin.ignore();
            getline(fin, Studio);
            getline(fin, ReleaseDate);
            LibraryItemVec.push_back(new DVD(LibraryID, Cost, CurrentStatus, LoanPeriod, Title, Category, RunTime, Studio, ReleaseDate));
        }
        else if(ITEM == 2){//read in CD
            string Artist, Title, ReleaseDate, Genre;
            int NumTracks;
            getline(fin, Artist);
            getline(fin, Title);
            fin >> NumTracks;
            fin.ignore();
            getline(fin, ReleaseDate);
            getline(fin, Genre);
            LibraryItemVec.push_back(new CD(LibraryID, Cost, CurrentStatus, LoanPeriod, Artist, Title, NumTracks, ReleaseDate, Genre));
        }
        else if(ITEM == 3){//read in book
            string Author, Title, ISBN, Category;
            getline(fin, Author);
            getline(fin, Title);
            getline(fin, ISBN);
            getline(fin, Category);
            LibraryItemVec.push_back(new book(LibraryID, Cost, CurrentStatus, LoanPeriod, Author, Title, ISBN, Category));
        }
    }
    fin.close();
}

string LibraryItems::checkStatus(int libraryID){
    string status;
    for (unsigned int i = 0; i < LibraryItemVec.size(); i++){
        if (libraryID == LibraryItemVec[i]->getLibraryID()){
            status = LibraryItemVec[i]->getCurrentStatus();
        }
    }
    return status;
}

void LibraryItems::updateStatusIn(int libraryID){
    for(unsigned int i = 0; i < LibraryItemVec.size(); i++){
        if(LibraryItemVec[i]->getLibraryID() == libraryID){
            LibraryItemVec[i]->setCurrentStatus("in");
        }
    }
}

void LibraryItems::updateStatusOut(int libraryID){
        for(unsigned int i = 0; i < LibraryItemVec.size(); i++){
            if(LibraryItemVec[i]->getLibraryID() == libraryID){
                LibraryItemVec[i]->setCurrentStatus("out");
            }
        }
    }

float LibraryItems::getCost(int libraryID){
    float cost = -1;
    for(unsigned int i = 0; i < LibraryItemVec.size(); i++){
        if(libraryID == LibraryItemVec[i]->getLibraryID()){
            cost = LibraryItemVec[i]->getCost();
        }
    }
    return cost;
}

void LibraryItems::reportLost(int libraryID){
    for(unsigned int i = 0; i < LibraryItemVec.size(); i++){
        if(LibraryItemVec[i]->getLibraryID() == libraryID){
            LibraryItemVec[i]->setCurrentStatus("lost");
        }
    }
}

void LibraryItems::clearVec(){
    for (auto it = LibraryItemVec.begin(); it != LibraryItemVec.end(); ++it){
        delete *it;
    }
    LibraryItemVec.clear();
}

long LibraryItems::returnLoanPeriod(int id){
    for(unsigned int i = 0; i < LibraryItemVec.size(); i++){
    if(LibraryItemVec[i]->getLibraryID() == id){
        return LibraryItemVec[i]->getLoanPeriod();
        }
    }
    return -1;
}
