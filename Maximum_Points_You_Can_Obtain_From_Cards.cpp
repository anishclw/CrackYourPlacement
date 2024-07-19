#include <bits/stdc++.h>
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int left = 0, right = 0, maxSum = 0;
        for (int i = 0; i < k; i++)
        {
            left += cardPoints[i];
        }

        maxSum = left;

        for (int leftIdx = k - 1, rightIdx = n - 1; leftIdx >= 0; leftIdx--, rightIdx--)
        {

            left -= cardPoints[leftIdx];

            right += cardPoints[rightIdx];
            maxSum = max(maxSum, left + right);
        }

        return maxSum;
    }
};