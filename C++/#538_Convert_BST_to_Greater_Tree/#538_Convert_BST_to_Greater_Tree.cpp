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
    int sum = 0;
    
    void traverseTree(TreeNode* node)
    {
        if(node == NULL)
            return;
        
        traverseTree(node->right);
        node->val += sum;
        sum = node->val;
        traverseTree(node->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        traverseTree(root);
        return root;
    }
};