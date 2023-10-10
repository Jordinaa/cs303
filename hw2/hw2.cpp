#include "hw2.h"
#include "single_linked_list.h"

// Implementation for Professional
Professional::Professional(double salary) : monthlySalary(salary), vacationDays(30) {}

// assuming 4 weeks in a month
double Professional::calculateWeeklySalary() {
    return monthlySalary / 4; }

// TWO EXTRA ADDED RULES FOR PROFESSIONALS
// assuming 5% contribution for professionals
double Professional::healthCareContributions() {
    return monthlySalary * 0.05; }

// assuming 52 weeks in a year
double Professional::vacationDaysEarned() {
    return static_cast<double>(vacationDays) / 52; }



// Implementation for NonProfessional
NonProfessional::NonProfessional(double rate) : hourlyRate(rate), hoursWorked(0) {}

void NonProfessional::setHoursWorked(int hours) {
    hoursWorked = hours;}

double NonProfessional::calculateWeeklySalary() {
    return hourlyRate * hoursWorked;}

// TWO EXTRA ADDED RULES FOR NON-PROFESSIONALS
// assuming 3% contribution for non-professionals
double NonProfessional::healthCareContributions() {
    return calculateWeeklySalary() * 0.03; }

// assuming 40 hours for a full week, hence one day off
double NonProfessional::vacationDaysEarned() {
    return static_cast<double>(hoursWorked) / 40; }