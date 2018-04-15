/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void travereTree(TreeNode* node)
    {
        if(node == NULL)
            return;

        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        
        travereTree(node->left);
        travereTree(node->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        travereTree(root);
        
        return root;
    }
};