class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int ans=100;
        int i=0,j=0;
        int w=0;
        while(j<n)
        {
            if(j-i+1<k)
            {
                if(blocks[j]=='W') w++;
                j++;
            }
            if(j-i+1==k)
            {
                if(blocks[j]=='W') w++;
                ans=min(ans,w);
                if(ans==0) return ans;
                
                if(blocks[i]=='W') w--;
                i++;
                j++;
            }
        }
        return ans;
    }
};