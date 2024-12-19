class Solution {
public:
    void sortColors(vector<int>& nums) {
        // any sorting algorithm
        // like merge sort 
        // TC = O(NlogN)   SC = o(N)

        // count number of 0's 1's and 2's and over-write them 
        // TC = O(2*N)    SC = O(N) 

        // Dutch National Flag Algorithm
        // low mid high
        // int start=0,end=nums.size()-1;
        // for(int idx=0;idx<nums.size();idx++)
        // {
        //     if(nums[idx]==0)
        // }

        // for(int i=0; i<nums.size(); i++)
        // {
        //     for(int j=i+1; j<nums.size(); j++)
        //     {
        //         if(nums[i]>nums[j])
        //         swap(nums[i],nums[j]);
        //     }
        // }

        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        return ;
    }
};