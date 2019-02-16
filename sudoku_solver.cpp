#include <iostream>
#include <vector>
#include <cmath>

class Solution
{
  public:
    bool IsValidValue(std::vector<std::vector<char>> &board, int row,
                      int col, char value)
    {

        // check row constraints
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == value)
            {
                return false;
            }
        }

        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][col] == value)
            {
                return false;
            }
        }

        int regionSize = std::sqrt(board.size());
        int rowFactor = row / regionSize;
        int colFactor = col / regionSize;

        for (int i = 0; i < regionSize; i++)
        {
            for (int j = 0; j < regionSize; j++)
            {
                if (board[rowFactor * regionSize + i][colFactor * regionSize + j] == value)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool solveSudokuHelper(std::vector<std::vector<char>> &board,
                           int row, int col)
    {

        if (row == board.size())
        {
            row = 0;
            if (++col == board[row].size())
            {
                return true;
            }
        }

        if (board[row][col] != '.')
        {
            return solveSudokuHelper(board, row + 1, col);
        }

        for (int val = 1; val <= board.size(); val++)
        {
            int c = '0' + val;
            if (IsValidValue(board, row, col, c))
            {
                board[row][col] = c;
                if (solveSudokuHelper(board, row + 1, col))
                {
                    return true;
                }
            }
        }

        board[row][col] = '.';
        return false;
    }

    void solveSudoku(std::vector<std::vector<char>> &board)
    {
        if (board.empty())
        {
            return;
        }

        solveSudokuHelper(board, 0, 0);
    }
};

int main()
{
    // std::vector<std::vector<char>> sudoku{
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    // std::vector<std::vector<char>> sudoku{
    //     {'6', '.', '.', '.', '.', '.', '.', '5', '.'},
    //     {'.', '9', '.', '8', '3', '.', '4', '.', '.'},
    //     {'4', '5', '8', '.', '.', '6', '.', '.', '.'},
    //     {'7', '4', '.', '.', '.', '.', '6', '3', '.'},
    //     {'.', '.', '.', '6', '5', '7', '.', '.', '.'},
    //     {'.', '6', '9', '.', '.', '.', '.', '7', '8'},
    //     {'.', '.', '.', '4', '.', '.', '3', '6', '2'},
    //     {'.', '.', '6', '.', '7', '2', '.', '8', '.'},
    //     {'.', '3', '.', '.', '.', '.', '.', '.', '9'}};

    std::vector<std::vector<char>> sudoku{
        {'7', '3', '.', '.', '.', '.', '.', '1', '.'},
        {'8', '.', '.', '.', '.', '5', '.', '.', '.'},
        {'.', '.', '.', '3', '6', '.', '9', '.', '.'},
        {'.', '.', '.', '2', '.', '.', '.', '7', '4'},
        {'.', '.', '.', '.', '.', '.', '5', '.', '.'},
        {'6', '.', '9', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '3', '.', '6', '.', '.'},
        {'5', '.', '3', '8', '.', '.', '.', '.', '.'},
        {'.', '4', '.', '.', '.', '7', '8', '2', '.'}};

    Solution c;

    c.solveSudoku(sudoku);

    for (auto i = 0; i < sudoku.size(); i++)
    {
        for (auto j = 0; j < sudoku.size(); j++)
        {
            std::cout << sudoku[i][j] << ' ';
        }

        std::cout << '\n';
    }
}