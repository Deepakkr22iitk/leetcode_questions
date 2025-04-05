class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // https://www.youtube.com/watch?v=YxtxNmhiXro
        int n=nums.size();
        int total=0;
        for(int i=1;i<(1<<n);i++)
        {
            int curr_total=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j)) curr_total^=nums[j];
            }
            total+=curr_total;
        }
        return total;
    }
};