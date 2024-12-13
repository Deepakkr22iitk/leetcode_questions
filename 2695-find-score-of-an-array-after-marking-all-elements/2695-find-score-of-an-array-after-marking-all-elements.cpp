class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        long long score=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }

        vector<int> mark(n,0);
        while(!pq.empty())
        {
            auto now=pq.top();
            int idx=now.second;
            if(mark[idx]==0)
            {
                score+=(1ll*now.first);
                mark[idx]++;
                if(idx+1<n && mark[idx+1]!=1) mark[idx+1]++;
                if(idx-1>=0 && mark[idx-1]!=1) mark[idx-1]++;
            }
            pq.pop(); 
        }
        return score;
    }
};