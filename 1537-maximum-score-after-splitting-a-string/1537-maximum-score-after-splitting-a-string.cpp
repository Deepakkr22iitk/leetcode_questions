class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int one=0;
        for(int i=0;i<n;i++){
            if(s[i] == '1') one++;
        }
        int zero=0;
        int ans = 0;
        for(int i=0;i<n-1;i++)
        {
            // if(one==0) break;
            if(s[i] == '0')
            {
                zero++;
                ans=max(ans,zero+one);
            }
            else
            {
                one--;
                ans=max(ans,zero+one);
            }
        }
        return ans;
    }
};