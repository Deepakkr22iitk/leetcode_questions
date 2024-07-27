class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long dee=0;
        int n=target.size();
        int len=original.size();
        vector<vector<long long>>cst(26,vector<long long>(26,1e18));
        cst[0][0]=0;
        for(int i=0;i<26;++i) cst[i][i]=0;
        
        for(int i=0;i<len;++i)
        {
            int ind1=original[i]-'a';
            int ind2=changed[i]-'a';
            cst[ind1][ind2]=min(cst[ind1][ind2],1LL*cost[i]);
        }
        
        for(int k=0;k<26;++k)
        {
            for(int i=0;i<26;++i)
            {
                for(int j=0;j<26;++j)
                {
                    if(cst[i][k]!=1e18 && cst[k][j]!=1e18) cst[i][j]=min(cst[i][j],cst[i][k]+cst[k][j]);
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            int ind1=source[i]-'a';
            int ind2=target[i]-'a';
            long long curr=cst[ind1][ind2];
            if(curr==1e18) return -1;
            
            dee+=curr;
        }
        return dee;
    }
};