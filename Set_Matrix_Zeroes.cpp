#include <bits/stdc++.h>
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(); // no. of rows and columns
        vector<int> row;
        vector<int> col;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.push_back(i); // pushing the row having a zero element into a vector
                    col.push_back(j); // pushing the column having a zero element into a vector
                }
            }
        }
        for (int i = 0; i < row.size(); i++)
        { // traversing the row vector to set the rows to zero
            for (int j = 0; j < n; j++)
            {
                matrix[row[i]][j] = 0; // setting the row to zero
            }
        }
        for (int i = 0; i < col.size(); i++)
        { // traversing the row vector to set the rows to zero
            for (int j = 0; j < m; j++)
            {
                matrix[j][col[i]] = 0; // setting the column to zero
            }
        }
    }
};