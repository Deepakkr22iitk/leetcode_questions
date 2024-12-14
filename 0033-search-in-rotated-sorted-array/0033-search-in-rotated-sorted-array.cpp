class Solution {
public:
    // at any point of time we are clear that any one half is sorted
    // and if any one part is sorted then we can apply BS 
    int search(vector<int>& nums, int target) {
        int beg=0,end=nums.size()-1,mid;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nums[mid]==target) return mid;

            // here we are clear that left half is sorted
            if(nums[beg]<=nums[mid])
            {
                if(target<=nums[mid] && target>=nums[beg])
                    end=mid-1;
                else
                    beg=mid+1;
            }
            
            // and here we are clear that right half is sorted
            else
            {
                if(target>=nums[mid] && target<=nums[end])
                   beg=mid+1;
                else
                    end=mid-1;
            }
            
        }
        return -1;
    }
};