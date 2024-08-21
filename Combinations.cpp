class Solution {
public:
    vector<vector<int>> ans;
    void f(int n, int k, int idx, vector<int> &temp)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        if(idx>n)return;
        temp.push_back(idx);
        f(n,k,idx+1,temp);
        temp.pop_back();
        f(n,k,idx+1,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
       f(n,k,1,temp);
        return ans;
    }
};