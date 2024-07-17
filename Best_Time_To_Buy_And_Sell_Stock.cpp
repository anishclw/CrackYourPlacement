#include<bits/stdc++.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curPrice =INT_MAX;
        int res = 0;

        for(int i=0;i<prices.size();i++) {
            curPrice = min(curPrice,prices[i]);
            res = max(res,prices[i]-curPrice);
        }

        return res;
    }
};