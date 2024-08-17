class Solution {
public:
    int foo(int n, vector<int> &dp) {
        if(n == 1 || n == 0)return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = foo(n-1, dp) + foo(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        int ans = foo(n, dp);
        return ans;
    }
};