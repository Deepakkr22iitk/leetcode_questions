class Solution {
public:
    int upperBound(vector<vector<int>>& events, int idx){
        int l = idx + 1, h = events.size() - 1, nextIndex = events.size();
        while (l <= h) {
            int mid = (l+h)/2;
            if (events[mid][0] > events[idx][1]){
                nextIndex = mid;
                h = mid - 1;
            }else{
               l = mid + 1; 
            }
        }
        return nextIndex;
    }

    int solve(vector<vector<int>>& events, int idx, int k, vector<vector<int>>& dp) {
        if (k == 2 || idx >= events.size()) return 0;
        if (dp[idx][k] != -1) return dp[idx][k];

        int nextindex = upperBound(events, idx);
        int include = events[idx][2] + solve(events, nextindex, k + 1, dp);
        int exclude = solve(events, idx + 1, k, dp);
        return dp[idx][k] = max(include, exclude);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        // solution 1
        // int n = events.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // sort(events.begin(), events.end());
        // return solve(events, 0, 0, dp);

        // solution 2
        vector<pair<int, pair<bool, int>>> timeline;
        int maxSum = 0, maxFinishedValue = 0;

        for (auto& event : events) {
            int start = event[0], end = event[1], value = event[2];
            timeline.push_back({start, {true, value}});
            timeline.push_back({end + 1, {false, value}});
        }

        sort(timeline.begin(), timeline.end());

        for (auto& entry : timeline) {
            int time = entry.first;
            bool isStart = entry.second.first;
            int value = entry.second.second;

            if (isStart) {
                maxSum = max(maxSum, maxFinishedValue + value);
            } else {
                maxFinishedValue = max(maxFinishedValue, value);
            }
        }

        return maxSum;
    }
};