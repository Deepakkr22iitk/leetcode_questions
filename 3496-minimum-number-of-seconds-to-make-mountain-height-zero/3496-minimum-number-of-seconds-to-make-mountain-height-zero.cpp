class Solution {
public:
    bool limit(long long mid,long long mountainHeight,auto &workerTimes)
    {
        long long temp=0;
        long long len=workerTimes.size();
        for(long long i=0;i<len;++i)
        {
            long long curr=0;
            long long cost=1LL*workerTimes[i];
            long long l=1,h=mountainHeight;
            
            while(l<=h)
            {
                long long m=l+(h-l)/2;
                long long curr_cost=(m*(m+1))/2 *cost;
                
                if(curr_cost<=mid)
                {
                    l=m+1;
                }
                else h=m-1;
            }
            
            temp=temp+h;
            if(temp>=mountainHeight) return true;
            
            // for(long long j=1;j<=mountainHeight;++j)
            // {
            //     if((curr+j*cost)<=mid) 
            //     {
            //         temp++;
            //         curr=curr+j*cost;
            //     }
            // }
        }
        bool ans=(temp>=mountainHeight);
        return ans;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l=0,h=1e18;
        long long dk=0;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(limit(mid,1LL*mountainHeight,workerTimes))
            {
                dk=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return dk;
    }
};