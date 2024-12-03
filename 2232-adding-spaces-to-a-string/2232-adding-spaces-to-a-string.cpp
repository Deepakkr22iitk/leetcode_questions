class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int idx=0,i=0;
        while(i<spaces.size())
        {
            if(idx==spaces[i]) 
            {
                ans+=" ";
                i++;
            }
            ans+=s[idx];
            idx++;
        }
        while(idx<s.size())
        {
            ans+=s[idx];
            idx++;
        }
        return ans;
    }
};