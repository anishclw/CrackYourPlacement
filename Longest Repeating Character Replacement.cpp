class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int i=0,j=0;
        
        unordered_map<char,int>mp;
        int ans=INT_MIN;
        int maxOcc=INT_MIN;
        
        while(j<n){
         mp[s[j]]++;
            
            maxOcc=max(maxOcc,mp[s[j]]);
            int ws=j-i+1;
            
            if(ws-maxOcc <=k){
                ans=max(ans,ws);
                j++;
            }
            else{
                mp[s[i]]--;
                i++,j++;
            }   
        }
        return ans;
    }
};