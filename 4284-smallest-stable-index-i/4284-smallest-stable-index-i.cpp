class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefMax(n), sufMin(n);

        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefMax[i] = max(prefMax[i - 1], nums[i]);

        sufMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            sufMin[i] = min(sufMin[i + 1], nums[i]);

        for (int i = 0; i < n; i++)
            if (prefMax[i] - sufMin[i] <= k)
                return i;

        return -1;
    }
};