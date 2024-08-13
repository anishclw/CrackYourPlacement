class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==NULL)
        {
            return v;
        }
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto i = q.front();
            q.pop();
            TreeNode *temp = i.first;
            int level = i.second;
            if(mp.find(level)==mp.end()) mp[level] = temp->val;
            if(temp->right) q.push({temp->right,level+1});
            if(temp->left) q.push({temp->left,level+1});
        }
        for(auto i:mp)
        {
            v.push_back(i.second);
        }
        return v;
    }
};