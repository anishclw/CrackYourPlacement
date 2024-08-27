class Solution {
public:
bool isvalid( vector< string > &grid, int row, int col)
{

for( int i=row;i>=0;i--)
if(grid[i][col]=='Q')return false;

  
for( int i=row,j=col;i>=0 and j>=0;i--,j--)
        if(grid[i][j]=='Q')return false;
    
   
for( int i=row,j=col;i>=0 and j<grid.size();i--,j++)
        if(grid[i][j]=='Q')return false; 
    
    return true;
}

void dfs(  vector< string > &grid, int row, vector< vector< string > > &ans)
{
   if(row==grid.size())  
   {
       ans.push_back(grid);  
       return;
   }
   for( int col=0;col<grid.size();col++){ 
       if(isvalid(grid,row,col))  
       {
           grid[row][col]='Q';    
           dfs(grid,row+1,ans);   
           grid[row][col]='.';    
           
       }
   }   
    
}
vector<vector<string>> solveNQueens(int n) {
    
   vector< string >  grid( n,string(n,'.'));  
   vector< vector< string > > ans;
    dfs(grid,0,ans);
    return ans;
}
};