class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long mod=1e9+7;
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(),hFences.end());
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(),vFences.end());
        int l1=hFences.size();
        int l2=vFences.size();
        set<int>rk1;
        vector<int>rk2;
//         if(l1==1)
//         {
//             rk1.insert(hFences[0]-1);
//             rk1.insert(m-hFences[0]);
//         }
        
//         if(l2==1)
//         {
//             rk2.insert(vFences[0]-1);
//             rk2.insert(m-vFences[0]);
//         }
        
        for(int i=l1-1;i>=0;--i)
        {
            for(int j=0;j<i;++j)
            {
                int prev=hFences[i];
                int next=hFences[j];
                
                int diff=prev-next;
                rk1.insert(diff);
            }
        }
        
        for(int i=l2-1;i>=0;--i)
        {
            for(int j=0;j<i;++j)
            {
                int prev=vFences[i];
                int next=vFences[j];
                
                int diff=prev-next;
                rk2.push_back(diff);
            }
        }
        
        long long ans=-1;
        sort(rk2.begin(),rk2.end());
        int len=rk2.size();
        for(int i=len-1;i>=0;--i)
        {
            if(rk1.find(rk2[i])!=rk1.end())
            {
                ans=rk2[i];
                break;
            }
        }
        if(ans!=-1)
            ans=(ans*ans)% mod;
        
        return ans;
    }
};