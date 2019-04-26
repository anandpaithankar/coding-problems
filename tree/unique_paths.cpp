#include "algo.h"

int uniquePaths(int m, int n)
{
    int mat[m + 1][n + 1];
    memset(mat, 0, sizeof(m + 1 * n + 1));
    mat[m - 1][n] = 1;
    for (int r = m - 1; r >= 0; r--)
    {
        for (int c = n - 1; c >= 0; c--)
        {
            mat[r][c] = mat[r + 1][c] + mat[r][c + 1];
        }
    }
    return mat[0][0];
}

int main()
{
    std::cout << uniquePaths(2, 3);
}