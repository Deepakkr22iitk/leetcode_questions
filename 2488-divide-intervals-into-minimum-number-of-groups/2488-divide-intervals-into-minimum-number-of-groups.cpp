class Solution {
public:
    // Result will be maximum number of groups required at any point of time similar to 'Meeting Rooms II'
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        map<int,int> points;

        for(auto &x:intervals)
        {
            points[x[0]]++;
            points[x[1]+1]--;
        }

        int ans=1;
        int curr=0;

        for(auto &x:points)
        {
            curr+=x.second;
            ans=max(ans,curr);
        }
        return ans;
    }
};