#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <vector>
#include "Matrix.h"

struct Element {
    int row;
    int col;
    int value;
    Element(int r, int c, int v) : row(r), col(c), value(v) {}
};

class SparseMatrix {
private:
    vector<Element> elements;
    int rows;
    int cols;
    int nonZeroCount;

public:
    SparseMatrix(int numRows = 0, int numCols = 0);
    
    void setValue(int row, int col, int value);
    int getValue(int row, int col) const;
    bool loadFromFile(const string& filename);
    void display() const;
    
    static SparseMatrix fromMatrix(const Matrix& matrix);
    
    SparseMatrix operator+(const SparseMatrix& other) const;
};

#endif