class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';

        int len=1<<n;   // Each n'th string length is equivalent to 2^n -1

        if(k<(len/2)) return findKthBit(n-1,k);  // If k<(len/2) then the kth bit is present in (n-1)th string at k'th bit

        if(k==(len/2)) return '1';

        else
        {
            char corresponding_bit=findKthBit(n-1,(len-k)); //If it's in other half then it'll be present at (len-k)'th bit

            if(corresponding_bit=='1') return '0';
            else return '1';
        }
    }
};