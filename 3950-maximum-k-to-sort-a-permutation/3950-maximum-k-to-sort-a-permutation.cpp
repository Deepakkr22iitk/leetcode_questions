class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int andValue = INT_MAX;
        bool flag = true;

        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                flag = false;
                andValue &= i;
            }
        }

        if(flag) {
            return 0;
        }

        return andValue;
    }
};