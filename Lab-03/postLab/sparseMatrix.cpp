#include <iostream>
#include <fstream>
#include <algorithm>
#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(int numRows, int numCols) 
    : rows(numRows), cols(numCols), nonZeroCount(0) {}

void SparseMatrix::setValue(int row, int col, int value) 
{
    if (row < 0 || row >= rows || col < 0 || col >= cols) 
    {
        throw out_of_range("Matrix indices out of range");
    }

    // Find if element already exists
    auto it = find_if(elements.begin(), elements.end(),
        [row, col](const Element& e) 
        { 
            return e.row == row && e.col == col; 
        });

    if (value != 0) 
    {
        if (it != elements.end()) 
        {
            it->value = value;
        } 
        else 
        {
            elements.emplace_back(row, col, value);
            nonZeroCount++;
        }
    } 
    else if (it != elements.end()) 
    {
        elements.erase(it);
        nonZeroCount--;
    }
}

int SparseMatrix::getValue(int row, int col) const 
{
    if (row < 0 || row >= rows || col < 0 || col >= cols) 
    {
        throw out_of_range("Matrix indices out of range");
    }

    auto it = find_if(elements.begin(), elements.end(),
        [row, col](const Element& e) 
        { 
            return e.row == row && e.col == col; 
        });
    
    return (it != elements.end()) ? it->value : 0;
}

bool SparseMatrix::loadFromFile(const string& filename) 
{
    ifstream file(filename);
    if (!file) 
    {
        throw runtime_error("Unable to open file: " + filename);
    }

    elements.clear();
    nonZeroCount = 0;

    int value;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (!(file >> value)) {
                throw runtime_error("Error reading matrix data from file");
            }
            if (value != 0) {
                elements.emplace_back(i, j, value);
                nonZeroCount++;
            }
        }
    }

    file.close();
    return true;
}

void SparseMatrix::display() const 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << getValue(i, j) << " ";
        }
        cout << endl;
    }
}

SparseMatrix SparseMatrix::fromMatrix(const Matrix& matrix) 
{
    SparseMatrix sparse(matrix.getRows(), matrix.getCols());
    
    for (int i = 0; i < matrix.getRows(); i++) 
    {
        for (int j = 0; j < matrix.getCols(); j++) 
        {
            int value = matrix.getValue(i, j);
            if (value != 0) 
            {
                sparse.setValue(i, j, value);
            }
        }
    }
    
    return sparse;
}

SparseMatrix SparseMatrix::operator+(const SparseMatrix& other) const 
{
    if (rows != other.rows || cols != other.cols) 
    {
        throw invalid_argument("Matrix dimensions don't match for addition");
    }

    SparseMatrix result(rows, cols);
    
    // Create a map of all positions that need to be added
    vector<pair<int, int>> positions;
    for (const auto& elem : elements) 
    {
        positions.emplace_back(elem.row, elem.col);
    }
    for (const auto& elem : other.elements) 
    {
        if (find(positions.begin(), positions.end(), 
            make_pair(elem.row, elem.col)) == positions.end()) 
            {
            positions.emplace_back(elem.row, elem.col);
        }
    }

    // Perform addition for each position
    for (const auto& pos : positions) 
    {
        int sum = getValue(pos.first, pos.second) + 
                 other.getValue(pos.first, pos.second);
        if (sum != 0) 
        {
            result.setValue(pos.first, pos.second, sum);
        }
    }

    return result;
}