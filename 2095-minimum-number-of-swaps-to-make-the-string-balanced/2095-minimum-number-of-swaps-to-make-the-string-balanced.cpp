class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        vector<int>open;
        for(int i=n-1;i>=0;--i)
        {
            if(s[i]=='[') open.push_back(i);
        }
        int ind=0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='[') cnt++;
            else cnt--;

            if(cnt<0)
            {
                ans++;
                swap(s[i],s[open[ind++]]);
                cnt+=2;
            }
        }
        return ans;
    }
};