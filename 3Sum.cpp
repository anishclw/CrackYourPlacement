#include <bits/stdc++.h>

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() <= 2)
            return ans;

        sort(nums.begin(), nums.end());
        set<vector<int>> s;

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue; // optimization step
            }
            int sum = nums[i], start = i + 1, end = nums.size() - 1;
            while (start < end)
            {
                int triplet = sum + nums[start] + nums[end];
                if (triplet == 0)
                    s.insert({sum, nums[start++], nums[end--]});
                else if (triplet < 0)
                    ++start;
                else
                    --end;
            }
        }

        for (const auto &i : s)
            ans.push_back(i);
        return ans;
    }
};