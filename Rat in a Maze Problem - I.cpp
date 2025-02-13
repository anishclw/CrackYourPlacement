class Solution {
  public:
   void help(vector<vector<int>> &mat, int i, int j,
              int n, vector<string> &ans, string temp)
    {
        if(i < 0 || j < 0 || i == n || j == n || mat[i][j] == 0)
            return;
        if(i == n-1 && j == n-1)
        {
            ans.push_back(temp);
            return;
        }
        mat[i][j] = 0;
        help(mat,i-1,j,n,ans,temp+'U');
        help(mat,i+1,j,n,ans,temp+'D');
        help(mat,i,j+1,n,ans,temp+'R');
        help(mat,i,j-1,n,ans,temp+'L');
        mat[i][j] = 1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &mat) 
    {
        vector<string> ans;
        int n = mat.size();
        if(mat[n-1][n-1] == 0)
            return ans;
        if(mat[0][0] == 1)
            help(mat,0,0,n,ans,"");
        return ans;
        // Your code goes here
    }
};