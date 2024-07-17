#include <bits/stdc++.h>
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxe = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                maxe += prices[i] - prices[i - 1];
            }
        }

        return maxe;
    }
};