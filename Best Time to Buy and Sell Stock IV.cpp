class Solution {
public:
      int solve(vector<int>& prices, int idx, bool haveBought, int maxSell, vector<vector<vector<int>>> &dp) {
        if(idx == prices.size() || maxSell <= 0) return 0;
        if(dp[idx][haveBought][maxSell] != -1) return dp[idx][haveBought][maxSell];
        int a, b, c, d;
        a = b = c = d = 0;
        if(haveBought == false) { // wanna buy
            // buy today
            a = solve(prices, idx+1, !haveBought, maxSell, dp) - prices[idx];
            // buy another day
            b = solve(prices, idx+1, haveBought, maxSell, dp);
        } else { // wanna sell
            // sell today
            c = solve(prices, idx+1, !haveBought, maxSell-1, dp) + prices[idx];
            // sell another day
            d = solve(prices, idx+1, haveBought, maxSell, dp);
        }
        return dp[idx][haveBought][maxSell] = max(max(a,b), max(c, d));
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(k+1,vector<int>(k+1,-1)));
        return solve(prices, 0, false, k, dp);
        
    }
};