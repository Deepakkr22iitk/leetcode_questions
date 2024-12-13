class Solution {
public:
    long long pred(vector<int> &piles,int least)
    {
        int n=piles.size();
        long long ans=0;
        for(int i=0;i<n && least;++i)
        {
            ans+=((piles[i]+least-1)/least);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        if(n==1) return (piles[0]+h-1)/h;
        long long big=0,idx=0;
        while(idx<n) 
        {
            big=max(big,1ll*piles[idx]);
            idx++;
        }
        long long low=0,high=big+1;
        while(low+1<high)
        {
            long long mid=low+(high-low)/2;
            if(pred(piles,mid)>h) low=mid;
            else high=mid;
        }
        return high;
    }
};