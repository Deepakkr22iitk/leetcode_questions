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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            map<TreeNode*, pair<TreeNode*,int>>parent;
            int sm=0;
            for(int i=0;i<len;++i)
            {
                auto curr=q.front();
                q.pop();
                int child_sm=0;
                if(curr->left) child_sm+=curr->left->val;
                if(curr->right) child_sm+=curr->right->val;
                if(curr->left)
                {
                    parent[curr->left]={curr,child_sm};
                    sm+=curr->left->val;
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    parent[curr->right]={curr,child_sm};
                    sm+=curr->right->val;
                    q.push(curr->right);
                }
            }

            for(auto &x:parent)
            {
                TreeNode* p=x.second.first;
                int curr_p_sum=x.second.second;

                x.first->val=(sm-curr_p_sum);
            }
        }
        return root;
    }
};