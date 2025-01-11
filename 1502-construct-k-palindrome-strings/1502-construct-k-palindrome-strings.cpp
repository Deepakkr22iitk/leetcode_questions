class Solution {
public:
    // The idea is simple characters having even no. of count is not problematic. only problematic scene is having odd no. of cnt of 
    // any character. At max I can have 'k' of them so that I can arrange them in each of the 'k' palindromes. 
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(k==n) return true;
        if(k>n) return false;
        vector<int>freq(26);
        for(int i=0;i<n;++i)
        {
            int ind=s[i]-'a';
            freq[ind]=(freq[ind]+1)%2;
        }

        int cnt_1=0;
        for(int i=0;i<26;++i) cnt_1+=freq[i];

        return (cnt_1<=k);
    }
};