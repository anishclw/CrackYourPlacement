#include <bits/stdc++.h>
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int n = max(a.size(), b.size());
        while (a.size() != n)
        {
            a = '0' + a;
        }
        while (b.size() != n)
        {
            b = '0' + b;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        // cout << a <<" " << b<<"\n";
        string s = "";
        int carry = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1' && b[i] == '1')
            {
                if (carry)
                {
                    s += '1';
                    carry = 1;
                }
                else
                {
                    s += '0';
                    carry = 1;
                }
            }
            else if (a[i] == '0' && b[i] == '1')
            {
                if (carry)
                {
                    s += '0';
                    carry = 1;
                }
                else
                {
                    s += '1';
                    carry = 0;
                }
            }
            else if (a[i] == '1' && b[i] == '0')
            {
                if (carry)
                {
                    s += '0';
                    carry = 1;
                }
                else
                {
                    s += '1';
                    carry = 0;
                }
            }
            else if (a[i] == '0' && b[i] == '0')
            {
                if (carry)
                {
                    s += '1';
                    carry = 0;
                }
                else
                {
                    s += '0';
                    carry = 0;
                }
            }
        }
        if (carry)
        {
            s += '1';
        }
        reverse(s.begin(), s.end());
        // cout << s <<"\n";

        return s;
    }
};