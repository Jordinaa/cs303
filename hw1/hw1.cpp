#include "hw1.h"

using namespace std;

// reads in file
bool readFile(const string& filename, int data[MAX_ROWS][MAX_COLS], int& currentRows, int& currentCols) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file: " << filename << endl;
        return false;
    }

    string line;
    currentRows = 0;
    while (getline(file, line) && currentRows < MAX_ROWS) {
        istringstream iss(line);
        int value;
        int colCount = 0;

        while (iss >> value && colCount < MAX_COLS) {
            data[currentRows][colCount] = value;
            colCount++;
        }
        currentCols = colCount;
        currentRows++;
    }
    return true;
}

// checks number of rows and digits
pair<int, int> checkNumber(const int data[MAX_ROWS][MAX_COLS], int number, int currentRows, int currentCols) {
    for (int i = 0; i < currentRows; ++i) {
        for (int j = 0; j < currentCols; ++j) {
            if (data[i][j] == number) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

bool modifyValueAtIndex(int data[MAX_ROWS][MAX_COLS], int rowIndex, int colIndex, int newValue, int& oldValue) {
    if (rowIndex < 0 || rowIndex >= MAX_ROWS || colIndex < 0 || colIndex >= MAX_COLS) {
        cerr << "Error: Index out of bounds." << endl;
        return false;
    }

    oldValue = data[rowIndex][colIndex];
    data[rowIndex][colIndex] = newValue;
    return true;
}

bool appendValue(int data[MAX_ROWS][MAX_COLS], int &currentRows, int &currentCols, int value) {
    if (currentRows == 0) {
        cerr << "No data has been read yet. Cannot append." << endl;
        return false;
    }

    if (currentCols == MAX_COLS) {
        cerr << "The last row is full! Cannot append." << endl;
        return false;
    }

    data[currentRows - 1][currentCols] = value;
    currentCols++;
    return true;
}


void modifyOrRemoveAtIndex(int data[MAX_ROWS][MAX_COLS], int& currentRows, int& currentCols, int rowIndex, int colIndex, bool setToZero) {
    if (rowIndex < 0 || rowIndex >= MAX_ROWS || colIndex < 0 || colIndex >= MAX_COLS) {
        cerr << "Error: Index out of bounds." << endl;
        return;
    }

    if (setToZero) {
        data[rowIndex][colIndex] = 0;  
    } else {
        for (int j = colIndex; j < currentCols - 1; j++) {
            data[rowIndex][j] = data[rowIndex][j + 1];
        }
        currentCols--;
        if (currentCols == 0 && rowIndex < currentRows - 1) {
            for (int i = rowIndex; i < currentRows - 1; i++) {
                for (int j = 0; j < MAX_COLS; j++) {
                    data[i][j] = data[i + 1][j];
                }
            }
            currentRows--;
        }
    }
}

void displayArray(int data[MAX_ROWS][MAX_COLS], int currentRows, int currentCols) {
    for (int i = 0; i < currentRows; i++) {
        for (int j = 0; j < currentCols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
