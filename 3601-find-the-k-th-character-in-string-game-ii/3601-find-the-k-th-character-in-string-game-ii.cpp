class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans=0;
        
        while(k!=1)
        {
            int t=log2(k);
            if((1LL<<t)==k) t--;

            k-=(1LL<<t);
            if(operations[t]) ans++;
        }

        return 'a'+(ans%26);
    }
};