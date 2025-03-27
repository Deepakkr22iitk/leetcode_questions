class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        map<int,int>rk,temp;
        for(int i=0;i<n;++i) rk[nums[i]]++;
        int mx=0;
        for(int i=0;i<n;++i)
        {
            temp[nums[i]]++;
            if(temp[nums[i]]>mx)
            {
                mx=max(mx,temp[nums[i]]);
                if((mx*2)>(i+1))
                {
                    int rem=rk[nums[i]]-temp[nums[i]];
                    int rem_l=(n-1-i);
                    
                    if((rem*2)>rem_l) return i;
                }   
            }
        }
        return -1;
    }
};