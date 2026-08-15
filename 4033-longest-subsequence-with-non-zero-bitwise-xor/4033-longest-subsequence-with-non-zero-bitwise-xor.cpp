class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();

        int res = 0;
        bool isAllZero = true;

        // Calculate XOR of the entire array
        // and check whether at least one
        // non-zero element exists.
        for (int i = 0; i < n; i++) {

            res ^= nums[i];

            if (nums[i] != 0) {
                isAllZero = false;
            }
        }

        // If every element is zero,
        // every subsequence has XOR = 0.
        if (isAllZero) {
            return 0;
        }

        // If total XOR is non-zero,
        // the entire array is valid.
        if (res != 0) {
            return n;
        }

        // Total XOR is zero, but at least one
        // non-zero element exists.
        // Remove one non-zero element.
        return n - 1;
    }
};