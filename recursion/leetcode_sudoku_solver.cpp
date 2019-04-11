class Solution
{
  public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &row,
             vector<vector<bool>> &col, vector<vector<bool>> &cell,
             int x, int y, bool &flag)
    {

        if (x == 9)
        {
            flag = true;
            return;
        }

        if (board[x][y] == '.')
        {
            for (int i = 1; i <= 9; i++)
            {
                if (row[x][i] == true)
                    continue;
                if (col[y][i] == true)
                    continue;
                if (cell[(x / 3) * 3 + y / 3][i] == true)
                    continue;

                row[x][i] = col[y][i] =
                    cell[(x / 3) * 3 + y / 3][i] = true;

                board[x][y] = i + '0';

                if (y == 8)
                    dfs(board, row, col, cell, x + 1, 0, flag);
                else
                    dfs(board, row, col, cell, x, y + 1, flag);

                if (flag == true)
                    return;

                row[x][i] = col[y][i] =
                    cell[(x / 3) * 3 + y / 3][i] = false;

                board[x][y] = '.';
            }
        }
        else
        {
            if (y == 8)
                dfs(board, row, col, cell, x + 1, 0, flag);
            else
                dfs(board, row, col, cell, x, y + 1, flag);
        }
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> cell(9, vector<bool>(10, false));

        bool flag = false;

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int temp = board[i][j] - '0';

                    row[i][temp] = col[j][temp] =
                        cell[(i / 3) * 3 + j / 3][temp] = true;
                }
            }

        dfs(board, row, col, cell, 0, 0, flag);
    }
};