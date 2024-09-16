class Solution {
public:
    int val_creation(string str,int i)
    {
        int ans=(str[i]-'0');
        ans=ans*10 + (str[i+1]-'0');
        return ans;
    }
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        sort(timePoints.begin(),timePoints.end());
        int ans=1e9;
        for(int i=0;i<n;++i)
        {
            string prev=timePoints[(i-1+n)%n];
            string curr=timePoints[i];

            int h1=val_creation(prev,0);
            int m1=val_creation(prev,3);

            int h2=val_creation(curr,0);
            int m2=val_creation(curr,3);

           int diff=(h2-h1)*60 + (m2-m1);
           diff=abs(diff);

           diff=min(diff,1440-diff);
           ans=min(ans,diff);
        }
        return ans;
    }
};