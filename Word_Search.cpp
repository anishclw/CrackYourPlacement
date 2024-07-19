#include <bits/stdc++.h>

class Solution
{
public:
    int row_dir[4] = {0, 0, -1, 1};
    int col_dir[4] = {-1, 1, 0, 0};

    bool isSafe(vector<vector<int>> &isVisited, int m, int n, int row, int col)
    {
        return row >= 0 && row < m && col >= 0 && col < n && (isVisited[row][col] == 0);
    }

    bool helper(vector<vector<char>> &board, vector<vector<int>> &isVisited, int m, int n, int row, int col, int idx, string word)
    {
        if (board[row][col] == word[idx])
        {
            isVisited[row][col] = 1;
            if (idx == word.length() - 1)
            {
                return true;
            }
            for (int i = 0; i < 4; i++)
            {
                if (isSafe(isVisited, m, n, row + row_dir[i], col + col_dir[i]))
                {
                    if (helper(board, isVisited, m, n, row + row_dir[i], col + col_dir[i], idx + 1, word))
                    {
                        return true;
                    }
                }
            }
            isVisited[row][col] = 0;
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> isVisited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (helper(board, isVisited, m, n, i, j, 0, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};