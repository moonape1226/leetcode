/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define HEAD    0
#define LEFT    1
#define RIGHT   2

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL)
            return t2;
        else
        {
            traverseTrees(t1, t2, t1, HEAD);
            return t1;            
        }
    }
    
    void traverseTrees(TreeNode* t1, TreeNode* t2, TreeNode* pre, int index)
    {
        if(t2 == NULL)
        {
            return;
        }
        else if(t1 == NULL && t2 != NULL)
        {
            t1 = new TreeNode(t2->val);
            t1->left = t2->left;
            t1->right = t2->right;
            
            if(index == LEFT)
                pre->left = t1;
            else if (index == RIGHT)
                pre->right = t1;
            return;
        }
        else
        {
            traverseTrees(t1->left, t2->left, t1, LEFT);
            t1->val += t2->val;
            traverseTrees(t1->right, t2->right, t1, RIGHT);
        }
    }
};