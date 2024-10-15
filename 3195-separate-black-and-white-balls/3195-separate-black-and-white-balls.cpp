class Solution {
public:
    long long minimumSteps(string s) {
        int cnt_1=0;
        long long ans=0;
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1') cnt_1++;
            else ans+=cnt_1;
        }
        return ans;
    }
};