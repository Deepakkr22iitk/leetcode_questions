
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size(),m=mana.size();

        vector<long long> time(n,0);
        long long t=0;
        for(int i=0;i<n;++i)
        {
            int value=mana[0];
            int kaam=skill[i];
            long long v=1ll*value;
            long long k=1ll*kaam;
            t+=v*k;
            time[i]=t;
        }

        vector<long long> prevTime(n,0);
        int sum=0;
        for(int i=0;i<n;++i)
        {
            prevTime[i]=sum;
            sum+=(1ll*skill[i]);
        }

        for(int i=1;i<m;++i)
        {
            long long minTime=time[0];
            for(int j=n-1;j>0;--j)
            {
                minTime=max(minTime,time[j]-(prevTime[j]*(1ll*mana[i])));
            }
            
            for(int k=0;k<n;++k)
            {
                minTime+=(1ll*skill[k]*mana[i]);
                time[k]=minTime;
            }
        }

        return time[n-1];
    }
};