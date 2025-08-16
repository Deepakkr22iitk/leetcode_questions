class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_set<int> sumSet;
        map<int,int> freq;
        // Traverse through array
        // and store prefix sums
        int sum = 0,count=0;
        freq[sum]++;
        sumSet.insert(sum);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // If prefix sum is 0 or
            // it is already present
            if (sumSet.find(sum-k) != sumSet.end())
                count+=freq[sum-k];

            sumSet.insert(sum);
            freq[sum]++;
        }
        return count;
    }
};