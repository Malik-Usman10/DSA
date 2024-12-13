#include "sparseMatrix.h"
#include <iostream>
using namespace std;


int main() 
{
    SparseMatrixADT<int> matrix1(4, 4);
    matrix1.SetValue(0, 0, 5);  
    matrix1.SetValue(1, 1, 10);
    matrix1.SetValue(2, 3, 15);
    matrix1.SetValue(3, 3, 20);

    int diagonalSum = matrix1.RecursiveDiagonalSum(0);
    cout << "Sum of diagonal elements: " << diagonalSum << endl;

    SparseMatrixADT<int> matrix2(3, 3);
    matrix2.SetValue(0, 1, 2);
    matrix2.SetValue(1, 2, 3);
    matrix2.SetValue(2, 0, 4);

    SparseMatrixADT<int> transposedMatrix = matrix2.Transpose();
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << transposedMatrix.GetValue(i, j) << " ";
        }
        cout << endl;
    }

    SparseMatrixADT<int> matrix3(2, 2);
    SparseMatrixADT<int> matrix4(2, 2);
    matrix3.SetValue(0, 0, 1); 
    matrix3.SetValue(0, 1, 2);
    matrix4.SetValue(0, 0, 3);
    matrix4.SetValue(1, 0, 4); 

    SparseMatrixADT<int> result = matrix3.Multiply(matrix4);
    cout << "Resulting Matrix after Multiplication:" << endl;
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            cout << result.GetValue(i, j) << " ";
        }
        cout << endl;
    }
}