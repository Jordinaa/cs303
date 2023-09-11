#include "hw1.h"

using namespace std;

bool readFile(const string& filename, vector<vector<int>>& data) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file: " << filename << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int value;
        vector<int> row;

        while (iss >> value) {
            row.push_back(value);
        }
        if (!row.empty()) {
            data.push_back(row);
        }
    }
    return true;
}

pair<int, int> checkNumber(const vector<vector<int>>& data, int number) {
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            if (data[i][j] == number) {
                 // return row and column where number is found
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    // return {-1, -1} if number is not found
    return {-1, -1};
}

bool modifyValueAtIndex(std::vector<std::vector<int>>& data, int rowIndex, int colIndex, int newValue, int& oldValue) {
    try {
        if (rowIndex < 0 || rowIndex >= data.size() || colIndex < 0 || colIndex >= data[rowIndex].size()) {
            throw IndexOutOfRangeException();
        }

        oldValue = data[rowIndex][colIndex];
        data[rowIndex][colIndex] = newValue;

        return true;
    }
    catch (const IndexOutOfRangeException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
}

void appendValue(std::vector<std::vector<int>>& data, int value) {
    try {
        if (data.empty()) {
            data.push_back(std::vector<int>{value});
        } else if (data.back().size() < 10) {
            data.back().push_back(value);
        } else {
            data.push_back(std::vector<int>{value});
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void modifyOrRemoveAtIndex(vector<vector<int>>& data, int rowIndex, int colIndex, bool setToZero) {
    if (rowIndex < 0 || rowIndex >= data.size() || colIndex < 0 || colIndex >= data[rowIndex].size()) {
        cerr << "Error: Index out of bounds." << endl;
        return;
    }

    if (setToZero) {
        // Set the value to zero
        data[rowIndex][colIndex] = 0;  
    } else {
        // Remove the value altogether
        data[rowIndex].erase(data[rowIndex].begin() + colIndex);  
        // If the row becomes empty after removal, erase the row as well
        if (data[rowIndex].empty()) {  
            data.erase(data.begin() + rowIndex);
        }
    }
}