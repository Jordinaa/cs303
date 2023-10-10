#ifndef HW2_H
#define HW2_H

#include "single_linked_list.h"

class Employee {
public:
    virtual ~Employee() {}
    virtual double calculateWeeklySalary() = 0;
    virtual double healthCareContributions() = 0;
    virtual double vacationDaysEarned() = 0;
};

class Professional : public Employee {
private:
    double monthlySalary;
    int vacationDays;
public:
    Professional(double salary);
    double calculateWeeklySalary() override;
    double healthCareContributions() override;
    double vacationDaysEarned() override;
};

class NonProfessional : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    NonProfessional(double rate);
    void setHoursWorked(int hours);
    double calculateWeeklySalary() override;
    double healthCareContributions() override;
    double vacationDaysEarned() override;
};

#endif // HW2_H
