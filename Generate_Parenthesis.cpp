#include <bits/stdc++.h>
class Solution
{
public:
    vector<string> res;
    void permute(int open, int close, string temp)
    {
        if (open == 0 && close == 0)
        {
            res.push_back(temp);
            return;
        }
        if (open > 0)
        {
            temp += '(';
            permute(open - 1, close, temp);
            temp.pop_back();
        }
        if (close > 0 && close > open)
        {
            temp += ')';
            permute(open, close - 1, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        permute(n, n, "");
        return res;
    }
};