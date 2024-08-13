class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
    if(root == NULL)
    {
        return ans;
    }
    queue<TreeNode*>q;
    int f = 0;
    q.push(root);
    while(!q.empty())
    {
        vector<int>tmp;
        int sz = q.size();
        while(sz--)
        {
            TreeNode *temp = q.front();
            q.pop();
            tmp.push_back(temp->val);
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
        if(f%2)reverse(tmp.begin(),tmp.end());
        // for(int i=0;i<tmp.size();i++) ans.push_back(tmp[i]);
        ans.push_back(tmp);
        f = !f;
    }
    return ans;
        
    }
};