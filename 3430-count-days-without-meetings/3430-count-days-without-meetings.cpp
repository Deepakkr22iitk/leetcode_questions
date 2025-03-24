class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n=meetings.size();
        // set<int> st;
        // int last=meetings[0][1];
        // for(int i=meetings[0][0];i<=meetings[0][1];i++)
        // {
        //     st.insert(i);
        // }
        // for(int i=1;i<n;i++)
        // {
        //     if(meetings[i][0]==meetings[i-1][0])
        //     {
        //         for(int j=meetings[i-1][1]+1;j<=meetings[i][1];j++)
        //         {
        //             st.insert(j);
        //         }
        //     }
        //     else
        //     {
        //         if(meetings[i][1]==meetings[i-1][1]) continue;
        //         else if(meetings[i][0]>meetings[i-1][0]&&meetings[i][0]<meetings[i-1][1] && meetings[i][1]>meetings[i-1][1])
        //         {
        //             for(int j=meetings[i-1][1]+1;j<=meetings[i][1];j++)
        //             {
        //                 st.insert(j);
        //             }
        //         }
        //         else if(meetings[i][0]>=meetings[i-1][1])
        //         {
        //             for(int j=meetings[i][0];j<=meetings[i][1];j++)
        //             {
        //                 st.insert(j);
        //             }
        //         }
        //     }
        // }
        // return days-st.size();
        int deep = 0;
        vector<pair<int, int>> collab;
        int end = meetings[0][1];
        int start = meetings[0][0];

        for (int i = 1; i <= n-1; ++i) {
            if (meetings[i][0] <= end + 1) {
                end = max(end, meetings[i][1]);
            } else {
                collab.push_back({start, end});
                end = meetings[i][1];
                start = meetings[i][0];
            }
        }
        collab.push_back({start, end});

        if (collab[0].first > 1) {
            deep += collab[0].first - 1;
        }

        for (int i = 1; i <= collab.size()-1; ++i) {
            deep += collab[i].first - collab[i - 1].second - 1;
        }

        if (collab.back().second < days) {
            deep += days - collab.back().second;
        }

        return deep;
    }
};