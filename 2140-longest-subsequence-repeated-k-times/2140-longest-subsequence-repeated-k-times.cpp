class Solution {
public:
    string ans; 
    int count_oc(string &sub, string &s)          // cnt of appearance of 'sub' in the string 's' as subsequence
    {
        if(sub.length() == 0) return s.size(); //dummy case when sub = ""
        int ind=0;  //current pointer in sub
        int cntr=0; //number of times it appears as subsequence

        for(int i=0;i<s.size();++i) 
        {
            if(sub[ind]==s[i])
            { 
                ind++; 
                if(ind==(int)sub.size()) ind=0,cntr++; //reset our pointer
            } 
        }
        return cntr;
    }

    void rec(string sub, string s, int k) 
    {
        if(count_oc(sub, s)<k) return; //if it doesn't work, appending something still won't make it work

        if(sub.size()>=ans.size() && sub>ans) ans=sub; //we've found something better!

        for(char c='a';c<='z';c++) rec(sub + c, s, k); //we can try appending and seeing if it works
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        rec("", s, k);
        return ans;
    }
};