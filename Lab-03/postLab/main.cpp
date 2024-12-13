// g++ main.cpp matrix.cpp sparseMatrix.cpp -o main
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include "Matrix.h"
#include "SparseMatrix.h"

void clearInputBuffer() 
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string getFilename(const string& matrixNumber) 
{
    string filename;
    cout << "Enter the filename for matrix " << matrixNumber << ": ";
    getline(cin, filename);
    return filename;
}

bool getDimensions(const string& filename, int& rows, int& cols) 
{
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Unable to open file: " + filename);
    }

    string line;
    rows = 0;
    cols = 0;
    
    // Get the first line to determine number of columns
    if (getline(file, line)) 
    {
        istringstream iss(line);
        int value;
        while (iss >> value) 
        {
            cols++;
        }
        rows = 1;
    }

    // Count remaining rows
    while (getline(file, line)) 
    {
        if (!line.empty()) 
        { 
            rows++;
            // Verify that each row has the same number of columns
            istringstream iss(line);
            int col_count = 0;
            int value;
            while (iss >> value) 
            {
                col_count++;
            }
            if (col_count != cols) 
            {
                throw runtime_error("Inconsistent number of columns in file: " + filename);
            }
        }
    }

    file.close();
    return true;
}

int main() {
    try {
        cout << "Welcome to Sparse Matrix Calculator\n";
        cout << "===================================\n\n";

        string filename1 = getFilename("1");
        string filename2 = getFilename("2");

        int rows1, cols1;
        if (!getDimensions(filename1, rows1, cols1)) 
        {
            throw runtime_error("Error determining matrix dimensions from " + filename1);
        }

        int rows2, cols2;
        if (!getDimensions(filename2, rows2, cols2)) 
        {
            throw runtime_error("Error determining matrix dimensions from " + filename2);
        }

        if (rows1 != rows2 || cols1 != cols2) 
        {
            throw runtime_error("Matrix dimensions are not compatible for addition");
        }

        Matrix matrix1(rows1, cols1);
        Matrix matrix2(rows2, cols2);
        
        cout << "\nLoading matrices from files...\n";
        
        if (!matrix1.loadFromFile(filename1)) 
        {
            throw runtime_error("Error loading matrix from " + filename1);
        }
        if (!matrix2.loadFromFile(filename2)) 
        {
            throw runtime_error("Error loading matrix from " + filename2);
        }

        cout << "\nConverting to sparse format...\n";
        SparseMatrix sparse1 = SparseMatrix::fromMatrix(matrix1);
        SparseMatrix sparse2 = SparseMatrix::fromMatrix(matrix2);

        cout << "\nMatrix 1 (from " << filename1 << "):\n";
        matrix1.display();
        
        cout << "\nMatrix 2 (from " << filename2 << "):\n";
        matrix2.display();

        // Perform addition and display result
        cout << "\nPerforming matrix addition...\n";
        cout << "Result of matrix addition:\n";
        SparseMatrix result = sparse1 + sparse2;
        result.display();

    } catch (const exception& e) 
    {
        cerr << "\nError: " << e.what() << endl;
        return 1;
    }
}