class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n=text.size();
        set<char> broken;
        for(auto it:brokenLetters) broken.insert(it);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if((text[i]==' ' || i==n-1) && broken.find(text[i])==broken.end())
            {
                ans++;
            }
            if(broken.find(text[i])!=broken.end())
            {
                while(i<n && text[i]!=' ') i++;
            }
        }
        return ans;
    }
};