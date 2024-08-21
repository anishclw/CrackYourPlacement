class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> s;
        if(num.size()==0){
            return ans;
        }
        s.push(num[0]);
        for(int i= 1;i<num.length();i++){
            while(!s.empty() && s.top()>num[i] && k>0){
                k--;
                s.pop();
            }
            s.push(num[i]);
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }
        
        while(!s.empty() && k>0){
            k--;
            s.pop();
        }
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return (ans == "")? "0":ans;
        
    }
};