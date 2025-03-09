class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<(k-1);++i) colors.push_back(colors[i]);
        int n=colors.size();
        int ans=0;
        int curr=1;
        for(int i=1;i<n;++i)
        {
            if(colors[i]!=colors[i-1]) curr++;
            else curr=1;

            if(curr>=k) ans++;
        }
        return ans;
    }
};