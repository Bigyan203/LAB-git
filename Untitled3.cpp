//Hospital Management System 
#include <ctype.h> //ctype.h for strcasecmp 
#include <stdio.h> 
#include <string.h> 
//Hospital haru lai 
struct Hospital 
{ 
char name[50]; 
char city[50]; 
int beds; 
float price; 
float rating; 
int reviews; 
}; 
//Patient haru lai 
struct Patient 
{ 
char name[50]; 
int age; 
char disease[50]; 
}; 
//Function to ask user for new entry 
void enterPatientData(struct Patient patients[][3], int hospitalIndex) { 
int i,n; 
printf("Enter how many patients:"); 
scanf("%d",&n); 
printf("Enter patient details for hospital :\n"/*patients[hospitalIndex][0].name*/); 
for (i = 0; i < n; i++)
 { 
printf("Enter patient name: "); 
scanf("%s", patients[hospitalIndex][i].name); 
printf("Enter patient age: "); 
scanf("%d", &patients[hospitalIndex][i].age); 
printf("Enter patient disease: "); 
scanf("%s", patients[hospitalIndex][i].disease);
} 
} 
// Function to print hospital data 
void printHospital(struct Hospital hosp) 
{ 
int i,j; 
printf("Hospital Name: %s\n", hosp.name); 
printf("City: %s\n", hosp.city); 
printf("Total Beds: %d\n", hosp.beds); 
printf("Price per Bed: Rs.%.2f\n", hosp.price); 
printf("Rating: %.1f\n", hosp.rating); 
printf("Reviews: %d\n", hosp.reviews); 
printf("\n"); 
} 
// Function to print patient data 
void printPatient(struct Patient patient) 
{ 
printf("Patient Name: %s\n", patient.name); 
printf("Age: %d\n", patient.age); 
printf("Disease: %s\n", patient.disease); 
printf("\n"); 
} 
// Function to sort hospitals by beds price (ascending) void sortByPrice(struct Hospital hospitals[], int n) { 
int i,j; 
for ( i = 0; i < n - 1; i++) 
{ 
for ( j = 0; j < n - i - 1; j++) 
{ 
if (hospitals[j].price > hospitals[j + 1].price) 
{ 
struct Hospital temp = hospitals[j]; 
hospitals[j] = hospitals[j + 1];
hospitals[j + 1] = temp; 
} 
} 
} 
} 
// Function to sort hospitals by rating and reviews (descending) void sortByRating(struct Hospital hospitals[], int n) { 
int i,j; 
//same as above 
for ( i = 0; i < n - 1; i++) 
{ 
for ( j = 0; j < n - i - 1; j++) 
{ 
if (hospitals[j].rating * hospitals[j].reviews 
< hospitals[j + 1].rating 
* hospitals[j + 1].reviews) 
{ 
struct Hospital temp = hospitals[j]; 
hospitals[j] = hospitals[j + 1]; 
hospitals[j + 1] = temp; 
} 
} 
} 
} 
// Function to sort hospitals by available beds (descending) void sortByBeds(struct Hospital hospitals[], int n) { 
int i,j; 
// sort 
for ( i = 0; i < n - 1; i++) 
{ 
for ( j = 0; j < n - i - 1; j++) 
{ 
if (hospitals[j].beds < hospitals[j + 1].beds) 
{
struct Hospital temp = hospitals[j]; 
hospitals[j] = hospitals[j + 1]; 
hospitals[j + 1] = temp; 
} 
} 
} 
} 
// Function to print hospitals in a specific city 
// case sensitive vayena 
void printHospitalsInCity(struct Hospital hospitals[]) 
{ 
int i,j; 
char city[50]; 
int hospitalsFound = 0; // Counter for hospitals found in the city 
printf("Enter city name:"); 
scanf("%s", city); 
printf("Hospitals in %s:\n", city); 
for ( i = 0; i < 5; i++) 
{ 
//strcasecmp upper ra lower case ignore garna lai 
if (strcasecmp(hospitals[i].city, city) == 0) 
{ 
printf("Hospital Name: %s\n", hospitals[i].name); 
printf("City: %s\n", hospitals[i].city); 
printf("Total Beds: %d\n", hospitals[i].beds); 
printf("Price per Bed: Rs.%.2f\n", hospitals[i].price); 
printf("Rating: %.1f\n", hospitals[i].rating); 
printf("Reviews: %d\n", hospitals[i].reviews); 
printf("\n"); 
hospitalsFound++; 
} 
} 
if (hospitalsFound == 0) { 
printf("No hospitals found in %s\n", city); 
} 
}
int main() 
{ 
int i,j; 
// afai rakeko hospital data 
struct Hospital hospitals[5] 
= { { "HAHA Hospital", "Chyasal", 100, 250.0, 4.5, 100 }, 
{ "HUHU Hospital", "Mangalbazar", 150, 200.0, 4.2, 80 }, 
{ "HEHE Hospital", "Manbhawan", 200, 180.0, 4.0, 120 }, 
{ "LALA Hospital", "Pulchowk", 80, 300.0, 4.8, 90 }, 
{ "KEKE Hospital", "Imadol", 120, 220.0, 4.6, 110 } }; 
// afai rakeko patient data 
struct Patient patients[5][3] = 
{ 
{{"Ram", 35, "Fever"}, {"Shyam", 45, "Headache"}, {"Hari", 28, "Flu"}}, {{"Sita", 62, "Arthritis"}, {"Gita", 18, "Asthma"}, {"Sarita", 55, "Diabetes"}}, {{"Ted", 50, "Cancer"}, {"Barney", 30, "Allergy"}, {"Marshall", 40, "Hypertension"}}, {{"Lily", 22, "Bronchitis"}, {"Robin", 38, "Migraine"}, {"Tracy", 60, "Osteoporosis"}}, {{"Harry", 28, "Cholera"}, {"Ron", 48, "Tuberculosis"}, {"Hermione", 33, "Hepatitis"}} }; 
int n = 5; // Number of hospitals 
int choice; 
char city[50]; 
do 
{ 
printf("\n\n\n*********** Hospital Management " 
"System Menu:************\n\n"); 
printf("1. Enter New Patient Data:\n"); 
printf("2. Display Hospital Data\n"); 
printf("3. Display Patient Data\n"); 
printf("4. Display Best Hospitals by Beds Price\n"); 
printf("5. Display Best Hospitals by Available Beds\n"); 
printf("6. Display Best Hospitals by Rating and Reviews\n"); 
printf("7. Display Hospitals in a Specific City\n"); 
printf("8. Exit\n\n");
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("\n\n\n***********NEW PATIENT************\n\n"); 
printf("Enter the index of the hospital to add patient data (0-4): "); 
int hospitalIndex; 
scanf("%d", &hospitalIndex); 
if (hospitalIndex >= 0 && hospitalIndex < 5) 
{ 
enterPatientData(patients, hospitalIndex); 
printf("Patient data entered successfully for hospital %s\n", 
hospitals[hospitalIndex].name); 
} 
else 
{ 
printf("Invalid hospital index.\n"); 
} 
break; 
case 2: 
printf("\nPrinting Hospital Data:\n\n"); 
for ( i = 0; i < n; i++) 
{ 
printHospital(hospitals[i]); 
} 
break; 
case 3: 
printf("Printing Patients Data:\n\n"); 
for ( i = 0; i < n; i++) 
{ 
printf("Hospital: %s\n", hospitals[i].name); 
for ( j = 0; j < 3; j++) 
{ 
printPatient(patients[i][j]); 
} 
} 
break;
case 4: 
printf("Sorting Hospitals by Beds Price " 
"(Ascending):\n"); 
sortByBeds(hospitals, n); 
for ( i = 0; i < n; i++) 
{ 
printHospital(hospitals[i]); 
} 
break; 
case 5: 
printf("Sorting Hospitals by Available Beds " 
"(Descending):\n"); 
sortByBeds(hospitals, n); // Fix: Sorting by available beds for ( i = 0; i < n; i++) 
{ 
printHospital(hospitals[i]); 
} 
break; 
case 6: 
printf("Sorting Hospitals by Rating and " 
"Reviews (Descending):\n"); 
sortByRating(hospitals, n); 
for ( i = 0; i < n; i++) 
{ 
printHospital(hospitals[i]); 
} 
break; 
case 7: 
printHospitalsInCity(hospitals); 
break; 
case 8: 
printf("Exiting the program.\n"); 
break; 
default:
printf("Invalid choice. Please enter a valid " 
"option.\n"); 
} 
} while (choice != 8); 
return 0; 
}

