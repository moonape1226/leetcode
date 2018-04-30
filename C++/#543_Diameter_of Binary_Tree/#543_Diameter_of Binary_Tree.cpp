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
    /* very slow method, two recursive */
    /*
    int diameter = 0;

    void traverseTree(TreeNode* node, int depth, vector<int> &depthList){
        if(node == NULL)
            return;
        
        traverseTree(node->left, depth+1, depthList);
        depthList.push_back(depth);
        traverseTree(node->right, depth+1, depthList);
    }
    
    int calcTreeDistance(TreeNode* node)
    {
        vector<int> depthList;
        int depthLeft = 0, depthRight = 0;
        bool leftFlag = true;
        
        traverseTree(node, 0, depthList);
        
        for(int i = 0; i < depthList.size(); i++)
        {
            if(depthList[i] == 0)
                leftFlag = false;
            
            if(leftFlag)
            {
                if(depthList[i] > depthLeft)
                    depthLeft = depthList[i];
            }
            else
            {
                if(depthList[i] > depthRight)
                    depthRight = depthList[i];
            }
        }
        
        return (depthLeft+depthRight);
    }
    
    void traverseTree2(TreeNode* node){
        if(node == NULL)
            return;
        
        traverseTree2(node->left);
        int currDist = calcTreeDistance(node);
        if(diameter < currDist)
            diameter = currDist;
        traverseTree2(node->right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        traverseTree2(root);
        return diameter;
    }
    */
    
    /* one recursive, Depth-First Search */
    int ret = 0;
    
    int calcDiameter(TreeNode* node)
    {
        if(node == NULL)
            return 0;
        
        int lDepth = calcDiameter(node->left);
        int rDepth = calcDiameter(node->right);
        ret = max(ret, lDepth+rDepth);
        return max(lDepth, rDepth) + 1;    
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        calcDiameter(root);
        return ret;
    }
};