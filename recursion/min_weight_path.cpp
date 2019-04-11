#include "algo.h"

int minPathSum(const vector<vector<int>> &grid, int row, int col, IntGrid &memo)
{
	if (row >= grid.size() || col >= grid[0].size())
	{
		return INT_MAX;
	}

	if (row == grid.size() - 1 && col == grid[0].size() - 1)
	{
		return grid[row][col];
	}

	if (memo[row][col] != INT_MAX)
	{
		return memo[row][col];
	}

	int val = std::min(minPathSum(grid, row + 1, col, memo), minPathSum(grid, row, col + 1, memo)) + grid[row][col];
	memo[row][col] = val;
	return val;
}

int minPathSum(vector<vector<int>> &grid)
{
	std::vector<std::vector<int>> memo(grid.size(), std::vector<int>(grid[0].size(), INT_MAX));
	return minPathSum(grid, 0, 0, memo);
}

int main()
{
	IntGrid grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	std::cout << minPathSum(grid);
}