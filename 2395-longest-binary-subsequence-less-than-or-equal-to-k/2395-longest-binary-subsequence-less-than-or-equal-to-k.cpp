class Solution {
public:
    // choosing a subsequence is same as deleting all the other digits
    int longestSubsequence(string s, int k) {
        int n=s.size();
        int deletion=0;
        long long curr=0;
        bool flag=false;
        for(int i=n-1;i>=0;--i)
        {
            if(s[i]=='1')
            {
                if(flag==true) deletion++;
                else 
                {
                    if(flag==false)
                    {
                        if((n-1-i)<=32) curr=curr|(1LL<<(n-1-i));
                        
                        if((curr>1LL*k) || (n-1-i)>32)
                        {
                            deletion++;
                            flag=true;
                        }
                    } 
                }
            }
        }
        return (n-deletion);
    }
};