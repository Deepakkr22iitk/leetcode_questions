class Solution {
public:
    // here we are trying to play with the index denoted by mid
    // how to play with index?
    // so here except the one unique element,every other exist two times that means 
    // before that unique element every element have it's first appearance at 
    // an even index and the second appearance at an odd index
    // but 
    // after that existance of unique element this will reverse 
    // so we are using this info to decide whether we want to continue with the right half 
    // or the left half
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        if(n==1) return nums[0];
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if((mid>0 && nums[mid-1]!=nums[mid]) &&
                 (mid<n-1 && nums[mid+1]!=nums[mid])) return nums[mid];
            else if(mid==0 && nums[mid+1]!=nums[mid]) return nums[mid];
            else if(mid==n-1 && nums[mid-1]!=nums[mid]) return nums[mid];

            if(mid%2) // taking the odd case
            {
                // if value at this index is second appearance it means unique will appear in right half
                if(nums[mid-1]==nums[mid]) low=mid+1;
                else high=mid-1; // else unique element is somewhere in left
            }
            else
            {
                if(mid>0 && nums[mid-1]==nums[mid]) high=mid-2;
                else low=mid+1;   
            }
        }
        return nums[0];
    }
};