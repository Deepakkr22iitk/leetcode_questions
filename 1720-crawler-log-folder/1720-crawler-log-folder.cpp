class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(logs[i]=="./")
            {
                continue;
            }
            else if(logs[i]=="../")
            {
                if(ans==0)
                {
                    continue;
                }
                else
                {
                    --ans;
                }
            }
            else ans++;
        }
        return ans;
    }
};