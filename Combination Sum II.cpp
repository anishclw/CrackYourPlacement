class Solution {
public:
    void comb(vector<vector<int>>& res, vector<int>& temp, vector<int>& c, int t, int idx){
        if(t<0)return;
        if(t==0){
            res.push_back(temp);
            return ;
        }
        
        for(int i=idx; i<c.size(); ++i){
            if(i!=idx && (c[i] == c[i-1])){
                continue;
            }
            int num = c[i];
            temp.push_back(num);
            comb(res, temp, c, t-num, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(target == 0)return {{}};
        
        sort(begin(candidates), end(candidates));
        
        vector<vector<int>> res;
        vector<int> temp;
        comb(res, temp, candidates, target, 0);
        
        return res;
    }
};