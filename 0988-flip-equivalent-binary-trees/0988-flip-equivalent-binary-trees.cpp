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
    // The idea is that even if there is any flip at any particular node or there is no flip still the value of left child and right child 
    // would remain same upon sorting in both of the tree if they are equivalent.
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr) return true;
        
        if((root1!=nullptr && root2==nullptr) || (root1==nullptr && root2!=nullptr)) return false;

        map<int,vector<int>>tree1;
        queue<TreeNode*>q;
        q.push(root1);
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            if(temp->left)
            {
                tree1[temp->val].push_back(temp->left->val);
                q.push(temp->left);
            }

            if(temp->right)
            {
                tree1[temp->val].push_back(temp->right->val);
                q.push(temp->right);
            }
        }

        q.push(root2);
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            vector<int>v;
            if(temp->left)
            {
                v.push_back(temp->left->val);
                q.push(temp->left);
            }

            if(temp->right)
            {
                v.push_back(temp->right->val);
                q.push(temp->right);
            }

            auto prev_vector=tree1[temp->val];
            sort(prev_vector.begin(),prev_vector.end());
            sort(v.begin(),v.end());

            if(v!=prev_vector) return false;
        }

        return true;
    }
};