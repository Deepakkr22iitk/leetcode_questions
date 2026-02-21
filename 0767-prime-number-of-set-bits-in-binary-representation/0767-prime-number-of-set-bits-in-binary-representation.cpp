class Solution {
public:
    bool prime(int m)
    {
        if(m < 2) return false;
        for(int i=2;i*i<=m;++i)
        {
            if(m%i==0) return false;
        }
        return true;
    }
    int nosb(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=(n%2);
            n/=2;
        }
        return ans;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;++i)
        {
            if(prime(nosb(i))) ans++;
        }
        return ans;
    }
};