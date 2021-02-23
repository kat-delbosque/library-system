//
//  patrons.cpp
//  Homework 4
//  Katriel Hadel

#include "patron.h"
#include "patrons.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
using namespace std;

unsigned int patrons::findPatron(int ID){
    unsigned int index = 0;
    bool IDFound = false;
    for(unsigned int i =0; i < patronVec.size(); i++){
        if(patronVec[i].getID() == ID){
            index = i;
            IDFound = true;
        }
    }
    if(IDFound == false){
            return -1;
        }
    else{
    return index;
    }
}

void patrons::addPatron(){
    string Name;
    int ID;
    float FineBalance = 0;
    int NumItems = 0;
    patron NewPatron;
    cout << "Enter name:";
    getline(cin, Name);
    NewPatron.setName(Name);
    cout << "Enter ID (six digits):";
    cin >> ID;
    cin.ignore();
    NewPatron.setID(ID);
    NewPatron.setFineBalance(FineBalance);
    NewPatron.setNumItems(NumItems);
    patronVec.push_back(NewPatron);
}

void patrons::editPatron(){
    int choice;
    int ID;
    cout << "Enter ID of patron to edit:";
    cin >> ID;
    cin.ignore();
    findPatron(ID);
    if(findPatron(ID) == -1){
        cout << "Patron ID not found in system." << endl;
    }
    else{
        cout << "What would you like to edit?" << endl;
        cout << "1 - Change name" << endl;
        cout << "2 - Change ID" << endl;
        cout << "3 - Change fine balance" << endl;
        cout << "4 - Change number of books" << endl;
        cout << "Enter any other key to quit." << endl;
        cin >> choice;
        cin.ignore();
        
        switch(choice){
            case 1: {
                cout << "Enter new name:";
                string Name;
                getline(cin, Name);
                patronVec.at(findPatron(ID)).setName(Name);
                break;
            }
            case 2: {
                cout << "Enter new ID (six digit):";
                int id;
                cin >> id;
                cin.ignore();
                if(isdigit(id) == true){
                    patronVec.at(findPatron(ID)).setID(id);}
                else{cout << "This is not a valid entry." << endl;}
                break;
            }
            case 3: {
                cout << "Enter new fine balance:";
                float fineBalance;
                cin >> fineBalance;
                cin.ignore();
                patronVec.at(findPatron(ID)).setFineBalance(fineBalance);
                break;
            }
            case 4: {
                cout << "Enter new number of books:";
                int numItems;
                cin >> numItems;
                cin.ignore();
                if(isdigit(numItems) == true && numItems <= 5 && numItems >= 0){
                patronVec.at(findPatron(ID)).setNumItems(numItems);
                }
                else{cout << "This is not a valid entry." << endl;}
                break;
            }
            default: {break;}
        }
        
    }
}

void patrons::deletePatron(){
    int id;
    cout << "Enter ID of patron to delete:";
    cin >> id;
    cin.ignore();
    findPatron(id);
    if(findPatron(id) == -1){
        cout << "Patron ID not found in system." << endl;
    }
    else{
        unsigned int i;
        i = findPatron(id);
        patronVec.erase(patronVec.begin() + i);
    }
}

void patrons::printPatrons(){
    for(unsigned int i = 0; i < patronVec.size(); i++){
        cout << endl;
        cout << "Name: " << patronVec[i].getName() << endl;
        cout << "ID: " << patronVec[i].getID() << endl;
        cout << "Fine Balance: $" << patronVec[i].getFineBalance() << endl;
        cout << "Number of Items: " << patronVec[i].getNumItems() << endl;
        cout << endl;
    }
}

void patrons::printPatron(int id){
    findPatron(id);
    if(findPatron(id) == -1){
        cout << "Patron ID not found in system." << endl;
    }
    else{
        cout << endl;
        cout << "Name: " << patronVec.at(findPatron(id)).getName() << endl;
        cout << "ID: " << patronVec.at(findPatron(id)).getID() << endl;
        cout << "Fine Balance: $" << patronVec.at(findPatron(id)).getFineBalance() << endl;
        cout << "Number of Items: " << patronVec.at(findPatron(id)).getNumItems() << endl;
        cout << endl;
    }
}

void patrons::payFines(){
    int id;
    cout << "Enter ID of patron who is making payment: ";
    cin >> id;
    cin.ignore();
    findPatron(id);
    if(findPatron(id) == -1){
        cout << "Patron ID not found in system." << endl;
    }
    else{
        cout << "Enter payment amount: $";
        float payment;
        cin >> payment;
        cin.ignore();
        payment = patronVec.at(findPatron(id)).getFineBalance() - payment;
        patronVec.at(findPatron(id)).setFineBalance(payment);
    }
} 

void patrons::storePatrons(){
    ofstream fout;
    fout.open("/Users/katriel/Documents/Computer Science II/Homework 1040/Homework 4/patrons.txt");
    fout << patronVec.size() << endl;
        for (unsigned int i = 0; i < patronVec.size(); i++){
        fout << patronVec[i].getName() << "," << patronVec[i].getID() << " " << patronVec[i].getFineBalance() << " " << patronVec[i].getNumItems() << endl;
        }
    fout.close();
}

void patrons::loadPatrons(){
    string Patron;
    ifstream fin;
    long numPatrons;
    string Name;
    int ID;
    float FineBalance;
    int NumItems;
    fin.open("/Users/katriel/Documents/Computer Science II/Homework 1040/Homework 4/patrons.txt");
    fin >> numPatrons;
    fin.ignore();
    while(getline(fin, Patron)){
        stringstream ss(Patron);
        getline(ss, Name, ',');
        ss >> ID;
        ss.ignore();
        ss >> FineBalance;
        ss.ignore();
        ss >> NumItems;
        ss.ignore();
        patronVec.push_back(patron(Name, ID, FineBalance, NumItems));
        }
    fin.close();
}

int patrons::checkNumLibraryItems(int patronID){
    int numItems = 0;
    for (unsigned int i = 0; i < patronVec.size(); i++){
        if(patronID == patronVec[i].getID()) { //find matching ID and check the num of books they have checked out
            numItems = patronVec[i].getNumItems();
        }
    }
    return numItems;
}

void patrons::decNumItems(int patronID){
    int num;
    for(unsigned int i = 0; i < patronVec.size(); i++){
        if(patronVec[i].getID() == patronID){
            num = patronVec[i].getNumItems();
            num -= 1;
            patronVec[i].setNumItems(num);
        }
    }
}

float patrons::patronBalance(int patronID){
    float amount = 0.0;
    for(unsigned int i = 0; i < patronVec.size(); i++){
        if(patronVec[i].getID() == patronID){
            amount = patronVec[i].getFineBalance();
        }
    }
    return amount;
}

void patrons::updateNumItems(int patronID){
    int numItems;
    for(unsigned int i = 0; i < patronVec.size(); i++){
        if(patronVec[i].getID() == patronID){
            numItems = patronVec[i].getNumItems();
            numItems += 1;
            patronVec[i].setNumItems(numItems);
        }
    }
}

void patrons::setNewBalance(float newBalance, int patronID){
    for(unsigned int i = 0; i < patronVec.size(); i++){
        if(patronVec.at(i).getID() == patronID){patronVec.at(i).setFineBalance(newBalance);}
    }
}
