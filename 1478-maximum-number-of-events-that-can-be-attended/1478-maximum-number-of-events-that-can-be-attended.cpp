class Solution {
public:
    // static bool comp(vector<int>&a,vector<int>&b)
    // {
    //     if(a[0]==b[0]) return (a[1]-b[1]);

    //     return (a[0]-b[0]);
    // }

    // Which one shall we attend among attendable events for a day?
    // Among the open events for a day, the one ends earliest should be attended.

    // How shall we tell which open event ends earliest?
    // We may maintain a min heap of open events sorted by end time for each day.

    // What are attendable events?
    // For day t, an event (start, end) is attendable if start <= t <= end and not attended yet

    // To promise start <= t <= end, we can add an event to the min heap when we are at day start; 
    // and remove events with end < t at day t.

    // To achieve not attended yet, we might sort events by start time at the beginning, and loop through 
    // sorted events using i, where events before i are either attended or not attendable.
    
    int maxEvents(vector<vector<int>>& events) {
        //sort(events.begin(),events.end(),comp);
        sort(events.begin(),events.end());

        int mx=0;
        int m=events.size();
        for(int i=0;i<m;++i) mx=max(mx,events[i][1]);

        priority_queue<int,vector<int>,greater<int>>pq;
        int mn=events[0][0];
        int i=0,ans=0;
        for(int t=mn;t<=mx;++t)
        {
            while(i<m && events[i][0]<=t)  // at each time, we add the new events that are now attendable
                pq.push(events[i++][1]);

            while(!pq.empty() && pq.top()<t) pq.pop(); // we remove the ones that are not attendable anymore

            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};