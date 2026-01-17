#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    
    Train(int no, const char* name, const char* src, const char* dest, const char* time) {
        trainNumber = no;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    
    ~Train() {
        trainCount--;
    }

    
    void setTrainNumber(int no) { trainNumber = no; }
    void setTrainName(const char* name) { strcpy(trainName, name); }
    void setSource(const char* src) { strcpy(source, src); }
    void setDestination(const char* dest) { strcpy(destination, dest); }
    void setTrainTime(const char* time) { strcpy(trainTime, time); }

    
    int getTrainNumber() { return trainNumber; }

    
    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

   
    void displayTrainDetails() {
        cout << "\nTrain Number : " << trainNumber;
        cout << "\nTrain Name   : " << trainName;
        cout << "\nSource       : " << source;
        cout << "\nDestination  : " << destination;
        cout << "\nTrain Time   : " << trainTime << endl;
    }

    
    static int getTrainCount() {
        return trainCount;
    }
};


int Train::trainCount = 0;

int main() {
    int choice;
    const int SIZE = 10;
    Train trains[SIZE];
    int count = 3; 

    cout << "Enter details for 3 trains:\n";
    for (int i = 0; i < count; i++) {
        cout << "\nTrain " << i + 1 << ":\n";
        trains[i].inputTrainDetails();
    }

    do {
        cout << "\n===== Train Management Menu =====";
        cout << "\n1. Display All Trains";
        cout << "\n2. Search Train by Number";
        cout << "\n3. Show Total Train Count";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < count; i++) {
                trains[i].displayTrainDetails();
            }
        } 
        else if (choice == 2) {
            int searchNo;
            bool found = false;
            cout << "Enter Train Number to search: ";
            cin >> searchNo;

            for (int i = 0; i < count; i++) {
                if (trains[i].getTrainNumber() == searchNo) {
                    trains[i].displayTrainDetails();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Train not found!";
            }
        } 
        else if (choice == 3) {
            cout << "Total Train Count: " << Train::getTrainCount();
        }

    } while (choice != 0);

    
}

