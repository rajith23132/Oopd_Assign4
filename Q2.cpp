#include <iostream>
#include <fstream>
#include <sstream>

const int MAX_VIOLATIONS = 100;

class TrafficViolation {
public:
    std::string carNumber;
    std::string reportType;
    std::string reportLocation;

    TrafficViolation() {}  // Default constructor

    TrafficViolation(const std::string& carNumber, const std::string& reportType, const std::string& reportLocation)
        : carNumber(carNumber), reportType(reportType), reportLocation(reportLocation) {}

    void displayInfo() const {
        std::cout << "Car Number: " << carNumber << ", Report Type: " << reportType << ", Report Location: " << reportLocation << std::endl;
    }
};

class TrafficViolationDatabase {
private:
    TrafficViolation violations[MAX_VIOLATIONS];
    int numViolations;

public:
    TrafficViolationDatabase() : numViolations(0) {}

    void readCSV(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line) && numViolations < MAX_VIOLATIONS) {
            std::istringstream iss(line);
            std::string carNumber, reportType, reportLocation;

            if (std::getline(iss, carNumber, ',') &&
                std::getline(iss, reportType, ',') &&
                std::getline(iss, reportLocation, ',')) {
                violations[numViolations] = TrafficViolation(carNumber, reportType, reportLocation);
                ++numViolations;
            }
        }

        file.close();
    }

    void displayViolations() const {
        for (int i = 0; i < numViolations; ++i) {
            violations[i].displayInfo();
        }
    }
};

int main() {
    TrafficViolationDatabase trafficDatabase;
    trafficDatabase.readCSV("A4-Q2.csv");
    trafficDatabase.displayViolations();
    return 0;
}
