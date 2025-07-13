class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int ans=0;
        int i=0;
        int j=0;
        int n=players.size();
        int m=trainers.size();
        while(i<n && j<m)
        {
            if(players[i]<=trainers[j])
            {
                ans++;
                i++;
                j++;
            }
            else j++;
        }
        return ans;
    }
};