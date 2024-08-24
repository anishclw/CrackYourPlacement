class Solution {
public:
    int dp[601][101][101];
    int givesub(vector<pair<int, int>> &counts, int idx, int m, int n) {   
        if(m < 0 || n < 0) return -1e9 + 100;
        if(idx < 0 ) return 0;
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        
        int nzero = counts[idx].first;
        int nones = counts[idx].second;
        int ans1 = 0, ans2 = 0;
        
        ans1 = 1 + givesub(counts, idx - 1, m-nzero, n-nones); // take
        ans2 = givesub(counts, idx-1, m, n); // not take
        
        return dp[idx][m][n] = max(ans1, ans2);
    } 
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        vector<pair<int, int>> counts;
        
        for(auto it:strs){
            int zeros = 0, ones = 0;
            for(int i = 0; i<it.size(); i++){
                if(it[i] == '0') zeros++;
                else ones++;
            }
            if(zeros > m || ones > n) continue;
            counts.push_back({zeros, ones});
        }
        
        return givesub(counts, counts.size() - 1, m, n);
    }
};