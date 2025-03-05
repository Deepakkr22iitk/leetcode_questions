class Solution {
public:
    // the number of cells added at each step follows the sequence: 4, 8, 12, 16, ..., increasing by 4 every time.
    // so, total= 1+4+8+12+16+20+.....
    // total= 1+ 4*(1+2+3+4+....+n-1)
    // total= 1+ 4*(n-1)*n/2
    long long coloredCells(int n) {
        long long ans=1+(1LL*n)*(n-1)*2;

        return ans;    
    }
};