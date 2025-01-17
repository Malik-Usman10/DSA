#include "FloodFill.h"
#include <queue>

void FloodFill::fillDFS(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];
    if (originalColor != newColor) {
        dfsHelper(image, sr, sc, newColor, originalColor);
    }
}

void FloodFill::dfsHelper(std::vector<std::vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
    if (!isValid(image, sr, sc, originalColor, newColor)) return;

    image[sr][sc] = newColor;

    dfsHelper(image, sr - 1, sc, newColor, originalColor); // Up
    dfsHelper(image, sr + 1, sc, newColor, originalColor); // Down
    dfsHelper(image, sr, sc - 1, newColor, originalColor); // Left
    dfsHelper(image, sr, sc + 1, newColor, originalColor); // Right
}

void FloodFill::fillBFS(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];
    if (originalColor == newColor) return;

    int rows = image.size();
    int cols = image[0].size();
    std::queue<std::pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty()) {
        auto [currentRow, currentCol] = q.front();
        q.pop();

        if (!isValid(image, currentRow, currentCol, originalColor, newColor)) continue;

        image[currentRow][currentCol] = newColor;

        q.push({currentRow - 1, currentCol}); // Up
        q.push({currentRow + 1, currentCol}); // Down
        q.push({currentRow, currentCol - 1}); // Left
        q.push({currentRow, currentCol + 1}); // Right
    }
}

bool FloodFill::isValid(std::vector<std::vector<int>>& image, int row, int col, int originalColor, int newColor) {
    int rows = image.size();
    int cols = image[0].size();
    return row >= 0 && row < rows && col >= 0 && col < cols && image[row][col] == originalColor;
}
