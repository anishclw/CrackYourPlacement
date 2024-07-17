#include <bits/stdc++.h>
class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // code
        sort(a.begin(), a.end());
        int mini = INT_MAX;
        for (int i = 0; i <= n - m; i++)
        {
            int k = a[i + m - 1] - a[i];
            mini = min(mini, k);
        }
        return mini;
    }
}