class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long,long long>>>pq;
        long long sum=0;
        int ans=1e9;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            sum+=(long long)nums[i];
            if(sum>=k) ans=min(ans,i+1);

            while(!pq.empty() && (sum-pq.top().first)>=k)
            {
                auto &p=pq.top();
                ans=min(ans,i-(int)p.second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans==1e9?-1:ans;
    }
};