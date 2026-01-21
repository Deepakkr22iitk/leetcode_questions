class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        for(int i=0;i<n;++i)
        {
            int ind1=i;
            int ind2=0;
            while(ind1<n && ind2<m && haystack[ind1]==needle[ind2])
            {
                ind1++;
                ind2++;
            }
            if(ind2==m) return i;
        }
        return -1;
    }
};