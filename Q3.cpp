#include <iostream>
#include <fstream>
#include <sstream>

const int MAX_PEOPLE = 1000; // Assuming a maximum of 100 people in the file

struct Person {
    std::string firstName;
    std::string lastName;
    int age;
    std::string gender;
    std::string address;
};

int main() {
    std::ifstream file("A4-Q3.csv");

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    Person people[MAX_PEOPLE];
    int count = 0;

    std::string line;
    getline(file, line); // Skip the header line

    while (getline(file, line) && count < MAX_PEOPLE) {
        std::stringstream ss(line);
        std::string firstName, lastName, gender, address;
        int age;

        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        ss >> age;
        ss.ignore(); // Ignore the comma after age
        getline(ss, gender, ',');
        getline(ss, address);

        people[count++] = {firstName, lastName, age, gender, address};
    }

    // Get user input
    std::string userFirstName, userLastName, userGender;
    int userAge;

    std::cout << "Enter first name: ";
    std::cin >> userFirstName;
    std::cout << "Enter last name: ";
    std::cin >> userLastName;
    std::cout << "Enter age: ";
    std::cin >> userAge;
    std::cout << "Enter gender: ";
    std::cin >> userGender;
    
    // Search for the user input in the people array
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (people[i].firstName == userFirstName && people[i].lastName == userLastName &&
            people[i].gender == userGender && people[i].age == userAge) {
            std::cout << "Potential address for " << userFirstName << " " << userLastName << ": " << people[i].address << std::endl;
            found = true;
            break; // Assuming there is only one matching record
        }
    }
    if (!found) {
        std::cout << "No matching record found for the provided information." << std::endl;
    }
    return 0;
}
