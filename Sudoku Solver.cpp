class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col, char ch)
    {
        int R = 0, C = 0;
        for(int i=0;i<9;i++)
        {
            R = 3 * (row/3) + i/3;
            C = 3 * (col/3) + i%3;
            if(board[row][i]==ch)return false;
            if(board[i][col]==ch)return false;
            if(board[R][C]==ch)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++)
        {
            for(int j =0;j<board[0].size();j++)
            {
                if(board[i][j] == '.')
                {
                    for(char ch = '1';ch<='9';ch++)
                    {
                        if(issafe(board,i,j,ch)==true)
                        {
                             board[i][j] = ch;
                       
                        
                           if(solve(board)) return true;
                        
                        
                            board[i][j] = '.';
                        }
                       
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
};