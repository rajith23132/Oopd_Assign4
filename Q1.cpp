#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_VEHICLES = 2000; // Maximum number of vehicles

class VehicleInformation {
public:
    string vehicle_number;
    string owner_name;
    int owner_age;
    string owner_gender;
    string owner_address;

    VehicleInformation() {}

    VehicleInformation(const string& number, const string& name, int age, const string& gender, const string& address)
        : vehicle_number(number), owner_name(name), owner_age(age), owner_gender(gender), owner_address(address) {}

    void display() const {
        cout << "Vehicle Number: " << vehicle_number << ", Owner: " << owner_name
                  << ", Age: " << owner_age << ", Gender: " << owner_gender << ", Address: " << owner_address << endl;
    }
};

class TrafficDepartment {
public:
    VehicleInformation vehicles[MAX_VEHICLES];
    int numVehicles; // Keep track of the number of vehicles

    TrafficDepartment() : numVehicles(0) {}

    void readCsv(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    // Assuming CSV format: VehicleNumber,FirstName,LastName,Age,Gender,Address
    string number, firstName, lastName, ageStr, gender, address;
    while (getline(file, number, ',') &&
           getline(file, firstName, ',') &&
           getline(file, lastName, ',') &&
           getline(file, ageStr, ',') &&
           getline(file, gender, ',') &&
           getline(file, address, '\n')) {

        try {
            int age = stoi(ageStr);
            vehicles[numVehicles++] = VehicleInformation(number, firstName + " " + lastName, age, gender, address);
        } catch (const invalid_argument& e) {
            cerr << "Invalid age value. Skipping entry." << endl;
        }

        if (numVehicles >= MAX_VEHICLES) {
            cerr << "Maximum number of vehicles reached. Ignoring additional entries." << endl;
            break;
        }
    }
    file.close();
}

    void printVehicleInformation() const {
        for (int i = 0; i < numVehicles; ++i) {
            vehicles[i].display();
        }
    }
};

int main() {
    TrafficDepartment trafficDepartment;
    trafficDepartment.readCsv("A4-Q1.csv");
    trafficDepartment.printVehicleInformation();

    return 0;
}
