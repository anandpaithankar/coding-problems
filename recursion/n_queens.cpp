#include <iostream>
#include <vector>
bool isUnderAttack(const std::vector<std::vector<int>> &board, int row, int col)
{
    int i, j;
    std::cout << "\n Under attack check a queen at row = " << row << " col = " << col;
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return true;

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return true;

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < board.size(); i++, j--)
        if (board[i][j])
            return true;

    return false;
}

bool nQueens(std::vector<std::vector<int>> &board, int col)
{
    if (col == board.size())
    {
        return true;
    }

    for (int row = 0; row < board.size(); row++)
    {
        if (!isUnderAttack(board, row, col))
        {
            board[row][col] = 1;
            std::cout << "\n Placing a queen at row = " << row << " col = " << col;
            if (nQueens(board, col + 1))
            {
                return true;
            }
            board[row][col] = 0;
            std::cout << "\n Erasing a queen at row = " << row << " col = " << col;
        }
    }
    return false;
}

// driver program to test above function
int main()
{
    std::vector<std::vector<int>> board{{0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0}};

    // std::vector<std::vector<int>> board{{0, 0, 0},
    //                                     {0, 0, 0},
    //                                     {0, 0, 0},
    //                                     {0, 0, 0}};

    if (nQueens(board, 0) == false)
    {
        printf("Solution does not exist");
    }
    else
    {
        std::cout << "\nFinal placement ";
        for (auto r = 0; r < board.size(); r++)
        {
            for (auto c = 0; c < board.size(); c++)
            {
                std::cout << board[r][c] << " ";
            }
            std::cout << "\n";
        }
    }
    return 0;
}
