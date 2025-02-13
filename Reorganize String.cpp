class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> count;
        for(auto&c : s){
            count[c]++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for(auto&p : count){
            maxHeap.push({p.second, p.first});// {count, character } heap with maximum count 
        }
        string result = "";
        while(maxHeap.size() > 1){// needs atleast two elements
            auto top1 = maxHeap.top(); maxHeap.pop();
            auto top2 = maxHeap.top(); maxHeap.pop();
            result+=top1.second;
            result+=top2.second;
            top1.first--;
             top2.first--;
            if (top1.first > 0) {
                maxHeap.push(top1);
            }
            if (top2.first > 0) {
                maxHeap.push(top2);
            }
        }

        if (!maxHeap.empty()) {
            auto last = maxHeap.top();
            if (last.first > 1) {
                return ""; // Not possible to rearrange
            }
            result += last.second;
        }

        return result;
    }
};