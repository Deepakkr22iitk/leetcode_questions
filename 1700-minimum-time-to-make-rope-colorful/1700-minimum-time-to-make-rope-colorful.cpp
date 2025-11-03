class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // vector<int> cost={neededTime.begin(),neededTime.end()};
        // int res = 0;
        // int n = colors.size();
        // for(int i = 1; i < n; i++)
        // {
        //     if(colors[i] == colors[i - 1])
        //     {
        //         res += min(cost[i], cost[i - 1]); 
        //         cost[i] = max(cost[i], cost[i - 1]); 
        //     }     
        // }
        
        // return res;

        int n=colors.size();
        int ans=0;
        
        for(int i=0;i<n-1;i++)
        {
            vector<int>time;
            int j=i+1;
            time.push_back(neededTime[i]);
            while(colors[j]==colors[i])
            {
                time.push_back(neededTime[j]);
                j++;
            }
            i=j-1;
            sort(time.begin(),time.end());
            int len=time.size();
            for(int k=0;k<len-1;k++)
            {
                ans+=time[k];
            }
        }
        return ans;
    }
};