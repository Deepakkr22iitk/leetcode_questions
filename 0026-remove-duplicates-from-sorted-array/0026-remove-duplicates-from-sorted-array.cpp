class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0], ind = 0;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] != curr){
                ind++;
                curr = nums[i];
                nums[ind] = curr;
            }
            else{
                nums[ind] = curr;
            }
        }
        return ind + 1;
    }
};