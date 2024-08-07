class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()){
                    if(s[i] == st.top().first){
                        st.top().second +=1;
                    if(st.top().second == k){
                        st.pop();
                    }
                }
                else{
                    st.push({s[i],1});
                }
            }
            else{
                st.push({s[i],1});
            }
            
        }
        string ans ="";
        while(!st.empty()) {
            while(st.top().second--){
                ans += st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};