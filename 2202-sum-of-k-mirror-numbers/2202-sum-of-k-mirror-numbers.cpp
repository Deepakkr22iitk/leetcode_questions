class Solution {
public:
    long long create_palindrome(long long num, bool odd_len) //create the palindromic number by adding the reverse of 'num' accordingly 
    {
        long long x=num;
        if(odd_len) x/=10;

        while(x)
        {
            num=num*10 + (x%10);
            x/=10;
        }
        return num;
    }

    bool is_Palindrome_baseK(long long num,int base)
    {
        vector<int>digits;
        while(num)
        {
            digits.push_back(num%base);
            num/=base;
        }

        int len=digits.size();
        int i=0,j=len-1;
        while(i<j)
        {
            if(digits[i++]!=digits[j--]) return false;
        }
        return true;
    }
    long long kMirror(int k, int n) {
        long long ans=0;
        for(long long len=1;n>0;len*=10)
        {
            for(long long i=len;n>0 && i<(len*10);++i)
            {
                long long curr=create_palindrome(i,true);
                if(is_Palindrome_baseK(curr,k))
                {
                    ans+=curr;
                    n--;
                }
            }

            for(long long i=len;n>0 && i<(len*10);++i)
            {
                long long curr=create_palindrome(i,false);
                if(is_Palindrome_baseK(curr,k))
                {
                    ans+=curr;
                    n--;
                }
            }
        }
        return ans;
    }
};