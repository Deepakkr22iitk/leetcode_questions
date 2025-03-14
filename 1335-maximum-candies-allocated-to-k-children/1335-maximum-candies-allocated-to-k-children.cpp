class Solution {
public:
    bool check(long long mid,long long &n,vector<int>&candies,long long &k)
    {
        if(mid==0) return true;
        long long cnt=0;
        for(int i=0;i<n;++i)
        {
            long long curr=1LL*candies[i];
            cnt+=(curr/mid);
        }
        return (cnt>=k);
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long n=candies.size();
        
        int mn=0;
        int mx=candies[0];
        for(int i=0;i<n;++i) mx=max(mx,candies[i]);

        int l=mn,h=mx;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
                
            if(check(mid,n,candies,k))
            {
                l=mid+1;
            }
            else h=mid-1;
        }
        return (l-1);
    }
};