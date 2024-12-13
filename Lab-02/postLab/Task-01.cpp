//the time complexity BigO(2^n^2) wrost case all 1 in maze
//the space complexity BigO(n^2) the longest path


#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int n; //fro size of maze as we cannot add it int he function params

bool isValidMove(int** maze, int x, int y) 
{
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

bool ratInMaze(int** maze, int x, int y, int targetX, int targetY, int** sol) 
{
    //base case for terminate
    if (x == targetX && y == targetY) 
    {
        sol[x][y] = 1;
        return true;
    }

    if (isValidMove(maze, x, y)) 
    {
        sol[x][y] = 1;  // Mark the cell as part of the solution path

        // Move right
        if (ratInMaze(maze, x, y + 1, targetX, targetY, sol)) return true;

        // Move down
        if (ratInMaze(maze, x + 1, y, targetX, targetY, sol)) return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}

void printMaze(int** maze) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}
//Function for setting up the maze
void setupMaze(int** maze) 
{
    cout << "Enter the maze values row by row (0 for blocked, 1 for open):\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            int value;
            while (true) 
            {
                cout << "Enter value for cell (" << i << "," << j << ") [0 or 1]: ";
                cin >> value;
                // Input validation
                if (cin.fail() || (value != 0 && value != 1)) 
                {
                    cout << "Invalid input, please enter 0 or 1.\n";
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                } 
                else 
                {
                    maze[i][j] = value;
                    break;
                }
            }
        }
    }
}

int main() 
{
    cout << "Enter the size of the maze (n x n): ";
    while (true) 
    {
        cin >> n;
        if (cin.fail() || n <= 0) 
        {
            cout << "Invalid input, please enter a positive integer for the size of the maze.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 
        else 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break;
        }
    }

    int** maze = new int*[n];
    int** sol = new int*[n];
    for (int i = 0; i < n; i++) 
    {
        maze[i] = new int[n]();
        sol[i] = new int[n]();
    }

    setupMaze(maze);

    if (ratInMaze(maze, 0, 0, n - 1, n - 1, sol)) 
    {
        cout << "\nMaze input:\n";
        printMaze(maze);
        cout << "\nSolution Path:\n";
        printMaze(sol);
    } 
    else 
    {
        cout << "No path found!\n";
    }

    for (int i = 0; i < n; i++) 
    {
        delete[] maze[i];
        delete[] sol[i];
    }
    delete[] maze;
    delete[] sol;
}
