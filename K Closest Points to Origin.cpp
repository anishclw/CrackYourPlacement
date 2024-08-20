class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
                priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++) {
            int x = points[i][0];
            int y = points[i][1];
            
            int dist = x*x + y*y;
            pq.push({dist,{x,y}});
        }
       
        while(k--) {
            vector<int> temp;
            auto it = pq.top();
            pq.pop();
            temp.push_back(it.second.first);
            temp.push_back(it.second.second);
            ans.push_back(temp);
        }
        return ans;
        
    }
};