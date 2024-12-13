#include <iostream>
using namespace std;

class NQueen {
private:
    int N;
    int* board;
    bool isSafe(int row, int col) 
    {
        for (int i = 0; i < col; i++) //No two queen in same row
        {
            if (board[i] == row)
            {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) //Upper Diagonal
        {
            if (board[j] == i)
            {
                return false;
            }
        }

        for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        {
            if (board[j] == i)
            {
                return false;
            }
        }

        return true;
    }

    bool solve(int col) 
    {
        if (col >= N) //base case
        {
            return true;
        }

        for (int i = 0; i < N; i++) 
        {
            if (isSafe(i, col)) 
            {
                board[col] = i;

                if (solve(col + 1))
                {
                    return true;
                }

                board[col] = -1;
            }
        }

        return false;
    }

public:
    NQueen(int n) : N(n) 
    {
        board = new int[N];
        for (int i = 0; i < N; i++)
            board[i] = -1;
    }

    ~NQueen() 
    {
        delete[] board;
    }

    void solveNQueens() 
    {
        if (solve(0)) 
        {
            cout << "Solution found:" << endl;
            printSolution();
        } 
        else 
        {
            cout << "No solution exists" << endl;
        }
    }

    void printSolution() 
    {
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                if (board[j] == i)  
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }
};

int main() 
{
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;
    
    if (n < 4) {
        cout << "N should be at least 4." << endl;
        return 1;
    }

    NQueen nQueen(n);
    nQueen.solveNQueens();

    return 0;
}