class Solution {
public:
    void helper(TreeNode* root,long long sum,int &count){
        if(root==NULL) return;
        if((long long)(root->val)==sum) count++;
        // Recursively call the helper function for left and right subtrees
        helper(root->left,sum-(long long)(root->val),count);
        helper(root->right,sum-(long long)(root->val),count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count=0;
        helper(root,(long long)(targetSum),count);
        // this will check every node as root and will get their target sum
        count += pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
        return count;
    }
};