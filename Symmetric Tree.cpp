class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true; 
        if (left == NULL  || right == NULL ) return false; // Only one subtree is empty
        if (left->val != right->val) return false; 
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL ) return true; // An empty tree is symmetric
        return isMirror(root->left, root->right); // Check if left and right subtrees are mirrors of each other
    }
};