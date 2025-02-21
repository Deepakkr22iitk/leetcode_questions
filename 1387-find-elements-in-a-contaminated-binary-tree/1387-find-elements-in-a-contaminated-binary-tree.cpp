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
class FindElements {
public:
    set<int>st;
    FindElements(TreeNode* root) {
        queue<TreeNode*>q;
        st.insert(0);
        root->val=0;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            {
                int p=curr->val;
                int lval=2*p+1;
                st.insert(lval);
                curr->left->val=lval;
                q.push(curr->left);
            }
            if(curr->right)
            {
                int p=curr->val;
                int rval=2*p+2;
                st.insert(rval);
                curr->right->val=rval;
                q.push(curr->right);
            }
        }
    }
    
    bool find(int target) {
        return (st.find(target)!=st.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */