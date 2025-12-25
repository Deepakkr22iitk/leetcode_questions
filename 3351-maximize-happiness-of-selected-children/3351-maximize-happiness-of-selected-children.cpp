class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.begin(),happiness.end());
        int times=0;
        int n=happiness.size();
        for(int j=n-1;j>=0 && k;j--)
        {
            ans+=max(happiness[j]-times,0);
            times++;
            k--;
        }
        return ans;
    }
};