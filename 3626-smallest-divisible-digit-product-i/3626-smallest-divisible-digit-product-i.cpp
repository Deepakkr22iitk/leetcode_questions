class Solution {
public:
    bool correct(int val,long long t)
    {
        long long product=1;
        while(val)
        {
            long long dig=(val%10);
            val/=10;
            product*=dig;
        }
        return ((product%t)==0);
    }
    int smallestNumber(int n, int t) {
        while(1)
        {
            if(correct(n,1LL*t)) return n;
            n++;
        }
        return 100;
    }
};