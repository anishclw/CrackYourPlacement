#include <bits/stdc++.h>
class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        // Your code here
        unordered_map<int, int> mp;
        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
                arr[i] = 0;
            mp[arr[i]]++;
            mx = max(mx, arr[i]);
        }
        int count = 1;
        while (count <= mx)
        {
            if (mp[count] == 0)
                return count;
            count++;
        }
        return count;
    }
};