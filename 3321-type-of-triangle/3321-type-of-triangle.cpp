class Solution {
public:
    string triangleType(vector<int>& nums) {
        // set<int> st;
        // for(int i=0;i<3;i++)
        // {
        //     st.insert(nums[i]);
        // }
        // if((nums[0]+nums[1])>nums[2] && (nums[1]+nums[2])>nums[0] && (nums[0]+nums[2])>nums[1])
        // {
        //     if(st.size()==1) return "equilateral";
        //     if(st.size()==2) return "isosceles";
        //     return "scalene";
        // }
        // return "none";

        sort(nums.begin(),nums.end());
        if(nums[0]+nums[1] > nums[2])
        {
            if(nums[0]==nums[2]) return "equilateral";
            else if(nums[0]==nums[1] || nums[1]==nums[2]) return "isosceles";
            return "scalene";
        }
        return "none";
    }
};