#include <vector>
#include <utility>
#include <iostream>
using namespace std;

template <class T>
class SparseMatrixADT 
{
private:
    vector<pair<pair<int, int>, T>> elements;
    int rows;
    int cols;

public:
    SparseMatrixADT(int r, int c) : rows(r), cols(c) {}

    void SetValue(int row, int col, T value) 
    {
        if (value != T())
        { 
            elements.push_back({{row, col}, value});
        }
    }

    T GetValue(int row, int col) const 
    {
        for (const auto& element : elements) 
        {
            if (element.first.first == row && element.first.second == col) 
            {
                return element.second;
            }
        }
        return T();
    }

    T RecursiveDiagonalSum(int index) 
    {
        if (index >= min(rows, cols)) 
        {
            return T();
        }
        return GetValue(index, index) + RecursiveDiagonalSum(index + 1);
    }

    SparseMatrixADT<T> Transpose() const 
    {
        SparseMatrixADT<T> transposed(cols, rows);
        TransposeHelper(transposed, 0);
        return transposed;
    }

    SparseMatrixADT<T> Multiply(const SparseMatrixADT<T>& other) const 
    {
        if (cols != other.rows) 
        {
            throw invalid_argument("Matrix dimensions do not match for multiplication");
        }

        SparseMatrixADT<T> result(rows, other.cols);

        for (const auto& elem1 : elements) 
        {
            for (const auto& elem2 : other.elements) 
            {
                if (elem1.first.first == elem2.first.second) 
                {
                    int row = elem1.first.first;
                    int col = elem2.first.second;
                    T value = result.GetValue(row, col) + elem1.second * elem2.second;
                    result.SetValue(row, col, value);
                }
            }
        }
        return result;
    }

private:
    void TransposeHelper(SparseMatrixADT<T>& transposed, size_t index) const 
    {
        if (index >= elements.size()) 
        {
            return;
        }
        const auto& element = elements[index];
        transposed.SetValue(element.first.second, element.first.first, element.second);
        TransposeHelper(transposed, index + 1);
    }
};
