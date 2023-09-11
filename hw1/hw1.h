#ifndef HW1_H
#define HW1_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

using namespace std;

bool readFile(const string& filename, int data[MAX_ROWS][MAX_COLS], int& currentRows, int& currentCols);
pair<int, int> checkNumber(const int data[MAX_ROWS][MAX_COLS], int number, int currentRows, int currentCols);
bool modifyValueAtIndex(int data[MAX_ROWS][MAX_COLS], int rowIndex, int colIndex, int newValue, int& oldValue);
bool appendValue(int data[MAX_ROWS][MAX_COLS], int &currentRows, int &currentCols, int value);
void modifyOrRemoveAtIndex(int data[MAX_ROWS][MAX_COLS], int& currentRows, int& currentCols, int rowIndex, int colIndex, bool setToZero);
void displayArray(int data[MAX_ROWS][MAX_COLS], int currentRows, int currentCols);

#endif
