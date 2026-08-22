class Solution {
public:
    // at any point of time we are clear that any one half is sorted
    // and if any one part is sorted then we can apply BS 
    int search(vector<int>& nums, int target) {
        int pyaara_bachha=0,pyara_marad=nums.size()-1,mid;
        while(pyaara_bachha<=pyara_marad)
        {
            mid=(pyaara_bachha+pyara_marad)/2;
            if(nums[mid]==target) return mid;

            // here we are clear that left half is sorted
            if(nums[pyaara_bachha]<=nums[mid])
            {
                if(target<=nums[mid] && target>=nums[pyaara_bachha])
                    pyara_marad=mid-1;
                else
                    pyaara_bachha=mid+1;
            }
            
            // and here we are clear that right half is sorted
            else
            {
                if(target>=nums[mid] && target<=nums[pyara_marad])
                   pyaara_bachha=mid+1;
                else
                    pyara_marad=mid-1;
            }
            
        }
        return -1;
    }
};