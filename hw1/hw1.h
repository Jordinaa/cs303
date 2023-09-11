#ifndef HW1_H
#define HW1_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Q2

// Function to read data from a file into a 2D array
bool readFile(const string& filename, vector<vector<int>>& data);
// Q2.1
// Function to check if a certain integer exists in the 2D array
pair<int, int> checkNumber(const vector<vector<int>>& data, int number);

// Q2.2
bool modifyValueAtIndex(vector<vector<int>>& data, int rowIndex, int colIndex, int newValue, int &oldValue);

// Q2.3
void appendValue(vector<vector<int>>& data, int value);

// Q2.4
void modifyOrRemoveAtIndex(vector<vector<int>>& data, int rowIndex, int colIndex, bool setToZero);

// QUESTION 2
class IndexOutOfRangeException : public std::exception {
public:
    const char* what() const throw() {
        return "Index out of range!";
    }
};

class InvalidInputException : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid input!";
    }
};


#endif