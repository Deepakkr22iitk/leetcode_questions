class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ha=0;
        int sum=0;
        for(int i=0;i<gain.size();i++)
        {
            sum+=gain[i];
            if(sum>=ha) ha=sum;
        }
        return ha;
    }
};