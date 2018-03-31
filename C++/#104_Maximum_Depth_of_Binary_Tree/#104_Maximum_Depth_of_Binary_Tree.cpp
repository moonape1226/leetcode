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
    int traverseTree(TreeNode* node){
        if(node == NULL)
            return 0;
        
        int res = 1 + max(traverseTree(node->left), traverseTree(node->right));
        return res;
    }
    
    int maxDepth(TreeNode* root) {        
        return traverseTree(root);
    }
};