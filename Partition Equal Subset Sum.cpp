class Solution{
public:
    bool solve(int N, int arr[],int index, int target,vector<vector<int>> &dp){
        
        if(index >= N){
            return 0;
        }
        
        if(target < 0)
            return 0;
            
        if(target == 0)
            return 1;
            
        if(dp[index][target] != -1)  {
            return dp[index][target];
        }  
            
        bool incl = solve(N,arr,index+1,target- arr[index],dp);
        bool excl = solve(N,arr,index+1,target,dp);
        
        dp[index][target] = incl||excl;
        
        return dp[index][target];
        
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum =0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum&1)
            return 0;
            
        int target = sum/2;
        vector<vector<int>> dp(N+1,vector<int>(target+1,-1));
        
        return solve(N, arr, 0, target,dp)?1:0;
    }
};