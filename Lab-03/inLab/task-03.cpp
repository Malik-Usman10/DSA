#include <iostream>
using namespace std;

class twoDArray
{
private:
    int *data;
    int rows, cols;
public:
    twoDArray(int r, int c) : rows(r), cols(c)
    {
        data = new int[rows * cols];
    }

    ~twoDArray()
    {
        delete[] data;
    }
    
    int getOneDIndex(int i, int j) const
    {
        return i + j * rows;
    }
    void setIndex(int i, int j, int value)
    {
        data[getOneDIndex(i,j)] = value;
    }
    int getIndex(int i, int j) const 
    {
        return data[getOneDIndex(i,j)];
    }
    void printArray() const 
    {
        for(int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << getOneDIndex(i,j) << " ";
            }
            cout << endl;
        }
    }

};

int main()
{
    int rows = 3, cols = 3;
    twoDArray arr(rows,cols);

    arr.setIndex(0, 0, 0);
    arr.setIndex(0, 1, 1);
    arr.setIndex(0, 2, 2);
    arr.setIndex(1, 0, 3);
    arr.setIndex(1, 1, 4);
    arr.setIndex(1, 2, 5);
    arr.setIndex(2, 0, 6);
    arr.setIndex(2, 1, 7);
    arr.setIndex(2, 2, 8);

    cout << "Array is: " << endl;
    arr.printArray();
}