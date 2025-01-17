#ifndef FLOODFILL_HPP
#define FLOODFILL_HPP

#include <vector>

class FloodFill {
public:
    static void fillDFS(std::vector<std::vector<int>>& image, int sr, int sc, int newColor);
    static void fillBFS(std::vector<std::vector<int>>& image, int sr, int sc, int newColor);

private:
    static void dfsHelper(std::vector<std::vector<int>>& image, int sr, int sc, int newColor, int originalColor);
    static bool isValid(std::vector<std::vector<int>>& image, int row, int col, int originalColor, int newColor);
};

#endif
