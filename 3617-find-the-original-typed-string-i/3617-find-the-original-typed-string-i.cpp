class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        int n=word.size();
        for(int i=0;i<n;++i)
        {
            int j=i+1;
            while(j<n && word[j]==word[i]) j++;

            int curr=(j-i);
            ans+=curr-1;
            i=j-1;
        }
        return ans;
    }
};