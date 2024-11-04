class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int n=word.size();
        for(int i=0;i<n;++i)
        {
            int j=i+1;
            int cnt=1;
            while(j<n && word[j]==word[i] && cnt<9)
            {
                j++;
                cnt++;
            }
            ans+=(char)(cnt+'0');
            ans+=word[i];
            i=j-1;
        }
        return ans;
    }
};