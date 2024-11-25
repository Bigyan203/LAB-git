#include <iostream>
#include <vector> //data store garna lai vector use gareko
#include <string> //sstring data operate garda ko lai + stringcmp use vaxa
#include <algorithm>  //std::sort lai used vako 
#include <cctype>  //to check if its a digits or a letter or etc

// patient  ko class
class Patient {
public:
    std::string name;
    int age;
    std::string disease;
    
    Patient() : name(""), age(0), disease("") {} //constructor vayo, non parameterised
    Patient(const std::string& n, int a, const std::string& d) : name(n), age(a), disease(d) {}
    //parameterised constructor vayo, esma (name,age,disease
    void print() const {
        std::cout << "Patient Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Disease: " << disease << std::endl;
        std::cout << std::endl;
    }
};

// hospital ko class
class Hospital {
public:
    std::string name;  
    std::string city;
    int beds;
    float price;
    float rating;
    int reviews;
    
    Hospital() : name(""), city(""), beds(0), price(0.0f), rating(0.0f), reviews(0) {}
    //constructor non para
    Hospital(const std::string& n, const std::string& c, int b, float p, float r, int rev) 
        : name(n), city(c), beds(b), price(p), rating(r), reviews(rev) {} //para (mathi jstai)
    
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

// data store garna lai structure ko satta vector use gareko
std::vector<Hospital> hospitals = {
    Hospital("HAHA Hospital", "Chyasal", 100, 250.0f, 4.5f, 100),
    Hospital("HUHU Hospital", "Mangalbazar", 150, 200.0f, 4.2f, 80),
    Hospital("HEHE Hospital", "Manbhawan", 200, 180.0f, 4.0f, 120),
    Hospital("LALA Hospital", "Pulchowk", 80, 300.0f, 4.8f, 90),
    Hospital("KEKE Hospital", "Imadol", 120, 220.0f, 4.6f, 110)
};

// esma structure ko satta vector gari 
std::vector<std::vector<Patient>> patients = {
    {Patient("Ram", 35, "Fever"), Patient("Shyam", 45, "Headache"), Patient("Hari", 28, "Flu")},
    {Patient("Sita", 62, "Arthritis"), Patient("Gita", 18, "Asthma"), Patient("Sarita", 55, "Diabetes")},
    {Patient("Ted", 50, "Cancer"), Patient("Barney", 30, "Allergy"), Patient("Marshall", 40, "Hypertension")},
    {Patient("Lily", 22, "Bronchitis"), Patient("Robin", 38, "Migraine"), Patient("Tracy", 60, "Osteoporosis")},
    {Patient("Harry", 28, "Cholera"), Patient("Ron", 48, "Tuberculosis"), Patient("Hermione", 33, "Hepatitis")}
};

// Function to enter new patient data
void enterPatientData(std::vector<std::vector<Patient>>& patients, int hospitalIndex) {
    int n;
    //std::cout << "Enter how many patients: ";
    //std::cin >> n;
    std::cout << "Enter patient details for hospital:" << std::endl;
    
    for (int i = 0; i < 1; ++i) {
        std::string name, disease;
        int age;
        
        std::cout << "Enter patient name: ";
        std::cin >> std::ws; // blank space pani linxa
        std::getline(std::cin, name);
        
        std::cout << "Enter patient age: ";
        std::cin >> age;
        
        std::cout << "Enter patient disease: ";
        std::cin >> std::ws; // blank space linxaaa
        std::getline(std::cin, disease);
        
        // Use push_back to add a new patient esko detail ma hernu parxa???
        patients[hospitalIndex].push_back(Patient(name, age, disease));
        //eslai chai jhos vector ma naya element add grxa
    }
}

// Function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string lowerStr;  //string ko declaration ya use vakoo
    std::transform(str.begin(), str.end(), std::back_inserter(lowerStr), [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

// case sensitivity check garna ko lai vayo
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
void sortByRating(std::vector<Hospital>& hospitals) { //mathi ko sort lai lyauxa esle
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

