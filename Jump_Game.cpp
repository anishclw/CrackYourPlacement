#include<bits/stdc++.h>
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;
        for(int i=0;i<n;i++)
        {
            if(reachable<i)return false;
            if(reachable<nums[i]+i) reachable = nums[i] +i;
        }
        return true;
    }
};