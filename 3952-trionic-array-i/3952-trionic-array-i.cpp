class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int ind=1,p=0,q=0;
        while(ind<n)
        {
            if(ind<n && nums[ind]>nums[ind-1])
            {    
                while(ind<n && nums[ind]>nums[ind-1]) ind++;
                p=ind-1;
            }
            else return false;
            if(ind<n && nums[ind]<nums[ind-1])
            {    
                while(ind<n && nums[ind]<nums[ind-1]) ind++;
                q=ind-1;
            }
            else return false;
            if(ind<n && nums[ind]>nums[ind-1])
            {
                    while(ind<n && nums[ind]>nums[ind-1]) ind++;
            }
            else return false;
        }
        if(ind==n && p!=q && p!=0 && q!=0) return true;
        return false;
    }
};