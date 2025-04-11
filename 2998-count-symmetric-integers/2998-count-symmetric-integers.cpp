class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;++i)
        {
            string str=to_string(i);
            int len=str.size();
            if(len%2) continue;

            int sum=0;
            for(int j=0;j<len;++j)
            {
                if(j<(len/2))
                {
                    sum+=(str[j]-'0');
                }
                else sum-=(str[j]-'0');
            }

            if(sum==0) ans++;
        }
        return ans;
    }
};