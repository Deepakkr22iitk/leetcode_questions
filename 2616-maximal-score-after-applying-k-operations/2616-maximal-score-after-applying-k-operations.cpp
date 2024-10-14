class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        
        int n=nums.size();
        for(int i=0;i<n;++i) pq.push(nums[i]);
        
        long long ans=0;
        
        while(k--)
        {
            int x=pq.top();
            pq.pop();
            ans+=1LL*x;
            x=(x+2)/3;   // ceil value of x
            pq.push(x);
        }
        return ans;
    }
};