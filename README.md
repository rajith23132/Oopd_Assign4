Traffic Department Vehicle Information System

Overview
This C++ program is designed to read vehicle information from a CSV file and display it to the console. The program utilizes classes to organize data and provide a structured approach to handling vehicle information.

Features
CSV File Reading: The program reads vehicle information from a CSV file, assuming the format: VehicleNumber,FirstName,LastName,Age,Gender,Address.
Error Handling: Invalid age values are handled using exception handling, and appropriate error messages are displayed.
User-Friendly Output: Vehicle information is displayed in a user-friendly format on the console.

Code Structure
VehicleInformation Class: Represents information about a vehicle and its owner.
TrafficDepartment Class: Manages an array of VehicleInformation objects and provides functions for reading CSV files and displaying information.
Main Function: Creates an instance of TrafficDepartment, reads vehicle information from a CSV file, and prints the information to the console.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

Traffic Violation Database
Overview
This C++ program is designed to read traffic violation data from a CSV file, store it in a collection of TrafficViolation objects, and display the information to the console. The program employs classes to organize and manage traffic violation data.

Features
CSV File Reading: The program reads traffic violation data from a CSV file, assuming the format: CarNumber,ReportType,ReportLocation.
Error Handling: File opening errors are detected and reported. The program also limits the number of violations to a predefined maximum.
User-Friendly Output: Traffic violation information is displayed in a user-friendly format on the console.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

People Information Search System
Overview
This C++ program reads information about people from a CSV file, stores it in an array of Person structures, and prompts the user to input details for searching a potential address. The program provides a simple command-line interface for user interaction.

Features
CSV File Reading: The program reads people information from a CSV file, assuming the format: FirstName,LastName,Age,Gender,Address.
User Search: Allows the user to input details such as first name, last name, age, and gender to search for a potential address.
User-Friendly Output: Displays search results in a user-friendly format on the console

Code Structure
Person Structure: Represents information about an individual, including first name, last name, age, gender, and address.
Main Function: Reads data from a CSV file, stores it in a vector of Person structures, and performs a user-driven search for a potential address.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

Traffic Case Management System

Overview
This C++ program provides a basic implementation of a Traffic Case Management System. It defines a set of classes to represent entities involved in a traffic case, including a person, traffic violation, witness, evidence, prior record, and the traffic case itself. The program demonstrates the use of classes, encapsulation, and composition to organize and manage data related to a traffic incident.

Classes
1. Person
Represents an individual's information, including their first name, last name, age, gender, and address.

2. TrafficViolation
Represents details of a traffic violation, including the offender (a Person) and the violation description.

3. Witness
Represents information about a witness, including their name and contact details.

4. Evidence
Combines information about the traffic violation, witnesses, and the offender's response to create a comprehensive evidence record.

5. PriorRecord
Represents a prior record related to a person involved in a traffic case, including details about a previous accident.

6. TrafficCase
Combines evidence and a vector of prior records to represent a complete traffic case.

Code Structure
Class Definitions: Each class is defined with members and methods to encapsulate related functionalities.
Main Function: The main function demonstrates the creation and display of a TrafficCase with associated details.
