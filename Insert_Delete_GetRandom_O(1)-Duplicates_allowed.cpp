#include <bits/stdc++.h>
class RandomizedCollection
{
public:
    unordered_map<int, set<int>> m;
    vector<int> v;
    int size;
    RandomizedCollection()
    {
        size = 0;
    }

    bool insert(int val)
    {
        bool ans = false;
        if (m.find(val) == m.end())
            ans = true;
        m[val].insert(size);
        v.push_back(val);
        size++;
        return ans;
    }

    bool remove(int val)
    {
        if (m.find(val) != m.end())
        {
            if (v[size - 1] == val)
            {
                m[val].erase(size - 1);
                v.pop_back();
                if (m[val].size() == 0)
                    m.erase(val);
                size--;
                return true;
            }
            int ind = *(m[val].begin());
            v[ind] = v[size - 1];
            m[v[size - 1]].erase(size - 1);
            v.pop_back();
            m[v[ind]].insert(ind);
            m[val].erase(ind);
            if (m[val].size() == 0)
            {
                m.erase(val);
            }
            size--;
            return true;
        }
        return false;
    }

    int getRandom()
    {
        int ans = rand() % size;
        return v[ans];
    }
};