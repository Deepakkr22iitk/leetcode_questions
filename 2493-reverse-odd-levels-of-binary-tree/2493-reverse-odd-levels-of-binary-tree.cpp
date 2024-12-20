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
    void reverse(TreeNode* left, TreeNode* right, int level){
        if(left==NULL) return;

        if(level&1) swap(left->val,right->val);

        reverse(left->left, right->right, level+1);
        reverse(left->right, right->left, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        // BFS
        // if(!root) return root;
        
        // queue<TreeNode*> q;
        // vector<int> values;
        // q.push(root);
        // int level=0;
        
        // while(!q.empty())
        // {
        //     int sz = q.size();
        //     vector<int> temp;
        //     for(int i=0; i<sz; i++)
        //     {
        //         TreeNode* node = q.front(); q.pop();
                
        //         if(level%2)
        //             node->val = values[sz-i-1];
                
        //         if(node->left)
        //         {
        //             q.push(node->left);
        //             temp.push_back(node->left->val);
        //         }
        //         if(node->right) 
        //         {
        //             q.push(node->right);
        //             temp.push_back(node->right->val);
        //         }
                
        //     }
        //     values = temp;
        //     level++;
        // }
        // return root;

        // DFS
        reverse(root->left,root->right,1);
        return root;
    }
};