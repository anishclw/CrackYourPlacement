class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // return solve(0,-1,nums, dp);
        vector<int> dp(n,1);
        int maxe = 0;
        for(int i = 0;i<n;i++){
            for(int prev = 0;prev < i; prev++){
                if(nums[prev]<nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxe = max(maxe,dp[i]);
        }
        for(int i=0;i<dp.size();i++){
            cout << dp[i] << " ";
        }
        return maxe;
    }
};