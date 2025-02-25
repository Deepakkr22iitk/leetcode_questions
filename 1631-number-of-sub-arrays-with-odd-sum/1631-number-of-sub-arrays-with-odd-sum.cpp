class Solution {
public:
    // The idea is simple keep track of the cnt of odd and even sum. If the current sum is odd, then cnt the contribution of cnt_even
    // else if the current sum is even, the cnt the contribution of cnt_odd
    const int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int cnt_even=1;
        int cnt_odd=0;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=arr[i];
            sum%=2;
            if(sum==0)
            {
                ans+=cnt_odd;
                ans%=mod;
                cnt_even++;
            }
            else
            {
                ans+=cnt_even;
                ans%=mod;
                cnt_odd++;
            }
        }
        return ans;
    }
};