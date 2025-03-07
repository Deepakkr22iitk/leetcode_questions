class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime(right+5,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=right;++i)
        {
            for(int j=i*i;j<=right;j+=i)
            {
                prime[j]=0;
            }    
        } 
        
        vector<int>ans(2);
        ans[0]=-1;
        ans[1]=-1;
        
        int prev=left;
        
        for(int i=left;i<=right;++i)
        {
            if(prime[i]==1)
            {
                prev=i;
                break;
            }     
        }
        
        int diff=1e8;
        for(int i=prev+1;i<=right;++i)
        {
            if(prime[i]==1)
            {
                if((i-prev) < diff)
                {
                    ans[0]=prev;
                    ans[1]=i;
                    diff=(i-prev);
                }
                prev=i;
            }
        } 
        return ans;
    }
};