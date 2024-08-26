/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>ans;
        if(root==nullptr) return ans;
        stack<Node*>st;
        st.push(root);

        while(!st.empty())
        {
            Node* curr=st.top();
            st.pop();
            vector<Node*>ch=curr->children;

            int n=ch.size();
            for(int i=0;i<n;++i)
            {
                if(ch[i]!=nullptr) st.push(ch[i]);
            }
            ans.push_back(curr->val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};