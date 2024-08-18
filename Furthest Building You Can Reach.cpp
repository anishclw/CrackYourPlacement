class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for(int i=0;i<heights.size()-1;i++) {
            int diff = heights[i+1] - heights[i];
            pq.push(diff);
            if(diff<0) continue;
            else {
                bricks -= diff;
                if(bricks<0) {
                    bricks += pq.top();
                    pq.pop();
                    if(ladders>0) ladders--;
                    else return i;
                }
            }
        }
        return heights.size()-1;
    }
};