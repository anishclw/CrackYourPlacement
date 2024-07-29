#include <bits/stdc++.h>
class Solution
{
public:
    // Function to find minimum number of pages.
    bool ifPossible(int n, int arr[], int m, int mid)
    {
        int studentCount = 1;
        int pagesCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (pagesCount + arr[i] <= mid)
            {
                pagesCount += arr[i];
            }
            else
            {
                studentCount++;
                if (studentCount > m || arr[i] > mid)
                {
                    return false;
                }
                pagesCount = arr[i];
            }
        }
        return true;
    }

    long long findPages(int n, int arr[], int m)
    {
        // code here
        int start = 0;
        int sum = 0;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int end = sum;
        int mid = start + (end - start) / 2;
        while (start <= end)
        {
            if (m > n)
            {
                return ans;
            }
            else if (ifPossible(n, arr, m, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
};