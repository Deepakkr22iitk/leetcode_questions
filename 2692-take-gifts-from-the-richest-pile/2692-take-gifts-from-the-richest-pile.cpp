class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto &it:gifts) pq.push(it);

        while(k)
        {
            int curr=pq.top();
            pq.pop();
            pq.push(sqrt(curr));
            k--;
        }

        long long ans=0;
        while(!pq.empty())
        {
            ans+=1ll*pq.top();
            pq.pop();
        }

        return ans;
    }
};