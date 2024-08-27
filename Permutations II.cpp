class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums,map<int,int> &mp,vector<int> temp) {
        if(temp.size()==nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(auto i:mp) {
            if(i.second>0) {
                mp[i.first]--;
                temp.push_back(i.first);
                solve(nums,mp,temp);
                temp.pop_back();
                mp[i.first]++;
            }
        }
        
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        vector<int> temp;
        solve(nums,mp,temp);
        return ans;
    }
};