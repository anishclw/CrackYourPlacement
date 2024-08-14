class Solution {
public:
    bool check(TreeNode* root,long int min,long int max){
        if(root==NULL)return true;
        if(root->val >min && root->val<max){
            bool left=check(root->left,min,root->val);
            bool right=check(root->right,root->val,max);
            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        if((root->left==NULL && root->right==NULL))return true;
        return check(root,LONG_MIN,LONG_MAX);
    }
};