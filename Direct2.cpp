#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Define Patient class
class Patient {
public:
    string name;
    int age;
    string disease;
    
    Patient() : name(""), age(0), disease("") {}
    Patient(string n, int a, string d) : name(n), age(a), disease(d) {}
    
    void print() const {
        cout << "Patient Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Disease: " << disease << endl;
        cout << endl;
    }
};

// Define Hospital class
class Hospital {
public:
    string name;
    string city;
    int beds;
    float price;
    float rating;
    int reviews;
    
    Hospital() : name(""), city(""), beds(0), price(0.0f), rating(0.0f), reviews(0) {}
    Hospital(string n, string c, int b, float p, float r, int rev) 
        : name(n), city(c), beds(b), price(p), rating(r), reviews(rev) {}
    
    void print() const {
        cout << "Hospital Name: " << name << endl;
        cout << "City: " << city << endl;
        cout << "Total Beds: " << beds << endl;
        cout << "Price per Bed: Rs. " << price << endl;
        cout << "Rating: " << rating << endl;
        cout << "Reviews: " << reviews << endl;
        cout << endl;
    }
};

// Function to enter new patient data
void enterPatientData(vector<vector<Patient> >& patients, int hospitalIndex) {
    int n;
    cout << "Enter how many patients: ";
    cin >> n;
    cout << "Enter patient details for hospital:" << endl;
    
    for (int i = 0; i < n; ++i) {
        string name, disease;
        int age;
        
        cout << "Enter patient name: ";
        cin >> ws; // Consume any leading whitespace
        getline(cin, name);
        
        cout << "Enter patient age: ";
        cin >> age;
        
        cout << "Enter patient disease: ";
        cin >> ws; // Consume any leading whitespace
        getline(cin, disease);
        
        // Use push_back instead of emplace_back
        patients[hospitalIndex].push_back(Patient(name, age, disease));
    }
}

// Function to sort hospitals by beds price (ascending)
void sortByPrice(vector<Hospital>& hospitals) {
    sort(hospitals.begin(), hospitals.end(), [](const Hospital& a, const Hospital& b) {
        return a.price < b.price;
    });  
}

// Function to sort hospitals by rating and reviews (descending)
void sortByRating(vector<Hospital>& hospitals) {
    sort(hospitals.begin(), hospitals.end(), [](const Hospital& a, const Hospital& b) {
        return (a.rating * a.reviews) > (b.rating * b.reviews);
    });
}

// Function to sort hospitals by available beds (descending)
void sortByBeds(vector<Hospital>& hospitals) {
    sort(hospitals.begin(), hospitals.end(), [](const Hospital& a, const Hospital& b) {
        return a.beds > b.beds;
    });
}

// Function to print hospitals in a specific city
void printHospitalsInCity(const vector<Hospital>& hospitals) {
    string city;
    cout << "Enter city name: ";
    cin >> ws; // Consume any leading whitespace
    getline(cin, city);
    
    bool found = false;
    for (const auto& hospital : hospitals) {
        if (strcasecmp(hospital.city.c_str(), city.c_str()) == 0) {
            hospital.print();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No hospitals found in " << city << endl;
    }
}

int main() {
    vector<Hospital> hospitals = {
        Hospital("HAHA Hospital", "Chyasal", 100, 250.0f, 4.5f, 100),
        Hospital("HUHU Hospital", "Mangalbazar", 150, 200.0f, 4.2f, 80),
        Hospital("HEHE Hospital", "Manbhawan", 200, 180.0f, 4.0f, 120),
        Hospital("LALA Hospital", "Pulchowk", 80, 300.0f, 4.8f, 90),
        Hospital("KEKE Hospital", "Imadol", 120, 220.0f, 4.6f, 110)
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
                    cout << "\n\n\n*********** NEW PATIENT ************\n\n";
                    int hospitalIndex;
                    cout << "Enter the index of the hospital to add patient data (0-4): ";
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
                sortByPrice(hospitals);
                for (const auto& hospital : hospitals) {
                    hospital.print();
                }
                break;
            case 5:
                cout << "Sorting Hospitals by Available Beds (Descending):\n";
                sortByBeds(hospitals);
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

