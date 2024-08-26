class Solution {
public:
    unordered_map<int,bool> mp;
    bool solve(int idx, int k, vector<int> &stones,int &n,map<pair<int,int>,bool> &memo) {
        if(mp.find(idx)==mp.end() || idx > stones[n-1])return false;
        if(idx==stones[n-1]) return true;
        if(memo.find({idx,k})!=memo.end()) return memo[{idx,k}];

        bool ans;
        if(idx==0) {
            ans = solve(idx+1,1,stones,n,memo);
        }
        else {
            if(k-1>0) {
                ans |= solve(idx+k-1,k-1,stones,n,memo);
            }
            ans |= solve(idx+k,k,stones,n,memo);
            ans |= solve(idx+k+1,k+1,stones,n,memo);
        }

        return memo[{idx,k}]=ans;
    }
    bool canCross(vector<int>& stones) {
        for(auto it:stones) {
            mp[it] = true;
        }
        map<pair<int,int>,bool> memo;
        int n = stones.size();
        return solve(0,1,stones,n,memo);
    }
};