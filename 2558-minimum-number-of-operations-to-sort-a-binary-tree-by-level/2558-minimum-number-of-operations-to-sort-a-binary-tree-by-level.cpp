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
    // Perform cycle sort at each level to get the minimum number of swap operations to sort the formed vector at each level
    int mincnt(vector<int>&nums)
    {
        int len=nums.size();
        unordered_map<int,int>map;
        for(int i=0;i<len;++i) map[nums[i]]=i;

        sort(nums.begin(),nums.end());
        vector<bool>visited(len);

        int ans=0;
        for(int i=0;i<len;++i) 
        {
            if (visited[i] || map[nums[i]]==i) continue;  // If it's already visited or nums[i] is already at the correct position i.e., (map[nums[i]]==i)

            int j=i,sz=0;
            while(!visited[j]) // Touch each of the values related with this particular element
            {
                visited[j] = true;

                j=map[nums[j]];
                sz++;
            }

            if(sz>0) ans+=(sz-1);    // number of operations will be no_of_elements in this particular touch -1
        }    
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*>q;
        if(root==nullptr) return 0;

        q.push(root);
        while(!q.empty())
        {
            vector<int>level;   // Keep track of the number of elements at this particular level
            int n=q.size();
            for(int i=0;i<n;++i)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=nullptr)
                {
                    q.push(temp->left);
                    level.push_back(temp->left->val);
                }
                if(temp->right!=nullptr)
                {
                    q.push(temp->right);
                    level.push_back(temp->right->val);
                }
            }
            ans+=mincnt(level);
        }  
        return ans;
    }
};