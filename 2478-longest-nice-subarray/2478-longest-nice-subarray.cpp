class Solution {
public:
    // The idea is to use Sliding Window and keep track of the bits in the current subarray under consideration
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int i=0;
        vector<int>curr_sub_bit(32);
        int j=0;
        while(j<n)
        {
            bitset<32>arr(nums[j]);
            bool flag=false;
            while(i<j && flag==false)
            {
                flag=true;
                bitset<32>prev(nums[i]);
                for(int ind=0;ind<32;++ind)
                {
                    if(arr[ind]>0 && curr_sub_bit[ind]>0)
                    {
                        flag=false;
                        break;
                    }
                }

                if(flag==false)
                {
                    for(int ind=0;ind<32;++ind)
                    {
                        curr_sub_bit[ind]-=prev[ind];
                    }
                    i++;
                }
            }
            for(int ind=0;ind<32;++ind) curr_sub_bit[ind]+=arr[ind];
            ans=max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};