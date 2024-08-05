class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        // Code here
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int s =0;
        int days=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    grid[i][j] =0;
                }
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty())
        {
            int k = q.size();
            s +=k;
            while(k--)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                   int  nx = x+dx[i], ny = y+dy[i];
                   if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1)
                   {
                       grid[nx][ny]=0;
                       q.push({nx,ny});
                   }
                }
            }
           
            
         days++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return days==-1?0:days;
    }
};