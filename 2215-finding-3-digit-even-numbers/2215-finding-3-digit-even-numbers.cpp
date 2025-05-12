class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<int>ans;
        vector<int>freq(10);
        for(int i=0;i<n;++i) freq[digits[i]]++;
        
        for(int i=1;i<=9;++i)
        {
            for(int j=0;j<=9;++j)
            {
                for(int k=0;k<=8;k+=2)
                {
                    vector<int>curr(10);
                    curr[i]++;
                    curr[j]++;
                    curr[k]++;

                    bool flag=true;
                    
                    if(curr[i]>freq[i]) flag=false;
                    if(curr[j]>freq[j]) flag=false;
                    if(curr[k]>freq[k]) flag=false;

                    if(flag)
                    {
                        int val=i*100+j*10+k;
                        ans.push_back(val);
                    }
                }
            }
        }
        return ans;
    }
};