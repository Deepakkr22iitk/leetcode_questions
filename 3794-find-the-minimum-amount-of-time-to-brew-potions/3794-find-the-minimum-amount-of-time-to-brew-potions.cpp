
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size(),m=mana.size();

        vector<long long> time(n,0); // we will update it sequentially for every mana
        long long tillNow=0;
        for(int i=0;i<n;++i) // we are calculating for first mana only here
        {
            tillNow+=(1ll*mana[0]*skill[i]);
            time[i]=tillNow;
        }

        vector<long long> beforeHand(n,0); // we are trying to get the skills of persons before
        int sum=0;
        for(int i=0;i<n;++i)
        {
            beforeHand[i]=sum;
            sum+=(1ll*skill[i]);
        }

        for(int i=1;i<m;++i) // we have calculate for 1st previously
        {
            long long minTime=time[0]; // least time for the next which is possible before calculating
            for(int j=n-1;j>0;--j) // in this loop we are trying to get the minTime to start next mana
            {
                minTime=max(minTime,time[j]-(beforeHand[j]*(1ll*mana[i])));
            }
            
            for(int k=0;k<n;++k) // updating the time of completing mana[i] by skill[k]
            {
                minTime+=(1ll*skill[k]*mana[i]);
                time[k]=minTime;
            }
        }

        return time[n-1];
    }
};