#include <iostream>
#include <vector>

// Class to represent a person's information
class Person {
public:
    std::string firstName;
    std::string lastName;
    int age;
    std::string gender;
    std::string address;

    // Additional data or methods related to a person can be added here
};

// Class to represent a traffic violation
class TrafficViolation {
public:
    Person offender; // Person responsible for the violation
    std::string violationDetails;

    // Additional data or methods related to a traffic violation can be added here
};

// Class to represent a witness
class Witness {
public:
    std::string name;
    std::string contactDetails;

    // Additional data or methods related to a witness can be added here
};

// Class to represent evidence in a case
class Evidence {
public:
    std::vector<Witness> witnesses;
    TrafficViolation violationDetails;
    std::string personResponse;

    // Additional data or methods related to evidence can be added here
};

// Class to represent a prior record related to an accident
class PriorRecord {
public:
    Person person;
    std::string accidentDetails;

    // Additional data or methods related to a prior record can be added here
};

// Class to represent a case, including related evidence and prior records
class TrafficCase {
public:
    Evidence evidence;
    std::vector<PriorRecord> priorRecords;

    // Additional data or methods related to a traffic case can be added here
};

int main() {
    // Example usage of the class structure
    TrafficCase trafficCase;

    // Populate the data for the traffic case
    trafficCase.evidence.personResponse = "The offender denies the violation.";
    trafficCase.evidence.violationDetails.offender.firstName = "Bee";
    trafficCase.evidence.violationDetails.offender.lastName = "Obed";
    trafficCase.evidence.violationDetails.violationDetails = "Speeding";

    // Add a witness to the evidence
    Witness witness;
    witness.name = "John Doe";
    witness.contactDetails = "john@example.com";
    trafficCase.evidence.witnesses.push_back(witness);

    // Add a prior record to the case
    PriorRecord priorRecord;
    priorRecord.person.firstName = "Bee";
    priorRecord.person.lastName = "Obed";
    priorRecord.accidentDetails = "Involved in a previous accident in 2019.";
    trafficCase.priorRecords.push_back(priorRecord);

    // Accessing data from the case
    std::cout << "Traffic Violation Details:" << std::endl;
    std::cout << "Offender: " << trafficCase.evidence.violationDetails.offender.firstName << " " << trafficCase.evidence.violationDetails.offender.lastName << std::endl;
    std::cout << "Violation: " << trafficCase.evidence.violationDetails.violationDetails << std::endl;

    std::cout << "\nWitness Details:" << std::endl;
    for (const auto& w : trafficCase.evidence.witnesses) {
        std::cout << "Name: " << w.name << ", Contact: " << w.contactDetails << std::endl;
    }

    std::cout << "\nPrior Records:" << std::endl;
    for (const auto& prior : trafficCase.priorRecords) {
        std::cout << "Person: " << prior.person.firstName << " " << prior.person.lastName << ", Prior Record: " << prior.accidentDetails << std::endl;
    }

    return 0;
}
