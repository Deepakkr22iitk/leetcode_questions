class Solution {
public:
    // In a sequence of K meetings and K + 1 gaps, you could move all meetings to the start of the sequence to get the max free time.
    // Use a sliding window of K + 1 size to store sum of gaps and take the maximum.
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        int ans=0;
        int prev=0;
        deque<int>dq;
        for(int i=0;i<k;++i)
        {
            int curr_gap=startTime[i]-prev;
            ans+=curr_gap;
            dq.push_front(curr_gap);
            prev=endTime[i];
            if(i==k-1)
            {
                if((i+1)<n)
                {
                    curr_gap=startTime[i+1]-prev;
                    ans+=curr_gap;
                    prev=endTime[i+1];
                }
                else
                {
                    curr_gap=eventTime-prev;
                    ans+=curr_gap;
                }
                dq.push_front(curr_gap);
            }
        }
        int total=ans;
    
        for(int i=k;i<n;++i)
        {
            total-=dq.back();
            dq.pop_back();
            int curr_gap=0;
            if(i<(n-1)) 
            {
                curr_gap=startTime[i+1]-prev;
                prev=endTime[i+1];
            }
            else curr_gap=eventTime-prev;

            total+=curr_gap;
            ans=max(ans,total);
            dq.push_front(curr_gap);
        }
        return ans;
    }
};