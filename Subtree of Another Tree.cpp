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

    bool helperSameTree(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr){
            return true;
        }
        if(root1 == nullptr || root2 == nullptr){
            return false;
        }
        if(root1 -> val != root2 -> val){
            return false;
        }
        return helperSameTree(root1 -> left, root2 -> left) && helperSameTree(root1 -> right, root2 -> right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr){
            return false;
        }
        queue <TreeNode*> nodes;
        nodes.push(root);
		
		// Perform level-order traversal of the main tree
		
        while(!nodes.empty()){
            auto curr = nodes.front();
            nodes.pop();
            if(curr -> left != nullptr){
                nodes.push(curr -> left);
            }
            if(curr -> right != nullptr){
                nodes.push(curr -> right);
            }
			
			// If the value of the current node matches the value of the root of the subtree,
            // check if the subtree starting from the current node is identical to the given subtree
			
            if(curr -> val == subRoot -> val){
                if(helperSameTree(curr, subRoot)){
                    return true;
                }
            }
        }
		
		// If no subtree is found, return false
        return false;
    }
};