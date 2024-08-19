/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int, multiset<int>>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* node = q.front().first;
                int col = q.front().second;
                q.pop();
                mp[col][level].insert(node->val);
                if(node->left) {
                    q.push({node->left,col-1});
                }
                if(node->right) {
                    q.push({node->right,col+1});
                }
               
            }
            level++;
            
        }
        vector<vector<int>> ans;
        for(auto col:mp) {
            vector<int> temp;
            for(auto row:col.second) {
                for(int ele:row.second) {
                    temp.push_back(ele);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};