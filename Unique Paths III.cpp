class Solution {
public:
    ////////////// D  U  L   R
    int x_dir[4] = {1, -1, 0, 0};
    int y_dir[4] = {0, 0, -1, 1};
    int ans = 0;
    
    bool isSafe(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
    
    void solve(vector<vector<int>>& grid, int row, int col, int m, int n, int zeros) {
        if(grid[row][col] == 2) {
            if(zeros == 0) ans++;
            return;
        }
        if(isSafe(row, col, m, n) && grid[row][col] >= 0) {
            grid[row][col] = -2;
            for(int i=0; i<4; i++) {
                if(isSafe(row+x_dir[i], col+y_dir[i], m, n))
                    solve(grid, row+x_dir[i], col+y_dir[i], m, n, zeros-1);
            }
            grid[row][col] = 0;
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int zeros = 0;
        int x, y;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) zeros++;
                else if(grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        solve(grid, x, y, m, n, zeros+1);
        return ans;
    }
};