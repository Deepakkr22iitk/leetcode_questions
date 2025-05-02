class Solution {
public:
    // The idea is markdown the impact from both the sides and take the decision at the end which side it'll fall
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>forces(n);
        string ans="";
        int force=0;
        for(int i=0;i<n;++i)
        {
            if(dominoes[i]=='L') force=0;
            
            else if(dominoes[i]=='R') force=n;
            else force=max(force-1,0);
            forces[i]=force;
        }

        force=0;
        for(int i=n-1;i>=0;--i)
        {
           if(dominoes[i]=='L') force=n;
            
            else if(dominoes[i]=='R') force=0;
            else force=max(force-1,0);
            forces[i]-=force;
        }
        for(auto &x:forces)
        {
            ans+= (x>0?'R':x<0?'L':'.');
        }
        return ans;
    }
};