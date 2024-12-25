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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<int> ans;
        queue.push(root);
        if (!root) return ans;
        while (!queue.empty()) {
            int level = queue.size();
            int max_val = INT_MIN;
            for (int i = 0; i < level; i++) {
                TreeNode* temp = queue.front();
                queue.pop();
                if (temp->left) {
                    queue.push(temp->left);
                }
                if (temp->right) {
                    queue.push(temp->right);
                }
                max_val = max(max_val, temp->val);
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};