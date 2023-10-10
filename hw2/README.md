## Author: Jordan Taranto
## Employee Management System

### Added two extra rules: 
**Healthcare Contribution:**
- Professional: 5% of monthly salary.
- NonProfessional: 3% of weekly earnings (based on hours worked).
**Vacation Days Earned:**
- Professional: 30 days annually.
- NonProfessional: 1 vacation hour earned per 40 hours worked.

## **Adding Employees:**
**For professionals with a monthly salary:**

```Professional* prof1 = new Professional(5000);```

**For non-professionals with an hourly rate and hours worked:**
```
NonProfessional* nonProf1 = new NonProfessional(25);
nonProf1->setHoursWorked(40);
```

**Storing Employees to the System:**
**Add an employee to the system:**
employees.push_back(prof1);
employees.push_back(nonProf1);

**Displaying Employee Information:**
**Display details for the first employee in the list:**
Employee* emp = employees.front();
std::cout << "Weekly Salary: $" << emp->calculateWeeklySalary() << std::endl;

**Modifying Employee Data:**
**Change the number of hours a non-professional worked:**
nonProf1->setHoursWorked(45);

**Removing Employees:**
**Remove the first employee:**
employees.pop_front();

**Remove the last employee:**
employees.pop_back();

**Remove an employee at a specific position:**
employees.remove(index);

**Finding Employees:**
**Find the position of a specific employee in the list:**
size_t position = employees.find(prof1);