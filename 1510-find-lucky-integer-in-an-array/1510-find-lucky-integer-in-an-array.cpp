class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>freq;
        for(auto &x:arr) freq[x]++;

        int ans=-1;
        for(auto &x:freq)
        {
            if(x.first==x.second) ans=x.first;
        }
        return ans;
    }
};