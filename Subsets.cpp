class Solution {
public:
    vector<vector<int>>ans;
    void permute(int idx, vector<int> nums, vector<int>temp)
    {
        if(idx==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        permute(idx+1,nums,temp);
        temp.pop_back();
        permute(idx+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        permute(0,nums,temp);
        return ans;
    }
};