class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int len = nums.size();
        sort(nums.begin(), nums.end());  // Sort the array for easier interval processing

        int ans = 1;    // Will store the final maximum frequency
        int curr = 0;   // Current count of overlapping ranges

        vector<vector<int>> period;  // To store start and end points of all valid ranges
        map<int, int> freq;          // Frequency of each element in the original array
        set<int> st;                 // Unique values (to iterate over possible targets)

        // Step 1: Build range intervals and store frequencies
        for (int i = 0; i < len; ++i) {
            freq[nums[i]]++;  // Count frequency of each number
            
            int l_val = nums[i] - k;   // Lower bound of range we can move this element to
            int h_val = nums[i] + k + 1; // Upper bound (exclusive) of range
            
            // Mark range entry and exit points
            period.push_back({l_val, 1});
            period.push_back({h_val, -1});
            
            // Collect unique potential values we might want to check
            st.insert(nums[i]);
            st.insert(l_val);
            st.insert(h_val);
        }

        // Step 2: Sort range change points by value
        sort(period.begin(), period.end());

        int i = 0;
        int n = period.size();

        // Step 3: Sweep line over all possible values
        for (auto &x : st) {
            // Move along the period list and update the current overlapping count
            while (i < n && period[i][0] <= x) {
                curr += period[i][1]; // +1 for entering a range, -1 for leaving
                ++i;
            }

            int curr_cnt = 0;
            if (freq.find(x) != freq.end()) 
                curr_cnt = freq[x]; // Current frequency of x in original array

            // You can increase this frequency by converting other numbers (within range)
            // But limited by numOperations (how many you can change)
            int val = curr_cnt + min(numOperations, curr - curr_cnt);

            ans = max(ans, val); // Update the answer if this gives higher frequency
        }

        return ans;
    }
};
