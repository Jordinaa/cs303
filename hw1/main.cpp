#include "hw1.h"
#include <iostream>

int main() {
    vector<vector<int>> data;
    string filename = "data.txt";

    // Read the data from the file
    if (!readFile(filename, data)) {
        cerr << "Failed to read data from " << filename << endl;
        return 1;
    }

    // Search for a number
    int number;
    cout << "Enter the number to be searched: ";
    cin >> number;

    auto [row, col] = checkNumber(data, number);
    if (row != -1) {
        cout << "Number found at index (" << row << "," << col << ")" << endl;

        // Modify the value at the found index
        int newValue;
        cout << "Enter the new value to replace the number: ";
        cin >> newValue;

        int oldValue;
        if (modifyValueAtIndex(data, row, col, newValue, oldValue)) {
            cout << "Value at index (" << row << "," << col << ") changed from " << oldValue << " to " << newValue << endl;
        }

    } else {
        cout << "Number not found in the array." << endl;
    }

    // Append a new value to the end of the array
    int appendVal;
    cout << "Enter an integer to append to the end of the array: ";
    cin >> appendVal;

    appendValue(data, appendVal);
    cout << "Value " << appendVal << " appended to the end of the array." << endl;

    // Modify or remove a value at a specific index
    int rowIndex, colIndex;
    bool setToZeroChoice;
    cout << "\nEnter the row index and column index of the integer to modify or remove: ";
    cin >> rowIndex >> colIndex;

    cout << "Do you want to set the value to 0 (1 for yes, 0 for remove): ";
    cin >> setToZeroChoice;

    modifyOrRemoveAtIndex(data, rowIndex, colIndex, setToZeroChoice);
    cout << "Modification done." << endl;

    // Display the modified 2D vector
    cout << "\nUpdated array:\n";
    for (const auto& row : data) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
