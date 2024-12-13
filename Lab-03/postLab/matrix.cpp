#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Matrix.h"

Matrix::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), data(nullptr) 
{
    initialize();
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(nullptr) 
{
    initialize();
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::~Matrix() 
{
    cleanup();
}

void Matrix::initialize() 
{
    try {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) 
        {
            data[i] = new int[cols]();  // Initialize with zeros
        }
    }
    catch (const bad_alloc& e) 
    {
        cleanup();
        throw runtime_error("Memory allocation failed");
    }
}

void Matrix::cleanup() 
{
    if (data) 
    {
        for (int i = 0; i < rows; i++) 
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

int Matrix::getValue(int row, int col) const 
{
    if (row < 0 || row >= rows || col < 0 || col >= cols) 
    {
        throw out_of_range("Matrix indices out of range");
    }
    return data[row][col];
}

void Matrix::setValue(int row, int col, int value) 
{
    if (row < 0 || row >= rows || col < 0 || col >= cols) 
    {
        throw out_of_range("Matrix indices out of range");
    }
    data[row][col] = value;
}

bool Matrix::loadFromFile(const string& filename) 
{
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Unable to open file: " + filename);
    }

    // Read matrix data
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (!(file >> data[i][j])) 
            {
                throw runtime_error("Error reading matrix data from file");
            }
        }
    }

    file.close();
    return true;
}

void Matrix::display() const 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix& Matrix::operator=(const Matrix& other) 
{
    if (this != &other)
    {
        cleanup();
        rows = other.rows;
        cols = other.cols;
        initialize();
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const 
{
    if (rows != other.rows || cols != other.cols) 
    {
        throw invalid_argument("Matrix dimensions don't match for addition");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}