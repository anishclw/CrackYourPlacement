class Solution {
public:
    int dirx[4] = {0,0,-1,1};
    int diry[4] = {-1,1,0,0};
    bool isSafe (int row, int col, int m, int n, vector<vector<int>>& image) {
        return row>=0 and row<m and col>=0 and col<n;
    }
    void solve(int row, int col,vector<vector<int>>& image,int &m, int &n, int &color) {
        int prevcol = image[row][col];
        image[row][col] = color;
        for(int i=0;i<4;i++) {
            int x = row + dirx[i];
            int y = col + diry[i];
            if(isSafe(x,y,m,n,image) and image[x][y] == prevcol) {
                solve(x,y,image,m,n,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        if(image[sr][sc]==color)return image;
        if(isSafe(sr,sc,m,n,image)) {
            solve(sr,sc,image,m,n,color);
        }
        return image;
    }
};