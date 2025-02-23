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
    TreeNode* helper(vector<int>& preorder,vector<int>& postorder,unordered_map<int,int>&rk,int psi,int pei,int posi,int poei)
    {
        if(psi>pei) return NULL;

        TreeNode* root=new TreeNode(preorder[psi]);
        if(psi==pei) return root;

        //int temp=rk[preorder[psi+1]];
        int temp=posi;
        while(postorder[temp]!=preorder[psi+1]) temp++;

        int len=(temp-posi+1);
        root->left=helper(preorder,postorder,rk,psi+1,psi+len,posi,temp);
        root->right=helper(preorder,postorder,rk,psi+len+1,pei,temp+1,poei-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>rk;
        int l=postorder.size();
        for(int i=0;i<l;++i) rk[postorder[i]]=i;
        return helper(preorder,postorder,rk,0,l-1,0,l-1);
    }
    
};