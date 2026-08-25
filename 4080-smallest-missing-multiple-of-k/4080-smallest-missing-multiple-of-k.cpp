class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> present(101, false);

        for (int num : nums) {
            present[num] = true;
        }

        for (int multiple = k; ; multiple += k) {
            if (multiple > 100 || !present[multiple]) {
                return multiple;
            }
        }
        return -1;
    }
};