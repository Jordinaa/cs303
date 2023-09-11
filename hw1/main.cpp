#include "hw1.h"

using namespace std;

int main() {
    int data[MAX_ROWS][MAX_COLS];
    int currentRows = 0;
    int currentCols = 0;
    string filename = "data.txt";

    // Read the data from the file
    if (!readFile(filename, data, currentRows, currentCols)) {
        cerr << "Failed to read data from " << filename << endl;
        return 1;
    }

    // Display the initial state of the array
    cout << "Initial array content:" << endl;
    displayArray(data, currentRows, currentCols);
    cout << endl;

    // Search for a number
    int number;
    cout << "Enter the number to be searched: ";
    cin >> number;

    auto [row, col] = checkNumber(data, number, currentRows, currentCols);
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

        // Display the array after the modification
        cout << "\nArray after searching and modifying:" << endl;
        displayArray(data, currentRows, currentCols);
        cout << endl;
    } else {
        cout << "Number not found in the array." << endl;
    }

    // Append a new value to the array
    int appendVal;
    cout << "Enter an integer to append to the array: ";
    cin >> appendVal;

    appendValue(data, currentRows, currentCols, appendVal);
    cout << "Value " << appendVal << " appended." << endl;

    // Display the array after appending
    cout << "\nArray after appending a value:" << endl;
    displayArray(data, currentRows, currentCols);
    cout << endl;

    // Modify or remove a value at a specific index
    int rowIndex, colIndex;
    bool setToZeroChoice;
    cout << "\nEnter the row index (0-" << currentRows-1 << ") and column index (0-" << (currentCols ? currentCols-1 : MAX_COLS-1) << ") of the integer to modify or remove: ";
    cin >> rowIndex >> colIndex;

    while(rowIndex >= currentRows || rowIndex < 0 || colIndex >= (rowIndex == currentRows-1 ? currentCols : MAX_COLS) || colIndex < 0) {
        cerr << "Invalid row or column index. Please try again." << endl;
        cout << "Enter the row index and column index of the integer to modify or remove: ";
        cin >> rowIndex >> colIndex;
    }

    cout << "Do you want to set the value to 0 (1 for yes, 0 for remove): ";
    cin >> setToZeroChoice;

    modifyOrRemoveAtIndex(data, currentRows, currentCols, rowIndex, colIndex, setToZeroChoice);
    cout << "Modification done." << endl;
    // Display the array after modification or removal
    cout << "\nArray after modification or removal:" << endl;
    displayArray(data, currentRows, currentCols);
    cout << endl;

    return 0;
}