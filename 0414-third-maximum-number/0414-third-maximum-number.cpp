class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int first=INT_MIN,second=INT_MIN,third=INT_MIN;
        // int n=nums.size();
        // set<int> st;
        // for(int i=0;i<n;i++)
        // {
        //     st.insert(nums[i]);
        //     if(nums[i]>first)
        //     {
        //         third=second;
        //         second=first;
        //         first=nums[i];
        //     }
        // }
        // return st.size()<3?first:third;

        int first=-2147483648,second=-2147483648,third=-2147483648;
        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
            if(nums[i]>first)
            {
                third=second;
                second=first;
                first=nums[i];
            }
            else if(nums[i]>second && nums[i]<first)
            {
                third=second;
                second=nums[i];
            }
            else if(nums[i]>third && nums[i]<second)
            {
                third=nums[i];
            }
        }
        return st.size()>2?third:first;
    }
};