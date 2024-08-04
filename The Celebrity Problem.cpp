class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
   int celebrity(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();
    vector<int> knows_me(n, 0), i_know(n, 0);
 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j])
            {
                knows_me[j]++;
                i_know[i]++;
            }
        }
    }
 

    int celebrity = -1;
    for (int i = 0; i < n; i++)
    {
        if (knows_me[i] == n - 1 && i_know[i] == 0){
            celebrity = i;
            break; // as we know there will be one celebrity always. Two or more is not possible 
             }
    }
 

    return celebrity;
}
 
};