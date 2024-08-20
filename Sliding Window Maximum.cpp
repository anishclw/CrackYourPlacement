class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> m;
        vector<int> v;
        int n = nums.size();
        for(int i=0;i<k;i++) {
            m.insert(nums[i]);
        }
        int num = *m.rbegin();
        v.push_back(num);
        for(int i=k;i<n;i++) {
            m.erase(m.find(nums[i-k]));
            m.insert(nums[i]);
            v.push_back(*m.rbegin());
        }
        
        return v;
    }
};