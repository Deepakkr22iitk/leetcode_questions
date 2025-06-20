class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0;
        int north=0;
        int south=0;
        int east=0;
        int west=0;
        int n=s.size();
        
        for (int i=0;i<n;++i) 
        {
            char c=s[i];
            if (c=='N') north++;
            else if(c=='S') south++;
            else if(c=='E') east++;
            else if(c=='W') west++;
            
            int x=abs(north-south);
            int y=abs(east-west);
            int m_dist=x+y;
            int curr=m_dist+min(2*k, i+1-m_dist);      // Maximum number of changes I'm allowed to make If I've processed 5 elements 
            ans=max(ans,curr);                   // and I've m_dist=3 then (5-3)=2 elements can be changed for our purpose
        }  
        return ans;
    }
};