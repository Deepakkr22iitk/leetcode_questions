class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int ans=0;
        int n=startTime.size();
        vector<int>gap;
        gap.push_back(startTime[0]);
        for(int i=1;i<n;++i)
        {
            gap.push_back(startTime[i]-endTime[i-1]);
        }

        gap.push_back(eventTime-endTime[n-1]);
        // n things give (n+1) gaps

        vector<int>largestRight(n+1);
        for(int i=n-1;i>=0;--i) largestRight[i]=max(largestRight[i+1],gap[i+1]);

        int largestLeft=0;
        for(int i=1;i<n+1;++i)
        {
            int curr_duration=endTime[i-1]-startTime[i-1];
            if(curr_duration<=max(largestLeft,largestRight[i])) ans=max(ans, gap[i-1]+gap[i]+curr_duration);  // It means I can move this duration somewher to left or right safely.

            ans=max(ans,gap[i-1]+gap[i]);

            largestLeft=max(largestLeft,gap[i-1]);
        }
        return ans;
    }
};