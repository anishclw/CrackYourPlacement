class Solution {
    int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0, n = arr.size();
        stack<pair<int, int>> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && s.top().second > arr[i]) {
                int j = s.top().first, num = s.top().second;
                s.pop();
                int l, r = i - j;
                if(s.empty()) l = j + 1;
                else l = j - s.top().first;
                ans = (ans + (int)(((long)num * l % mod) * r % mod)) % mod;  
            }
            s.push({i, arr[i]});
        }
        while(!s.empty()) {
            int j = s.top().first, num = s.top().second;
            s.pop();
            int l, r = n - j;  
            if(s.empty()) l = j + 1;
            else l = j - s.top().first;
            ans = (ans + (int)(((long)num * l % mod) * r % mod)) % mod; 
        }
        return ans;
    }
};