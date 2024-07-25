#include <bits/stdc++.h>
class Solution
{
public:
    // time/space: O(nklogk)/O(nk)
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // build a map with `sorted words as the key` and `anagrams as values (vector)`
        unordered_map<string, vector<string>> hash;
        for (auto &s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            hash[t].push_back(s);
        }

        // convert the hash map to the result
        vector<vector<string>> result;
        for (auto &[k, v] : hash)
            result.push_back(v);
        return result;
    }
};