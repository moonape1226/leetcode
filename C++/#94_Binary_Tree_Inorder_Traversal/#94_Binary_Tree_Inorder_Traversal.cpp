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
    vector<int> inorderTraversal(TreeNode* root) {
        
		/* time:O(N), space:O(N) */
		/*
        stack<TreeNode*> node_stack;
        vector<int> ret;
        TreeNode* curr = root;
        
        if(root == NULL)
            return ret;
        
        while(1)
        {
            //node_stack.push(curr);   
            
            if(curr->left)
            {
                node_stack.push(curr); 
                curr = curr->left;
            }
            else
            {
                //curr = node_stack.top();
                //node_stack.pop();
                
                ret.push_back(curr->val);
                //cout << curr->val << ":";
                
                if(curr->right == NULL && node_stack.size() == 0)
                    break;
                
                if(curr->right)
                {
                    curr = curr->right;
                }
                else
                {
                    curr = node_stack.top();
                    node_stack.pop();
                    curr->left = NULL;
                }
            }
            //cout << node_stack.size() << endl;
        }  
        
        return ret;
        */
        
		/* time:O(N), space:O(N), method from discussion */
        vector<int> nodes;
        stack<TreeNode*> toVisit;
        TreeNode* curNode = root;
        while (curNode || !toVisit.empty()) {
            if (curNode) {
                toVisit.push(curNode);
                curNode = curNode -> left;
            }
            else {
                curNode = toVisit.top();
                toVisit.pop();
                nodes.push_back(curNode -> val);
                curNode = curNode -> right;
            }
        }
        return nodes;
    }
};	