#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <map>
#include <algorithm>
using namespace std;


const string outopt[7] = {"Input Employee", "List All Employees", "Search Employees", "Sort Employees", "Delete Employees", "Update Employee", "Exit program"};
const string outlol[5] = {"Employee ID: ", "Employee name: ", "Employee Sex: ", "Employee Role: ", "Monthly Salary: "};
vector<string> database;
int opt;
int total = 0;
vector<string>::iterator it;
int pos;
int choice;
vector<string> arr;
// I'm sorry you have to read all of this :(

void sortas(int typ) {
for(int i = typ; i < total * 5; i+=5) {
    arr.push_back(database.at(i));
}
sort(arr.begin(), arr.end());

for(int i = 0; i < total; i++) {
    cout << i + 1 << ". " << arr[i]<< endl;
}
cout << endl;
arr.clear();

} 

void sortde(int typ2) {
for(int i = typ2; i < total * 5; i+=5) {
    arr.push_back(database.at(i));
}
sort(arr.begin(), arr.end());

for(int i = total - 1; i > -1; i--) {
    cout << total - i << ". " << arr[i] << endl;
}
cout << endl;
arr.clear();
}

void setVal(string alpha, string beta, string gamma, string omega, string delta) {
database.push_back(delta);
database.push_back(alpha);
database.push_back(beta);
database.push_back(gamma);
database.push_back(omega);
total++;
}

void getVal() {
string alpha, beta, gamma, omega, delta;
cout << "Employee ID:\t";
cin >> delta;
cout << "Employee Name:\t";
cin.clear(); cin.ignore(); getline(cin, alpha);
cout << "Employee Sex:\t";
cin >> beta;
cout << "Employee Role:\t";
cin >> gamma;
cout << "Monthly Salary:\t";
cin >> omega;
cout << endl;
setVal(alpha, beta, gamma, omega, delta);
}   

void listall() {
    for(int i = 0; i < total * 5; i+=5) {
        cout << "ID: " << database[i] << "\tName: " << database[i + 1] << endl << endl;
    }
}

void deletion() {
    string id;
    while(true) {
        cout << "Input employee id for deletion: ";
        cin >> id;
        it = find(database.begin(), database.end(), id);
        if(it != database.end()) {
        database.erase(it, it + 5);
        total--;
        cout << "Sucessfuly deleted employee ID " << id << "Listing all eployees:" << endl;
        listall();
        break;
    }
    else {
        cout << "ID: " << id << endl << " was not found. " << endl << "Please try again." << endl << endl;
    }
}
}

void output(int n) {
    for(int i = 0; i < 5; i++){
        cout << outlol[i] << database[i + n] << endl;
    }
}

void upd() {
    string id;
    string neww;
    cout << "Enter ID for update: ";
    cin >> id;
    it = find(database.begin(), database.end(), id);
    while(true) {
        if(it != database.end()) {
            pos = it - database.begin();
            output(pos);
            cout << "New Values: " << endl << endl;
            for(int i = 0; i < 5; i++) {
                cout << outlol[i];
                cin >> database[pos + i];
            }
            break;
        }

        else {
            cout << "ID: " << id << endl << "was not found. " << endl << "Please try again." << endl << endl;
        }
    }
}
void search() {
    string name;
    string id;
    while(choice != 1 || choice != 2) {
        cout << "1. Search by name." << endl;
        cout << "2. Search by ID. " << endl;
        cout << "Choose with number: ";
        cin >> choice;
        switch(choice) {
            case 1:
                while(true) {
                    cout << "Enter name to search: ";
                    cin >> name;
                    it = find(database.begin(), database.end(), name);
                    if(it != database.end()) {
                        pos = it - database.begin();
                        for(int i = 0; i < 5; i++) {
                            cout << outlol[i] << database[pos - 1 + i] << endl;
                        }
                        break;
                    }
                    else {
                        cout << "Name: " << name << endl << "was not found. " << endl << "Please try again." << endl << endl;
                    }
                }

                break;

            case 2:
                while(true) {
                    cout << "Enter ID to search: ";
                    cin >> id;
                    it = find(database.begin(), database.end(), id);
                    if(it != database.end()) {
                        pos = it - database.begin();
                        output(pos);
                        break;
                    }
                    else {
                        cout << "ID: " << id << endl << "was not found. " << endl << "Please try again." << endl << endl;
                    }
                }
                break;

            default:
                cout << "Invalid option. Please try again." << endl << endl;
                break;

        }
        cout << endl;
        break;
    }
}

void sortt() {
    cout << "1. Sort by name ascending." << endl;
    cout << "2. Sort by name descending." << endl;
    cout << "3. Sort by Id ascending." << endl;
    cout << "4. Sort by Id descending." << endl;
    cout << "5. Sort by salary ascending." << endl;
    cout << "6. Sort by salary descending." << endl;
    cout << "Choose: ";
    cin >> choice;
    cout << endl;
    
    switch(choice) {
        case 1:

            sortas(1);
            break;

        case 2:

            sortde(1);
            break;

        case 3:

            sortas(0);
            break;

        case 4:

            sortde(0);
            break;

        case 5:

            sortas(4);
            break;

        case 6:

            sortde(4);
            break;

        default:
            cout << "Invalid option" << endl;
    }
}

class Employeelister {

public:
    void options() {
        for(int i = 0; i < 7; i++) {
            cout << i + 1 << ". " << outopt[i] << endl;
        }
        cout << "Choose: ";
        cin >> opt;
        cout << endl;
        scenario(opt);
	}
	
    void scenario(int opt) {
        switch (opt) {
            case 1:
                getVal();
                break;

            case 2:
            	listall();
            	break;

            case 3:
                search();
                break;
                
            case 4:
            	sortt();
            	break;
                
            case 5:
                deletion();
                break;

            case 6:
                upd();
                break;

            case 7:
                cout << "Program exit" << endl;
                break;

            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
};

int main() {
    Employeelister emp;
    while (opt != 7) {
        emp.options();
    }
    return 0;
}