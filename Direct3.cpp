#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

// Define Patient class
class Patient {
public:
    std::string name;
    int age;
    std::string disease;
    
    Patient() : name(""), age(0), disease("") {}
    Patient(std::string n, int a, std::string d) : name(n), age(a), disease(d) {}
    
    void print() const {
        std::cout << "Patient Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Disease: " << disease << std::endl;
        std::cout << std::endl;
    }
};

// Define Hospital class
class Hospital {
public:
    std::string name;
    std::string city;
    int beds;
    float price;
    float rating;
    int reviews;
    
    Hospital() : name(""), city(""), beds(0), price(0.0f), rating(0.0f), reviews(0) {}
    Hospital(std::string n, std::string c, int b, float p, float r, int rev) 
        : name(n), city(c), beds(b), price(p), rating(r), reviews(rev) {}
    
    void print() const {
        std::cout << "Hospital Name: " << name << std::endl;
        std::cout << "City: " << city << std::endl;
        std::cout << "Total Beds: " << beds << std::endl;
        std::cout << "Price per Bed: Rs. " << price << std::endl;
        std::cout << "Rating: " << rating << std::endl;
        std::cout << "Reviews: " << reviews << std::endl;
        std::cout << std::endl;
    }
};

// Function to enter new patient data
void enterPatientData(std::vector<std::vector<Patient>>& patients, int hospitalIndex) {
    int n;
    std::cout << "Enter how many patients: ";
    std::cin >> n;
    std::cout << "Enter patient details for hospital:" << std::endl;
    
    for (int i = 0; i < n; ++i) {
        std::string name, disease;
        int age;
        
        std::cout << "Enter patient name: ";
        std::cin >> std::ws; // Consume any leading whitespace
        std::getline(std::cin, name);
        
        std::cout << "Enter patient age: ";
        std::cin >> age;
        
        std::cout << "Enter patient disease: ";
        std::cin >> std::ws; // Consume any leading whitespace
        std::getline(std::cin, disease);
        
        // Use push_back instead of emplace_back
        patients[hospitalIndex].push_back(Patient(name, age, disease));
    }
}

// Function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string lowerStr;
    std::transform(str.begin(), str.end(), std::back_inserter(lowerStr), [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

// Function to check if two strings are equal case-insensitively
bool caseInsensitiveCompare(const std::string& str1, const std::string& str2) {
    return toLower(str1) == toLower(str2);
}

// Function to sort hospitals by beds price (ascending)
void sortByPrice(std::vector<Hospital>& hospitals) {
    std::sort(hospitals.begin(), hospitals.end(), [](const Hospital& a, const Hospital& b) {
        return a.price < b.price;
    });
}

// Function to sort hospitals by rating and reviews (descending)
void sortByRating(std::vector<Hospital>& hospitals) {
    std::sort(hospitals.begin(), hospitals.end(), [](const Hospital& a, const Hospital& b) {
        return (a.rating * a.reviews) > (b.rating * b.reviews);
    });
}

// Function to sort hospitals by available beds (descending)
void sortByBeds(std::vector<Hospital>& hospitals) {
    std::sort(hospitals.begin(), hospitals.end(), [](const Hospital& a, const Hospital& b) {
        return a.beds > b.beds;
    });
}

// Function to print hospitals in a specific city
void printHospitalsInCity(const std::vector<Hospital>& hospitals) {
    std::string city;
    std::cout << "Enter city name: ";
    std::cin >> std::ws; // Consume any leading whitespace
    std::getline(std::cin, city);
    
    bool found = false;
    for (const auto& hospital : hospitals) {
        if (caseInsensitiveCompare(hospital.city, city)) {
            hospital.print();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No hospitals found in " << city << std::endl;
    }
}

int main() {
    std::vector<Hospital> hospitals = {
        Hospital("HAHA Hospital", "Chyasal", 100, 250.0f, 4.5f, 100),
        Hospital("HUHU Hospital", "Mangalbazar", 150, 200.0f, 4.2f, 80),
        Hospital("HEHE Hospital", "Manbhawan", 200, 180.0f, 4.0f, 120),
        Hospital("LALA Hospital", "Pulchowk", 80, 300.0f, 4.8f, 90),
        Hospital("KEKE Hospital", "Imadol", 120, 220.0f, 4.6f, 110)
    };
    
    std::vector<std::vector<Patient>> patients(hospitals.size());

    int choice;
    
    do {
        std::cout << "\n\n\n*********** Hospital Management System Menu: ************\n\n";
        std::cout << "1. Enter New Patient Data:\n";
        std::cout << "2. Display Hospital Data\n";
        std::cout << "3. Display Patient Data\n";
        std::cout << "4. Display Best Hospitals by Beds Price\n";
        std::cout << "5. Display Best Hospitals by Available Beds\n";
        std::cout << "6. Display Best Hospitals by Rating and Reviews\n";
        std::cout << "7. Display Hospitals in a Specific City\n";
        std::cout << "8. Exit\n\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                {
                    std::cout << "\n\n\n*********** NEW PATIENT ************\n\n";
                    int hospitalIndex;
                    std::cout << "Enter the index of the hospital to add patient data (0-4): ";
                    std::cin >> hospitalIndex;
                    if (hospitalIndex >= 0 && hospitalIndex < hospitals.size()) {
                        enterPatientData(patients, hospitalIndex);
                        std::cout << "Patient data entered successfully for hospital " << hospitals[hospitalIndex].name << std::endl;
                    } else {
                        std::cout << "Invalid hospital index.\n";
                    }
                }
                break;
            case 2:
                std::cout << "\nPrinting Hospital Data:\n\n";
                for (const auto& hospital : hospitals) {
                    hospital.print();
                }
                break;
            case 3:
                std::cout << "Printing Patients Data:\n\n";
                for (size_t i = 0; i < hospitals.size(); ++i) {
                    std::cout << "Hospital: " << hospitals[i].name << std::endl;
                    for (const auto& patient : patients[i]) {
                        patient.print();
                    }
                }
                break;
            case 4:
                std::cout << "Sorting Hospitals by Beds Price (Ascending):\n";
                sortByPrice(hospitals);
                for (const auto& hospital : hospitals) {
                    hospital.print();
                }
                break;
            case 5:
                std::cout << "Sorting Hospitals by Available Beds (Descending):\n";
                sortByBeds(hospitals);
                for (const auto& hospital : hospitals) {
                    hospital.print();
                }
                break;
            case 6:
                std::cout << "Sorting Hospitals by Rating and Reviews (Descending):\n";
                sortByRating(hospitals);
                for (const auto& hospital : hospitals) {
                    hospital.print();
                }
                break;
            case 7:
                printHospitalsInCity(hospitals);
                break;
            case 8:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 8);
    
    return 0;
}

