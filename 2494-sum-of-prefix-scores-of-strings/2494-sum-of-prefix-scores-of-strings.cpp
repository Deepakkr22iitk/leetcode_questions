class Node{
    public:
    Node* child[26];
    int cnt_prefix;
    Node()
    {
        cnt_prefix=0;
        for(int i=0;i<26;++i) child[i]=nullptr;
    }
};

class Trie{
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }

    void insert(string &word)
    {
        Node* temp=root;
        for(auto &x:word)
        {
            int ind=x-'a';
            if(temp->child[ind]==nullptr) temp->child[ind]=new Node();

            temp->child[ind]->cnt_prefix++;     // Increment the count of the current prefix.
            temp=temp->child[ind];
        }
    }

    int prefix_count(string &str)
    {
        int ans=0;
        Node* temp=root;
        for(auto &x:str)
        {
            int ind=x-'a';
            ans+=temp->child[ind]->cnt_prefix;

            temp=temp->child[ind];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        int len=words.size();
        for(int i=0;i<len;++i)
        {
            trie.insert(words[i]);
        }

        vector<int>ans(len);

        for(int i=0;i<len;++i)
        {
            ans[i]=trie.prefix_count(words[i]);
        }
        return ans;
    }
};