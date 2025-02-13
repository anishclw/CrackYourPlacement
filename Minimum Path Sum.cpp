class Solution {
public:
//     MEMO
    int m = 0;
    int n = 0;
    int solve(vector<vector<int>>& grid,vector<vector<int>>& memo,int i,int j){
        if(j==n-1 && i==m-1)return grid[i][j];
        if(j>=n || i>=m) return INT_MAX;
        if(memo[i][j]!=-1) return memo[i][j];
        int val1 = solve(grid,memo,i,j+1);  //Right
        int val2 = solve(grid,memo,i+1,j);  //Down
        int ans = min(val1,val2) + grid[i][j];
        memo[i][j] = ans;
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return solve(grid,memo,0,0);
    }
};