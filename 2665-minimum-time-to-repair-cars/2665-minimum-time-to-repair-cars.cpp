class Solution {
public:
    bool check(vector<int>& ranks,int cars,long long mid)
    {
        int n=ranks.size();
        long long total_cars=0;
        for(int i=0;i<n;++i)
        {
            int r=ranks[i];
            long long temp = mid / (1LL*r);
            long long x=sqrt(temp);
            total_cars += x;
            if(total_cars >= cars) return true;
         }
        return total_cars>=cars;
    }   
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        long long l=0,h=1e18; 
        long long ans=0;
        while(l<=h) 
        {
            long long mid=l+(h-l)/2;
            if(check(ranks,cars,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};