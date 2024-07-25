#include <bits/stdc++.h>

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> stk;
        int a;
        istringstream iss(s);
        char op = '+';
        while (iss >> a)
        {
            if (op == '+' || op == '-')
            {
                stk.push(op == '+' ? a : -a);
            }
            else
            {
                int last = stk.top();
                stk.pop();
                if (op == '*')
                    last *= a;
                else
                    last /= a;
                stk.push(last);
            }
            iss >> op;
        }
        int sum = 0;
        while (!stk.empty())
        {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};