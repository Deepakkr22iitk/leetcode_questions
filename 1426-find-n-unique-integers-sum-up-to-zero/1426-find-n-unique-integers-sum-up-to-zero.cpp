class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        for(int i=1;i<=n/2;++i)
        {
            ans[i-1]=-i;
            ans[n-i]=i;
        }
        if(n%2) ans[n/2]=0;
        return ans;
    }
};