#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define Patient and Hospital classes
class Patient {
public:
    string name;
    int age;
    string disease;
    
    Patient() : name(""), age(0), disease("") {}
    Patient(string n, int a, string d) : name(n), age(a), disease(d) {}
    
    void print() const {
        cout << "Name: " << name << ", Age: " << age << ", Disease: " << disease << endl;
    }
};

class Hospital {
public:
    string name;
    int bedsPrice;
    int availableBeds;
    float rating;
    string city;
    
    Hospital() : name(""), bedsPrice(0), availableBeds(0), rating(0.0), city("") {}
    Hospital(string n, int p, int a, float r, string c) : name(n), bedsPrice(p), availableBeds(a), rating(r), city(c) {}
    
    void print() const {
        cout << "Name: " << name << ", Beds Price: " << bedsPrice
             << ", Available Beds: " << availableBeds
             << ", Rating: " << rating << ", City: " << city << endl;
    }
};

void enterPatientData(vector<vector<Patient>>& patients, int hospitalIndex) {
    string name;
    int age;
    string disease;
    
    cout << "Enter patient name: ";
    cin >> ws;  // To consume any leading whitespace
    getline(cin, name);
    
    cout << "Enter patient age: ";
    cin >> age;
    
    cout << "Enter patient disease: ";
    cin >> ws;  // To consume any leading whitespace
    getline(cin, disease);
    
    patients[hospitalIndex].emplace_back(name, age, disease);
}

void sortByBeds(vector<Hospital>& hospitals) {
    sort(hospitals.begin(), hospitals.end(), [](const Hospital& a, const Hospital& b) {
        return a.bedsPrice < b.bedsPrice;
    });
}

void sortByAvailableBedsDescending(vector<Hospital>& hospitals) {
    sort(hospitals.begin(), hospitals.end(), [](const Hospital& a, const Hospital& b) {
        return a.availableBeds > b.availableBeds;
    });
}

void sortByRating(vector<Hospital>& hospitals) {
    sort(hospitals.begin(), hospitals.end(), [](const Hospital& a, const Hospital& b) {
        return a.rating > b.rating;
    });
}

void printHospitalsInCity(const vector<Hospital>& hospitals) {
    string city;
    cout << "Enter city: ";
    cin >> ws;  // To consume any leading whitespace
    getline(cin, city);
    
    for (const auto& hospital : hospitals) {
        if (hospital.city == city) {
            hospital.print();
        }
    }
}

int main() {
    vector<Hospital> hospitals = {
        Hospital("Hospital A", 1000, 50, 4.5, "City1"),
        Hospital("Hospital B", 1500, 30, 4.0, "City2"),
        Hospital("Hospital C", 2000, 20, 4.8, "City1"),
        Hospital("Hospital D", 1200, 40, 4.2, "City3"),
        Hospital("Hospital E", 800, 60, 4.7, "City2")
    };
    
    vector<vector<Patient>> patients(hospitals.size());
    int choice;
    
    do {
        cout << "\n\n\n*********** Hospital Management System Menu: ************\n\n";
        cout << "1. Enter New Patient Data:\n";
        cout << "2. Display Hospital Data\n";
        cout << "3. Display Patient Data\n";
        cout << "4. Display Best Hospitals by Beds Price\n";
        cout << "5. Display Best Hospitals by Available Beds\n";
        cout << "6. Display Best Hospitals by Rating and Reviews\n";
        cout << "7. Display Hospitals in a Specific City\n";
        cout << "8. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                {
                    cout << "\n\n\n***********NEW PATIENT************\n\n";
                    cout << "Enter the index of the hospital to add patient data (0-4): ";
                    int hospitalIndex;
                    cin >> hospitalIndex;
                    if (hospitalIndex >= 0 && hospitalIndex < hospitals.size()) {
                        enterPatientData(patients, hospitalIndex);
                        cout << "Patient data entered successfully for hospital " << hospitals[hospitalIndex].name << endl;
                    } else {
                        cout << "Invalid hospital index.\n";
                    }
                }
                break;
            case 2:
                cout << "\nPrinting Hospital Data:\n\n";
                for (const auto& hospital : hospitals) {
                    hospital.print();
                }
                break;
            case 3:
                cout << "Printing Patients Data:\n\n";
                for (size_t i = 0; i < hospitals.size(); ++i) {
                    cout << "Hospital: " << hospitals[i].name << endl;
                    for (const auto& patient : patients[i]) {
                        patient.print();
                    }
                }
                break;
            case 4:
                cout << "Sorting Hospitals by Beds Price (Ascending):\n";
                sortByBeds(hospitals);
                for (const auto& hospital : hospitals) {
                    hospital.print();
                }
                break;
            case 5:
                cout << "Sorting Hospitals by Available Beds (Descending):\n";
                sortByAvailableBedsDescending(hospitals);
                for (const auto& hospital : hospitals) {
                    hospital.print();
                }
                break;
            case 6:
                cout << "Sorting Hospitals by Rating and Reviews (Descending):\n";
                sortByRating(hospitals);
                for (const auto& hospital : hospitals) {
                    hospital.print();
                }
                break;
            case 7:
                printHospitalsInCity(hospitals);
                break;
            case 8:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 8);
    
    return 0;
}

