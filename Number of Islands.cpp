class Solution {
public:
    int row_dir[4] ={0,0,-1,1};
    int col_dir[4] = {-1,1,0,0};
     bool isSafe(vector<vector<char>>& grid, int m, int n, int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n && (grid[row][col] == '1');
    }
    void dfs(vector<vector<char>>& grid, int m, int n, int row, int col){
        grid[row][col]='0';
        for(int i=0;i<4;i++)
        {
            if(isSafe(grid,m,n,row + row_dir[i],col + col_dir[i])){
                dfs(grid,m,n,row + row_dir[i],col + col_dir[i]);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(grid[i][j]=='1'){
                  dfs(grid,m,n,i,j);
                  count++;
              }
          }  
        }
        return count;
        
    }
};