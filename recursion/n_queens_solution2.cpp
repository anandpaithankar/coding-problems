#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

bool isValid(std::vector<std::vector<char>> &grid, int row, int col)
{
    for (int r = 0; r < row; ++r)
    {
        if (grid[r][col] == 'q')
        {
            return false;
        }
    }

    for (int c = 0; c < col; c++)
    {
        if (grid[row][c] == 'q')
        {
            return false;
        }
    }

    // diagonal - upper left
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; --r, --c)
    {
        if (grid[r][c] == 'q')
        {
            return false;
        }
    }

    // diagonal - lower left
    for (int r = row + 1, c = col - 1; r < grid.size() && c >= 0; r++, c--)
    {
        if (grid[r][c] == 'q')
        {
            return false;
        }
    }

    // diagonal - upper right
    for (int r = row - 1, c = col + 1; r >= 0 && c < grid.size(); r--, c++)
    {
        if (grid[r][c] == 'q')
        {
            return false;
        }
    }

    // diagnoal - lower right
    for (int r = row + 1, c = col + 1; r < grid.size() && c < grid.size(); r++, c++)
    {
        if (grid[r][c] == 'q')
        {
            return false;
        }
    }

    return true;
}

bool placeNQueensRecur(std::vector<std::vector<char>> &grid, int n, int row)
{
    if (row == grid.size())
    {
        // we have successfully placed all queens.
        return true;
    }

    for (int c = 0; c < grid[0].size(); c++)
    {
        // place a queen
        grid[row][c] = 'q';
        std::cout << "Placed a queen at " << row << ", " << c << "\n";
        // check if the current placement is valid
        // Here we don't have to decrement n as we are not checking
        // n anywhere, so its redundant operation.

        // the placeNQueensRecur() method could return true or false.
        // True -
        //  1. If the all the queens have been successfully placed on
        //      all the rows. i.e. when base case is true!
        //  2. If each queens has been successfully placed on the row.
        //      The return true will be returned from the return inside
        //      the following if{}.
        //
        // False -
        //  1. If we have exhausted all the columns to place a queen
        //      in a given row and col.
        if (isValid(grid, row, c) && placeNQueensRecur(grid, n - 1, row + 1))
        {
            // we successfully placed a queen for this row, return.
            // this return value is also used by above recursive call.
            return true;
            // Base case hit -
            // Once the base case returns true, we'll get here and also
            // return true.
            // If we have to print all the permutations of the n-queens
            // placements then instead of the returning true, we can let
            // placement continue by increasing the colums in above for-loop.
            // We must erase earlier placements as we go down the stacks.
        }
        else
        {
            std::cout << "Erasing a queen from " << row << ", " << c << "\n";
            grid[row][c] = '-';
        }
    }
    return false;
}

void nQueens(int n)
{
    std::vector<std::vector<char>> grid(n);
    for (auto i = 0; i < n; ++i)
    {
        grid[i].resize(n, '-');
    }

    if (placeNQueensRecur(grid, n, 0))
    {
        std::cout << n << " queens have been placed successfully.\n";
    }

    // print grid
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    int n = 4;
    nQueens(n);
}