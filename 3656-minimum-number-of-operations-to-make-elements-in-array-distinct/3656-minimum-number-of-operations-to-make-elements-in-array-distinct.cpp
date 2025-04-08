class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        map<int,int>freq;
        for(int i=0;i<n;++i) freq[nums[i]]++;

        int op=0;
        for(int i=0;i<n;i+=3)
        {
            int rem=n-i;
            int curr=freq.size();
            if(rem==curr) return op;

            if(--freq[nums[i]]==0) freq.erase(nums[i]);
            if((i+1)<n && --freq[nums[i+1]]==0) freq.erase(nums[i+1]);
            if((i+2)<n && --freq[nums[i+2]]==0) freq.erase(nums[i+2]);
            op++;
        }

        return (op+(freq.size()>0));
    }
};