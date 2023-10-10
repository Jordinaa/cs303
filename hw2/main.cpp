#include "hw2.h"
#include <iostream>

using namespace std;

int main() {
    SingleLinkedList employees;

    // Create Employees
    Professional* prof1 = new Professional(5000);  
    Professional* prof2 = new Professional(6000);  
    NonProfessional* nonProf1 = new NonProfessional(25);  
    nonProf1->setHoursWorked(40); 
    NonProfessional* nonProf2 = new NonProfessional(30);  
    nonProf2->setHoursWorked(35);  

    // push_front
    employees.push_front(prof1);
    // push_back
    employees.push_back(nonProf1);

    cout << "\nAfter adding two employees:" << endl;
    cout << "First Employee Weekly Salary: $" << employees.front()->calculateWeeklySalary() << "\n";
    cout << "First Employee Healthcare Contributions: $" << employees.front()->healthCareContributions() << "\n";
    cout << "First Employee Vacation Days Earned This Week: " << employees.front()->vacationDaysEarned() << "\n";
    cout << "Last Employee Weekly Salary: $" << employees.back()->calculateWeeklySalary() << "\n";
    cout << "Last Employee Healthcare Contributions: $" << employees.back()->healthCareContributions() << "\n";
    cout << "Last Employee Vacation Days Earned This Week: " << employees.back()->vacationDaysEarned() << "\n\n";

    // insert
    employees.insert(1, prof2);  

    // find
    size_t position = employees.find(prof2);
    cout << "Position of second professional (should be 1): " << position << "\n\n";

    // Test removing an employee
    employees.remove(1);  
    cout << "After removing second professional:" << endl;
    cout << "First Employee Weekly Salary: $" << employees.front()->calculateWeeklySalary() << "\n";
    cout << "Last Employee Weekly Salary: $" << employees.back()->calculateWeeklySalary() << "\n\n";

    // Adding more employees for further tests
    employees.push_back(prof2);
    employees.push_back(nonProf2);

    cout << "After adding more employees:" << endl;
    cout << "Last Employee Weekly Salary: $" << employees.back()->calculateWeeklySalary() << "\n";
    cout << "Last Employee Healthcare Contributions: $" << employees.back()->healthCareContributions() << "\n";
    cout << "Last Employee Vacation Days Earned This Week: " << employees.back()->vacationDaysEarned() << "\n\n";

    // pop_front
    employees.pop_front();
    cout << "After removing the first employee:" << endl;
    cout << "First Employee Weekly Salary: $" << employees.front()->calculateWeeklySalary() << "\n\n";

    // pop_back
    employees.pop_back();
    cout << "After removing the last employee:" << endl;
    if(!employees.empty()) {
        cout << "Last Employee Weekly Salary: $" << employees.back()->calculateWeeklySalary() << "\n";
        cout << "Last Employee Healthcare Contributions: $" << employees.back()->healthCareContributions() << "\n";
        cout << "Last Employee Vacation Days Earned This Week: " << employees.back()->vacationDaysEarned() << "\n\n";
    } else {
        cout << "No employees left in the list.\n";
    }

    // Cleanup dynamically allocated memory
    delete prof1;
    delete prof2;
    delete nonProf1;
    delete nonProf2;

    return 0;
}
