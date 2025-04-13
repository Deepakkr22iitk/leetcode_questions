class Solution {
public:
    long long mod=1e9+7;
    long long modexpo(long long a,long long b)
    {
        if(b==0) return 1;

        long long p=modexpo(a,b/2);
        p=(p%mod *p%mod)%mod;

        if(b%2==0) return p;
        return (a%mod *p%mod)%mod;
    }
    int countGoodNumbers(long long n) {
        if(n==1) return 5;
        return (modexpo(5,(n+1)/2)%mod * modexpo(4,n/2)%mod)%mod;
    }
};