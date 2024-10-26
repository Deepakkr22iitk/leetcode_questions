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
    int findheight(TreeNode* root,int level, map<int,int>&depth,map<int,int>&height)
    {
        if(root==nullptr) return -1;
        depth[root->val]=level;
        int temp1=findheight(root->left,level+1,depth,height);
        int temp2=findheight(root->right,level+1,depth,height);
        
        return height[root->val]=(1+max(temp1,temp2));
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        map<int,int>height;  
        map<int,int>depth;               // {val,depth}
        int h_tree=findheight(root,0,depth,height);
        int m=queries.size();

        vector<int>ans;
        map<int,vector<pair<int,int>>>cousins; // push cousins for each of the corresponding depth and store only the top '2' cousins by height
        for(auto &x:depth)
        {
            cousins[x.second].push_back({height[x.first], x.first});
            sort(cousins[x.second].begin(), cousins[x.second].end(),greater<pair<int,int>>());   // sorted in decreasing order
            if(cousins[x.second].size()>2) cousins[x.second].pop_back();
        }

        for(auto &x:queries)
        {
            int curr_depth=depth[x];
            if(cousins[curr_depth].size()==1) ans.push_back(curr_depth-1);          // If it's farthest one having no cousin then height will be decreased by 1
            // Now, If the highest tree height subtree needs to be deleted then new height will be corresponding to it's just smaller cousins which is stored at index '1' 
            else if(cousins[curr_depth][0].second==x)  ans.push_back(cousins[curr_depth][1].first+curr_depth);  
            else ans.push_back(h_tree);
        }
        return ans;
    }
};