class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,neg=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]<=-1)
            {
                neg=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        if(neg==-1) neg=0;
        else neg+=1;
        low=0,high=n-1;
        int pos=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]<=0)
            {
                pos=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        if(pos!=-1) pos=((n-pos)-1);
        else pos=n;
        cout<<neg<<" "<<pos;
        return max(neg,pos);
    }
};