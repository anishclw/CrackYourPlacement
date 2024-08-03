class Solution {
public:

    bool canWePlace(vector<int> &arr, int n, int cows, int mid)
    {
        int cntCows = 1, last = arr[0];
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] - last >= mid)
            {
                cntCows++;
                last = arr[i];
            }
        }
        
        return cntCows >= cows;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        
        // Ans lies in between 1 and difference between (maximum and minimum element)
        // Applying Binary search
        
        int low = 1, high = stalls[n-1]-stalls[0];
        int ans = -1;
        
        while(low <= high)
        {
            int mid = low+(high-low)/2;
            
            if(canWePlace(stalls, n, k, mid))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return ans;
    }
};