class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n<0) return false;
        // if(n<2) return n;
        // while(n>1)
        // {
        //     if(n%2) return false;
        //     n/=2;
        // }
        // return true;

        if(n<0) return false;
        if(n<2) return n;
        return (n&(n-1))==0;
    }
};