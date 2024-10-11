class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        int target_arrival=times[targetFriend][0];   // All the arrival time is unique
        sort(times.begin(),times.end());
        set<int>available;  // 
        int nxt=0;    // next available chair

        for(int i=0;i<n;++i)
        {
            int st=times[i][0];
            int en=times[i][1];

            while(!pq.empty() && pq.top().first<=st)    //Free up chairs based on current time
            {
                available.insert(pq.top().second);  // All the end position chairs are available for us so, inserting
                pq.pop();
            }

            int curr_chair;   // Assign chair from available set or increment new chair
            if(!available.empty())
            {
                curr_chair=*available.begin();
                available.erase(available.begin());
            }
            else curr_chair=nxt++;

            if(st==target_arrival) return curr_chair;

            pq.push({en,curr_chair});    // Push current leave time and chair no.
        }

        return 0;
    }
};