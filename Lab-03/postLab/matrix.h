#ifndef MATRIX_H
#define MATRIX_H
#include <string>
using namespace std;

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    Matrix(int numRows = 0, int numCols = 0);
    Matrix(const Matrix& other);
    ~Matrix();
    int getRows() const 
    { 
        return rows; 
    }
    int getCols() const 
    { 
        return cols; 
    }
    int getValue(int row, int col) const;

    void setValue(int row, int col, int value);

    bool loadFromFile(const string& filename);
    void display() const;

    Matrix& operator=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;
private:
    void initialize();
    void cleanup();
};

#endif