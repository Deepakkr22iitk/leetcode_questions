class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while (true) {
            bool is_sorted = true;
            for (size_t i = 0; i + 1 < nums.size(); ++i) {
                if (nums[i] > nums[i + 1]) {
                    is_sorted = false;
                    break;
                }
            }

            if (is_sorted) return ops;

            long long min_sum = -1;
            int min_idx = -1;

            for (size_t i = 0; i + 1 < nums.size(); ++i) {
                long long current_sum = (long long)nums[i] + nums[i + 1];
                if (min_idx == -1 || current_sum < min_sum) {
                    min_sum = current_sum;
                    min_idx = i;
                }
            }
            nums[min_idx] = (int)min_sum;
            nums.erase(nums.begin() + min_idx + 1);
            ops++;
        }
    }
};