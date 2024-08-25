class Solution {
public:
    int dp[13][10002];
    int solve(int idx,vector<int>& coins, int amount, int n) {
        if(idx >= n) {
            if(amount == 0)return 0;
            else return 1e9;
        }
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        
        int ans = INT_MAX;
        if(coins[idx]<=amount){
            ans = 1 + solve(idx,coins,amount-coins[idx],n);
        }
        ans = min(ans,solve(idx+1,coins,amount,n));
        return dp[idx][amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,coins,amount,n);
        return ans==1e9?-1:ans;
    }
};