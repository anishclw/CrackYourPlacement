class Solution {
public:
    vector<vector<string>> ans;
    bool isPalin(string &s) {
        int n = s.size();
        for(int i=0;i<s.size();i++) {
            if(s[i] != s[n-i-1]) {
                return false;
            }
        }
        return true;
    }
    void solve(string &s, int idx, vector<string>temp) {
        if(idx == s.size()) {
            ans.push_back(temp);
             return;
        }
        
        for(int i = idx; i<s.size();i++) {
            string str = s.substr(idx,i-idx+1);
            if(isPalin(str)) {
                temp.push_back(str);
                solve(s,i+1,temp);
                temp.pop_back();
            }
        }
        
        // solve(s,idx+1,temp);
        // temp.pop_back();
        
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s,0,temp);
        return ans;
    }
};