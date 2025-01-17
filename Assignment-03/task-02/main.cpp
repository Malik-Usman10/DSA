#include "FloodFill.h"
#include <iostream>
#include <vector>
using namespace std;

void printImage(const vector<vector<int>>& image) 
{
    for (const auto& row : image) 
    {
        for (const auto& pixel : row) 
        {
            cout << pixel << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> image = 
    {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, newColor = 2;

    cout << "Original Image:\n";
    printImage(image);

    cout << "\nFlood Fill using DFS:\n";
    FloodFill::fillDFS(image, sr, sc, newColor);
    printImage(image);

    // Reset image for BFS test
    image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    cout << "\nFlood Fill using BFS:\n";
    FloodFill::fillBFS(image, sr, sc, newColor);
    printImage(image);

    return 0;
}
