class Solution {
public:
    int digisum(int n) 
    {
        int sum=0;
        while(n) 
        {
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        if(n<=9) return n;

        vector<int>freq(37);    // since largest possible is [9,9,9,9]==36
        
        for(int i=1;i<=n;++i) freq[digisum(i)]++;

        int mx=0,cnt=0;
        for(auto &x:freq)
        {
            if(x>mx) 
            {
                mx=x;
                cnt=1;
            }
            else if (x==mx) cnt++;
        }
        return cnt;
    } 
};