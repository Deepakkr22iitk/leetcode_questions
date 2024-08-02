class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;++i) pre[i]=pre[i-1]+nums[i];


        int cnt_1=pre[n-1];
        if(cnt_1==n) return 0;

        int ans=n;      
        for(int i=0;i<cnt_1;++i)              // Now from start, taking each element and remaining from the end
        {
            int first=pre[i];
            int last=pre[n-1]-pre[n-(cnt_1-i)];

            int left_element=cnt_1-(i+1);

            ans=min(ans, (i+1-first)+left_element-last);
        }

        for(int i=cnt_1;i<n;++i)                 // Now, these are the window of size=cnt_1 
        {
            int curr=pre[i]-pre[i-cnt_1];

            ans=min(ans,cnt_1-curr);
        }
        return ans;
    }
};