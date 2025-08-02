class Solution {
public:
    // There are two ways to swap elements, One way is direct swap i.e., Take the minm of two elements being swapped
    // and the other way is indirect swap i.e., Swap with the helps of minimum element present, Let it be 'mn' then 
    // swap 'mn' with ele1 and then swap 'mn' with ele2. so, the cost would be 2*mn
    // At each step, we should choose one of these two types of swap. 
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int>rk;
        int n=basket1.size();
        int mn=INT_MAX;
        for(int i=0;i<n;++i)
        {
            rk[basket1[i]]++;
            rk[basket2[i]]--;
            mn=min(mn,basket1[i]);
            mn=min(mn,basket2[i]);
        }
        
        vector<int>swaps;
        for(auto &x:rk)
        {
            if(x.second%2 ==1) return -1;      // If count is odd, then it's never possible
            int cnt=abs(x.second);
            
            for(int i=0;i<cnt/2;++i) swaps.push_back(x.first);   // only half of them needs to be swapped...right?
        }
        
        long long ans=0;
        int len=swaps.size();
        for(int i=0;i<len/2;++i)
        {
            ans+=min(2LL*mn,1LL*swaps[i]);
        }
        return ans;
    }
};