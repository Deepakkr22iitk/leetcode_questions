struct Node{
    public:
    string name;
    unordered_map<string,Node*> children;
    string signature;

    Node(string name)
    {
        this->name=name;
    }
};

// Build a filesystem tree using a Trie-like structure for paths.
// Serialize every subtree into a string that uniquely captures its structure and contents.
// Skip duplicate subtrees by checking how many times each signature appears

class Solution {
public:
    void dfs(Node* node, unordered_map<string,int>&freq)
    {
        if(node->children.empty()) 
        {
            node->signature="";
            return;
        }

        vector<string>child_signatures;
        for(auto &[name,child]: node->children)
        {
            dfs(child,freq);
            child_signatures.push_back(name+"#"+child->signature+"#");
        }
        sort(child_signatures.begin(),child_signatures.end());
        node->signature="";
        for(auto &sig:child_signatures) node->signature+=sig;

        freq[node->signature]++;
    }

    void dfs2(Node* node,vector<string>& curr_path,auto &ans,auto &freq)
    {
        if(!node->children.empty() && freq[node->signature]>=2) return;

        curr_path.push_back(node->name);
        ans.push_back(curr_path);
        for(auto &[name,child]: node->children) dfs2(child,curr_path,ans,freq);

        curr_path.pop_back();
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Adding it into the Trie
        Node* root=new Node("");
        for(auto &x:paths)
        {
            Node* curr=root;
            for(auto &folder: x)
            {
                if(curr->children.find(folder)==curr->children.end()) curr->children[folder]=new Node(folder);

                curr=curr->children[folder];
            }
        }

        unordered_map<string,int>freq;
        dfs(root,freq);

        vector<vector<string>>ans;
        vector<string>curr_path;
        for(auto &[name,child]: root->children) dfs2(child,curr_path,ans,freq);

        delete root;
        return ans;
    }
};