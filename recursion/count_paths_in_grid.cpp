#include <iostream>

// Count all paths in a grid moving right or down.
int countPaths(std::vector<std::vector<int> > &grid, int row, int col) {
    if (row == grid.size()-1 && col == grid[0].size()-1) {
        return 1;
    }

    if (row >= grid.size() || col >= grid.size()) {
        return 0;
    }

    int numRightPaths = countPaths(grid, row, col+1);
    int numDownPaths = countPaths(grid, row+1, col);
    return numRightPaths + numDownPaths;
}


int main() {
    std::vector<std::vector<int>> grid;
    grid.resize(10);
    grid[0].resize(10);

    std::cout << "Number of paths "<< countPaths(grid, 0, 0);

}
