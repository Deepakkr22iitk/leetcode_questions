class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        unordered_map<string,int>mp;

        string word="";
        for(auto &ch:s1)
        {
            if(ch==' ')
            {
                mp[word]++;
                word="";
            }
            else word+=ch;
        }

        mp[word]++;
        word="";

        for(auto &ch:s2)
        {
            if(ch==' ')
            {
                mp[word]++;
                word="";
            }
            else word+=ch;
        }
        mp[word]++;

        for(auto &x:mp)
        {
            if(x.second==1) ans.push_back(x.first);
        }
        return ans;
    }
};