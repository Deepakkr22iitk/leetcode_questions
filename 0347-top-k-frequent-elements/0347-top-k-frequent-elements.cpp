class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();

        map<int,int> freq; // no. and freq
        for(int i=0;i<n;++i)
        {
            freq[nums[i]]++;
        }
        
        vector<vector<int>> v;
        for(auto &it:freq)
        {
            v.push_back({it.second,it.first});
        }
        vector<int> ans;
        sort(v.begin(),v.end());
        for(int i=v.size()-k;i<v.size();++i)
        {
            ans.push_back(v[i][1]);
        }
        return ans;
    }
};