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
// here we have taken piles in sorted order, although it's not necessary and also it 
// won't affect our ans precedure

// here we are trying to implement BS on ans(or say minimizing the k)
// to finish all banana in <= h hours
//                               max(piles[i])
//                                 o     h(given)
//                             o   o
//                         o   o   o
//                     o   o   o   o
//                 o   o   o   o   o
//             o   o   o   o   o   o
//         o   o   o   o   o   o   o   h(calulated)
// k=0    inf inf inf  .   .   .   .       inf
// k=1     1   2   3   4   5   6   7       28
// k=2     1   1   2   2   3   3   4       16
// .
// .
// k=max   1   1   1   1   1   1   1       n(length of piles)

// now we have to do BS on k such that
//     k   n    n+1   n+2   n+3   .   .   .   inf
//   team  0     0     0     1    1   1   1    1
// team 1 means it is feasible and can be the ans
// we need to output the first 1
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